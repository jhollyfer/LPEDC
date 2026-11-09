## 0182 · Caminhos e ciclos

O caminhão da coleta de lixo sai da garagem, precisa passar por **todas as
ruas** do bairro e voltar. Cada rua repetida é diesel jogado fora e meia hora
a mais de turno. A pergunta da prefeitura: existe um roteiro que passa por
cada rua **exatamente uma vez** e termina na garagem?

Leonhard Euler respondeu essa pergunta em 1736, sobre as pontes de
Königsberg, e a resposta sai de uma contagem, sem testar roteiro nenhum.

**Grau.** O **grau** de um vértice é quantas arestas tocam nele (um laço, aresta
de um vértice para ele mesmo, conta 2). Num grafo dirigido o grau se divide em
dois: o **grau de entrada** (setas que chegam) e o **grau de saída** (setas que
saem). O 0109 já calculou os dois.

**Lema do aperto de mãos.** Some os graus de todos os vértices: cada aresta é
contada duas vezes, uma em cada ponta. Então a soma é **2 × E**, sempre par. Uma
consequência que cai em prova: o número de vértices de **grau ímpar** é par.
No dirigido, a soma dos graus de entrada é E, e a dos de saída também.

**Andar pelo grafo.** Os livros não concordam nos nomes, e a prova pode usar
qualquer um. O que muda é **o que pode se repetir**:

| O que pode repetir | Cormen | Edital e teoria dos grafos | Também chamado |
| --- | --- | --- | --- |
| vértices e arestas | caminho | **passeio** | percurso (*walk*) |
| vértices, mas nenhuma aresta | (sem nome) | **trajeto** | trilha (*trail*) |
| nada | caminho simples | **caminho** | (*path*) |
| fechado, nenhuma aresta repetida | (sem nome) | **circuito** | trilha fechada |
| fechado, nenhum vértice repetido | ciclo simples | **ciclo** | |

No Cormen, "caminho" aceita repetição e "ciclo" é qualquer caminho fechado
com pelo menos uma aresta; o adjetivo **simples** proíbe repetir vértice.
Neste módulo, quando a diferença importa, vale a coluna do meio (a do
edital), com o nome do Cormen ao lado. O **comprimento** é o número de
arestas, não de vértices.

**Circuito euleriano** é um circuito que usa **toda aresta exatamente uma
vez** (o Cormen chama de *percurso de Euler*). Teorema de Euler, para um grafo
**conexo** (ignorando vértices isolados):

- existe circuito euleriano ⇔ **todos os graus são pares**;
- existe trajeto euleriano aberto ⇔ **exatamente dois** vértices de grau
  ímpar, e ele começa num e termina no outro.

O porquê vem do aperto de mãos: toda vez que o caminhão entra numa esquina,
sai por outra rua, e as ruas de cada esquina se gastam aos pares. Só a saída
e a chegada escapam disso. No dirigido, a condição vira "entrada
= saída em todo vértice".

**Hierholzer** monta o circuito em O(V + E) com lista (O(V²) com matriz). Ele
anda por ruas ainda não usadas, apagando cada uma, até travar. Com graus pares,
só se trava no ponto de partida. Aí volta pela pilha até achar uma esquina com
rua sobrando, faz um desvio a partir dela e **encaixa** o desvio no circuito.

O bairro tem 6 esquinas e 8 ruas. Os números em roxo são
os graus; os números nas ruas, a ordem em que o caminhão passa por elas:

{{ideia}}

O código guarda as ruas numa matriz de contagem (`rua[u][v]` é quantas ruas
ligam `u` e `v`), confere a condição de Euler e roda o Hierholzer com uma
pilha explícita:

```c
#include <stdbool.h>
#include <stdio.h>

#define V 6
#define MAX_RUAS 16

const char *esquinas[V] = {"Garagem", "Praça", "Feira", "Escola", "Igreja", "Posto"};
int rua[V][V]; // rua[u][v] = quantas ruas ligam u e v (mão dupla)

int grau(int u) {
    int g = 0;
    for (int v = 0; v < V; v++) g += rua[u][v];
    return g;
}

// Hierholzer: anda por ruas ainda não usadas; quando trava, a esquina
// sai da pilha e entra no circuito (de trás para frente)
int hierholzer(int inicio, int circuito[]) {
    int pilha[MAX_RUAS + 1], topo = 0, n = 0;
    pilha[topo++] = inicio;
    while (topo > 0) {
        int u = pilha[topo - 1];
        int v = 0;
        while (v < V && rua[u][v] == 0) v++;
        if (v < V) {                  // ainda há rua livre saindo de u
            rua[u][v]--, rua[v][u]--; // apaga a rua: não passa de novo
            pilha[topo++] = v;
        } else {                      // travou: u está pronto
            circuito[n++] = u;
            topo--;
        }
    }
    return n;
}

int main(void) {
    int ruas[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 5}, {2, 4}, {2, 5}, {3, 4}};
    int e = 8;
    for (int k = 0; k < e; k++) {
        rua[ruas[k][0]][ruas[k][1]]++;
        rua[ruas[k][1]][ruas[k][0]]++;
    }

    int soma = 0, impares = 0;
    for (int u = 0; u < V; u++) {
        printf("grau(%s) = %d\n", esquinas[u], grau(u));
        soma += grau(u);
        if (grau(u) % 2 != 0) impares++;
    }
    printf("Soma dos graus: %d = 2 x %d ruas\n", soma, e);
    if (impares != 0) {
        printf("%d esquinas de grau ímpar: não há circuito\n", impares);
        return 0;
    }

    int circuito[MAX_RUAS + 1];
    int n = hierholzer(0, circuito);
    printf("Circuito:");
    for (int i = n - 1; i >= 0; i--) printf(" %s", esquinas[circuito[i]]);
    printf("\n(%d ruas, cada uma uma vez)\n", n - 1);
    return 0;
}
// Saída:
// grau(Garagem) = 2
// grau(Praça) = 4
// grau(Feira) = 4
// grau(Escola) = 2
// grau(Igreja) = 2
// grau(Posto) = 2
// Soma dos graus: 16 = 2 x 8 ruas
// Circuito: Garagem Praça Feira Igreja Escola Praça Posto Feira Garagem
// (8 ruas, cada uma uma vez)
```

No fluxograma, cada volta do laço olha o topo da pilha. Se há rua livre,
avança e apaga a rua; se não há, a esquina sai da pilha e vai para o
circuito. Ninguém escolhe rota, e mesmo assim nenhuma rua sobra:

{{fluxograma}}

### Passo a passo

A pilha depois de cada passo (o topo à direita). O primeiro passeio fecha cedo,
em Garagem Praça Feira Garagem, e deixa 5 ruas para trás. O desvio sai da
Feira e é encaixado ali:

| Passo | Pilha | Circuito (ao contrário) |
| --- | --- | --- |
| G → P → F → G | G P F G | |
| G travou | G P F | G |
| F → I → E → P → S → F | G P F I E P S F | G |
| todos travam, um a um | | G F S P E I F P G |

Invertido, o circuito é Garagem Praça Feira Igreja Escola Praça Posto Feira
Garagem. A Praça e a Feira aparecem duas vezes: é um **circuito**, não um
**ciclo**. O A363 faz as contas de grau num grafo dirigido; o A364 desenha a
casinha "sem tirar o lápis do papel", um trajeto aberto.

> [!WARNING]
> "Todos os graus pares" só garante o circuito se o grafo for **conexo**. Dois
> triângulos separados têm todos os graus iguais a 2 e nenhum circuito passa
> pelas 6 arestas. Confira a conexidade (uma DFS, 0111) antes de confiar nos
> graus. E não confunda: euleriano passa por toda **aresta** uma vez;
> hamiltoniano (0183) passa por todo **vértice** uma vez.

> [!TIP]
> **Por dentro do C:** apagar a rua é só `rua[u][v]--` e `rua[v][u]--`, dois
> acessos a uma matriz de `int` que mora num bloco contínuo de 6 × 6 × 4 =
> 144 bytes. Como cada rua é empilhada e desempilhada uma vez, a pilha nunca
> passa de E + 1 posições, e por isso `pilha[MAX_RUAS + 1]` cabe na pilha do
> programa sem `malloc`. A busca do próximo vizinho recomeça do 0
> a cada volta; com lista de adjacência e um ponteiro "próxima aresta" por
> vértice, o total cai para O(V + E).

> [!NOTE]
> **Pergunta para você:** se a prefeitura abrir uma rua nova entre a Escola e
> o Posto, quantas esquinas ficam com grau ímpar? Ainda existe circuito? E
> trajeto aberto, entre quais esquinas? Responda antes de rodar.

{{pratique}}

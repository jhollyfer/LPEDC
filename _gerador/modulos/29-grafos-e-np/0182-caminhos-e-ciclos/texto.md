## 0182 · Caminhos e ciclos

O caminhão da coleta de lixo precisa passar por **todas as ruas** do bairro e
voltar à garagem. Existe um roteiro que usa cada rua **exatamente uma vez**?
Euler respondeu em 1736, sobre as pontes de Königsberg, com uma contagem.

**Grau** de um vértice é quantas arestas tocam nele (um laço conta 2). No
dirigido, há o **grau de entrada** e o **de saída** (0109).

**Lema do aperto de mãos.** Cada aresta conta duas vezes, uma em cada ponta:
a soma dos graus é **2 × E**, sempre par, e o número de vértices de **grau
ímpar** é par. No dirigido, a soma dos graus de entrada é E, e a dos de saída
também.

**Andar pelo grafo.** Os nomes variam conforme **o que pode se repetir**:

| O que pode repetir | Cormen | Edital e teoria dos grafos | Também chamado |
| --- | --- | --- | --- |
| vértices e arestas | caminho | **passeio** | percurso (*walk*) |
| vértices, mas nenhuma aresta | (sem nome) | **trajeto** | trilha (*trail*) |
| nada | caminho simples | **caminho** | (*path*) |
| fechado, nenhuma aresta repetida | (sem nome) | **circuito** | trilha fechada |
| fechado, nenhum vértice repetido | ciclo simples | **ciclo** | |

No Cormen, "ciclo" é qualquer caminho fechado com pelo menos uma aresta, e
**simples** proíbe repetir vértice. Aqui vale a coluna do meio (a do edital).
O **comprimento** é o número de arestas.

**Circuito euleriano** é um circuito que usa **toda aresta exatamente uma
vez**. Teorema de Euler, para um grafo **conexo** (ignorando vértices
isolados):

- existe circuito euleriano ⇔ **todos os graus são pares**;
- existe trajeto euleriano aberto ⇔ **exatamente dois** vértices de grau
  ímpar, e ele começa num e termina no outro.

O porquê: o caminhão entra numa esquina e sai por outra rua, então as ruas de
cada esquina se gastam aos pares; só a saída e a chegada escapam. No
dirigido, a condição é "entrada = saída em todo vértice".

O **Hierholzer** monta o circuito em O(V + E) com lista (O(V²) com matriz):
anda por ruas não usadas, apagando-as, até travar (com graus pares, só na
partida). Volta pela pilha até uma esquina com rua sobrando e **encaixa** o
desvio feito dali.

O bairro tem 6 esquinas e 8 ruas. Em roxo, os graus; nas ruas, a ordem da
passagem:

{{ideia}}

O código guarda as ruas numa matriz de contagem (`rua[u][v]` é quantas ligam
`u` e `v`), confere Euler e roda o Hierholzer com pilha explícita:

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

No fluxograma, cada volta olha o topo da pilha: com rua livre, avança e a
apaga; sem, a esquina vai para o circuito:

{{fluxograma}}

### Passo a passo

A pilha depois de cada passo (topo à direita). O primeiro passeio fecha cedo
e deixa 5 ruas para trás; o desvio sai da Feira e é encaixado ali:

| Passo | Pilha | Circuito (ao contrário) |
| --- | --- | --- |
| G → P → F → G | G P F G | |
| G travou | G P F | G |
| F → I → E → P → S → F | G P F I E P S F | G |
| todos travam, um a um | | G F S P E I F P G |

Invertido: Garagem Praça Feira Igreja Escola Praça Posto Feira Garagem. Praça
e Feira repetem: é um **circuito**, não um **ciclo**. O A363 faz as contas de
grau num dirigido; o A364 desenha a casinha "sem tirar o lápis", um trajeto
aberto.

> [!WARNING]
> "Todos os graus pares" só garante o circuito se o grafo for **conexo**: dois
> triângulos separados têm todos os graus 2 e nenhum circuito passa pelas 6
> arestas. Confira a conexidade (DFS, 0111). E não confunda: euleriano passa
> por toda **aresta** uma vez; hamiltoniano (0183), por todo **vértice**.

> [!TIP]
> Com matriz, a busca do vizinho recomeça do 0 a cada volta. Com lista de
> adjacência e um ponteiro "próxima aresta" por vértice, o total é O(V + E).

> [!NOTE]
> **Pergunta para você:** se abrirem uma rua entre a Escola e o Posto, quantas
> esquinas ficam com grau ímpar? Ainda existe circuito? E trajeto aberto,
> entre quais esquinas?

{{pratique}}

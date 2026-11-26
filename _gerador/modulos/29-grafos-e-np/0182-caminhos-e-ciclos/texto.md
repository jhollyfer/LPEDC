## 0182 · Caminhos e ciclos

O caminhão da coleta de lixo precisa passar por todas as ruas do bairro e
voltar à garagem. Passar duas vezes pela mesma rua é gasolina jogada fora.
Existe um roteiro que usa cada rua exatamente uma vez? Euler respondeu a essa
pergunta em 1736, a propósito das pontes de Königsberg, e a resposta é uma
conta simples com os graus dos vértices. Antes dela, você precisa do
vocabulário que a prova usa para falar de percursos num grafo.

O **grau** de um vértice é o número de arestas que tocam nele. Um laço, a
aresta que sai e volta ao mesmo vértice, conta 2, porque toca o vértice nas
duas pontas. Num grafo dirigido (0109) há dois graus: o **grau de entrada**,
quantas arestas chegam, e o **grau de saída**, quantas partem (CORMEN et al.,
2024, apêndice B).

Somando os graus de todos os vértices, cada aresta entra na conta duas vezes,
uma em cada ponta. Por isso a soma dos graus é sempre **2 × E**, com E o
número de arestas. Esse fato tem nome, **lema do aperto de mãos**: numa
festa, se você soma quantas mãos cada pessoa apertou, cada aperto aparece
duas vezes. Uma consequência cai muito em prova: como a soma é par, o número
de vértices de grau ímpar também é par. Num dirigido, a soma dos graus de
entrada é E, e a dos graus de saída também (CORMEN et al., 2024, apêndice B).

Agora o vocabulário dos percursos. Andar pelo grafo é seguir uma sequência de
vértices em que cada um está ligado ao seguinte por uma aresta. O
**comprimento** do percurso é o número de arestas usadas. O nome do percurso
muda conforme o que pode se repetir. Se vértices e arestas podem repetir, é
um **passeio**. Se vértices podem repetir mas nenhuma aresta se repete, é um
**trajeto**. Se nada se repete, é um **caminho**. Os fechados, que terminam
onde começaram, seguem a mesma lógica: sem aresta repetida é um **circuito**;
sem vértice repetido (fora o primeiro, que é também o último) é um **ciclo**
(SZWARCFITER, 2018).

O Cormen usa outros nomes: para ele, "caminho" é qualquer passeio, e o que
não repete vértice é um "caminho simples"; "ciclo" é qualquer passeio fechado
com pelo menos uma aresta, e "ciclo simples" proíbe repetir vértice. Neste
módulo vale a coluna do edital, que é a da teoria dos grafos. A tabela põe os
nomes lado a lado:

| O que pode repetir | Cormen | Edital e teoria dos grafos | Também chamado |
| --- | --- | --- | --- |
| vértices e arestas | caminho | **passeio** | percurso (*walk*) |
| vértices, mas nenhuma aresta | (sem nome) | **trajeto** | trilha (*trail*) |
| nada | caminho simples | **caminho** | (*path*) |
| fechado, nenhuma aresta repetida | (sem nome) | **circuito** | trilha fechada |
| fechado, nenhum vértice repetido | ciclo simples | **ciclo** | |

Com isso dá para formular a pergunta do caminhão. Um **circuito euleriano** é
um circuito que usa toda aresta do grafo exatamente uma vez. O teorema de
Euler diz que, num grafo conexo (ignorando vértices isolados), existe
circuito euleriano se e só se todos os vértices têm grau par. E existe um
**trajeto euleriano** aberto se e só se há exatamente dois vértices de grau
ímpar; nesse caso ele começa num deles e termina no outro (LINTZMAYER; MOTA,
2023).

O porquê cabe numa frase. Cada vez que o caminhão chega a uma esquina, sai
dela por outra rua, então as ruas de cada esquina se gastam aos pares. Só a
esquina de partida e a de chegada escapam dessa regra, e num circuito as duas
são a mesma. Num grafo dirigido a condição muda para "grau de entrada igual
ao grau de saída em todo vértice" (CORMEN et al., 2024, cap. 20).

Saber que o circuito existe não diz qual é. O **algoritmo de Hierholzer** o
monta. Ele parte de um vértice e anda por arestas ainda não usadas, apagando
cada uma ao passar, até travar; com todos os graus pares, ele só trava de
volta ao ponto de partida. Se sobraram arestas, ele volta pela pilha de
vértices visitados até um que ainda tenha aresta livre, faz dali um novo
passeio fechado e o **encaixa** no circuito naquele ponto. Com lista de
adjacência, o custo é O(V + E); com matriz, procurar o próximo vizinho custa
O(V) por vez e o total vai a O(V²) (HIERHOLZER; WIENER, 1873).

> [!WARNING]
> "Todos os graus pares" só garante o circuito se o grafo for **conexo**: dois
> triângulos separados têm todos os graus 2 e nenhum circuito. E euleriano
> passa por toda **aresta**; hamiltoniano (0183), por todo **vértice**.

{{exemplo}}

O caminhão da coleta de lixo precisa passar por todas as 8 ruas de um bairro
de 6 esquinas e voltar à garagem. Em roxo, os graus; nas ruas, a ordem da
passagem:

{{ideia}}

O código guarda as ruas numa matriz de contagem, confere Euler e roda o
Hierholzer com pilha explícita:

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

Cada volta olha o topo da pilha: com rua livre, avança e a apaga; sem, a
esquina vai para o circuito:

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

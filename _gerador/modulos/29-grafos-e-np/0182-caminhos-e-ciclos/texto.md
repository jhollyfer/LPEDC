## 0182 · Caminhos e ciclos

- **Grau**: quantas arestas tocam o vértice (um laço conta 2). No dirigido, há
  grau de entrada e de saída (CORMEN et al., 2024, apêndice B).
- **Lema do aperto de mãos**: cada aresta conta duas vezes, então a soma dos
  graus é **2 × E** e o número de vértices de grau ímpar é par
  (CORMEN et al., 2024, apêndice B).
- **Passeio, trajeto, caminho, circuito, ciclo**: os nomes mudam conforme o
  que pode se repetir (tabela). O **comprimento** é o número de arestas. Aqui
  vale a coluna do edital (SZWARCFITER, 2018).
- **Circuito euleriano**: usa **toda aresta exatamente uma vez**. Num grafo
  conexo, existe se e só se todos os graus são pares; trajeto aberto, se e só
  se há exatamente dois ímpares, que são as pontas (LINTZMAYER; MOTA, 2023).
- **Por que pares**: cada vez que o percurso entra numa esquina, sai por outra
  rua; só a saída e a chegada escapam. No dirigido: entrada = saída em todo
  vértice (CORMEN et al., 2024, cap. 20).
- **Hierholzer**: anda por arestas não usadas, apagando-as, até travar; volta
  pela pilha até um vértice com aresta sobrando e encaixa o desvio. O(V + E)
  com lista, O(V²) com matriz (HIERHOLZER; WIENER, 1873).

| O que pode repetir | Cormen | Edital e teoria dos grafos | Também chamado |
| --- | --- | --- | --- |
| vértices e arestas | caminho | **passeio** | percurso (*walk*) |
| vértices, mas nenhuma aresta | (sem nome) | **trajeto** | trilha (*trail*) |
| nada | caminho simples | **caminho** | (*path*) |
| fechado, nenhuma aresta repetida | (sem nome) | **circuito** | trilha fechada |
| fechado, nenhum vértice repetido | ciclo simples | **ciclo** | |

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

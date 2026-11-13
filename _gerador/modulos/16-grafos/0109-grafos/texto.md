## 0109 · Grafos

Uma lista põe os dados em fila indiana: cada item tem um seguinte. Uma árvore
dá a cada item um pai só e não deixa voltar. Muita coisa do mundo não cabe
nisso. Pense nas ciclovias de uma cidade: o Centro liga na Praia **e** na
Feira, e a Praia liga na Feira, fechando um triângulo. Ninguém é pai de
ninguém, e dá para sair de um ponto e voltar a ele por outro caminho.

Para isso existe o **grafo**: um conjunto de **vértices**, que são os pontos,
e um conjunto de **arestas**, que são as ligações entre pares de vértices. O
Cormen escreve **G = (V, E)**, com V o conjunto de vértices e E o de arestas, e
usa as mesmas letras para as quantidades. É daí que vêm expressões como Θ(V²)
e Θ(V + E) que você vai ver no módulo inteiro (CORMEN et al., 2024, cap. 20).
Toda árvore é um grafo, mas a recíproca não vale: um grafo pode ter voltas e
pedaços soltos, sem ligação com o resto (TENENBAUM; LANGSAM; AUGENSTEIN, 1995,
cap. 8).

O grafo traz um vocabulário próprio, e cada palavra tem um sentido preciso.
Dois vértices ligados por uma aresta são **vizinhos**, ou **adjacentes**. O
**grau** de um vértice é quantas arestas tocam nele: se a Feira tem ciclovia
para Centro, Praia e Parque, o grau dela é 3. Um **caminho** é uma sequência
de vértices em que cada um é vizinho do seguinte, como Praia, Feira, Parque.
Um **ciclo** é um caminho que volta ao vértice de onde saiu, como Centro,
Praia, Feira, Centro. E um grafo é **conexo** quando dá para ir de qualquer
vértice a qualquer outro (ZIVIANI, 2010, cap. 7).

Os graus guardam uma conta curiosa. Cada aresta toca dois vértices, então ela
soma 1 no grau de cada um. Somando os graus de todos os vértices, cada aresta
foi contada duas vezes, e o total é o dobro do número de arestas (ZIVIANI,
2010, cap. 7). Cinco ciclovias dão soma de graus 10, sem precisar olhar o
desenho.

Às vezes a ligação tem mão única, como uma rua. Aí o grafo é **dirigido**:
cada aresta vira uma seta de um vértice para outro, e cada vértice passa a ter
**grau de saída** (setas que partem dele) e **grau de entrada** (setas que
chegam). Quando a aresta carrega um número, como minutos de viagem ou reais de
pedágio, o grafo é **ponderado**, e esse número é o **peso** da aresta
(CORMEN et al., 2024, cap. 20). As ciclovias valem nos dois sentidos e não têm
peso: o grafo delas é não dirigido e sem pesos.

No C, cada vértice vira um número de `0` a `V - 1`, porque número serve de
índice de vetor. Os nomes ficam num vetor à parte: `nomes[2]` é `"Feira"`
(FEOFILOFF, 2009). Falta guardar as arestas, e há duas formas clássicas.

A **matriz de adjacência** é um `int adj[V][V]` em que `adj[i][j] = 1` quando
existe aresta de `i` para `j`. Perguntar se `i` e `j` são vizinhos custa O(1),
uma leitura. Listar os vizinhos de `i` custa O(V), porque é preciso varrer a
linha inteira. Num grafo não dirigido, a matriz sai simétrica. A **lista de
adjacência** é um vetor de V listas encadeadas, em que a lista de `i` guarda só
os vizinhos de `i`. Ela ocupa O(V + E) e lista os vizinhos de `i` no tempo do
grau dele. A tabela compara as duas:

| Representação | Espaço | "i e j são vizinhos?" | Listar vizinhos de `i` |
| --- | --- | --- | --- |
| **matriz** `int adj[V][V]` | O(V²) | O(1) | O(V), a linha inteira |
| **lista de adjacência** | O(V + E) | o grau de `i` | o grau de `i` |

A escolha depende do tamanho. `int adj[5][5]` são 25 `int` seguidos, 100
bytes. Com 100 mil vértices, a matriz teria 10¹⁰ casas, uns 40 GB, quase todas
zero. Grafo pequeno ou **denso** (com muitas arestas), matriz; grafo grande e
**esparso** (com poucas arestas perto do máximo), lista.

> [!WARNING]
> Em grafo não dirigido, a aresta entra **nos dois sentidos**: `adj[a][b] = 1`
> e `adj[b][a] = 1`. Esquecer um cria um grafo dirigido sem querer, e o erro
> só aparece quando a busca não acha um caminho que existe.

{{exemplo}}

Cinco ciclovias ligam Centro, Praia, Feira, Parque e Estádio, nos dois
sentidos e sem peso. A matriz sai simétrica; a Feira tem três vizinhos, e a
linha 2 tem três 1:

{{ideia}}

As arestas entram como pares, e o grau sai da soma de cada linha. Soma ímpar
indicaria um sentido esquecido:

```c
#include <stdio.h>

#define V 5 // número de vértices (pontos da cidade)

int main(void) {
    const char *nomes[V] = {"Centro", "Praia", "Feira", "Parque", "Estadio"};
    int adj[V][V] = {0}; // adj[i][j] == 1: existe ciclovia entre i e j

    // as ciclovias, como pares de vértices
    int ciclovias[][2] = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 4}};
    int total = (int)(sizeof ciclovias / sizeof ciclovias[0]);

    for (int k = 0; k < total; k++) {
        int a = ciclovias[k][0];
        int b = ciclovias[k][1];
        adj[a][b] = 1;
        adj[b][a] = 1; // não dirigido: vale nos dois sentidos
    }

    printf("     0 1 2 3 4\n");
    int soma_graus = 0;
    for (int i = 0; i < V; i++) {
        int grau = 0;
        printf("  %d ", i);
        for (int j = 0; j < V; j++) {
            printf(" %d", adj[i][j]);
            grau += adj[i][j]; // o grau é a soma da linha
        }
        printf("  %-8s grau %d\n", nomes[i], grau);
        soma_graus += grau;
    }
    printf("Soma dos graus: %d = 2 x %d ciclovias\n", soma_graus, total);
    return 0;
}
// Saída:
//      0 1 2 3 4
//   0  0 1 1 0 0  Centro   grau 2
//   1  1 0 1 0 0  Praia    grau 2
//   2  1 1 0 1 0  Feira    grau 3
//   3  0 0 1 0 1  Parque   grau 2
//   4  0 0 0 1 0  Estadio  grau 1
// Soma dos graus: 10 = 2 x 5 ciclovias
```

Primeiro monta-se a estrutura, depois respondem-se as perguntas; todo
algoritmo do módulo segue essa ordem. O A217 guarda pesos na matriz e o A218
usa a lista de adjacência como TAD:

{{fluxograma}}

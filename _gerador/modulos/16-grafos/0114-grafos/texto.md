## 0114 · Grafos

A prefeitura inaugurou cinco ciclovias ligando Centro, Praia, Feira, Parque e
Estádio. Você quer um app que responda: de onde dá para ir direto para onde?
Qual ponto tem mais ligações? Dá para chegar no Estádio saindo da Praia?

Lista não serve: ela é uma fila indiana, cada item tem um próximo. Árvore
também não: cada nó tem um pai só e não existe volta. Aqui o Centro liga na
Praia **e** na Feira, e a Praia liga de volta na Feira, fechando um triângulo.
Para isso existe o **grafo**.

Um grafo é um conjunto de **vértices** (os pontos) e de **arestas** (as
ligações entre pares de pontos). Os vértices da ciclovia são os cinco lugares;
as arestas, as cinco ciclovias. Toda árvore é um grafo, mas um grafo pode ter
ciclos e partes soltas.

O vocabulário que você vai usar o módulo inteiro:

- **vizinhos** (ou adjacentes): dois vértices ligados por uma aresta;
- **grau**: quantas arestas tocam o vértice (a Feira tem grau 3);
- **caminho**: uma sequência de vértices vizinhos (Praia, Feira, Parque);
- **ciclo**: um caminho que volta ao começo (Centro, Praia, Feira, Centro);
- **conexo**: dá para ir de qualquer vértice a qualquer outro.

Se a ligação tem mão única, o grafo é **dirigido** e cada aresta vira uma seta
(seguir alguém no Instagram não obriga a pessoa a seguir de volta). Se a
aresta carrega um número, como minutos ou reais, o grafo é **ponderado**. As
ciclovias valem nos dois sentidos e ainda não têm peso.

No C, vértice é um **número de 0 a V-1**. O nome bonito fica num vetor à parte
(`nomes[2]` é `"Feira"`). Para guardar as arestas existem duas representações
clássicas:

- **matriz de adjacência**: `int adj[V][V]`, com `adj[i][j] = 1` quando existe
  aresta de `i` para `j`. Perguntar "i e j são vizinhos?" custa O(1). Listar os
  vizinhos de `i` custa O(V), porque você varre a linha inteira.
- **lista de adjacência**: um vetor de V listas encadeadas; a lista de `i`
  guarda só os vizinhos de `i`. Ocupa O(V + E) (E é o número de arestas) e
  listar os vizinhos custa só o grau.

Uma rede social guarda, para cada usuário, a lista de quem ele segue: é uma
lista de adjacência. No C não tem dicionário nem vetor que cresce prontos: ou
você aloca a matriz, ou monta as listas com `malloc`.

Vamos ver na prática. Cada ciclovia liga um 1 em **duas** casas da matriz,
`adj[a][b]` e `adj[b][a]`, por isso a matriz de um grafo não dirigido é
espelhada na diagonal. A Feira tem três vizinhos, e a linha 2 tem três 1:

{{ideia}}

No código, as arestas entram como pares e o grau sai somando cada linha:

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

Repara no fluxograma: primeiro o programa monta a estrutura (uma volta por
aresta, marcando os dois sentidos) e só depois responde perguntas sobre ela.
Todo algoritmo de grafo deste módulo segue essa ordem:

{{fluxograma}}

A última linha não é coincidência. Cada aresta encosta em dois vértices e
soma 1 no grau de cada um, então a soma dos graus é sempre o dobro do número
de arestas. Isso serve de teste rápido: se a soma der ímpar, você esqueceu um
dos sentidos em algum lugar.

O exemplo A228 mostra a outra representação, a lista de adjacência, como um
TAD (`grafo.h` + `grafo.c`) e com arestas dirigidas: quem segue quem.

> [!WARNING]
> Em grafo não dirigido, a aresta entra **nos dois sentidos**: `adj[a][b] = 1`
> e `adj[b][a] = 1`. Esquecer um deles cria um grafo dirigido sem querer: o
> Centro "vai" para a Praia, mas a Praia não volta. O compilador não reclama, e
> o erro só aparece mais tarde, quando a busca não acha um caminho que existe.

> [!TIP]
> **Por dentro do C:** `int adj[5][5]` são 25 `int` seguidos na memória, linha
> após linha: 100 bytes. Com 100 mil vértices seriam 10¹⁰ casas, 40 GB, quase
> todas com zero, porque um mapa de ruas real tem poucos vizinhos por esquina.
> Na lista de adjacência cada aresta vira um nó `{ int destino; No *prox; }`
> de 16 bytes (4 do `int`, 4 de alinhamento e 8 do ponteiro): com 300 mil
> arestas, uns 5 MB. Regra prática: grafo pequeno ou denso, matriz; grafo
> grande e esparso, lista.

> [!NOTE]
> **Pergunta para você:** se a prefeitura abrir uma ciclovia entre Praia e
> Estádio, quais números da saída mudam? Preveja a nova matriz e a soma dos
> graus antes de mudar o A227.

{{pratique}}

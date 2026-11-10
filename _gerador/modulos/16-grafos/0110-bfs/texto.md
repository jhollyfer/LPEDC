## 0110 · BFS: busca em largura

Você quer uma indicação para a vaga da recrutadora Rita, que não conhece, mas
conhece Max e Nina, que conhecem outras pessoas. Qual é a corrente mais curta
de apresentações? Num grafo não dirigido, é o **menor caminho em número de
arestas** de Lia (você) até Rita. O "conexão de 2º grau" do LinkedIn é essa
**distância**, sem relação com o grau do assunto 0109.

A **busca em largura** (BFS, *breadth-first search*) explora o grafo em ondas,
como uma pedra jogada no lago: a onda 0 é Lia; a 1, quem está a uma aresta
(Max e Nina); a 2, os vizinhos deles ainda não vistos (Otto e Pedro); a 3,
Rita.

A BFS usa uma **fila** (assunto 0085), e quem foi descoberto primeiro sai
primeiro. O laço tira `u` da frente e, para cada vizinho `v` não descoberto,
faz `dist[v] = dist[u] + 1`, `pai[v] = u` e põe `v` no fim da fila.

`dist[]` guarda a distância e, com `-1`, o "não descoberto", o que impede a
busca de andar em círculos: num grafo dá para chegar ao mesmo vértice por
caminhos diferentes (Otto é vizinho de Max **e** de Nina). `pai[]` guarda quem
descobriu cada vértice; os pares (pai, filho) formam a **árvore da BFS**, e
seguir `pai[]` de Rita até `-1` dá o caminho mais curto, de trás para frente.

O Cormen usa **cores**: **branco** é o não descoberto (`dist == -1`), **cinza**
o que está na fila e **preto** o que já saiu; `v.d` é o `dist[v]` e `v.π`, o
`pai[v]`.

No desenho, as setas verdes são a árvore da BFS, e o número de cada pessoa é a
distância:

{{ideia}}

O código monta a matriz, roda a BFS a partir de Lia e reconstrói o caminho:

```c
#include <stdio.h>

#define V 6

int main(void) {
    const char *nomes[V] = {"Lia", "Max", "Nina", "Otto", "Pedro", "Rita"};
    int adj[V][V] = {0};
    int conexoes[][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 5}, {4, 5}};
    for (int k = 0; k < 7; k++) {
        adj[conexoes[k][0]][conexoes[k][1]] = 1;
        adj[conexoes[k][1]][conexoes[k][0]] = 1;
    }

    int dist[V], pai[V];
    for (int v = 0; v < V; v++) {
        dist[v] = -1; // -1: ainda não descoberto
        pai[v] = -1;
    }

    int fila[V]; // cada vértice entra uma vez só: V posições bastam
    int inicio = 0, fim = 0;
    int origem = 0; // Lia
    dist[origem] = 0;
    fila[fim++] = origem;

    printf("Ordem da visita:\n");
    while (inicio < fim) {
        int u = fila[inicio++]; // tira da frente
        printf("  %-5s distância %d\n", nomes[u], dist[u]);
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && dist[v] == -1) {
                dist[v] = dist[u] + 1; // marca ao ENTRAR na fila
                pai[v] = u;
                fila[fim++] = v;
            }
        }
    }

    // o caminho sai de trás para frente, seguindo pai[]
    int destino = 5; // Rita
    int caminho[V], n = 0;
    for (int v = destino; v != -1; v = pai[v]) caminho[n++] = v;
    printf("Caminho até %s:", nomes[destino]);
    for (int i = n - 1; i >= 0; i--) printf(" %s%s", nomes[caminho[i]], i > 0 ? " ->" : "");
    printf(" (distância %d)\n", dist[destino]);
    return 0;
}
// Saída:
// Ordem da visita:
//   Lia   distância 0
//   Max   distância 1
//   Nina  distância 1
//   Otto  distância 2
//   Pedro distância 2
//   Rita  distância 3
// Caminho até Rita: Lia -> Max -> Otto -> Rita (distância 3)
```

A busca termina quando a fila esvazia:

{{fluxograma}}

### Passo a passo

Cada linha é uma volta do `while`. Otto já foi descoberto por Max; quando Nina
o vê, nada acontece:

| Tira | Vizinhos novos | dist anotada | Fila depois |
| --- | --- | --- | --- |
| (início) | | Lia = 0 | Lia |
| Lia | Max, Nina | 1, 1 | Max, Nina |
| Max | Otto | 2 | Nina, Otto |
| Nina | Pedro (Otto já tem dist) | 2 | Otto, Pedro |
| Otto | Rita | 3 | Pedro, Rita |
| Pedro | nenhum (Rita já tem dist) | | Rita |
| Rita | nenhum | | (vazia) |

Saem da fila todos de distância 1, depois todos de 2: o primeiro caminho até
Rita é o mais curto. Isso vale porque toda aresta custa 1; com pesos
diferentes entra Dijkstra (assunto 0112).

O exemplo A219 agrupa as pessoas por onda e mostra quem a BFS não alcança. O
A220 roda a BFS numa grade, onde os vizinhos saem de uma conta, sem matriz.

> [!WARNING]
> Marque o vértice como descoberto **ao pôr na fila**, não ao tirar. Marcando
> ao tirar, Otto entra duas vezes (por Max e por Nina) e a fila estoura.

> [!TIP]
> **Por dentro do C:** cada vértice entra na fila uma vez, então `int fila[V]`
> basta e `fila[inicio++]` é O(1). A BFS custa O(V²) com matriz e O(V + E)
> com lista de adjacência.

> [!NOTE]
> **Pergunta para você:** sem a conexão entre Max e Otto, qual passa a ser o
> caminho até Rita, e quem descobre Otto? Preveja a tabela antes de apagar o
> par `{1, 3}`.

{{pratique}}

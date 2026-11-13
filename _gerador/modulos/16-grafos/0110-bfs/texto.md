## 0110 · BFS: busca em largura

- **Distância**: o menor número de arestas num caminho de `s` até `v`. Não
  confunda com o grau do 0109 (FEOFILOFF, 2009, cap. 5).
- **Busca em largura** (BFS, *breadth-first search*): explora em ondas a
  partir da origem. Primeiro quem está a 1 aresta, depois a 2, e assim por
  diante (CORMEN et al., 2024, cap. 20).
- **Fila** (0085): quem foi descoberto primeiro sai primeiro. O laço tira `u`
  da frente e, para cada vizinho `v` novo, faz `dist[v] = dist[u] + 1`,
  `pai[v] = u` e põe `v` no fim (FEOFILOFF, 2009, cap. 5).
- **`dist[]` com -1**: marca o "não descoberto" e impede andar em círculos,
  porque dá para chegar ao mesmo vértice por caminhos diferentes
  (FEOFILOFF, 2009, cap. 5).
- **Árvore da BFS**: os pares (`pai[v]`, `v`). Seguir `pai[]` do destino até
  `-1` dá o caminho mais curto, de trás para frente
  (CORMEN et al., 2024, cap. 20).
- **Cores do Cormen**: **branco** é o não descoberto, **cinza** o que está na
  fila e **preto** o que já saiu; `v.d` é `dist[v]` e `v.π`, `pai[v]`
  (CORMEN et al., 2024, cap. 20).
- **Custo**: cada vértice entra na fila uma vez, então `int fila[V]` basta.
  O(V²) com matriz e O(V + E) com lista (ZIVIANI, 2010, cap. 7).
- **Só vale sem peso**: o primeiro caminho achado é o mais curto porque toda
  aresta custa 1. Com pesos, entra Dijkstra (0112) (CORMEN et al., 2024,
  cap. 22).

> [!WARNING]
> Marque o vértice como descoberto **ao pôr na fila**, não ao tirar. Marcando
> ao tirar, um vértice com dois vizinhos já vistos entra duas vezes e a fila
> estoura.

{{exemplo}}

Lia quer uma indicação para a vaga da recrutadora Rita. A onda 1 é Max e
Nina; a 2, Otto e Pedro; a 3, Rita. As setas verdes são a árvore da BFS, e o
número de cada pessoa é a distância:

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

A busca termina quando a fila esvazia. O A219 agrupa por onda e o A220 roda a
BFS numa grade:

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

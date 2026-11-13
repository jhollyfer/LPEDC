## 0187 · Reduções

- **Redução polinomial** (A ≤p B): algoritmo polinomial que transforma toda
  instância de A numa de B com **a mesma resposta**. A não é mais difícil que
  B (CORMEN et al., 2024, cap. 34).
- **Dois usos**: resolver A com um programa de B; ou provar dificuldade: se A
  é NP-difícil e A ≤p B, B também é (LINTZMAYER; MOTA, 2023).
- **Conjunto independente**: vértices sem nenhuma aresta entre eles.
  **Clique**: vértices com todas as arestas entre eles. **Cobertura de
  vértices**: vértices que tocam toda aresta. Os três são NP-completos na
  versão "existe um de tamanho k?" (KARP, 1972).
- **Complemento** de G: tem aresta entre os pares que G não liga. S é
  independente em G se e só se S é clique no complemento, e se e só se
  **V − S** é cobertura de G. Montar o complemento custa O(V²)
  (CORMEN et al., 2024, cap. 34).
- **Do 3-SAT à clique**: cada cláusula vira um grupo de vértices, um por
  literal; ligue vértices de cláusulas diferentes que não se contradizem. Uma
  clique com um vértice por cláusula dá uma atribuição que satisfaz a fórmula
  (CORMEN et al., 2024, cap. 34).
- **Máscaras**: o complemento de um conjunto é `todos & ~comissao`, com
  `todos = (1 << V) - 1`; o do grafo é `paz[a][b] = a != b && !briga[a][b]`.

> [!WARNING]
> A pegadinha é o sentido. Para provar que X é difícil, reduza um difícil
> conhecido **a X**. Reduzir X a SAT só mostra que X não é mais difícil que
> SAT. E a redução precisa ser polinomial.

{{exemplo}}

Uma síndica quer a maior comissão sem nenhum par que já brigou, e o sobrinho
tem um programa que acha o maior grupo de amigos. À esquerda, G e a maior
comissão; no meio, o complemento, em que ela vira clique; à direita, os
outros três são a cobertura:

{{ideia}}

A força bruta de clique é a **caixa-preta**; a redução é a montagem de
`paz`:

```c
#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *moradores[V] = {"Jorge", "Rita", "Kátia", "Léo", "Márcio", "Nina"};
int briga[V][V];    // G: aresta = os dois brigaram
int paz[V][V];      // complemento de G: aresta = não brigaram

// a "caixa-preta": maior clique por força bruta (devolve a máscara)
int maior_clique(int g[V][V]) {
    int melhor = 0, tam_melhor = 0;
    for (int m = 1; m < (1 << V); m++) {
        bool ok = true;
        int tam = 0;
        for (int a = 0; a < V; a++) {
            if (!(m >> a & 1)) continue;
            tam++;
            for (int b = a + 1; b < V; b++)
                if ((m >> b & 1) && !g[a][b]) ok = false;
        }
        if (ok && tam > tam_melhor) melhor = m, tam_melhor = tam;
    }
    return melhor;
}

void mostra(const char *rotulo, int m) {
    int tam = 0;
    printf("%s:", rotulo);
    for (int v = 0; v < V; v++)
        if (m >> v & 1) printf(" %s", moradores[v]), tam++;
    printf(" (%d)\n", tam);
}

int main(void) {
    int brigas[][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {4, 5}, {2, 5}};
    for (int k = 0; k < 7; k++) briga[brigas[k][0]][brigas[k][1]] = briga[brigas[k][1]][brigas[k][0]] = 1;

    // a redução: montar o complemento custa O(V²)
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) paz[a][b] = a != b && !briga[a][b];

    int comissao = maior_clique(paz);         // clique no complemento...
    mostra("Comissão sem brigas", comissao);   // ...é conjunto independente em G
    int todos = (1 << V) - 1;
    mostra("Mediadores (cobertura)", todos & ~comissao); // o resto cobre toda briga
    return 0;
}
// Saída:
// Comissão sem brigas: Rita Kátia Márcio (3)
// Mediadores (cobertura): Jorge Léo Nina (3)
```

Os três passos de toda redução: transformar a entrada, chamar o resolvedor do
outro problema e traduzir a resposta:

{{fluxograma}}

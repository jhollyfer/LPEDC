## 0189 · Juntando tudo

- **Caixeiro viajante** (TSP): o **ciclo hamiltoniano** de custo mínimo
  (0183). A versão de decisão ("existe volta de no máximo L?") é NP-completa
  por redução do ciclo hamiltoniano: arestas do grafo custam 1, as que faltam
  custam 2 (CORMEN et al., 2024, cap. 34).
- **Métrico**: com desigualdade triangular, a árvore mínima dá uma
  2-aproximação (0188) (CORMEN et al., 2024, cap. 35).
- **Força bruta**: fixe o ponto de partida e teste as (n − 1)! ordens; 87
  bilhões com 15 pontos.
- **Held-Karp**: programação dinâmica sobre subconjuntos. `dp[S][j]` é o menor
  caminho que sai da origem, passa exatamente pelos pontos de S e termina em
  j. Só importam o conjunto e o último ponto, não a ordem (HELD; KARP, 1962):

```text
dp[{0}][0] = 0
dp[S ∪ {k}][k] = min sobre j em S:  dp[S][j] + d[j][k]
resposta = min sobre j:  dp[todos][j] + d[j][0]
```

- **Custo do Held-Karp**: 2ⁿ conjuntos × n finais × n extensões, **O(n² ·
  2ⁿ)** de tempo e **O(n · 2ⁿ)** de memória, bem menos que n!
  (HELD; KARP, 1962).
- **Quando usar cada um**: até uns 20 pontos, Held-Karp resolve em segundos
  (o limite é a memória); acima, aproximação com melhoria local, como o
  2-opt.
- **Bits sem parênteses**: `s >> j & 1` e `s | 1 << k` funcionam porque `>>`
  e `<<` vêm antes de `&` e `|` (0170).

| n | (n − 1)! rotas | n² · 2ⁿ (Held-Karp) | n² (aproximado) |
| --- | --- | --- | --- |
| 8 | 5 040 | 16 384 | 64 |
| 15 | 8,7 · 10¹⁰ | 7,4 · 10⁶ | 225 |
| 20 | 1,2 · 10¹⁷ | 4,2 · 10⁸ | 400 |
| 30 | 8,8 · 10³⁰ | 9,7 · 10¹¹ | 900 |

> [!WARNING]
> A garantia de 2 × ótimo só vale com a **desigualdade triangular**; com
> distâncias quaisquer, nenhum algoritmo polinomial tem fator constante, a
> menos que P = NP. Held-Karp é **exato** e exponencial; a árvore é
> **aproximada** e polinomial.

{{exemplo}}

O entregador de uma farmácia tem sete endereços e quer a volta mais curta,
com distâncias em quarteirões (|dx| + |dy|). À esquerda, a rota exata; à
direita, a da árvore mínima, com voltas desnecessárias no fim:

{{ideia}}

S é uma máscara de bits (0186); o bit 0, a farmácia, está sempre ligado, por
isso o laço anda de 2 em 2:

```c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 8
#define INF 1000000000

const char *pontos[N] = {"Farmácia", "Ana", "Bruno", "Clara", "Dênis", "Edna", "Fábio", "Gil"};
const int px[N] = {0, 1, 4, 6, 7, 5, 2, 3};
const int py[N] = {0, 3, 4, 3, 0, 1, 6, 1};
int d[N][N];
long passos;

// exato: Held-Karp. dp[S][j] = menor caminho que sai da farmácia, passa
// por todos de S e termina em j
int dp[1 << N][N], ant[1 << N][N];

int exato(int rota[]) {
    for (int s = 0; s < (1 << N); s++)
        for (int j = 0; j < N; j++) dp[s][j] = INF;
    dp[1][0] = 0;
    for (int s = 1; s < (1 << N); s += 2)        // só conjuntos com a farmácia (bit 0)
        for (int j = 0; j < N; j++) {
            if (!(s >> j & 1) || dp[s][j] == INF) continue;
            for (int k = 1; k < N; k++) {        // estende o caminho até k
                if (s >> k & 1) continue;
                passos++;
                int t = s | 1 << k, c = dp[s][j] + d[j][k];
                if (c < dp[t][k]) dp[t][k] = c, ant[t][k] = j;
            }
        }
    int todos = (1 << N) - 1, fim = 1;
    for (int j = 2; j < N; j++)
        if (dp[todos][j] + d[j][0] < dp[todos][fim] + d[fim][0]) fim = j;
    int custo = dp[todos][fim] + d[fim][0];
    for (int i = N - 1, s = todos, j = fim; i >= 0; i--) { // volta pelos anteriores
        rota[i] = j;
        int a = ant[s][j];
        s &= ~(1 << j);
        j = a;
    }
    return custo;
}

// aproximado: árvore mínima (Prim) + pré-ordem
int pai[N], tam;
void preordem(int u, int rota[]) {
    rota[tam++] = u;
    for (int v = 1; v < N; v++)
        if (pai[v] == u) preordem(v, rota);
}

int aproximado(int rota[]) {
    int chave[N];
    bool dentro[N] = {false};
    for (int v = 0; v < N; v++) chave[v] = INF, pai[v] = -1;
    chave[0] = 0;
    for (int k = 0; k < N; k++) {
        int u = -1;
        for (int v = 0; v < N; v++)
            if (!dentro[v] && (u == -1 || chave[v] < chave[u])) u = v;
        dentro[u] = true;
        for (int v = 0; v < N; v++, passos++)
            if (!dentro[v] && d[u][v] < chave[v]) chave[v] = d[u][v], pai[v] = u;
    }
    tam = 0;
    preordem(0, rota);
    int custo = 0;
    for (int i = 0; i < N; i++) custo += d[rota[i]][rota[(i + 1) % N]];
    return custo;
}

void mostra(const char *nome, int custo, const int rota[]) {
    printf("%s: %d quarteirões, %ld passos\n ", nome, custo, passos);
    for (int i = 0; i < N; i++) printf(" %s", pontos[rota[i]]);
    printf(" %s\n", pontos[0]);
}

int main(void) {
    for (int a = 0; a < N; a++)
        for (int b = 0; b < N; b++) d[a][b] = abs(px[a] - px[b]) + abs(py[a] - py[b]);
    int rota[N];

    passos = 0;
    int c1 = exato(rota);
    mostra("Exato (Held-Karp)", c1, rota);
    passos = 0;
    int c2 = aproximado(rota);
    mostra("Aproximado (árvore)", c2, rota);
    printf("O aproximado gasta %.0f%% a mais\n", 100.0 * (c2 - c1) / c1);
    return 0;
}
// Saída:
// Exato (Held-Karp): 28 quarteirões, 1351 passos
//   Farmácia Gil Edna Dênis Clara Bruno Fábio Ana Farmácia
// Aproximado (árvore): 36 quarteirões, 64 passos
//   Farmácia Ana Bruno Clara Edna Dênis Gil Fábio Farmácia
// O aproximado gasta 29% a mais
```

O aproximado errou por 29%, longe do dobro permitido, e fez 64 passos contra
1351. O fluxograma é a decisão de um programa real: poucos pontos, exato;
muitos, aproximado e melhorado:

{{fluxograma}}

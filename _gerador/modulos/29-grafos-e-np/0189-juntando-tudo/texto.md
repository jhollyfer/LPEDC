## 0189 · Juntando tudo

O entregador da farmácia recebe sete endereços e quer a volta mais curta,
saindo da farmácia e voltando a ela. No pico da tarde, os endereços passam de
quarenta. Esse é o **problema do caixeiro viajante** (TSP, da sigla em
inglês), e ele reúne quase tudo o que o módulo apresentou: é um problema de
ciclo, é NP-difícil, tem solução aproximada com garantia e tem solução exata
por programação dinâmica.

Em termos de grafo, as cidades são vértices, toda dupla de cidades tem uma
aresta com um custo, e o TSP pede o **ciclo hamiltoniano** (0183) de custo
total mínimo. A versão de decisão pergunta se existe uma volta de custo no
máximo L, e ela é NP-completa (CORMEN et al., 2024, cap. 34). A prova é uma
redução (0187) a partir do próprio ciclo hamiltoniano. Dado um grafo G com V
vértices, monte um TSP nas mesmas cidades: as arestas que existem em G custam
1, e as que faltam custam 2. Uma volta de custo V só usa arestas de custo 1,
que são justamente as arestas de G, e por isso é um ciclo hamiltoniano de G.
Assim, G tem ciclo hamiltoniano se e só se o TSP tem volta de custo no máximo
V.

Quando as distâncias são **métricas**, isto é, obedecem à desigualdade
triangular (ir direto nunca é mais longo que dar a volta), vale o
2-aproximado do 0188: árvore geradora mínima, percurso em pré-ordem e volta
ao começo, com custo no máximo o dobro do ótimo (CORMEN et al., 2024, cap.
35). Distância em quarteirões, |dx| + |dy|, é métrica.

Para a resposta exata, o primeiro jeito é a força bruta. Como a volta é um
ciclo, fixe a farmácia como ponto de partida e teste as (n − 1)! ordens dos
outros pontos. Com 7 clientes são 5040 rotas, o que passa num piscar; com 15
pontos são 87 bilhões, e a força bruta já não serve.

O **algoritmo de Held-Karp** faz programação dinâmica sobre subconjuntos,
como a cadeia de matrizes (0185) fazia sobre intervalos. A observação central
é que, para continuar uma rota parcial da melhor forma, só importam duas
coisas: **quais** pontos já foram visitados e **em qual** deles a rota está
agora. A ordem em que os visitados foram percorridos não muda o que vem
depois. Então `dp[S][j]` guarda o menor custo de um caminho que sai da
farmácia (o ponto 0), passa exatamente pelos pontos do conjunto S e termina
em `j`, que pertence a S (HELD; KARP, 1962). A recorrência estende o caminho
um ponto por vez:

```text
dp[{0}][0] = 0
dp[S ∪ {k}][k] = min sobre j em S:  dp[S][j] + d[j][k]
resposta = min sobre j:  dp[todos][j] + d[j][0]
```

A segunda linha diz: para chegar a `k` tendo visitado S e mais `k`, o melhor
é vir de algum `j` de S, pelo melhor caminho até `j`, mais a distância de `j`
a `k`. A terceira fecha o ciclo voltando à farmácia. Há 2ⁿ conjuntos, n
pontos finais para cada um e n extensões possíveis: **O(n² · 2ⁿ)** de tempo e
**O(n · 2ⁿ)** de memória (HELD; KARP, 1962). Continua exponencial, mas bem
menos que n!. A tabela compara o número de passos:

| n | (n − 1)! rotas | n² · 2ⁿ (Held-Karp) | n² (aproximado) |
| --- | --- | --- | --- |
| 8 | 5 040 | 16 384 | 64 |
| 15 | 8,7 · 10¹⁰ | 7,4 · 10⁶ | 225 |
| 20 | 1,2 · 10¹⁷ | 4,2 · 10⁸ | 400 |
| 30 | 8,8 · 10³⁰ | 9,7 · 10¹¹ | 900 |

Na prática, até uns 20 pontos o Held-Karp resolve em segundos, e o limite é a
memória da tabela. Acima disso, o caminho é o aproximado, de preferência
seguido de uma melhoria local como o **2-opt**, que troca duas arestas da rota
quando a troca a encurta e repete enquanto houver ganho.

Em C, o conjunto S é uma máscara de bits, como no 0186: o bit `j` ligado quer
dizer que o ponto `j` está em S. As expressões `s >> j & 1` (o ponto `j` está
em S?) e `s | 1 << k` (S com `k` acrescentado) funcionam sem parênteses porque
os deslocamentos `>>` e `<<` têm precedência maior que `&` e `|` (0170).

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

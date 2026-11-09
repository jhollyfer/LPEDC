// 0188 · Aproximação
// Exercício E1127 · ★★★
//
// Complete a 2-aproximação do caixeiro viajante métrico para um passeio
// turístico com sete pontos (coordenadas em quarteirões). O programa já
// tem a matriz de distâncias, o Prim (vetor pai[]) e a força bruta.
// Faltam duas funções:
//
//   void preordem(int u): a rota é a pré-ordem da árvore (u primeiro,
//     depois os filhos de u em ordem de índice);
//   int custo(const int r[]): o tamanho da rota fechada.
//
//   Saída esperada:
//   Árvore mínima: 21 quarteirões
//   Rota aproximada: Base Feira Igreja Zoo Museu Teatro Praia Base = 34 quarteirões
//   Ótimo (força bruta): 30 quarteirões
//   Garantia: rota <= 2 x árvore = 42
//
// Dicas:
// 1. Os filhos de u são os v com pai[v] == u (e v != u). A recursão
//    preordem(v) cuida dos netos.
// 2. No custo, o último trecho é d[r[N - 1]][r[0]]: use (i + 1) % N.
// 3. Resposta esperada: a saída acima. 34 fica entre o ótimo (30) e a
//    garantia (42): 13% acima do ótimo.
//
// Escreva sua resposta abaixo (complete as duas funções):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 7

// pontos turísticos em quarteirões (x, y); distância = quarteirões andados
const char *pontos[N] = {"Base", "Feira", "Igreja", "Museu", "Praia", "Teatro", "Zoo"};
const int px[N] = {0, 3, 6, 6, 2, 8, 4};
const int py[N] = {0, 1, 0, 4, 5, 3, 3};
int d[N][N];
int pai[N];           // pai na árvore geradora mínima
int rota[N], tam_rota = 0;

// FALTA: põe u em rota[tam_rota++] e depois visita os filhos de u na árvore
void preordem(int u) {
    (void)u; // apague esta linha ao escrever a função
}

// FALTA: soma as distâncias da rota r, incluindo a volta do último ao primeiro
int custo(const int r[]) {
    (void)r; // apague esta linha ao escrever a função
    return 0;
}

int melhor = 1 << 30, atual[N];
bool usado[N];

void forca_bruta(int pos, int acum) { // todas as rotas que começam na Loja
    if (acum >= melhor) return;
    if (pos == N) {
        if (acum + d[atual[N - 1]][0] < melhor) melhor = acum + d[atual[N - 1]][0];
        return;
    }
    for (int v = 1; v < N; v++) {
        if (usado[v]) continue;
        usado[v] = true;
        atual[pos] = v;
        forca_bruta(pos + 1, acum + d[atual[pos - 1]][v]);
        usado[v] = false;
    }
}

int main(void) {
    for (int a = 0; a < N; a++)
        for (int b = 0; b < N; b++) d[a][b] = abs(px[a] - px[b]) + abs(py[a] - py[b]);

    // Prim O(N²) a partir da Loja
    int chave[N];
    bool na_arvore[N] = {false};
    for (int v = 0; v < N; v++) chave[v] = 1 << 30, pai[v] = -1;
    chave[0] = 0;
    int peso_arvore = 0;
    for (int k = 0; k < N; k++) {
        int u = -1;
        for (int v = 0; v < N; v++)
            if (!na_arvore[v] && (u == -1 || chave[v] < chave[u])) u = v;
        na_arvore[u] = true;
        peso_arvore += chave[u];
        for (int v = 0; v < N; v++)
            if (!na_arvore[v] && d[u][v] < chave[v]) chave[v] = d[u][v], pai[v] = u;
    }

    preordem(0);
    printf("Árvore mínima: %d quarteirões\nRota aproximada:", peso_arvore);
    for (int i = 0; i < N; i++) printf(" %s", pontos[rota[i]]);
    printf(" %s = %d quarteirões\n", pontos[0], custo(rota));

    atual[0] = 0;
    usado[0] = true;
    forca_bruta(1, 0);
    printf("Ótimo (força bruta): %d quarteirões\n", melhor);
    printf("Garantia: rota <= 2 x árvore = %d\n", 2 * peso_arvore);
    return 0;
}

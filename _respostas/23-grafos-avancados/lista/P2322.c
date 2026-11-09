// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2322 · ★★★ · Arbitragem na casa de câmbio

#include <math.h>
#include <stdio.h>

#define M 5
#define E 20

typedef struct {
    int de, para;
    double taxa;
} Troca;

const char *moedas[M] = {"Real", "Dólar", "Euro", "Libra", "Peso"};

void analisa(const char *rotulo, const Troca t[], int n) {
    double dist[M];
    int ant[M];
    for (int v = 0; v < M; v++) {
        dist[v] = 0; // uma origem imaginária ligada a todas com peso 0
        ant[v] = -1;
    }
    int x = -1;
    for (int r = 1; r <= M; r++) { // a M-ésima rodada é a extra
        x = -1;
        for (int i = 0; i < n; i++) {
            double w = -log(t[i].taxa);
            if (dist[t[i].de] + w < dist[t[i].para] - 1e-12) {
                dist[t[i].para] = dist[t[i].de] + w;
                ant[t[i].para] = t[i].de;
                x = t[i].para;
            }
        }
        if (x == -1) break;
    }
    if (x == -1) {
        printf("%s: sem arbitragem\n", rotulo);
        return;
    }
    for (int k = 0; k < M; k++) x = ant[x]; // anda M passos: cai dentro do ciclo
    int ciclo[M + 1], n_ciclo = 0;
    int y = x;
    do {
        ciclo[n_ciclo++] = y;
        y = ant[y];
    } while (y != x);

    printf("%s: arbitragem", rotulo);
    double fator = 1;
    printf(" %s", moedas[x]);
    for (int k = n_ciclo - 1; k >= 0; k--) { // ant[] aponta para trás: inverte
        int de = ciclo[(k + 1) % n_ciclo], para = ciclo[k];
        for (int i = 0; i < n; i++)
            if (t[i].de == de && t[i].para == para) fator *= t[i].taxa;
        printf(" -> %s", moedas[para]);
    }
    printf("\n  fator do ciclo: %.4f (lucro de %.2f%%)\n", fator, (fator - 1) * 100);
}

int main(void) {
    Troca t[E] = {{0, 1, 0.20}, {1, 0, 4.95}, {0, 2, 0.18}, {2, 0, 5.50}, {0, 3, 0.155}, {3, 0, 6.30},
                  {1, 2, 0.92}, {2, 1, 1.07}, {1, 3, 0.78}, {3, 1, 1.26}, {2, 3, 0.85}, {3, 2, 1.16},
                  {0, 4, 210.0}, {4, 0, 0.0046}, {1, 4, 1000.0}, {4, 1, 0.00090}, {2, 4, 1080.0},
                  {4, 2, 0.00084}, {3, 4, 1260.0}, {4, 3, 0.00072}};
    analisa("Segunda-feira", t, E);

    t[3].taxa = 5.40; // a casa corrigiu Euro -> Real
    analisa("Terça-feira", t, E);
    return 0;
}

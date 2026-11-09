// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2026 · ★★★ · Comprar barato, vender caro

#include <stdio.h>

#define N 12

typedef struct {
    int lucro, compra, venda;
    int menor, dia_menor, maior, dia_maior;
} Res;

Res melhor(const int v[], int ini, int fim) {
    if (ini == fim) {
        Res r = {0, ini, ini, v[ini], ini, v[ini], ini};
        return r;
    }
    int meio = ini + (fim - ini) / 2;
    Res e = melhor(v, ini, meio);
    Res d = melhor(v, meio + 1, fim);
    Res r = e.lucro >= d.lucro ? e : d;
    int cruza = d.maior - e.menor;
    if (cruza > r.lucro) {
        r.lucro = cruza;
        r.compra = e.dia_menor;
        r.venda = d.dia_maior;
    }
    if (e.menor <= d.menor) {
        r.menor = e.menor;
        r.dia_menor = e.dia_menor;
    } else {
        r.menor = d.menor;
        r.dia_menor = d.dia_menor;
    }
    if (e.maior >= d.maior) {
        r.maior = e.maior;
        r.dia_maior = e.dia_maior;
    } else {
        r.maior = d.maior;
        r.dia_maior = d.dia_maior;
    }
    return r;
}

int main(void) {
    const int p[N] = {31, 27, 34, 22, 25, 41, 36, 19, 24, 33, 38, 29};
    Res r = melhor(p, 0, N - 1);
    printf("Compra no dia %d (R$ %d), vende no dia %d (R$ %d)\n", r.compra, p[r.compra], r.venda, p[r.venda]);
    printf("Lucro: R$ %d\n", r.lucro);
    int bruta = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (p[j] - p[i] > bruta) {
                bruta = p[j] - p[i];
            }
        }
    }
    printf("Força bruta: R$ %d\n", bruta);
    return 0;
}

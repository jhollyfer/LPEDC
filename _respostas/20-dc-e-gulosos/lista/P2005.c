// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2005 · ★☆☆ · A melhor semana da lanchonete

#include <stdio.h>

#define N 10

typedef struct {
    int ini, fim, soma;
} Trecho;

Trecho cruza(const int v[], int ini, int meio, int fim) {
    Trecho t;
    int soma = 0, melhor = v[meio] - 1;
    for (int i = meio; i >= ini; i--) {
        soma += v[i];
        if (soma > melhor) {
            melhor = soma;
            t.ini = i;
        }
    }
    int esq = melhor;
    soma = 0;
    melhor = v[meio + 1] - 1;
    for (int j = meio + 1; j <= fim; j++) {
        soma += v[j];
        if (soma > melhor) {
            melhor = soma;
            t.fim = j;
        }
    }
    t.soma = esq + melhor;
    return t;
}

Trecho maximo(const int v[], int ini, int fim) {
    if (ini == fim) {
        Trecho t = {ini, ini, v[ini]};
        return t;
    }
    int meio = ini + (fim - ini) / 2;
    Trecho e = maximo(v, ini, meio);
    Trecho d = maximo(v, meio + 1, fim);
    Trecho c = cruza(v, ini, meio, fim);
    if (e.soma >= d.soma && e.soma >= c.soma) {
        return e;
    }
    if (d.soma >= c.soma) {
        return d;
    }
    return c;
}

int main(void) {
    const int lucro[N] = {-40, 120, -30, 80, -150, 60, 90, -20, 70, -60};
    Trecho t = maximo(lucro, 0, N - 1);
    printf("Melhor trecho: dias %d a %d\n", t.ini, t.fim);
    printf("Lucro: R$ %d\n", t.soma);
    return 0;
}

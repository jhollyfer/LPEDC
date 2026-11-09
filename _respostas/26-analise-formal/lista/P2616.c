// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2616 · ★★☆ · A pilha do quick sort azarado

#include <stdio.h>

unsigned semente = 42;
int prof = 0;
int prof_max = 0;

int sorteia(int limite) {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente / 65536u) % (unsigned)limite);
}

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void quick(int v[], int ini, int fim) {
    prof++;
    if (prof > prof_max) {
        prof_max = prof;
    }
    if (ini < fim) {
        int pivo = v[fim], i = ini;
        for (int j = ini; j < fim; j++) {
            if (v[j] < pivo) {
                troca(&v[i], &v[j]);
                i++;
            }
        }
        troca(&v[i], &v[fim]);
        quick(v, ini, i - 1);
        quick(v, i + 1, fim);
    }
    prof--;
}

int main(void) {
    int v[1000];
    const char *nome[3] = {"crescente", "decrescente", "embaralhado"};
    for (int caso = 0; caso < 3; caso++) {
        for (int i = 0; i < 1000; i++) {
            v[i] = caso == 0 ? i : caso == 1 ? 1000 - i : sorteia(100000);
        }
        prof_max = 0;
        quick(v, 0, 999);
        printf("%-11s: profundidade %d\n", nome[caso], prof_max);
    }
    return 0;
}

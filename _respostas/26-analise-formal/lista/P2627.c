// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2627 · ★★★ · Selection contra insertion

#include <stdio.h>

#define N 1000

unsigned semente = 2026;
long comps, movs;

int sorteia(int limite) {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente / 65536u) % (unsigned)limite);
}

void selecao(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            comps++;
            if (v[j] < v[m]) {
                m = j;
            }
        }
        if (m != i) {
            int t = v[i];
            v[i] = v[m];
            v[m] = t;
            movs++;
        }
    }
}

void insercao(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int x = v[i];
        int j = i - 1;
        while (j >= 0) {
            comps++;
            if (v[j] <= x) {
                break;
            }
            v[j + 1] = v[j];
            movs++;
            j--;
        }
        v[j + 1] = x;
        movs++;
    }
}

int main(void) {
    static int base[N], v[N];
    const char *nome[3] = {"ordenada", "invertida", "embaralhada"};
    printf("entrada       selection: comps   movs | insertion: comps   movs\n");
    for (int caso = 0; caso < 3; caso++) {
        for (int i = 0; i < N; i++) {
            base[i] = caso == 0 ? i : caso == 1 ? N - i : sorteia(10001);
        }
        long r[4];
        for (int alg = 0; alg < 2; alg++) {
            for (int i = 0; i < N; i++) {
                v[i] = base[i];
            }
            comps = movs = 0;
            if (alg == 0) {
                selecao(v, N);
            } else {
                insercao(v, N);
            }
            r[2 * alg] = comps;
            r[2 * alg + 1] = movs;
        }
        printf("%-11s %17ld %6ld | %16ld %6ld\n", nome[caso], r[0], r[1], r[2], r[3]);
    }
    return 0;
}

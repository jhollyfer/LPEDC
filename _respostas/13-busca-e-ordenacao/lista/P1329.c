// Lista · Módulo 13 · Busca e ordenação
// Exercício P1329 · ★★★ · Que algoritmo deixou o vetor assim?

#include <stdio.h>
#include <stdbool.h>

#define N 7
#define MAX_PASSOS N

// estados[k] guarda o vetor depois do passo k + 1
int bubble(const int orig[], int estados[][N]) {
    int v[N], passos = 0;
    for (int i = 0; i < N; i++) {
        v[i] = orig[i];
    }
    for (int p = 1; p < N; p++) {
        for (int j = 0; j < N - p; j++) {
            if (v[j] > v[j + 1]) {
                int t = v[j];
                v[j] = v[j + 1];
                v[j + 1] = t;
            }
        }
        for (int i = 0; i < N; i++) {
            estados[passos][i] = v[i];
        }
        passos++;
    }
    return passos;
}

int selection(const int orig[], int estados[][N]) {
    int v[N], passos = 0;
    for (int i = 0; i < N; i++) {
        v[i] = orig[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < N; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        int t = v[i];
        v[i] = v[menor];
        v[menor] = t;
        for (int k = 0; k < N; k++) {
            estados[passos][k] = v[k];
        }
        passos++;
    }
    return passos;
}

int insertion(const int orig[], int estados[][N]) {
    int v[N], passos = 0;
    for (int i = 0; i < N; i++) {
        v[i] = orig[i];
    }
    for (int j = 1; j < N; j++) {
        int x = v[j], i = j - 1;
        while (i >= 0 && v[i] > x) {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = x;
        for (int k = 0; k < N; k++) {
            estados[passos][k] = v[k];
        }
        passos++;
    }
    return passos;
}

bool iguais(const int a[], const int b[]) {
    for (int i = 0; i < N; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int orig[N] = {31, 8, 22, 15, 4, 27, 12};
    int pistas[][N] = {
        {4, 8, 12, 15, 31, 27, 22},
        {8, 15, 22, 31, 4, 27, 12},
        {8, 15, 4, 22, 12, 27, 31},
        {8, 22, 4, 15, 27, 31, 12},
    };
    int (*algoritmos[])(const int[], int[][N]) = {bubble, selection, insertion};
    const char *nomes[] = {"bubble", "selection", "insertion"};

    for (int p = 0; p < 4; p++) {
        printf("pista %d:", p + 1);
        bool achou = false;
        for (int a = 0; a < 3; a++) {
            int estados[MAX_PASSOS][N];
            int passos = algoritmos[a](orig, estados);
            for (int k = 0; k < passos; k++) {
                if (iguais(estados[k], pistas[p])) {
                    printf(" %s após o passo %d", nomes[a], k + 1);
                    achou = true;
                    break;
                }
            }
        }
        printf("%s\n", achou ? "" : " nenhum dos três");
    }
    return 0;
}

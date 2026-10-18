// 0122 · Bucket sort
// Exercício E732 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

typedef struct {
    bool usado;
    int menor, maior;
} Balde;

int compara(const void *a, const void *b) {
    int x = *(const int *) a, y = *(const int *) b;
    return (x > y) - (x < y);
}

void hora(int minutos, char s[]) {
    sprintf(s, "%02d:%02d", minutos / 60, minutos % 60);
}

int main(void) {
    // partidas do ônibus, em minutos desde a meia-noite (fora de ordem)
    int partidas[N] = {345, 1210, 480, 615, 390, 905, 1300, 760, 1050, 530};

    int menor = partidas[0], maior = partidas[0];
    for (int i = 1; i < N; i++) {
        if (partidas[i] < menor) {
            menor = partidas[i];
        }
        if (partidas[i] > maior) {
            maior = partidas[i];
        }
    }
    // N - 1 intervalos somam maior - menor: o maior deles é pelo menos a
    // média. Com baldes dessa largura, o maior intervalo nunca fica dentro
    // de um balde: está sempre entre o maior de um e o menor do seguinte
    int largura = (maior - menor + N - 2) / (N - 1); // arredonda para cima
    Balde baldes[N] = {{false, 0, 0}};
    for (int i = 0; i < N; i++) {
        int b = (partidas[i] - menor) / largura;
        if (!baldes[b].usado) {
            baldes[b].usado = true;
            baldes[b].menor = baldes[b].maior = partidas[i];
        } else {
            if (partidas[i] < baldes[b].menor) {
                baldes[b].menor = partidas[i];
            }
            if (partidas[i] > baldes[b].maior) {
                baldes[b].maior = partidas[i];
            }
        }
    }
    int melhor = 0, de = 0, ate = 0;
    int anterior = baldes[0].maior; // o balde 0 sempre tem o menor
    for (int b = 1; b < N; b++) {
        if (!baldes[b].usado) {
            continue;
        }
        if (baldes[b].menor - anterior > melhor) {
            melhor = baldes[b].menor - anterior;
            de = anterior;
            ate = baldes[b].menor;
        }
        anterior = baldes[b].maior;
    }
    char h1[6], h2[6];
    hora(de, h1);
    hora(ate, h2);
    printf("maior intervalo: %d min, entre %s e %s\n", melhor, h1, h2);

    // conferência: ordena (O(n log n)) e olha vizinhos
    qsort(partidas, N, sizeof(int), compara);
    int confere = 0;
    for (int i = 1; i < N; i++) {
        if (partidas[i] - partidas[i - 1] > confere) {
            confere = partidas[i] - partidas[i - 1];
        }
    }
    printf("conferindo com qsort: %d min\n", confere);
    return 0;
}

// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1930 · ★★★ · Quantos caminhões?

#include <stdio.h>

#define N 9
#define CAP 10

const int carga[N] = {5, 4, 3, 3, 3, 3, 3, 3, 2};
int ocup[N], cam[N];
int melhor = N, melhor_cam[N];

int guloso(void) {
    int oc[N], abertos = 0;
    for (int i = 0; i < N; i++) {
        int j = 0;
        while (j < abertos && oc[j] + carga[i] > CAP) {
            j++;
        }
        if (j == abertos) {
            oc[abertos++] = 0;
        }
        oc[j] += carga[i];
    }
    return abertos;
}

void otimo(int i, int abertos) {
    if (abertos >= melhor) {
        return;
    }
    if (i == N) {
        melhor = abertos;
        for (int k = 0; k < N; k++) {
            melhor_cam[k] = cam[k];
        }
        return;
    }
    for (int j = 0; j < abertos; j++) {
        if (ocup[j] + carga[i] > CAP) {
            continue;
        }
        int igual = 0;
        for (int j2 = 0; j2 < j; j2++) {
            if (ocup[j2] == ocup[j]) {
                igual = 1;
            }
        }
        if (igual) {
            continue;
        }
        ocup[j] += carga[i];
        cam[i] = j;
        otimo(i + 1, abertos);
        ocup[j] -= carga[i];
    }
    ocup[abertos] = carga[i];
    cam[i] = abertos;
    otimo(i + 1, abertos + 1);
    ocup[abertos] = 0;
}

int main(void) {
    printf("Guloso: %d caminhões\n", guloso());
    otimo(0, 0);
    printf("Ótimo: %d caminhões\n", melhor);
    for (int j = 0; j < melhor; j++) {
        int soma = 0;
        printf("Caminhão %d:", j + 1);
        for (int i = 0; i < N; i++) {
            if (melhor_cam[i] == j) {
                printf(" %d", carga[i]);
                soma += carga[i];
            }
        }
        printf(" (%d t)\n", soma);
    }
    return 0;
}

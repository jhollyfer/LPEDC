// 0096 · Bubble sort
// Exercício E575 · ★★★

#include <stdio.h>
#include <stdbool.h>

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int bubble(int v[], int n, int *comparacoes) {
    int passadas = 0;
    *comparacoes = 0;
    bool trocou = true;
    for (int p = 1; p < n && trocou; p++) {
        trocou = false;
        passadas++;
        for (int j = 0; j < n - p; j++) {
            (*comparacoes)++;
            if (v[j] > v[j + 1]) {
                troca(&v[j], &v[j + 1]);
                trocou = true;
            }
        }
    }
    return passadas;
}

// coqueteleira: ida leva o maior para o fim, volta traz o menor para a frente
int shaker(int v[], int n, int *comparacoes) {
    int passadas = 0;
    int ini = 0, fim = n - 1;     // a parte ainda bagunçada é v[ini..fim]
    *comparacoes = 0;
    bool trocou = true;
    while (trocou && ini < fim) {
        trocou = false;
        passadas++;                               // ida
        for (int j = ini; j < fim; j++) {
            (*comparacoes)++;
            if (v[j] > v[j + 1]) {
                troca(&v[j], &v[j + 1]);
                trocou = true;
            }
        }
        fim--;                                    // o maior foi para v[fim]
        if (!trocou) {
            break;
        }
        trocou = false;
        passadas++;                               // volta
        for (int j = fim; j > ini; j--) {
            (*comparacoes)++;
            if (v[j - 1] > v[j]) {
                troca(&v[j - 1], &v[j]);
                trocou = true;
            }
        }
        ini++;                                    // o menor foi para v[ini]
    }
    return passadas;
}

int main(void) {
    int a[] = {2, 3, 4, 5, 6, 7, 8, 1};
    int b[] = {2, 3, 4, 5, 6, 7, 8, 1};
    int ca, cb;

    int pa = bubble(a, 8, &ca);
    int pb = shaker(b, 8, &cb);
    printf("bubble: %d passadas, %d comparações\n", pa, ca);
    printf("shaker: %d passadas, %d comparações\n", pb, cb);
    printf("resultado:");
    for (int i = 0; i < 8; i++) {
        printf(" %d", b[i]);
    }
    printf("\n");
    return 0;
}

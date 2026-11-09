// Lista · Módulo 13 · Busca e ordenação
// Exercício P1313 · ★★☆ · O bubble no melhor e no pior dia

#include <stdio.h>
#include <stdbool.h>

void bubble(int v[], int n, int *comp, int *trocas, int *passadas) {
    *comp = *trocas = *passadas = 0;
    for (int p = 1; p < n; p++) {
        bool trocou = false;
        (*passadas)++;
        for (int j = 0; j < n - p; j++) {
            (*comp)++;
            if (v[j] > v[j + 1]) {
                int t = v[j];
                v[j] = v[j + 1];
                v[j + 1] = t;
                (*trocas)++;
                trocou = true;
            }
        }
        if (!trocou) {
            break;
        }
    }
}

void testa(const char *nome, int v[], int n) {
    int c, t, p;
    bubble(v, n, &c, &t, &p);
    printf("%-10s passadas %d, comparações %2d, trocas %2d\n", nome, p, c, t);
}

int main(void) {
    int crescente[] = {1, 2, 3, 4, 5, 6};
    int invertido[] = {6, 5, 4, 3, 2, 1};
    int misturado[] = {4, 1, 6, 2, 5, 3};

    testa("crescente", crescente, 6);
    testa("invertido", invertido, 6);
    testa("misturado", misturado, 6);
    return 0;
}

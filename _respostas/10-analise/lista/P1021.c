// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1021 · ★★★ · A melhor sequência de dias do food truck

#include <stdio.h>

int cubica(const int v[], int n, int *ini, int *fim, long *somas) {
    int melhor = v[0];
    *ini = *fim = 0;
    *somas = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int s = 0;
            for (int k = i; k <= j; k++) {
                s += v[k];
                (*somas)++;
            }
            if (s > melhor) {
                melhor = s;
                *ini = i;
                *fim = j;
            }
        }
    }
    return melhor;
}

int quadratica(const int v[], int n, int *ini, int *fim, long *somas) {
    int melhor = v[0];
    *ini = *fim = 0;
    *somas = 0;
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = i; j < n; j++) {
            s += v[j];
            (*somas)++;
            if (s > melhor) {
                melhor = s;
                *ini = i;
                *fim = j;
            }
        }
    }
    return melhor;
}

int linear(const int v[], int n, int *ini, int *fim, long *somas) {
    int melhor = v[0], atual = 0, comeco = 0;
    *ini = *fim = 0;
    *somas = 0;
    for (int j = 0; j < n; j++) {
        if (j == 0 || atual <= 0) {
            atual = v[j];
            comeco = j;
        } else {
            atual += v[j];
        }
        (*somas)++;
        if (atual > melhor) {
            melhor = atual;
            *ini = comeco;
            *fim = j;
        }
    }
    return melhor;
}

int main(void) {
    int lucro[10] = {-3, 5, -2, 8, -10, 4, 7, -1, -7, 3};
    int ini, fim;
    long somas;
    int s = cubica(lucro, 10, &ini, &fim, &somas);
    printf("Cúbica:     %d (dias %d a %d), %ld somas\n", s, ini + 1, fim + 1, somas);
    s = quadratica(lucro, 10, &ini, &fim, &somas);
    printf("Quadrática: %d (dias %d a %d), %ld somas\n", s, ini + 1, fim + 1, somas);
    s = linear(lucro, 10, &ini, &fim, &somas);
    printf("Linear:     %d (dias %d a %d), %ld somas\n", s, ini + 1, fim + 1, somas);
    return 0;
}

// 0168 · Complexidade espacial
// Exercício E1008 · ★★★

#include <stdio.h>
#include <stdlib.h>

long chamadas = 0;
int prof = 0;
int prof_max = 0;

// formas de subir n degraus de 1 em 1 ou de 2 em 2, recursão pura
long formas_rec(int n) {
    chamadas++;
    prof++;
    if (prof > prof_max) {
        prof_max = prof;
    }
    long r = (n <= 1) ? 1 : formas_rec(n - 1) + formas_rec(n - 2);
    prof--;
    return r;
}

// tabela de baixo para cima: Θ(n) de tempo, Θ(n) de espaço
long formas_tabela(int n, size_t *bytes) {
    long *t = malloc((n + 1) * sizeof(long));
    if (t == NULL) {
        *bytes = 0;
        return -1;
    }
    t[0] = 1;
    t[1] = 1;
    for (int i = 2; i <= n; i++) {
        t[i] = t[i - 1] + t[i - 2];
    }
    long r = t[n];
    free(t);
    *bytes = (n + 1) * sizeof(long);
    return r;
}

// só os dois últimos valores: Θ(n) de tempo, Θ(1) de espaço
long formas_duas(int n) {
    long anterior = 1, atual = 1;
    for (int i = 2; i <= n; i++) {
        long proximo = atual + anterior;
        anterior = atual;
        atual = proximo;
    }
    return atual;
}

int main(void) {
    int n = 30;
    long r1 = formas_rec(n);
    printf("recursão: %ld formas, %ld chamadas, %d frames na pilha\n", r1, chamadas, prof_max);
    size_t bytes;
    long r2 = formas_tabela(n, &bytes);
    printf("tabela:   %ld formas, %zu bytes na tabela\n", r2, bytes);
    printf("duas:     %ld formas, %zu bytes extras\n", formas_duas(n), 2 * sizeof(long));
    return 0;
}

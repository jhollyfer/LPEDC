// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1029 · ★★★ · O lado do terreno por busca binária

#include <assert.h>
#include <stdio.h>

long long raiz_linear(long long a, long *passos) {
    long long l = 0;
    *passos = 1;
    while ((l + 1) * (l + 1) <= a) {
        l++;
        (*passos)++;
    }
    return l;
}

long long raiz_binaria(long long a, long *passos) {
    long long lo = 0, hi = a + 1;
    *passos = 0;
    while (hi - lo > 1) {
        assert(lo * lo <= a && hi > a / hi); // lo² <= a < hi²
        (*passos)++;
        long long meio = lo + (hi - lo) / 2;
        if (meio <= a / meio) { // meio² <= a, sem estourar
            lo = meio;
        } else {
            hi = meio;
        }
    }
    return lo;
}

int main(void) {
    long long areas[3] = {50, 1000000, 2000000000LL};
    for (int i = 0; i < 3; i++) {
        long pl, pb;
        long long l1 = raiz_linear(areas[i], &pl);
        long long l2 = raiz_binaria(areas[i], &pb);
        if (l1 != l2) {
            printf("As duas discordam!\n");
        }
        printf("A = %lld: lado %lld | linear %ld passos | binária %ld passos\n", areas[i], l2, pl, pb);
    }
    return 0;
}

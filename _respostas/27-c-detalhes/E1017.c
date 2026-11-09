// 0170 · Precedência e ordem de avaliação
// Exercício E1017 · ★★☆

#include <stdio.h>

int pos_incremento(int *p) {
    int antigo = *p;
    *p = *p + 1;
    return antigo;
}

int pre_incremento(int *p) {
    *p = *p + 1;
    return *p;
}

int main(void) {
    int a = 5;
    int b = a++ * 2;
    int c = ++a * 2;
    printf("com ++:      a = %d, b = %d, c = %d\n", a, b, c);

    int a2 = 5;
    int b2 = pos_incremento(&a2) * 2;
    int c2 = pre_incremento(&a2) * 2;
    printf("com funcoes: a = %d, b = %d, c = %d\n", a2, b2, c2);
    return 0;
}

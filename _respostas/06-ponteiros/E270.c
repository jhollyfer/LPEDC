// 0045 · Ponteiros
// Exercício E270 · ★★★

#include <stdio.h>

int main(void) {
    double conta_a = -50.25, conta_b = 300.00, conta_c = 12.00;
    double *menor = &conta_a;
    double *negativa = NULL;

    if (conta_b < *menor) {
        menor = &conta_b;
    }
    if (conta_c < *menor) {
        menor = &conta_c;
    }
    if (*menor < 0) {
        negativa = menor;
    }

    if (negativa != NULL) {
        printf("Cobri R$ %.2f\n", -(*negativa));
        *negativa = 0;
    } else {
        printf("Nenhuma conta negativa\n");
    }
    printf("A: %.2f  B: %.2f  C: %.2f\n", conta_a, conta_b, conta_c);
    return 0;
}

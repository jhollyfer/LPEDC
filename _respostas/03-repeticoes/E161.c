// 0027 · For
// Exercício E161 · ★★★

#include <stdio.h>

int main(void) {
    int termos = 1000;
    double pi = 0.0;

    for (int k = 0; k < termos; k++) {
        double sinal = (k % 2 == 0) ? 4.0 : -4.0;
        pi = pi + sinal / (2 * k + 1);
    }
    printf("pi ~ %.6f\n", pi);
    return 0;
}

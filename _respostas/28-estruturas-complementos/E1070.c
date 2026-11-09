// 0179 · Sondagem quadrática e dupla
// Exercício E1070 · ★☆☆

#include <math.h>
#include <stdio.h>

double sem_sucesso(double a) {
    return 1 / (1 - a);
}

double com_sucesso(double a) {
    return (1 / a) * log(1 / (1 - a));
}

int main(void) {
    double cargas[] = {0.25, 0.5, 0.75, 0.9, 0.99};
    printf("carga | sem sucesso | com sucesso\n");
    for (int i = 0; i < 5; i++) {
        printf(" %.2f | %11.2f | %11.2f\n", cargas[i], sem_sucesso(cargas[i]), com_sucesso(cargas[i]));
    }
    return 0;
}

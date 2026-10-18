// 0010 · math.h
// Exercício E056 · ★☆☆
//
// Resposta: 3.00, 4.00, 3.00, -3.00, -4.00, -3.00, 7.25, 12.00, 1024.00,
// 3.00 e 1.00.

#include <stdio.h>
#include <math.h>

int main(void) {
    printf("%.2f %.2f %.2f %.2f\n", floor(3.7), ceil(3.2), round(2.5), round(-2.5));
    printf("%.2f %.2f %.2f %.2f\n", floor(-3.2), ceil(-3.7), fabs(-7.25), sqrt(144));
    printf("%.2f %.2f %.2f\n", pow(2, 10), pow(9, 0.5), fmod(10, 3));
    return 0;
}

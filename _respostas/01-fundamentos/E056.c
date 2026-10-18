// 0010 · math.h
// Exercício E056 · ★☆☆

#include <stdio.h>
#include <math.h>

int main(void) {
    printf("a) %.0f viagens\n", ceil(13.0 / 4));   // 3.25 sobe para 4
    printf("b) %.0f anos\n", floor(34.9));
    printf("c) nota %.0f\n", round(6.5));          // o meio vai para longe do zero
    printf("d) R$ %.2f\n", fabs(-42.75));
    printf("e) %.0f m\n", sqrt(144));
    printf("f) %.0f\n", pow(2, 10));
    printf("g) %.0f graus\n", floor(-3.2));        // descer na reta: -4
    return 0;
}

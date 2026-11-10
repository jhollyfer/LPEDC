// A031 · FizzBuzz e a ordem que importa

#include <stdio.h>

// Aqui as condições não são faixas: um número pode cumprir várias ao mesmo
// tempo. Como o else if para no primeiro Sim, a mais exigente vem primeiro.
int main(void) {
    int n = 15; // divisível por 3 e por 5

    printf("Ordem certa:  ");
    if (n % 3 == 0 && n % 5 == 0) {
        printf("FizzBuzz\n");
    } else if (n % 3 == 0) {
        printf("Fizz\n");
    } else if (n % 5 == 0) {
        printf("Buzz\n");
    } else {
        printf("%d\n", n);
    }

    printf("Ordem errada: ");
    if (n % 3 == 0) { // 15 já para aqui: o FizzBuzz nunca é testado
        printf("Fizz\n");
    } else if (n % 5 == 0) {
        printf("Buzz\n");
    } else if (n % 3 == 0 && n % 5 == 0) {
        printf("FizzBuzz\n");
    } else {
        printf("%d\n", n);
    }
    return 0;
}
// Saída:
// Ordem certa:  FizzBuzz
// Ordem errada: Fizz

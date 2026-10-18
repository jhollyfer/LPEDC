// 0034 · Parâmetros e passagem por valor
// Exercício E204 · ★★★

#include <stdbool.h>
#include <stdio.h>

int inverter(int n) {
    int invertido = 0;
    while (n > 0) {
        invertido = invertido * 10 + n % 10;
        n = n / 10;
    }
    return invertido;
}

bool eh_capicua(int n) {
    return inverter(n) == n;
}

int main(void) {
    int numero = 12345;
    int capicuas = 0;

    printf("inverter(%d) = %d\n", numero, inverter(numero));
    printf("No main, numero continua %d\n", numero);
    for (int n = 100; n <= 999; n++) {
        if (eh_capicua(n)) {
            capicuas++;
        }
    }
    printf("Capicuas de 100 a 999: %d\n", capicuas);
    return 0;
}

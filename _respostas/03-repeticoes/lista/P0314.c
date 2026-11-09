// Lista · Módulo 03 · Laços
// Exercício P0314 · ★★☆ · O próximo ano primo

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int ano = 2027;
    while (true) {
        bool primo = true;
        for (int d = 2; d * d <= ano; d++) {
            if (ano % d == 0) {
                primo = false;
                break;
            }
        }
        if (primo) {
            break;
        }
        ano++;
    }
    printf("Próximo ano primo: %d\n", ano);

    ano = 2025;
    while (true) {
        bool primo = true;
        for (int d = 2; d * d <= ano; d++) {
            if (ano % d == 0) {
                primo = false;
                break;
            }
        }
        if (primo) {
            break;
        }
        ano--;
    }
    printf("Último ano primo antes de 2026: %d\n", ano);
    return 0;
}

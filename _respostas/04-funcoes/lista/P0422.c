// Lista · Módulo 04 · Funções e modularização
// Exercício P0422 · ★★★ · De volta para a base 10

#include <stdio.h>

long long para_decimal(long long digitos, int base) {
    if (digitos == 0) {
        return 0;
    }
    int ultimo = (int)(digitos % 10);
    if (ultimo >= base) {
        return -1; // dígito que não existe nessa base
    }
    long long resto = para_decimal(digitos / 10, base);
    if (resto < 0) {
        return -1;
    }
    return resto * base + ultimo;
}

void mostrar(long long digitos, int base) {
    long long valor = para_decimal(digitos, base);
    if (valor < 0) {
        printf("%lld na base %d = inválido\n", digitos, base);
    } else {
        printf("%lld na base %d = %lld\n", digitos, base, valor);
    }
}

int main(void) {
    mostrar(11111101010LL, 2);
    mostrar(3752, 8);
    mostrar(2210001, 3);
    mostrar(1289, 8);
    return 0;
}

// 0036 · Juntando tudo: o caixa da lanchonete
// Exercício E215 · ★★★

#include <stdio.h>

char digito(int valor) {
    if (valor < 10) {
        return (char)('0' + valor);
    }
    return (char)('A' + (valor - 10));
}

void em_base(int n, int base) {
    if (n < base) {
        printf("%c", digito(n));
        return;
    }
    em_base(n / base, base);
    printf("%c", digito(n % base));
}

void mostrar(int n, int base) {
    printf("%d na base %d: ", n, base);
    if (base < 2 || base > 16) {
        printf("base inválida\n");
        return;
    }
    em_base(n, base);
    printf("\n");
}

int main(void) {
    mostrar(255, 16);
    mostrar(255, 2);
    mostrar(2026, 8);
    mostrar(2026, 16);
    mostrar(46655, 6);
    mostrar(10, 20);
    return 0;
}

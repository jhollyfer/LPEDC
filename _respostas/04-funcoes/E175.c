// 0030 · Escopo e tempo de vida
// Exercício E175 · ★☆☆

#include <stdio.h>

int pontos = 100; // global: o saldo do cartão

void extrato(void) {
    printf("extrato: %d\n", pontos); // só enxerga a global
}

void somar_na_global(int valor) {
    pontos += valor;
}

int main(void) {
    extrato();
    int pontos = 30; // local: esconde a global daqui para baixo
    printf("compra de hoje: %d\n", pontos);
    somar_na_global(pontos);
    extrato();
    printf("compra de hoje: %d\n", pontos);
    return 0;
}

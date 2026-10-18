// 0034 · Módulos: .h, .c e compilação separada
// Exercício E200 · ★☆☆
//
// Na pasta do assunto, o main abaixo usa o módulo com #include "conversao.h",
// e o rodar compila o conversao.c junto. Para esta resolução rodar sozinha
// aqui, as duas funções usadas do módulo estão copiadas logo abaixo.

#include <stdio.h>

// --- cópia do necessário de conversao.h + conversao.c ---
static int contador = 0;

double celsius_para_fahrenheit(double celsius) {
    contador++;
    return celsius * 9 / 5 + 32;
}

int conversoes_feitas(void) {
    return contador;
}
// --- fim da cópia ---

int main(void) {
    for (int c = 0; c <= 40; c += 10) {
        printf("%d °C = %.1f °F\n", c, celsius_para_fahrenheit(c));
    }
    printf("Conversões: %d\n", conversoes_feitas());
    return 0;
}

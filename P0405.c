// Lista · Módulo 04 · Funções e modularização
// Exercício P0405 · ★☆☆ · O protótipo esquecido
//
// O programa abaixo não compila, de propósito: o main chama area_terreno antes
// de o compilador saber que ela existe. Conserte sem mudar a ordem das funções,
// só acrescentando o protótipo no lugar certo. O terreno tem 12.5 m por 30 m:
//
//   Saída esperada:
//   Área do terreno: 375.0 m2
//
// Dicas:
// 1. O protótipo é a primeira linha da função terminada em ponto e vírgula.
// 2. Ele vai antes do main, depois dos #include.
// 3. Resposta esperada: Área do terreno: 375.0 m2.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    printf("Área do terreno: %.1f m2\n", area_terreno(12.5, 30.0));
    return 0;
}

double area_terreno(double frente, double fundo) {
    return frente * fundo;
}

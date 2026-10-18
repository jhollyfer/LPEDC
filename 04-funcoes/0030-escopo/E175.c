// 0030 · Escopo e tempo de vida
// Exercício E175 · ★☆☆
//
// O cartão fidelidade da farmácia tem 100 pontos guardados (uma global) e a
// compra de hoje vale 30 pontos (uma local do main com o MESMO nome). Escreva:
//
//   int pontos = 100;                 global: o saldo do cartão
//   void extrato(void)                mostra "extrato: <pontos>"
//   void somar_na_global(int valor)   soma valor nos pontos do cartão
//
// No main, chame extrato, declare "int pontos = 30;", mostre "compra de hoje",
// chame somar_na_global(pontos), chame extrato de novo e mostre a compra de
// hoje outra vez.
//
//   Saída esperada:
//   extrato: 100
//   compra de hoje: 30
//   extrato: 130
//   compra de hoje: 30
//
// Dicas:
// 1. Dentro de extrato e de somar_na_global só existe a global: as funções
//    não enxergam nada do main.
// 2. No main, depois de "int pontos = 30;", o nome pontos é a local: ela
//    esconde a global daí para baixo.
// 3. Resposta esperada: a saída acima. somar_na_global recebe uma cópia do 30
//    e soma na global; a local do main nem fica sabendo.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

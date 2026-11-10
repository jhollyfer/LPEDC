// Lista · Módulo 21 · Programação dinâmica
// Exercício P2111 · ★★☆ · Dois barcos com o mesmo peso
//
// Oito caixas de açaí vão descer o rio em dois barcos, e para a viagem ser
// segura os dois precisam levar EXATAMENTE o mesmo peso. As caixas pesam
// (kg): 12 7 9 15 6 11 8 4. Dá para dividir? Este é o problema da
// PARTIÇÃO: com total 72, basta achar um subconjunto que some 36. Escreva
// do zero a tabela booleana pode[i][s] ("com as i primeiras caixas, dá
// para somar s?") e, se der, reconstrua as caixas do primeiro barco.
//
//   Saída esperada:
//   Barco 1: 12 9 15 (36 kg)
//   Barco 2: 7 6 11 8 4 (36 kg)
//
// Dicas:
// 1. Total ímpar já responde "não dá". pode[0][0] = true; pode[i][s] =
//    pode[i - 1][s] || (s >= peso[i - 1] && pode[i - 1][s - peso[i - 1]]).
// 2. Reconstrução: de (8, 36) para trás; se pode[i - 1][s] já era true, a
//    caixa i - 1 não foi; senão, ela foi e s -= peso[i - 1].
// 3. Resposta esperada: dá. Barco 1 com 12 + 9 + 15 = 36 kg (a
//    reconstrução de trás para a frente acha esta) e o resto no barco 2.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}

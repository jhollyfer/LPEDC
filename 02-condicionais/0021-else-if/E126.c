// 0021 · else if, if aninhado e o else pendurado
// Exercício E126 · ★★★
//
// Imposto progressivo (tabela simplificada, inspirada no IR). Cada alíquota
// vale só para a PARTE do salário que cai na faixa:
//
//   até R$ 2000.00            isento
//   de 2000.01 a 3000.00      7.5%
//   de 3000.01 a 4500.00      15%
//   acima de 4500.00          22.5%
//
// Leia o salário e mostre o imposto. Com R$ 5000: os primeiros 2000 não
// pagam; os 1000 seguintes pagam 75.00; os 1500 seguintes pagam 225.00; os
// 500 que passam de 4500 pagam 112.50. Total: R$ 412.50.
//
//   Salário: 5000
//   Imposto: R$ 412.50
//
// Dicas:
// 1. Uma cadeia de else if escolhe a faixa mais alta que o salário alcança.
// 2. As faixas de baixo, quando cheias, valem um valor fixo: a faixa de 7.5%
//    cheia dá 75.00 e a de 15% cheia dá 225.00. Some só a parte da última.
// 3. Resposta esperada: 1800 → 0.00; 2500 → 37.50; 3500 → 150.00;
//    5000 → 412.50.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

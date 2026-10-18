// 0027 · For
// Exercício E161 · ★★★
//
// Dá para calcular pi com uma soma infinita (série de Leibniz):
//
//   pi = 4/1 - 4/3 + 4/5 - 4/7 + 4/9 - ...
//
// Escreva um programa que soma os primeiros 1000 termos e mostra o resultado
// com 6 casas. Depois troque para 10 e para 100000 termos e veja a
// aproximação melhorar (devagar).
//
//   Saída esperada (1000 termos):
//   pi ~ 3.140593
//
// Dicas:
// 1. O termo k (começando em 0) tem denominador 2 * k + 1.
// 2. O sinal alterna: k par soma, k ímpar subtrai. O ternário ajuda:
//    (k % 2 == 0) ? 4.0 : -4.0. Use 4.0, não 4: divisão inteira estraga tudo.
// 3. Resposta esperada: 1000 termos → 3.140593; 10 termos → 3.041840;
//    100000 termos → 3.141583.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

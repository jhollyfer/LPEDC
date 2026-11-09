// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1010 · ★☆☆ · Os apertos de mão da reunião
//
// Numa reunião de condomínio com n pessoas, cada uma aperta a mão de cada
// outra uma vez. Escreva long apertos_laco(int n), que conta os apertos com
// dois for aninhados (a pessoa i aperta a mão de cada j > i), e
// long apertos_formula(int n), que devolve n (n - 1) / 2. Mostre os dois
// para n = 5, 10, 50 e 1000, e diga se conferem.
//
//   Saída esperada:
//   n = 5: laço 10, fórmula 10, confere
//   n = 10: laço 45, fórmula 45, confere
//   n = 50: laço 1225, fórmula 1225, confere
//   n = 1000: laço 499500, fórmula 499500, confere
//
// Dicas:
// 1. for (i = 0; i < n; i++) for (j = i + 1; j < n; j++) cont++;
// 2. A pessoa 0 faz n - 1 apertos, a 1 faz n - 2, ..., a última faz 0:
//    (n - 1) + (n - 2) + ... + 0 = n (n - 1) / 2. É Θ(n²), e é o mesmo
//    número de comparações de quem testa "todo par" num vetor.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

// Lista · Módulo 04 · Funções e modularização
// Exercício P0419 · ★★☆ · O número da numerologia
//
// A numerologia soma os dígitos da data de nascimento até sobrar um dígito só:
// 27111990 → 30 → 3. Escreva "int soma_digitos(int n)", recursiva, e "int
// reduz(int n)", também recursiva, que mostra cada passo e devolve o dígito
// final: se n já tem um dígito, ele é a resposta; senão, reduz a soma dos
// dígitos. Teste com 27111990 e com 2026:
//
//   Saída esperada:
//   27111990 -> 30 -> 3
//   2026 -> 10 -> 1
//
// Dicas:
// 1. soma_digitos(n): se n < 10 devolve n; senão n % 10 + soma_digitos(n /
//    10).
// 2. reduz(n): mostra n; se n < 10, quebra a linha e devolve n; senão mostra
//    " -> " e devolve reduz(soma_digitos(n)).
// 3. Resposta esperada: 3 e 1.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

// Lista · Módulo 04 · Funções e modularização
// Exercício P0429 · ★★★ · Os números felizes
//
// Troque um número pela soma dos quadrados dos seus dígitos e repita: 2026 →
// 4 + 0 + 4 + 36 = 44 → 32 → 13 → 10 → 1. Quem chega em 1 é um número feliz.
// Quem não é feliz cai, mais cedo ou mais tarde, no ciclo que passa pelo 4 (4
// → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4). Escreva "int
// soma_quadrados(int n)", recursiva, e "bool feliz(int n)", também recursiva
// (sem laço). Mostre o caminho de 2026, os números felizes de 1 a 50 e quantos
// são:
//
//   Saída esperada:
//   2026 -> 44 -> 32 -> 13 -> 10 -> 1
//   Felizes até 50: 1 7 10 13 19 23 28 31 32 44 49
//   Total: 11
//
// Dicas:
// 1. soma_quadrados(0) = 0; senão (n % 10)² + soma_quadrados(n / 10).
// 2. feliz(n): se n == 1, true; se n == 4, false; senão feliz(soma_quadrados(n)).
// 3. Para o caminho, escreva "void caminho(int n)", que mostra n e, se não
//    for 1 nem 4, mostra " -> " e chama caminho(soma_quadrados(n)).
// 4. Resposta esperada: 11 números felizes até 50.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}

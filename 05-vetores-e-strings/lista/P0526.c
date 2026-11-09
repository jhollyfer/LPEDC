// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0526 · ★★★ · O cartão passa no teste de Luhn?
//
// Antes de mandar o pagamento para o banco, a loja confere se o número do
// cartão foi digitado direito com o algoritmo de Luhn:
// 1. Ande pelos dígitos da DIREITA para a esquerda.
// 2. Dobre um dígito sim, um não, começando pelo SEGUNDO da direita. Se o
//    dobro passar de 9, subtraia 9 (8 * 2 = 16 vira 7).
// 3. Some tudo. O número é válido se a soma for múltipla de 10.
//
// Escreva bool luhn(const char s[], int soma[1]), que ignora espaços (e recusa
// qualquer
// outro caractere que não seja dígito) e confira os quatro números abaixo,
// mostrando também a soma:
//
//   "4539 1488 0343 6467"
//   "4539 1488 0343 6468"
//   "79927398713"
//   "1234-5678"
//
//   Saída esperada:
//   4539 1488 0343 6467  soma  80 -> válido
//   4539 1488 0343 6468  soma  81 -> inválido
//   79927398713          soma  70 -> válido
//   1234-5678            soma  -1 -> inválido
//
// Dicas:
// 1. Comece em i = strlen(s) - 1 e desça até 0. Um contador de dígitos já
//    vistos (pos) diz se este é para dobrar: dobra quando pos é ímpar.
// 2. Guarde a soma em soma[0], para o main mostrar; ponha -1 lá quando
//    aparecer caractere inválido.
// 3. Espaço: continue. Não dígito e não espaço: return false.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {

    return 0;
}

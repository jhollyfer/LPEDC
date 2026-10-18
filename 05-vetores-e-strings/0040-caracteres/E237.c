// 0040 · Caracteres
// Exercício E237 · ★★☆
//
// A cifra de César troca cada letra pela que fica K posições depois no
// alfabeto, dando a volta no fim (com K = 3: A vira D, X vira A, Z vira C).
// O que não é letra fica como está.
//
// Cifre a mensagem abaixo com K = 3, mostre, depois decifre (ande 3 para
// trás) e mostre de novo:
//
//   char msg[] = {'Z', 'E', 'B', 'R', 'A', ' ', 'A', 'Z', 'U', 'L'};
//
//   Saída esperada:
//   Cifrada: CHEUD DCXO
//   Decifrada: ZEBRA AZUL
//
// Dicas:
// 1. Transforme a letra numa posição de 0 a 25: p = c - 'A'.
// 2. Ande e dê a volta com o resto: p = (p + K) % 26. Depois volte: c = 'A' + p.
// 3. Para decifrar, ande 26 - K para frente (é o mesmo que K para trás, sem
//    risco de resto negativo).
// 4. O vetor tem 10 itens e não é uma string: mostre com putchar num laço.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <ctype.h>

#define K 3

int main(void) {

    return 0;
}

// 0087 · Deque
// Exercício E518 · ★☆☆
//
// Num vetor circular de cap gavetas, escreva a função
// int volta(int i, int passos, int cap), que devolve a gaveta que fica
// passos casas ANTES de i, dando a volta quantas vezes for preciso. passos
// pode ser maior que cap. Antes, mostre com printf quanto o C calcula para
// -1 % 8 e -9 % 8 (e repare no sinal).
//
//   Saída esperada:
//   -1 % 8 = -1
//   -9 % 8 = -1
//   volta(0, 1, 8) = 7
//   volta(3, 5, 8) = 6
//   volta(2, 18, 8) = 0
//
// Dicas:
// 1. (i - passos) pode ser bem negativo. Primeiro reduza passos com
//    passos % cap, aí i - passos fica maior que -cap.
// 2. Depois some cap e tire o resto: (i - passos % cap + cap) % cap.
// 3. Para mostrar o %, escreva %% dentro do printf.
// 4. Resposta esperada: as cinco linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

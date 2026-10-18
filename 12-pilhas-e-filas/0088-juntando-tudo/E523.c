// 0088 · Juntando tudo: a calculadora de expressões
// Exercício E523 · ★☆☆
//
// Faça à mão a conversão de 2 * (3 + 4) com as regras do texto. Para cada
// símbolo, anote o que está na pilha de operadores e o que já está na fila
// de saída. Depois avalie a fila com a pilha de valores.
//
// Dicas:
// 1. Comece com a pilha e a fila vazias. O 2 vai direto para a fila.
// 2. O "(" sempre empilha; o "+" que vem depois não tira o "*" de lá,
//    porque o "(" está no meio.
// 3. Resposta esperada: depois do "4", a pilha é * ( + e a fila é 2 3 4.
//    O ")" manda o + para a fila e descarta o "(". No fim, o * sai. Pós-fixa:
//    2 3 4 + *. Avaliação: 2 | 2 3 | 2 3 4 | 2 7 | 14. Resultado: 14.
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>

int main(void) {

    return 0;
}

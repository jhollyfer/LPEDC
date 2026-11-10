// Lista · Módulo 12 · Pilhas e filas
// Exercício P1222 · ★★★ · Calcular a infixa direto, com duas pilhas
//
// Dá para avaliar uma expressão infixa SEM gerar a pós-fixa antes: o
// algoritmo das duas pilhas usa uma pilha de VALORES (int) e uma de
// OPERADORES (char). Escreva
//
//   int avalia(const char *s, int *resultado)
//
// para operandos de um dígito, + - * / e parênteses (sem espaços).
// Devolve 1 se deu certo ou 0 se faltou operando ou houve divisão por zero.
//
//   Saída esperada:
//   2+3*4 = 14
//   (2+3)*4 = 20
//   8-3-2 = 3
//   9/3/3 = 1
//   2*(3+4)-5 = 9
//   7/(2-2): erro
//
// Dicas:
// 1. Escreva aplica(): tira um operador da pilha de operadores, tira b e
//    depois a da pilha de valores (b sai primeiro: é o da direita) e empilha
//    a op b.
// 2. Dígito: empilha o valor. '(': empilha. ')': aplica até achar o '(' e
//    descarta o '('. Operador op: enquanto o topo for operador com
//    precedência >= à de op, aplica; depois empilha op.
// 3. No fim, aplique o que sobrou. Deu certo se a pilha de valores ficou
//    com um item só. O ">=" na dica 2 é o que faz 8-3-2 dar 3.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <ctype.h>
#include <stdio.h>

int main(void) {

    return 0;
}

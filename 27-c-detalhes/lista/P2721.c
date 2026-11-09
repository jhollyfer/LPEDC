// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2721 · ★★★ · Calculadora de notação polonesa reversa
//
// Na notação polonesa reversa, o operador vem depois dos operandos e não
// existe precedência nem parênteses: "3 4 + 2 *" é (3 + 4) * 2. Escreva
// int avaliar(const char *expr, int *resultado), que percorre a string com um
// ponteiro, empilha cada dígito (só operandos de 0 a 9) num vetor e, a cada
// operador (+ - * /), desempilha dois, faz a conta com um switch e empilha o
// resultado. Devolve 1 se deu certo e 0 se a expressão é inválida (faltou
// operando, divisão por zero ou sobrou mais de um número).
//
//   Saída esperada:
//   3 4 + 2 * = 14
//   5 1 2 + 4 * + 3 - = 14
//   9 2 3 * - = 3
//   4 + = expressão inválida
//   8 0 / = expressão inválida
//
// Dicas:
// 1. Pilha num vetor: int pilha[32]; int topo = 0; empilhar é
//    pilha[topo++] = x; desempilhar é pilha[--topo].
// 2. Cuidado com a ordem: o primeiro desempilhado é o operando da DIREITA.
//    Em "9 2 3 * -", a conta é 9 - 6.
// 3. Um dígito c vira número com c - '0'. Espaço, pule.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

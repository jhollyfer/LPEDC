// 0084 · Pilha na prática: parênteses e notação pós-fixa
// Exercício E502 · ★★☆
//
// Esta calculadora pós-fixa (operandos de um dígito) compila sem aviso e
// acerta a soma. Mas erra outras contas. Rode, compare com a saída esperada,
// ache o bug e conserte mexendo no mínimo de código.
//
//   Saída esperada depois do conserto:
//   2 3 + = 5
//   8 3 - = 5
//   8 4 / = 2
//   9 5 2 - * = 27
//
// Dicas:
// 1. Rode: a soma está certa, a subtração dá -5 e a divisão dá 0. O que a
//    soma tem que a subtração e a divisão não têm?
// 2. Qual operando sai primeiro da pilha: o da esquerda ou o da direita?
// 3. Resposta esperada: os dois pilha_desempilha estão na ordem errada. O
//    primeiro a sair é o operando da direita, então ele tem que ir para b.
//    Trocando a ordem (desempilha em b, depois em a), as quatro contas
//    ficam certas. A soma e a multiplicação escondiam o erro porque
//    a + b == b + a.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include "pilha.h"

int avalia(const char *expr) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return 0;
    }
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c >= '0' && c <= '9') {
            pilha_empilha(p, c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int a = 0, b = 0;
            pilha_desempilha(p, &a);
            pilha_desempilha(p, &b);
            int r = c == '+' ? a + b : c == '-' ? a - b : c == '*' ? a * b : a / b;
            pilha_empilha(p, r);
        }
    }
    int resultado = 0;
    pilha_desempilha(p, &resultado);
    pilha_libera(p);
    return resultado;
}

int main(void) {
    const char *contas[] = {"2 3 +", "8 3 -", "8 4 /", "9 5 2 - *"};
    for (int i = 0; i < 4; i++) {
        printf("%s = %d\n", contas[i], avalia(contas[i]));
    }
    return 0;
}

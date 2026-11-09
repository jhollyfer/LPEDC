// Lista · Módulo 14 · Árvores
// Exercício P1423 · ★★★ · A árvore da expressão
//
// A calculadora da escola recebe contas em notação posfixa (operandos de um
// dígito, separados por espaço) e monta a ÁRVORE DA EXPRESSÃO: as folhas
// são os números, cada nó interno é um operador com seus dois operandos como
// filhos. Escreva:
//
//   No *monta(const char *posfixa)   com uma pilha de árvores: dígito vira
//                                    folha empilhada; operador desempilha a
//                                    direita, depois a esquerda, e empilha o
//                                    nó novo
//   void infixa(const No *r)         em ordem, com parênteses em cada operador
//   void prefixa(const No *r)        pré-ordem
//   int avalia(const No *r)          pós-ordem: avalia os filhos, depois opera
//   int altura(const No *r)
//
// Rode com "3 4 + 2 *", "9 5 - 8 2 / *" e "6 2 3 * + 8 4 - /" e libere cada
// árvore.
//
//   Saída esperada:
//   posfixa: 3 4 + 2 *
//     infixa: ((3 + 4) * 2)
//     prefixa: * + 3 4 2
//     valor: 14, altura: 2
//   posfixa: 9 5 - 8 2 / *
//     infixa: ((9 - 5) * (8 / 2))
//     prefixa: * - 9 5 / 8 2
//     valor: 16, altura: 2
//   posfixa: 6 2 3 * + 8 4 - /
//     infixa: ((6 + (2 * 3)) / (8 - 4))
//     prefixa: / + 6 * 2 3 - 8 4
//     valor: 3, altura: 3
//
// Dicas:
// 1. Os três percursos da mesma árvore dão as três notações: pré = prefixa,
//    em = infixa, pós = posfixa (a própria entrada).
// 2. O primeiro desempilhado é o operando da DIREITA: em "8 4 -", o 4 sai
//    primeiro, e a conta é 8 - 4.
// 3. Na infixa, a folha é impressa sem parênteses.
// 4. Use isdigit((unsigned char)c) de <ctype.h>; a folha vale c - '0'.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct No {
    char c;
    struct No *esq, *dir;
} No;

int main(void) {

    return 0;
}

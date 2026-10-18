// 0009 · Constantes
// Exercício E051 · ★★☆
//
// Este programa não compila de propósito: tem TRÊS erros com constantes.
// Rode, leia as mensagens (repare em QUAL linha o gcc aponta) e conserte.
//
//   Saída esperada (depois de consertar):
//   Mensalidade: R$ 89.90
//   Desconto: R$ 10.00
//   Vencimento: dia 10
//
// Dicas:
// 1. O #define cola exatamente o texto que vem depois do nome, = e ;
//    inclusive. O gcc acusa a linha onde o nome é usado.
// 2. Uma variável const precisa receber o valor na declaração, não depois.
// 3. Resposta esperada: tire o ; de "#define MENSALIDADE 89.90;"; tire o =
//    de "#define DESCONTO = 10.00"; e escreva "const int dia = 10;" numa
//    linha só (const não aceita atribuição depois: "assignment of read-only
//    variable 'dia'").
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define MENSALIDADE 89.90;
#define DESCONTO = 10.00

int main(void) {
    const int dia;
    dia = 10;

    printf("Mensalidade: R$ %.2f\n", MENSALIDADE);
    printf("Desconto: R$ %.2f\n", DESCONTO);
    printf("Vencimento: dia %d\n", dia);
    return 0;
}

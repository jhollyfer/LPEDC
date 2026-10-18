// 0009 · Atribuição, ++ e --
// Exercício E053 · ★★★
//
// Este programa compila, mas o gcc mostra avisos. Pior: cada compilador
// pode mostrar uma saída diferente. Rode e leia os avisos. Depois conserte:
// reescreva as duas linhas marcadas para ficarem claras e previsíveis, com
// a intenção indicada em cada comentário, e rode de novo até não sobrar
// aviso.
//
//   Saída esperada (depois de consertar):
//   senha 1235
//   fila: atendendo 7, próximo 8
//
// Dicas:
// 1. Procure "may be undefined" nos avisos.
// 2. Alterar uma variável e usá-la de novo na mesma expressão não tem ordem
//    definida no C. Separe em linhas.
// 3. Resposta esperada: senha = senha++ e printf com fila++ e fila na mesma
//    chamada são comportamento indefinido (-Wsequence-point). Conserto:
//    senha++; numa linha só; e no printf, mostre fila e fila + 1 e só depois
//    faça fila++.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int senha = 1234;
    senha = senha++;  // intenção: somar 1 na senha
    printf("senha %d\n", senha);

    int fila = 7;
    // intenção: mostrar quem está sendo atendido e quem é o próximo
    printf("fila: atendendo %d, próximo %d\n", fila++, fila);
    return 0;
}

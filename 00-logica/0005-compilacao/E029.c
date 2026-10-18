// 0005 · Do .c ao executável
// Exercício E029 · ★★★
//
// Este programa compila, mas o rodar mostra um AVISO (warning). Rode, leia o
// aviso e responda: o que o compilador percebeu? O que este programa mostraria
// se o aviso fosse ignorado? Conserte para mostrar "Total: 10".
//
// Dicas:
// 1. Procure a palavra "uninitialized" no aviso.
// 2. Uma variável criada sem valor guarda o que já estava naquele pedaço de
//    memória: lixo.
// 3. Resposta esperada: "total" é usada sem nunca ter recebido valor
//    (-Wuninitialized). Sem conserto, mostraria um número imprevisível. A
//    correção é "int total = 0;".
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int total;
    total = total + 10;
    printf("Total: %d\n", total);
    return 0;
}

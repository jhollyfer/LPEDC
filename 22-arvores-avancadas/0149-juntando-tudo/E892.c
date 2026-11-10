// 0149 · Juntando tudo
// Exercício E892 · ★★☆
//
// O revisor quer um relatório: cada palavra fora do dicionário, em ordem
// alfabética, com quantas vezes ela apareceu no texto. Guarde as palavras
// desconhecidas numa BST de strings (assunto 0099) com um contador no nó:
// palavra repetida soma 1 em vezes. No fim, um percurso em ordem imprime o
// relatório e conta as palavras diferentes e as ocorrências.
//
//   Saída esperada:
//   cedo: 1
//   fiera: 2
//   mas: 1
//   pasou: 1
//   4 palavras diferentes, 5 ocorrências
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "corretor.h"

int main(void) {
    const char *texto = "hoje a fiera tem pao barato e cafe barato mas ontem a fiera "
                        "tinha pao caro e o onibus pasou cedo";
    (void)texto; // apague esta linha

    return 0;
}

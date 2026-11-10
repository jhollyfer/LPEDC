// 0096 · Comparando: estabilidade, custo e qsort
// Exercício E575 · ★★★
//
// Uma agenda de contatos:
//
//   typedef struct { char nome[16]; char telefone[16]; } Contato;
//
//   {"Rafael", "81 99876-1234"}, {"Carla", "11 98765-4321"},
//   {"Bruno", "21 97654-3210"}, {"Marina", "31 96543-2109"},
//   {"Diego", "85 95432-1098"}
//
// Ordene por nome com qsort e depois procure "Carla" e "Zeca" com bsearch:
//
//   void *bsearch(const void *chave, const void *base, size_t n,
//                 size_t tamanho, int (*compara)(const void *, const void *));
//
// Ela devolve o endereço do elemento achado ou NULL. Passe como chave a
// própria string (const char *), sem montar um Contato.
//
//   Saída esperada:
//   Carla: 11 98765-4321 (posição 1)
//   Zeca: não está na agenda
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}

// Lista · Módulo 07 · Memória dinâmica
// Exercício P0723 · ★★★ · Quebrar o texto em linhas
//
// O visor da máquina de cartão tem 16 colunas. Escreva
//
//   char **quebrar(const char *texto, int largura, int *n_linhas);
//
// que divide o texto em linhas de no máximo largura caracteres, quebrando
// nos espaços (uma palavra nunca é cortada, a não ser que sozinha passe da
// largura: aí ela é partida). Cada linha é uma string nova no heap, sem
// espaço no começo nem no fim, e o vetor de linhas cresce com realloc.
// Mostre as linhas entre barras, para ver o tamanho, e libere tudo:
//
//   const char *msg = "Pagamento aprovado no credito em 3x sem juros. "
//                     "Obrigado pela preferencia, volte sempre!";
//
//   Saída esperada:
//   |Pagamento       |  9
//   |aprovado no     | 11
//   |credito em 3x   | 13
//   |sem juros.      | 10
//   |Obrigado pela   | 13
//   |preferencia,    | 12
//   |volte sempre!   | 13
//   7 linhas
//
// Dicas:
// 1. Ande com um ponteiro p. Pule espaços. A partir de p, ache o fim da
//    linha: avance palavra por palavra enquanto couber (o tamanho conta os
//    espaços entre as palavras).
// 2. Se nem a primeira palavra cabe, corte em largura caracteres.
// 3. Para cada linha: malloc(tam + 1), memcpy e o '\0'. Para o vetor:
//    realloc a cada linha nova (ou dobrando, se preferir).
// 4. Para liberar: cada linha e, por fim, o vetor.
// 5. Resposta esperada: a saída acima (7 linhas).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *msg = "Pagamento aprovado no credito em 3x sem juros. "
                      "Obrigado pela preferencia, volte sempre!";
    (void) msg; // apague esta linha quando escrever

    return 0;
}

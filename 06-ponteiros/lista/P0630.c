// Lista · Módulo 06 · Ponteiros
// Exercício P0630 · ★★★ · O caça-palavras com ponteiros
//
// Um caça-palavras de 5 linhas e 6 colunas está no esqueleto, numa matriz
// char g[5][7] (cada linha tem 6 letras + '\0'). Escreva
//
//   bool achar(char g[5][7], const char *palavra, int *lin, int *col,
//              int *dir, const int *dl, const int *dc);
//
// que procura a palavra nas 8 direções a partir de cada casa e,
// se achar, entrega a casa inicial e o número da direção (0 a 7). Use os
// vetores dl e dc do esqueleto: andar na direção d é somar dl[d] à linha e
// dc[d] à coluna. Procure as cinco palavras do esqueleto:
//
//   Saída esperada:
//   BURITI linha 4, coluna 0, ->
//   ACAI   linha 0, coluna 3, <-
//   PEQUI  linha 0, coluna 5, desce
//   TUPI   linha 4, coluna 4, sobe <-
//   CUPU   não está na grade
//
// Dicas:
// 1. Quatro laços: linha, coluna, direção e, por fim, as letras da palavra.
//    Para a letra k: l = i + k * dl[d], c = j + k * dc[d].
// 2. Antes de ler g[l][c], confira se 0 <= l < 5 e 0 <= c < 6. Ler fora da
//    matriz é estouro (o AddressSanitizer acusa).
// 3. Ande pela palavra com um ponteiro: for (const char *p = palavra; *p;
//    p++, k++).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    char g[5][7] = {"IACAZP",
                    "CIMAXE",
                    "OLPAUQ",
                    "JANUEU",
                    "BURITI"};
    const char *palavras[5] = {"BURITI", "ACAI", "PEQUI", "TUPI", "CUPU"};
    int dl[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dc[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    const char *nomes[8] = {"->", "<-", "desce", "sobe", "desce ->", "desce <-",
                            "sobe ->", "sobe <-"};
    (void) g, (void) palavras, (void) dl, (void) dc, (void) nomes; // apague esta linha quando escrever

    return 0;
}

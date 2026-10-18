// 0042 · Lendo strings
// Exercício E252 · ★★★
//
// O programa abaixo lê com fgets num vetor de só 6 bytes, num laço, até a
// entrada acabar, e mostra cada pedaço lido entre colchetes. Preveja a saída
// EXATA (inclusive onde caem as quebras de linha) para esta entrada de duas
// linhas:
//
//   abacaxi
//   uva
//
// Depois rode com `printf 'abacaxi\nuva\n' | ~/LPEDC/rodar` seguido do caminho
// deste arquivo.
//
// Dicas:
// 1. Com 6 bytes, cada fgets lê no máximo 5 caracteres (sobra 1 para o '\0').
// 2. O fgets para no '\n' (e o guarda) ou quando enche, o que vier primeiro.
//    O que não coube fica para a próxima chamada.
// 3. Um '\n' guardado no pedaço quebra a linha ANTES do ']'.
// 4. Resposta esperada: os pedaços são "abaca", "xi\n" e "uva\n" (3
//    leituras). Na tela: a 1ª linha é [abaca][xi, a 2ª é ][uva, a 3ª é ] e
//    a última, "3 leituras". Uma linha longa chega em pedaços, e cada pedaço
//    parece uma linha nova se você não conferir o '\n'.
//
// Escreva sua resposta abaixo (o código está pronto para conferir):

#include <stdio.h>

int main(void) {
    char s[6];
    int leituras = 0;

    while (fgets(s, sizeof(s), stdin) != NULL) {
        printf("[%s]", s);
        leituras++;
    }
    printf("\n%d leituras\n", leituras);
    return 0;
}

// 0141 · Maior subsequência comum (LCS)
// Exercício E844 · ★★☆
//
// Charada de palavras: qual é a MENOR sequência de letras (não precisa
// existir no dicionário) que contém BANANA e também CABANA como
// subsequências? É a menor supersequência comum, e ela sai da tabela da
// LCS: as letras da LCS aparecem uma vez só, e todas as outras letras das
// duas palavras entram também. Por isso o tamanho é m + n - LCS.
//
// Monte a tabela da LCS, construa a supersequência numa volta pela tabela
// e confira o resultado com uma função
//
//   int eh_subsequencia(const char *p, const char *t)
//
// que diz se p é subsequência de t.
//
//   Saída esperada:
//   LCS: 4 letras
//   Supersequência: CABANANA (8 letras)
//   BANANA está nela? sim
//   CABANA está nela? sim
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}

// 0046 · Strings
// Exercício E276 · ★★★
//
// Uma biblioteca quer padronizar os títulos dos livros: a primeira letra de
// cada palavra em maiúscula e as outras em minúscula. Escreva
//
//   int capitalizar(char s[]);
//
// que altera a string no lugar e devolve quantas palavras ela tem. Palavras
// são separadas por um ou mais espaços (pode haver espaço no começo e no fim).
//
//   char titulo[] = "  o SENHOR   dos aneis ";
//
//   Saída esperada:
//   [  O Senhor   Dos Aneis ]
//   4 palavras
//
// Dicas:
// 1. Guarde num bool se o caractere anterior era espaço (comece com true:
//    antes do texto é como se houvesse um espaço).
// 2. Se o atual não é espaço e o anterior era: começou uma palavra. Conte e
//    use toupper. Se não é espaço e o anterior também não era: tolower.
// 3. Percorra até o '\0', não até sizeof.
// 4. Resposta esperada: a saída acima (os colchetes mostram que os espaços
//    das pontas continuam lá).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {

    return 0;
}

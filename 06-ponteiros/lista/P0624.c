// Lista · Módulo 06 · Ponteiros
// Exercício P0624 · ★★★ · Números romanos nos dois sentidos
//
// Os capítulos de um livro antigo vêm em algarismos romanos. Escreva:
//
//   int romano_para_int(const char *s);
//   void int_para_romano(int n, char *saida);
//
// A primeira anda com um ponteiro pela string: cada símbolo soma seu valor,
// mas se o próximo for MAIOR, ele subtrai (IV = 4, XC = 90). A segunda
// escreve o romano em saida, avançando um ponteiro de escrita. Converta os
// romanos "XIV", "XCIX", "MMXXVI" e "CDXLIV" para int, e 1987, 3999 e 49
// para romano:
//
//   Saída esperada:
//   XIV = 14
//   XCIX = 99
//   MMXXVI = 2026
//   CDXLIV = 444
//   1987 = MCMLXXXVII
//   3999 = MMMCMXCIX
//   49 = XLIX
//
// Dicas:
// 1. Uma função int valor(char c) com um switch (I 1, V 5, X 10, L 50,
//    C 100, D 500, M 1000).
// 2. Na leitura: se valor(*s) < valor(*(s + 1)), subtrai; senão, soma. No
//    último símbolo, *(s + 1) é o '\0', que vale 0: soma.
// 3. Na escrita, use duas tabelas em ordem decrescente, incluindo os pares
//    de subtração: 1000 M, 900 CM, 500 D, 400 CD, 100 C, 90 XC, 50 L,
//    40 XL, 10 X, 9 IX, 5 V, 4 IV, 1 I. Enquanto n >= valor, copie o símbolo
//    (andando com char *p) e tire o valor de n. Feche com *p = '\0'.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

// 0005 · printf
// Exercício E030 · ★★★
//
// Seis linhas, seis pegadinhas. Sem rodar, preveja a saída de cada uma e
// explique. Depois rode e confira.
//
//   printf("[%5.1f]\n", 3456.78);
//   printf("[%.3s]\n", "Brasília");
//   printf("[%.2f]\n", 2.675);
//   printf("[%e]\n", 123456.0);
//   printf("[%g] [%g]\n", 0.0001, 0.00001);
//   int n = printf("Pão\n");
//   printf("[%d]\n", n);
//
// Dicas:
// 1. A largura é mínima, nunca corta. A precisão de um %s corta.
// 2. 2.675 não existe exato em binário: o double guarda 2.67499999...
// 3. O %g escolhe o formato mais curto e passa para o científico quando o
//    número fica pequeno demais (expoente menor que -4).
// 4. O printf devolve quantos BYTES escreveu: o ã ocupa 2.
// 5. Resposta esperada: [3456.8]; [Bra]; [2.67] (e não 2.68); [1.234560e+05];
//    [0.0001] [1e-05]; "Pão" e depois [5] (P, ã com 2 bytes, o e o \n).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

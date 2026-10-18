// 0021 · Do-while
// Exercício E122 · ★☆☆
//
// Os trechos A e B abaixo já estão no main do arquivo e são quase iguais:
//
//   // trecho A                     // trecho B
//   int n = 10;                     int m = 10;
//   while (n < 5) {                 do {
//       printf("%d ", n);               printf("%d ", m);
//       n++;                            m++;
//   }                               } while (m < 5);
//   printf("| A terminou com n = %d\n", n);   (e o mesmo para m no B)
//
// Acrescente um trecho C, com a variável k começando em 10, que mostre
// exatamente o mesmo que o B, mas usando while (sem do-while). Rode e confira:
//
//   Saída esperada:
//   | A terminou com n = 10
//   10 | B terminou com m = 11
//   10 | C terminou com k = 11
//
// Dicas:
// 1. O while pergunta antes de entrar; o do-while entra e pergunta depois.
//    10 < 5 é falso logo na primeira pergunta.
// 2. Para o while rodar o corpo pelo menos uma vez, escreva uma cópia do
//    corpo ANTES do laço.
// 3. Resposta esperada: a saída acima. O trecho C fica: int k = 10;
//    printf("%d ", k); k++; while (k < 5) { printf("%d ", k); k++; } e o
//    printf final.
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdio.h>

int main(void) {
    // trecho A
    int n = 10;
    while (n < 5) {
        printf("%d ", n);
        n++;
    }
    printf("| A terminou com n = %d\n", n);

    // trecho B
    int m = 10;
    do {
        printf("%d ", m);
        m++;
    } while (m < 5);
    printf("| B terminou com m = %d\n", m);

    return 0;
}

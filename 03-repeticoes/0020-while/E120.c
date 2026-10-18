// 0020 · While
// Exercício E120 · ★★★
//
// Os três laços abaixo já estão no main do arquivo (cada um entre um printf
// com a letra do trecho e um printf("|\n")):
//
//   // trecho A               // trecho B             // trecho C
//   int i = 0;                int n = 100;            int k = 10;
//   while (i++ < 5) {         while (n > 1) {         while (k < 10) {
//       printf("%d ", i);         n = n / 3;              k++;
//   }                         }                       }
//
// Estenda o programa para ele contar e mostrar o que cada laço fez: crie um
// contador de voltas para cada trecho (voltas_a, voltas_b e voltas_c,
// começando em 0, somando 1 dentro do corpo) e, no fim de cada trecho, mostre
// o contador e o valor final da variável da pergunta. No trecho B, mostre
// também o valor de n depois de cada divisão. Rode e confira:
//
//   Saída esperada:
//   A: 1 2 3 4 5 | voltas 5, i final 6
//   B: 33 11 3 1 | voltas 4, n final 1
//   C: | voltas 0, k final 10
//
// Dicas:
// 1. Trecho A: i++ compara o valor ANTIGO e só depois soma 1 (assunto 0009).
//    Isso vale também na última pergunta, a que dá falso: por isso i termina
//    em 6, com 5 voltas.
// 2. Trecho B: divisão inteira. 100 / 3 = 33. O printf de n vai logo depois
//    da linha n = n / 3.
// 3. Resposta esperada: a saída acima. No trecho C o corpo roda zero vezes,
//    porque o while pergunta antes: 10 < 10 já é falso.
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdio.h>

int main(void) {
    // trecho A
    int i = 0;
    printf("A: ");
    while (i++ < 5) {
        printf("%d ", i);
    }
    printf("|\n");

    // trecho B
    int n = 100;
    printf("B: ");
    while (n > 1) {
        n = n / 3;
    }
    printf("|\n");

    // trecho C
    int k = 10;
    printf("C: ");
    while (k < 10) {
        k++;
    }
    printf("|\n");
    return 0;
}

// 0023 · Break e continue
// Exercício E134 · ★☆☆
//
// O laço abaixo já está no main do arquivo:
//
//   for (int i = 1; i <= 10; i++) {
//       if (i % 4 == 0) {
//           continue;
//       }
//       if (i == 7) {
//           break;
//       }
//       printf("%d ", i);
//   }
//   printf("\n");
//
// Estenda o programa:
//
// 1. acrescente um contador de quantas vezes o continue aconteceu e mostre-o
//    no fim da linha;
// 2. logo depois, escreva uma cópia do laço (com o seu contador) em que o
//    break testa i == 8 em vez de i == 7.
//
//   Saída esperada:
//   1 2 3 5 6 (continue: 1 vez)
//   1 2 3 5 6 7 9 10 (continue: 2 vezes)
//
// Dicas:
// 1. continue pula só esta volta; break acaba com o laço. O contador soma 1
//    logo antes do continue, dentro do mesmo if.
// 2. Na cópia, o 8 é múltiplo de 4: quem chega primeiro nele, o continue ou
//    o break?
// 3. Resposta esperada: a saída acima. Com i == 8, o break nunca acontece,
//    porque o continue pega o 8 antes; o laço vai até o 10 e pula o 4 e o 8.
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 10; i++) {
        if (i % 4 == 0) {
            continue;
        }
        if (i == 7) {
            break;
        }
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}

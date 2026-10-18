// 0022 · For
// Exercício E132 · ★★★
//
// Preveja a saída. Quantas linhas aparecem, e com que valores i e j terminam?
//
//   int i, j;
//   for (i = 0, j = 20; i < j; i += 3, j -= 2) {
//       printf("i = %2d, j = %2d\n", i, j);
//   }
//   printf("Fim: i = %d, j = %d\n", i, j);
//
// Depois reescreva o mesmo laço com while, sem mudar a saída.
//
// Dicas:
// 1. A vírgula separa duas inicializações e dois passos; a condição é uma só.
// 2. Monte a tabela: (0, 20), (3, 18)... até a pergunta i < j dar falso.
// 3. Resposta esperada: 4 linhas: (0, 20), (3, 18), (6, 16), (9, 14); depois
//    "Fim: i = 12, j = 12". Com while: "i = 0; j = 20; while (i < j) {
//    printf(...); i += 3; j -= 2; }".
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

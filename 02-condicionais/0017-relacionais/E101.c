// 0017 · Relacionais e a verdade em C
// Exercício E101 · ★★★
//
// Na matemática, 5 > 4 > 3 é verdade. No C, é outra conversa. Preveja o que
// cada linha mostra, explique por quê e só depois teste (o compilador vai
// avisar: leia o aviso, ele está certo).
//
//   printf("%d\n", 5 > 4 > 3);
//   printf("%d\n", 3 < 2 < 1);
//   printf("%d\n", 1 == 1 == 1);
//   printf("%d\n", 2 == 2 == 2);
//   printf("%d\n", -1 < 0 < 1);
//
// Dicas:
// 1. O C avalia da esquerda para a direita: 5 > 4 > 3 é (5 > 4) > 3.
// 2. A primeira comparação já virou 0 ou 1. A segunda compara esse número.
// 3. Resposta esperada: 0, 1, 1, 0, 0. Por exemplo, 2 == 2 == 2 vira
//    1 == 2, que é 0. Para "entre" de verdade, você vai precisar do &&
//    (assunto 0018).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

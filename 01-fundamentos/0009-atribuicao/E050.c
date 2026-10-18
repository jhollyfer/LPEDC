// 0009 · Atribuição, ++ e --
// Exercício E050 · ★☆☆
//
// Acrescente um printf depois de cada uma das três últimas linhas,
// mostrando a instrução, o valor de x e o valor da variável que acabou de
// ser criada, no formato abaixo. Antes de rodar, tente adivinhar cada
// número; depois confira com a saída.
//
//   Saída esperada:
//   y = x++ -> x = 6, y = 5
//   z = ++x -> x = 7, z = 7
//   w = x-- -> x = 6, w = 7
//
// Dicas:
// 1. x++ entrega o valor antigo e depois soma; ++x soma e entrega o novo.
// 2. O printf vai na linha de baixo, sozinho: printf("y = x++ -> x = %d,
//    y = %d\n", x, y);
// 3. Resposta esperada: as três linhas acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

int main(void) {
    int x = 5;
    int y = x++;
    int z = ++x;
    int w = x--;

    (void)y; (void)z; (void)w; // apague esta linha
    return 0;
}

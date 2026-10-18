// 0044 · Matrizes
// Exercício E264 · ★★★
//
// Campo minado! Num campo 4x5, 1 é bomba e 0 é livre:
//
//   0 1 0 0 0
//   0 0 0 1 0
//   1 1 0 0 0
//   0 0 0 0 1
//
// Mostre o campo "aberto": '*' onde há bomba e, nas outras casas, quantas
// bombas existem nas até 8 casas vizinhas (incluindo as diagonais).
//
//   Saída esperada:
//   1 * 2 1 1
//   3 3 3 * 1
//   * * 2 2 2
//   2 2 1 1 *
//
// Dicas:
// 1. Para cada casa (l, c), percorra as vizinhas com dois laços: i de l - 1 a
//    l + 1 e j de c - 1 a c + 1.
// 2. Na borda, algumas vizinhas não existem (l - 1 = -1, por exemplo). Pule
//    com um if: só conte se 0 <= i < 4 e 0 <= j < 5. Sem isso, você lê fora da
//    matriz, e o sanitizer avisa.
// 3. A própria casa entra nos dois laços; como ela não é bomba (senão você
//    nem estaria contando), não atrapalha.
// 4. Resposta esperada: a saída acima. Escreva uma função
//    int vizinhas(int campo[][COLUNAS], int l, int c) para deixar o main limpo.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define LINHAS 4
#define COLUNAS 5

int main(void) {

    return 0;
}

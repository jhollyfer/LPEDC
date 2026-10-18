// 0044 · Matrizes
// Exercício E260 · ★☆☆
//
// Sem rodar, preveja a saída. Depois rode e confira.
//
//   int a[2][3] = {{1}, {4, 5}};
//   int b[][2] = {{1, 2}, {3, 4}, {5}};
//
//   printf("%d %d %d\n", a[0][0], a[0][2], a[1][1]);
//   printf("%zu\n", sizeof(b) / sizeof(b[0]));
//   printf("%d %d\n", b[1][0], b[2][1]);
//   printf("%zu %zu\n", sizeof(a), sizeof(a[1]));
//
// Dicas:
// 1. Com chaves internas, cada chave é uma linha; o que falta vira 0.
// 2. Sem o tamanho da 1ª dimensão, o compilador conta as chaves internas.
// 3. sizeof(b[0]) é o tamanho de uma linha (2 int = 8 bytes).
// 4. Resposta esperada: "1 0 5", "3", "3 0" e "24 12".
//
// Escreva sua resposta abaixo (o código está pronto para conferir):

#include <stdio.h>

int main(void) {
    int a[2][3] = {{1}, {4, 5}};
    int b[][2] = {{1, 2}, {3, 4}, {5}};

    printf("%d %d %d\n", a[0][0], a[0][2], a[1][1]);
    printf("%zu\n", sizeof(b) / sizeof(b[0]));
    printf("%d %d\n", b[1][0], b[2][1]);
    printf("%zu %zu\n", sizeof(a), sizeof(a[1]));
    return 0;
}

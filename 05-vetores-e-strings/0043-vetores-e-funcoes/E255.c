// 0043 · Vetores e funções
// Exercício E255 · ★★☆
//
// Sem rodar, preveja as duas linhas que o programa abaixo mostra. Para cada
// parâmetro de mexer, pergunte: ele é uma cópia ou dá acesso ao original?
//
//   void mexer(int v[], int x) {
//       v[0] = v[0] * 10;
//       x = x * 10;
//       v[1] = x;
//   }
//
//   int a[3] = {1, 2, 3};
//   int b = 5;
//   mexer(a, b);
//   printf("%d %d %d %d\n", a[0], a[1], a[2], b);
//   mexer(a, a[2]);
//   printf("%d %d %d\n", a[0], a[1], a[2]);
//
// Dicas:
// 1. v recebe o endereço de a: v[0] e a[0] são a mesma gaveta.
// 2. x recebe uma cópia: mudar x não muda b, nem a[2].
// 3. Na segunda chamada, x começa com o valor de a[2] naquele momento.
// 4. Resposta esperada: "10 50 3 5" e "100 30 3".
//
// Escreva sua resposta abaixo (o código está pronto para você conferir):

#include <stdio.h>

void mexer(int v[], int x) {
    v[0] = v[0] * 10;
    x = x * 10;
    v[1] = x;
}

int main(void) {
    int a[3] = {1, 2, 3};
    int b = 5;

    mexer(a, b);
    printf("%d %d %d %d\n", a[0], a[1], a[2], b);
    mexer(a, a[2]);
    printf("%d %d %d\n", a[0], a[1], a[2]);
    return 0;
}

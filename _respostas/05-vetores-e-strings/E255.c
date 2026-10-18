// 0043 · Vetores e funções
// Exercício E255 · ★★☆
//
// Resposta: "10 50 3 5" e "100 30 3".
// 1ª chamada: v é o próprio a, então a[0] vira 10; x é cópia de b (5), vira
// 50 e vai para a[1]. b continua 5.
// 2ª chamada: x é cópia de a[2] (3). a[0] vira 100, x vira 30 e vai para a[1].
// a[2] continua 3.

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

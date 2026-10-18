// 0038 · Vetores e funções
// Exercício E225 · ★★☆

#include <stdio.h>

void mexer(int v[], int x) {
    v[0] = v[0] * 10;
    x = x * 10;
    v[1] = x;
    printf("dentro: v = %d %d %d, x = %d\n", v[0], v[1], v[2], x);
}

// recebe o vetor e a posição: mexe na gaveta de quem chamou
void vezes_dez(int v[], int pos) {
    v[pos] = v[pos] * 10;
}

int main(void) {
    int a[3] = {1, 2, 3};
    int b = 5;

    mexer(a, b); // x é cópia de b: b continua 5
    printf("fora: a = %d %d %d, b = %d\n", a[0], a[1], a[2], b);
    mexer(a, a[2]); // x é cópia de a[2]: a[2] continua 3
    printf("fora: a = %d %d %d\n", a[0], a[1], a[2]);

    vezes_dez(a, 2);
    printf("depois de vezes_dez: a = %d %d %d\n", a[0], a[1], a[2]);
    return 0;
}

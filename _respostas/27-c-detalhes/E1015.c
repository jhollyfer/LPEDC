// 0170 · Precedência e ordem de avaliação
// Exercício E1015 · ★☆☆

#include <stdio.h>

int main(void) {
    int n1 = 7, n2 = 8, n3 = 9;
    int media = (n1 + n2 + n3) / 3;
    printf("media = %d\n", media);

    int f = 104;
    int celsius = (f - 32) * 5 / 9;
    printf("celsius = %d\n", celsius);

    int largura = 4, altura = 3;
    int area = (largura + 2) * (altura + 2);
    printf("area = %d\n", area);
    return 0;
}

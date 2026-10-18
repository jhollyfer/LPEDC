// 0007 · Aritmética
// Exercício E042 · ★★★

#include <stdio.h>

int main(void) {
    int n;
    printf("Número: ");
    scanf("%d", &n);

    int unidade = n % 10;       // 472 -> 2
    int dezena = n / 10 % 10;   // 472 -> 7
    int centena = n / 100;      // 472 -> 4
    int invertido = unidade * 100 + dezena * 10 + centena;

    printf("Ao contrário: %03d\n", invertido); // 120 -> 21, mostrado como 021
    return 0;
}

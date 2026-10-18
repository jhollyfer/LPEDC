// 0022 · Ternário: condição ? a : b
// Exercício E128 · ★☆☆

#include <stdio.h>

int main(void) {
    int n;
    printf("Quantidade: ");
    if (scanf("%d", &n) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    printf("%d %s %s\n", n, n == 1 ? "mensagem" : "mensagens", n == 1 ? "nova" : "novas");
    return 0;
}

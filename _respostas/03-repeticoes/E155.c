// 0026 · Do-while
// Exercício E155 · ★★★

#include <stdio.h>

int main(void) {
    const int correta = 4321;
    int senha;
    int tentativas = 0;

    do {
        printf("Senha: ");
        if (scanf("%d", &senha) != 1) {
            return 1;
        }
        tentativas++;
    } while (senha != correta && tentativas < 3);

    if (senha == correta) {
        printf("Senha correta na tentativa %d.\n", tentativas);
    } else {
        printf("Cartão bloqueado.\n");
    }
    return 0;
}

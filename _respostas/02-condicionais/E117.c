// 0020 · if/else e o = no lugar do ==
// Exercício E117 · ★★☆
//
// Resposta: "if (tentativas = 3)" é uma atribuição. Estrago 1: a variável
// passa a valer 3, seja qual for a entrada. Estrago 2: o if testa esse 3,
// que é diferente de zero, então é sempre verdade e o cartão é bloqueado.

#include <stdio.h>

int main(void) {
    int tentativas;
    printf("Senhas erradas até agora: ");
    if (scanf("%d", &tentativas) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    if (tentativas == 3) {
        printf("Cartão bloqueado.\n");
    } else {
        printf("Senha errada. Restam %d tentativa(s).\n", 3 - tentativas);
    }
    printf("Tentativas registradas: %d\n", tentativas);
    return 0;
}

// 0023 · Break e continue
// Exercício E134 · ★☆☆
//
// Resposta: "1 2 3 5 6". Trocar a ordem dos if não muda nada aqui (7 não é
// múltiplo de 4). Com i == 8, o break nunca acontece, porque o continue pega
// o 8 antes: a saída vira "1 2 3 5 6 7 9 10".

#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 10; i++) {
        if (i % 4 == 0) {
            continue;
        }
        if (i == 7) {
            break;
        }
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 1; i <= 10; i++) {
        if (i % 4 == 0) {
            continue;
        }
        if (i == 8) {
            break;
        }
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}

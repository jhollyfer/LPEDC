// 0052 · Ponteiros e vetores
// Exercício E312 · ★★★

#include <stdio.h>

int compacta(int *v, int n) {
    if (n == 0) {
        return 0;
    }
    int *escreve = v + 1;
    for (int *le = v + 1; le < v + n; le++) {
        if (*le != *(escreve - 1)) {
            *escreve = *le;
            escreve++;
        }
    }
    return (int)(escreve - v);
}

int main(void) {
    int leituras[10] = {3, 3, 5, 5, 5, 2, 8, 8, 3, 3};
    int n = compacta(leituras, 10);

    printf("Novo tamanho: %d\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", leituras[i]);
    }
    printf("\n");
    return 0;
}

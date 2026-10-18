// A074 · Imprimir antes ou depois da chamada

#include <stdio.h>

// imprime e depois chama: os números saem na ida
void regressiva(int n) {
    if (n == 0) {
        printf("Feliz Ano Novo!\n");
        return;
    }
    printf("%d... ", n);
    regressiva(n - 1);
}

// chama e depois imprime: os números saem na volta
void crescente(int n) {
    if (n == 0) {
        return;
    }
    crescente(n - 1);
    printf("%d ", n);
}

int main(void) {
    regressiva(5);
    crescente(5);
    printf("\n");
    return 0;
}
// Saída:
// 5... 4... 3... 2... 1... Feliz Ano Novo!
// 1 2 3 4 5

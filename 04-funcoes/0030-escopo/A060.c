// A060 · Três variáveis com o mesmo nome

#include <stdio.h>

int nivel = 1; // global

void mostrar_global(void) {
    printf("na função: %d\n", nivel); // aqui só existe a global
}

int main(void) {
    printf("antes: %d\n", nivel); // ainda não há local: vê a global
    int nivel = 2;                // esconde a global daqui para baixo
    printf("main: %d\n", nivel);
    {
        int nivel = 3; // esconde a do main, só dentro deste bloco
        printf("bloco: %d\n", nivel);
    }
    printf("main de novo: %d\n", nivel);
    mostrar_global();

    for (int i = 0; i < 2; i++) {
        int dobro = i * 2; // i e dobro só existem dentro do for
        printf("i = %d, dobro = %d\n", i, dobro);
    }
    // printf("%d\n", i); // erro: 'i' undeclared
    return 0;
}
// Saída:
// antes: 1
// main: 2
// bloco: 3
// main de novo: 2
// na função: 1
// i = 0, dobro = 0
// i = 1, dobro = 2

// 0031 · A pilha de chamadas
// Exercício E184 · ★★☆

#include <stdio.h>

int dobro_mais_um(int n) {
    printf("dobro_mais_um entra: n = %d\n", n);
    int r = n * 2;
    n = r + 1;
    printf("dobro_mais_um sai: n = %d, r = %d\n", n, r);
    return n;
}

int processa(int n) {
    int r = dobro_mais_um(n);
    printf("processa: n = %d, r = %d\n", n, r);
    int resultado = r + n;
    printf("processa devolve %d\n", resultado);
    return resultado;
}

int main(void) {
    int n = 5;
    int r = processa(n);
    printf("main: n = %d, r = %d\n", n, r);
    return 0;
}

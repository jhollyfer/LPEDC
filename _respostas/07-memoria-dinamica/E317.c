// 0053 · Pilha e heap
// Exercício E317 · ★★★
//
// contador (global) e chamadas (static) moram nos dados: há um só de cada.
// local mora na pilha: cada frame tem a sua, e cada uma vale 1.

#include <stdio.h>

int contador = 100;

int passo(int n) {
    static int chamadas = 0;
    int local = 0;
    chamadas++;
    local++;
    contador--;
    printf("entra n=%d: chamadas=%d local=%d contador=%d\n", n, chamadas, local, contador);
    if (n > 0) {
        passo(n - 1);
    }
    int resultado = chamadas * 10 + local;
    printf("sai n=%d: devolve %d\n", n, resultado);
    return resultado;
}

int main(void) {
    printf("%d\n", passo(3));
    printf("%d\n", passo(0));
    printf("%d\n", contador);
    return 0;
}
// Saída:
// entra n=3: chamadas=1 local=1 contador=99
// entra n=2: chamadas=2 local=1 contador=98
// entra n=1: chamadas=3 local=1 contador=97
// entra n=0: chamadas=4 local=1 contador=96
// sai n=0: devolve 41
// sai n=1: devolve 41
// sai n=2: devolve 41
// sai n=3: devolve 41
// 41
// entra n=0: chamadas=5 local=1 contador=95
// sai n=0: devolve 51
// 51
// 95

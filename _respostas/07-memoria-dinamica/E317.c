// 0053 · Pilha e heap
// Exercício E317 · ★★★
//
// Resposta: 41, 51 e 95.
// - contador (global) e chamadas (static) moram nos dados: há um só de cada.
// - local mora na pilha: cada um dos 4 frames de passo(3) tem a sua, e cada
//   uma vale 1.
// - Quando o primeiro frame (n = 3) chega ao return, as 3 chamadas de dentro
//   já terminaram: chamadas = 4, local = 1 -> 41.
// - passo(0) é a 5ª chamada: 5 * 10 + 1 = 51.
// - contador perdeu 1 em cada uma das 5 chamadas: 95.

#include <stdio.h>

int contador = 100;

int passo(int n) {
    static int chamadas = 0;
    int local = 0;
    chamadas++;
    local++;
    contador--;
    if (n > 0) {
        passo(n - 1);
    }
    return chamadas * 10 + local;
}

int main(void) {
    printf("%d\n", passo(3));
    printf("%d\n", passo(0));
    printf("%d\n", contador);
    return 0;
}
// Saída:
// 41
// 51
// 95

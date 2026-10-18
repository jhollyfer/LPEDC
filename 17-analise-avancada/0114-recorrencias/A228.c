// A228 · Hanói: a árvore em que cada nível dobra

#include <stdio.h>

#define MAX_DISCOS 25

long movimentos_nivel[MAX_DISCOS]; // movimentos feitos em cada nível da recursão

// move n discos de 'de' para 'para' usando 'aux': T(n) = 2 T(n-1) + 1
void hanoi(int n, char de, char para, char aux, int nivel, int mostrar) {
    if (n == 0) {
        return;
    }
    if (mostrar) {
        printf("%*shanoi(%d, %c -> %c)\n", 2 * nivel, "", n, de, para);
    }
    hanoi(n - 1, de, aux, para, nivel + 1, mostrar); // tira os n-1 de cima
    movimentos_nivel[nivel]++;                       // move o disco maior: o "+ 1"
    hanoi(n - 1, aux, para, de, nivel + 1, mostrar); // põe os n-1 por cima
}

long resolve(int n, int mostrar) {
    for (int k = 0; k < MAX_DISCOS; k++) {
        movimentos_nivel[k] = 0;
    }
    hanoi(n, 'A', 'C', 'B', 0, mostrar);
    long total = 0;
    for (int k = 0; k < n; k++) {
        total += movimentos_nivel[k];
    }
    return total;
}

int main(void) {
    printf("A árvore de chamadas com 3 discos (o recuo é o nível):\n");
    resolve(3, 1);

    printf("\nCom 5 discos, nível por nível:\n");
    long total = resolve(5, 0);
    for (int k = 0; k < 5; k++) {
        printf("nível %d: %2ld × hanoi(%d), 1 movimento cada\n", k, movimentos_nivel[k], 5 - k);
    }
    printf("total: %ld = 2^5 - 1\n", total);

    printf("\n n   movimentos\n");
    for (int n = 5; n <= 20; n += 5) {
        printf("%2d %12ld\n", n, resolve(n, 0));
    }
    return 0;
}
// Saída:
// A árvore de chamadas com 3 discos (o recuo é o nível):
// hanoi(3, A -> C)
//   hanoi(2, A -> B)
//     hanoi(1, A -> C)
//     hanoi(1, C -> B)
//   hanoi(2, B -> C)
//     hanoi(1, B -> A)
//     hanoi(1, A -> C)
//
// Com 5 discos, nível por nível:
// nível 0:  1 × hanoi(5), 1 movimento cada
// nível 1:  2 × hanoi(4), 1 movimento cada
// nível 2:  4 × hanoi(3), 1 movimento cada
// nível 3:  8 × hanoi(2), 1 movimento cada
// nível 4: 16 × hanoi(1), 1 movimento cada
// total: 31 = 2^5 - 1
//
//  n   movimentos
//  5           31
// 10         1023
// 15        32767
// 20      1048575

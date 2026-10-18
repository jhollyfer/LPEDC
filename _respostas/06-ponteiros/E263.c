// 0044 · Memória e endereços
// Exercício E263 · ★★★

#include <stdio.h>

int main(void) {
    int a = 1, b = 2, c = 3;
    int v[3] = {1, 2, 3};

    printf("a em %p\n", (void *)&a);
    printf("b em %p\n", (void *)&b);
    printf("c em %p\n", (void *)&c);
    for (int i = 0; i < 3; i++) {
        printf("v[%d] em %p\n", i, (void *)&v[i]);
    }
    printf("sizeof v = %zu, a + b + c = %zu\n", sizeof v, sizeof a + sizeof b + sizeof c);
    return 0;
}

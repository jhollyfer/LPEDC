// 0105 · A ideia e a função hash
// Exercício E625 · ★☆☆

#include <stdio.h>

int nicho(int pedido) {
    return pedido % 11;
}

int main(void) {
    int pedidos[] = {1043, 2210, 3876, 5521, 7019};
    for (int i = 0; i < 5; i++) {
        printf("pedido %d -> nicho %d\n", pedidos[i], nicho(pedidos[i]));
    }
    // 2210 e 5521 colidem no nicho 10
    return 0;
}

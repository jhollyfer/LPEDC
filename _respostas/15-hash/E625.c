// 0105 · A ideia e a função hash
// Exercício E625 · ★☆☆

#include <stdio.h>

int nicho(int pedido) {
    return pedido % 11;
}

int main(void) {
    int pedidos[] = {1043, 2210, 3876, 5521, 7019};
    int dono[11] = {0}; // 0 = nicho vazio
    for (int i = 0; i < 5; i++) {
        int n = nicho(pedidos[i]);
        printf("pedido %d -> nicho %d", pedidos[i], n);
        if (dono[n] != 0) {
            printf(" (colide com %d)", dono[n]);
        } else {
            dono[n] = pedidos[i];
        }
        printf("\n");
    }
    return 0;
}

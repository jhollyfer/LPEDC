// Lista · Módulo 25 · Estruturas especiais
// Exercício P2525 · ★★★ · O relógio da segunda chance

#include <stdio.h>

#define R 12

int pedidos[R] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};

int lru(int cap) {
    int v[8], n = 0, acertos = 0; // v[0] = usado há mais tempo
    for (int r = 0; r < R; r++) {
        int x = pedidos[r], i = 0;
        while (i < n && v[i] != x) i++;
        if (i < n) acertos++;
        else if (n == cap) i = 0; // sai o v[0]
        else i = n++;
        for (; i < n - 1; i++) v[i] = v[i + 1];
        v[n - 1] = x;
    }
    return acertos;
}

int relogio(int cap, int mostrar) {
    int quadro[8], bit[8], n = 0, ponteiro = 0, acertos = 0;
    for (int r = 0; r < R; r++) {
        int x = pedidos[r], i = 0;
        while (i < n && quadro[i] != x) i++;
        int acerto = i < n;
        if (acerto) { // acerto: ganha a segunda chance
            bit[i] = 1;
            acertos++;
        } else if (n < cap) {
            quadro[n] = x;
            bit[n++] = 1;
        } else {
            while (bit[ponteiro] == 1) { // gasta a chance de quem tem e segue
                bit[ponteiro] = 0;
                ponteiro = (ponteiro + 1) % cap;
            }
            quadro[ponteiro] = x;
            bit[ponteiro] = 1;
            ponteiro = (ponteiro + 1) % cap;
        }
        if (mostrar) {
            printf("%d %-6s", x, acerto ? "acerto" : "falta");
            for (int k = 0; k < n; k++) printf(" %s%d:%d", k == ponteiro ? ">" : " ", quadro[k], bit[k]);
            printf("\n");
        }
    }
    return acertos;
}

int main(void) {
    int a = relogio(3, 1);
    printf("Relógio, 3 quadros: %d acertos\n", a);
    printf("quadros  LRU  relógio\n");
    for (int c = 2; c <= 4; c++) printf("%8d %4d %8d\n", c, lru(c), relogio(c, 0));
    return 0;
}

// Lista · Módulo 25 · Estruturas especiais
// Exercício P2517 · ★★☆ · Cache LRU contra cache FIFO

#include <stdio.h>

#define R 16

int pedidos[R] = {1, 2, 3, 1, 4, 1, 2, 5, 1, 2, 3, 4, 1, 5, 2, 1};

// o cache é um vetor: posição 0 = quem sai primeiro
int simula(int cap, int lru) {
    int cache[8], n = 0, acertos = 0;
    for (int r = 0; r < R; r++) {
        int x = pedidos[r], i = 0;
        while (i < n && cache[i] != x) i++;
        if (i < n) {
            acertos++;
            if (lru) { // LRU: usado agora vai para o fim (o último a sair)
                for (; i < n - 1; i++) cache[i] = cache[i + 1];
                cache[n - 1] = x;
            }
            continue;
        }
        if (n == cap) { // cheio: sai o da posição 0
            for (int k = 0; k < n - 1; k++) cache[k] = cache[k + 1];
            n--;
        }
        cache[n++] = x;
    }
    return acertos;
}

int main(void) {
    printf("capacidade  LRU  FIFO\n");
    for (int cap = 1; cap <= 5; cap++) printf("%10d %4d %5d\n", cap, simula(cap, 1), simula(cap, 0));
    return 0;
}

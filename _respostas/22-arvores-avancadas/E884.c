// 0148 · Union-find
// Exercício E884 · ★☆☆

#include <stdio.h>
#include "uniao.h"

// tamanho do maior grupo: só as raízes (pai[x] == x) guardam o tamanho certo
int maior_grupo(const UF *u) {
    int maior = 0;
    for (int x = 0; x < u->n; x++) {
        if (u->pai[x] == x && u->tam[x] > maior) {
            maior = u->tam[x];
        }
    }
    return maior;
}

int sozinhos(const UF *u) {
    int qtd = 0;
    for (int x = 0; x < u->n; x++) {
        if (u->pai[x] == x && u->tam[x] == 1) {
            qtd++;
        }
    }
    return qtd;
}

int main(void) {
    // apartamentos 0 a 11; cada par entrou no grupo de mensagens pelo convite do outro
    int convites[][2] = {{0, 3}, {3, 7}, {1, 2}, {7, 9}, {4, 5}, {2, 6}, {9, 11}, {6, 1}};
    UF *u = uf_cria(12);
    for (int i = 0; i < 8; i++) {
        uf_une(u, convites[i][0], convites[i][1]);
    }
    printf("grupos: %d | maior: %d apartamentos | sozinhos: %d\n",
           uf_grupos(u), maior_grupo(u), sozinhos(u));
    uf_libera(u);
    return 0;
}

// 0129 · Labirinto
// Exercício E773 · ★★★
//
// Resposta: com a cor nova igual à velha, pintar uma casa não a tira da
// região "da cor velha". Dois vizinhos ficavam se chamando para sempre e a
// pilha estourava. Basta não fazer nada quando velha == nova.

#include <stdio.h>

#define L 4
#define C 8

char img[L][C + 1] = {
    "..##....",
    ".####.##",
    "..##..##",
    "..#.....",
};

int pinta(int l, int c, char velha, char nova) {
    if (l < 0 || l >= L || c < 0 || c >= C || img[l][c] != velha) {
        return 0;
    }
    img[l][c] = nova;
    return 1 + pinta(l, c + 1, velha, nova) + pinta(l + 1, c, velha, nova)
             + pinta(l, c - 1, velha, nova) + pinta(l - 1, c, velha, nova);
}

int balde(int l, int c, char nova) {
    char velha = img[l][c];
    if (velha == nova) {
        return 0;     // já é dessa cor: pintar não marcaria nada
    }
    return pinta(l, c, velha, nova);
}

void mostra(void) {
    for (int l = 0; l < L; l++) {
        printf("%s\n", img[l]);
    }
}

int main(void) {
    printf("1º clique: %d pixels\n", balde(1, 2, 'o'));
    mostra();
    printf("2º clique: %d pixels\n", balde(1, 2, 'o'));
    printf("3º clique: %d pixels\n", balde(1, 6, '+'));
    mostra();
    return 0;
}

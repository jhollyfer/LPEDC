// 0142 · Distância de edição
// Exercício E851 · ★★★
//
// Resposta: a matriz memo tinha MAX x MAX posições (índices 0 a 15), mas a
// tabela de palavras de até MAX letras precisa dos índices 0 a MAX, por
// causa da linha e da coluna do prefixo vazio. Com 14 letras, o maior índice
// usado é 14 e tudo cabe; com 16, dist(16, 14) lê memo[16][14], fora da
// matriz. Conserto: int memo[MAX + 1][MAX + 1];.

#include <stdio.h>
#include <string.h>

#define MAX 16 // palavras de até 16 letras

const char *a, *b;
int memo[MAX + 1][MAX + 1];
long chamadas = 0;

int menor3(int x, int y, int z) {
    int m = x < y ? x : y;
    return m < z ? m : z;
}

// distância entre a[0..i-1] e b[0..j-1], de cima para baixo
int dist(int i, int j) {
    chamadas++;
    if (i == 0) {
        return j;                   // insere as j letras
    }
    if (j == 0) {
        return i;                   // remove as i letras
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    if (a[i - 1] == b[j - 1]) {
        memo[i][j] = dist(i - 1, j - 1);
    } else {
        memo[i][j] = 1 + menor3(dist(i - 1, j - 1), dist(i - 1, j), dist(i, j - 1));
    }
    return memo[i][j];
}

int calcula(const char *x, const char *y) {
    a = x;
    b = y;
    memset(memo, -1, sizeof memo); // todos os bytes 0xFF: cada int vira -1
    chamadas = 0;
    return dist(strlen(a), strlen(b));
}

int main(void) {
    const char *pares[][2] = {
        {"CONSTITUCIONAL", "INSTITUCIONAL"},
        {"INCONSTITUCIONAL", "CONSTITUCIONAL"},
    };
    for (int p = 0; p < 2; p++) {
        int d = calcula(pares[p][0], pares[p][1]);
        printf("%s -> %s: %d (%ld chamadas)\n", pares[p][0], pares[p][1], d, chamadas);
    }
    return 0;
}

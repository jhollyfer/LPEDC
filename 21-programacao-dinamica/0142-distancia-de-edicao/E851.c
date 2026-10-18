// 0142 · Distância de edição
// Exercício E851 · ★★★
//
// Esta versão calcula a distância de edição DE CIMA PARA BAIXO: a recursão
// natural com memoização (assunto 0138), guardando cada dist(i, j) numa
// matriz global memo. Ela foi feita para palavras de até 16 letras. Com
// CONSTITUCIONAL (14 letras) funciona; com INCONSTITUCIONAL (16 letras), o
// rodar acusa "index 16 out of bounds" e o AddressSanitizer para o programa
// com "global-buffer-overflow". Há UM erro de propósito. Ache, conserte e
// rode até a saída ficar limpa.
//
//   Saída esperada (depois de consertar):
//   CONSTITUCIONAL -> INSTITUCIONAL: 2 (19 chamadas)
//   INCONSTITUCIONAL -> CONSTITUCIONAL: 2 (15 chamadas)
//
// Dicas:
// 1. Na primeira chamada, dist(i, j) recebe i = strlen(a). Para uma palavra
//    de 16 letras, que índice de memo ela usa?
// 2. Quantas linhas e colunas tem a tabela de uma palavra de m letras
//    contra uma de n? (Lembre da linha e da coluna do prefixo vazio.)
// 3. O memset preenche todos os bytes com 0xFF; num int, isso é -1. O
//    sizeof memo faz o memset acompanhar o tamanho da matriz sozinho.
// 4. Resposta esperada: a matriz precisa de MAX + 1 linhas e colunas
//    (índices 0 a 16): int memo[MAX + 1][MAX + 1];.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>

#define MAX 16 // palavras de até 16 letras

const char *a, *b;
int memo[MAX][MAX];
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

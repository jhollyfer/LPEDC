// 0142 · Distância de edição
// Exercício E848 · ★☆☆
//
// O programa abaixo calcula a distância de edição de PATO para SAPATO e
// mostra a tabela inteira, mas a BORDA da tabela não foi preenchida: hoje
// ele lê lixo da pilha (ou mostra números sem sentido). Complete os dois
// laços marcados com COMPLETE AQUI e rode.
//
//   Saída esperada:
//      - S A P A T O
//   -  0 1 2 3 4 5 6
//   P  1 1 2 2 3 4 5
//   A  2 2 1 2 2 3 4
//   T  3 3 2 2 3 2 3
//   O  4 4 3 3 3 3 2
//   distância: 2
//
// Dicas:
// 1. A coluna 0 responde "quanto custa transformar a[0..i-1] em nada?".
// 2. A linha 0 responde "quanto custa transformar nada em b[0..j-1]?".
// 3. Na linha do O, o 2 do canto é a resposta: inserir S e A no começo.
// 4. Resposta esperada: d[i][0] = i e d[0][j] = j, e a saída acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>
#include <string.h>

#define MAX 30

int menor3(int x, int y, int z) {
    int m = x < y ? x : y;
    return m < z ? m : z;
}

int main(void) {
    const char *a = "PATO";
    const char *b = "SAPATO";
    int m = strlen(a), n = strlen(b);
    int d[MAX + 1][MAX + 1];

    for (int i = 0; i <= m; i++) {
        // COMPLETE AQUI: a coluna 0
    }
    for (int j = 0; j <= n; j++) {
        // COMPLETE AQUI: a linha 0
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = 1 + menor3(d[i - 1][j - 1], d[i - 1][j], d[i][j - 1]);
            }
        }
    }

    printf("   -");
    for (int j = 0; j < n; j++) {
        printf(" %c", b[j]);
    }
    printf("\n");
    for (int i = 0; i <= m; i++) {
        printf("%c ", i == 0 ? '-' : a[i - 1]);
        for (int j = 0; j <= n; j++) {
            printf(" %d", d[i][j]);
        }
        printf("\n");
    }
    printf("distância: %d\n", d[m][n]);
    return 0;
}

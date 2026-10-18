// 0159 · Horspool
// Exercício E954 · ★★★

#include <stdio.h>
#include <string.h>

#define ALFABETO 256

int horspool(const char *t, const char *p, int *achados) {
    int n = (int) strlen(t);
    int m = (int) strlen(p);
    int salto[ALFABETO];
    for (int c = 0; c < ALFABETO; c++) {
        salto[c] = m;
    }
    for (int j = 0; j < m - 1; j++) {
        salto[(unsigned char) p[j]] = m - 1 - j;
    }
    int i = 0, alinhamentos = 0;
    *achados = 0;
    while (i <= n - m) {
        alinhamentos++;
        int j = m - 1;
        while (j >= 0 && t[i + j] == p[j]) {
            j--;
        }
        if (j < 0) {
            (*achados)++;
        }
        i += salto[(unsigned char) t[i + m - 1]];
    }
    return alinhamentos;
}

// Sunday: o salto olha a letra logo DEPOIS da janela, t[i + m]
int sunday(const char *t, const char *p, int *achados) {
    int n = (int) strlen(t);
    int m = (int) strlen(p);
    int salto[ALFABETO];
    for (int c = 0; c < ALFABETO; c++) {
        salto[c] = m + 1;                 // letra fora do padrão: passa por cima dela
    }
    for (int j = 0; j < m; j++) {         // agora a última letra entra
        salto[(unsigned char) p[j]] = m - j;
    }
    int i = 0, alinhamentos = 0;
    *achados = 0;
    while (i <= n - m) {
        alinhamentos++;
        int j = 0;
        while (j < m && t[i + j] == p[j]) {
            j++;
        }
        if (j == m) {
            (*achados)++;
        }
        // com i = n - m, t[i + m] é o '\0': salta m + 1 e o laço acaba
        i += salto[(unsigned char) t[i + m]];
    }
    return alinhamentos;
}

int main(void) {
    const char *cardapio = "PASTEL DE CARNE, PASTEL DE PIZZA E PASTEL DE QUEIJO";
    const char *padroes[] = {"QUEIJO", "PASTEL", "FRANGO"};
    int a1, a2;

    for (int k = 0; k < 3; k++) {
        int h = horspool(cardapio, padroes[k], &a1);
        int s = sunday(cardapio, padroes[k], &a2);
        printf("%-6s: Horspool %2d alinhamentos, Sunday %2d (achou %d e %d)\n",
               padroes[k], h, s, a1, a2);
    }
    return 0;
}

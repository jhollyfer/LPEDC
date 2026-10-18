// 0158 · KMP
// Exercício E943 · ★☆☆

#include <stdio.h>
#include <string.h>

#define MAX 32

void calcula_pi(const char *p, int m, int pi[]) {
    int k = 0;                       // tamanho da borda atual
    pi[0] = 0;
    for (int j = 1; j < m; j++) {
        while (k > 0 && p[j] != p[k]) {
            k = pi[k - 1];
        }
        if (p[j] == p[k]) {
            k++;
        }
        pi[j] = k;
    }
}

int main(void) {
    const char *palavras[] = {"papapa", "cacau", "ovo", "pix", "tatuta"};
    int pi[MAX];

    for (int w = 0; w < 5; w++) {
        int m = (int) strlen(palavras[w]);
        calcula_pi(palavras[w], m, pi);
        printf("%s:", palavras[w]);
        for (int j = 0; j < m; j++) {
            printf(" %d", pi[j]);
        }
        printf("\n");
    }
    return 0;
}

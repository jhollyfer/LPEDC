// 0158 · KMP
// Exercício E948 · ★★★

#include <stdio.h>
#include <string.h>

#define MAX 32

void calcula_pi(const char *p, int m, int pi[]) {
    int k = 0;
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

// escreve em saida o menor palíndromo que termina com a palavra s
void completa(const char *s, char saida[]) {
    int m = (int) strlen(s);
    char aux[2 * MAX + 2];
    int pi[2 * MAX + 2];

    // aux = s + '#' + s ao contrário; a maior borda de aux é o maior
    // prefixo de s que é palíndromo (o '#' impede a borda de passar do meio)
    int t = 0;
    for (int i = 0; i < m; i++) {
        aux[t++] = s[i];
    }
    aux[t++] = '#';
    for (int i = m - 1; i >= 0; i--) {
        aux[t++] = s[i];
    }
    aux[t] = '\0';
    calcula_pi(aux, t, pi);
    int pal = pi[t - 1];          // tamanho do maior prefixo palíndromo

    // na frente vai o resto (s[pal..m-1]) ao contrário, depois s inteira
    int k = 0;
    for (int i = m - 1; i >= pal; i--) {
        saida[k++] = s[i];
    }
    for (int i = 0; i < m; i++) {
        saida[k++] = s[i];
    }
    saida[k] = '\0';
    printf("%-8s -> %-12s (prefixo palíndromo: %d letras, +%d)\n",
           s, saida, pal, m - pal);
}

int main(void) {
    const char *palavras[] = {"ovos", "arara", "abacaxi", "assar"};
    char saida[2 * MAX];

    for (int w = 0; w < 4; w++) {
        completa(palavras[w], saida);
    }
    return 0;
}

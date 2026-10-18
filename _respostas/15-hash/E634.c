// 0106 · Encadeamento
// Exercício E634 · ★★☆

#include <stdio.h>
#include <string.h>

#define M 8
#define N 10

unsigned hash_tamanho(const char *s) {
    return (unsigned)strlen(s);
}

unsigned hash_pol(const char *s) {
    unsigned h = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        h = h * 31 + (unsigned char)s[i];
    }
    return h;
}

// mostra o tamanho de cada corrente e a média de comparações para achar
// cada cidade (o k-ésimo nó de uma corrente custa k comparações)
void analisa(const char *nome, unsigned (*h)(const char *), const char *cidades[]) {
    int tam[M] = {0};
    for (int i = 0; i < N; i++) {
        tam[h(cidades[i]) % M]++;
    }
    int maior = 0;
    int comparacoes = 0;
    printf("%s:", nome);
    for (int b = 0; b < M; b++) {
        printf(" %d", tam[b]);
        if (tam[b] > maior) {
            maior = tam[b];
        }
        comparacoes += tam[b] * (tam[b] + 1) / 2; // 1 + 2 + ... + tam
    }
    printf(" | maior: %d | média: %.1f\n", maior, (double)comparacoes / N);
}

int main(void) {
    const char *cidades[N] = {"recife", "natal", "manaus", "belem", "santos",
                              "maceio", "osasco", "palmas", "macapa", "cuiaba"};
    analisa("tamanho  ", hash_tamanho, cidades);
    analisa("polinomio", hash_pol, cidades);
    return 0;
}

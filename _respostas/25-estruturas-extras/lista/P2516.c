// Lista · Módulo 25 · Estruturas especiais
// Exercício P2516 · ★★☆ · Mover para a frente contra a melhor ordem fixa

#include <stdio.h>
#include <string.h>

#define N 5
#define R 14

const char *nomes[N] = {"arroz", "feijao", "cafe", "leite", "pao"};
const char *pedidos[R] = {"pao", "pao", "pao", "leite", "leite", "cafe", "pao", "pao",
                          "arroz", "feijao", "arroz", "feijao", "arroz", "feijao"};

int posicao(const char *v[], const char *x) {
    for (int i = 0; i < N; i++)
        if (strcmp(v[i], x) == 0) return i;
    return -1;
}

int fixa(const char *ordem[]) {
    int custo = 0;
    for (int r = 0; r < R; r++) custo += posicao(ordem, pedidos[r]) + 1;
    return custo;
}

int mtf(void) {
    const char *v[N];
    for (int i = 0; i < N; i++) v[i] = nomes[i];
    int custo = 0;
    for (int r = 0; r < R; r++) {
        int i = posicao(v, pedidos[r]);
        custo += i + 1;
        const char *achado = v[i];
        for (; i > 0; i--) v[i] = v[i - 1];
        v[0] = achado;
    }
    return custo;
}

int main(void) {
    // a melhor ordem FIXA põe os mais pedidos na frente (precisa saber o futuro)
    int freq[N] = {0};
    for (int r = 0; r < R; r++) freq[posicao(nomes, pedidos[r])]++;
    const char *otima[N];
    int usado[N] = {0};
    printf("Frequências:");
    for (int i = 0; i < N; i++) printf(" %s=%d", nomes[i], freq[i]);
    printf("\nOrdem ótima fixa:");
    for (int k = 0; k < N; k++) {
        int melhor = -1;
        for (int i = 0; i < N; i++)
            if (!usado[i] && (melhor == -1 || freq[i] > freq[melhor])) melhor = i;
        usado[melhor] = 1;
        otima[k] = nomes[melhor];
        printf(" %s", otima[k]);
    }
    printf("\n");
    printf("Ordem do cadastro: %d\n", fixa(nomes));
    printf("Ordem ótima fixa: %d\n", fixa(otima));
    printf("Mover para a frente: %d\n", mtf());
    return 0;
}

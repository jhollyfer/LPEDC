// Lista · Módulo 25 · Estruturas especiais
// Exercício P2530 · ★★★ · Três políticas no mesmo balcão

#include <stdio.h>

#define N 10
#define R 5000

int pedidos[R];

int custo_mtf(void) {
    int v[N], total = 0;
    for (int i = 0; i < N; i++) v[i] = N - 1 - i; // começa ao contrário: o pior caso
    for (int r = 0; r < R; r++) {
        int i = 0;
        while (v[i] != pedidos[r]) i++;
        total += i + 1;
        for (; i > 0; i--) v[i] = v[i - 1];
        v[0] = pedidos[r];
    }
    return total;
}

int custo_transpoe(void) {
    int v[N], total = 0;
    for (int i = 0; i < N; i++) v[i] = N - 1 - i;
    for (int r = 0; r < R; r++) {
        int i = 0;
        while (v[i] != pedidos[r]) i++;
        total += i + 1;
        if (i > 0) {
            int t = v[i];
            v[i] = v[i - 1];
            v[i - 1] = t;
        }
    }
    return total;
}

int custo_conta(void) {
    int v[N], c[N], total = 0; // c[i]: contagem de quem está na posição i
    for (int i = 0; i < N; i++) {
        v[i] = N - 1 - i;
        c[i] = 0;
    }
    for (int r = 0; r < R; r++) {
        int i = 0;
        while (v[i] != pedidos[r]) i++;
        total += i + 1;
        c[i]++;
        while (i > 0 && c[i] > c[i - 1]) {
            int t = v[i];
            v[i] = v[i - 1];
            v[i - 1] = t;
            t = c[i];
            c[i] = c[i - 1];
            c[i - 1] = t;
            i--;
        }
    }
    return total;
}

int main(void) {
    // o item i sai com peso 2520 / (i + 1): poucos itens recebem quase tudo
    int peso[N], soma = 0;
    for (int i = 0; i < N; i++) soma += peso[i] = 2520 / (i + 1);
    unsigned s = 2026;
    int freq[N] = {0};
    for (int r = 0; r < R; r++) {
        s = s * 1103515245u + 12345u;
        int sorteio = (int)((s >> 16) % (unsigned)soma), i = 0;
        while (sorteio >= peso[i]) sorteio -= peso[i++];
        pedidos[r] = i;
        freq[i]++;
    }
    // ótima fixa: em ordem de frequência (aqui, 0, 1, 2, ... na prática)
    int ordem[N], usado[N] = {0}, otima = 0;
    for (int k = 0; k < N; k++) {
        int m = -1;
        for (int i = 0; i < N; i++)
            if (!usado[i] && (m == -1 || freq[i] > freq[m])) m = i;
        usado[m] = 1;
        ordem[k] = m;
        otima += freq[m] * (k + 1);
    }
    printf("Frequências:");
    for (int i = 0; i < N; i++) printf(" %d", freq[i]);
    printf("\nOrdem ótima:");
    for (int k = 0; k < N; k++) printf(" %d", ordem[k]);
    printf("\n");
    int fixa = 0;
    for (int r = 0; r < R; r++) fixa += N - pedidos[r]; // a ordem inicial, ao contrário
    printf(" custo  média  política\n");
    printf("%6d %6.2f  fixa (ao contrário)\n", fixa, fixa / (double)R);
    printf("%6d %6.2f  mover para a frente\n", custo_mtf(), custo_mtf() / (double)R);
    printf("%6d %6.2f  transposição\n", custo_transpoe(), custo_transpoe() / (double)R);
    printf("%6d %6.2f  contagem\n", custo_conta(), custo_conta() / (double)R);
    printf("%6d %6.2f  ótima fixa\n", otima, otima / (double)R);
    return 0;
}

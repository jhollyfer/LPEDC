// Lista · Módulo 21 · Programação dinâmica
// Exercício P2129 · ★★★ · Juntar os sacos vizinhos

#include <stdio.h>

#define N 6

const int saco[N] = {4, 7, 2, 6, 3, 5};
int c[N][N], s[N][N];

int soma(int i, int j) {
    int t = 0;
    for (int k = i; k <= j; k++) {
        t += saco[k];
    }
    return t;
}

void mostra(int i, int j) {
    if (i == j) {
        printf("%d", saco[i]);
        return;
    }
    printf("(");
    mostra(i, s[i][j]);
    printf(" ");
    mostra(s[i][j] + 1, j);
    printf(")");
}

int huffman(void) {
    int v[N], n = N, custo = 0;
    for (int i = 0; i < N; i++) {
        v[i] = saco[i];
    }
    while (n > 1) {
        int a = 0;
        for (int i = 1; i < n; i++) {
            if (v[i] < v[a]) {
                a = i;
            }
        }
        int x = v[a];
        v[a] = v[--n];
        int b = 0;
        for (int i = 1; i < n; i++) {
            if (v[i] < v[b]) {
                b = i;
            }
        }
        v[b] += x;
        custo += v[b];
    }
    return custo;
}

int main(void) {
    for (int i = 0; i < N; i++) {
        c[i][i] = 0;
    }
    for (int tam = 2; tam <= N; tam++) {
        for (int i = 0; i + tam - 1 < N; i++) {
            int j = i + tam - 1;
            c[i][j] = -1;
            for (int k = i; k < j; k++) {
                int v = c[i][k] + c[k + 1][j] + soma(i, j);
                if (c[i][j] < 0 || v < c[i][j]) {
                    c[i][j] = v;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("Só vizinhos: custo %d com ", c[0][N - 1]);
    mostra(0, N - 1);
    printf("\n");
    printf("Quaisquer dois (Huffman): custo %d\n", huffman());
    return 0;
}

// Lista · Módulo 15 · Tabelas hash
// Exercício P1519 · ★★☆ · Medindo os blocos da sondagem linear

#include <stdio.h>

#define M 13
#define VAZIO -1

void insere(int t[], int k) {
    int pos = k % M;
    while (t[pos] != VAZIO) {
        pos = (pos + 1) % M;
    }
    t[pos] = k;
}

int main(void) {
    int t[M];
    for (int i = 0; i < M; i++) {
        t[i] = VAZIO;
    }
    int chaves[] = {27, 40, 2, 15, 8, 21, 34, 50, 11};
    for (int i = 0; i < 9; i++) {
        insere(t, chaves[i]);
    }
    printf("tabela:");
    for (int i = 0; i < M; i++) {
        if (t[i] == VAZIO) {
            printf(" _");
        } else {
            printf(" %d", t[i]);
        }
    }
    printf("\n");

    // a tabela tem vazios: comece logo depois de um, para não cortar um bloco
    int inicio = 0;
    while (t[inicio] != VAZIO) {
        inicio++;
    }
    int maior = 0;
    for (int d = 1; d <= M; d++) {
        int i = (inicio + d) % M;
        if (t[i] != VAZIO && t[(i - 1 + M) % M] == VAZIO) { // começo de bloco
            int tam = 0;
            while (t[(i + tam) % M] != VAZIO) {
                tam++;
            }
            printf("bloco começando em %d, tamanho %d\n", i, tam);
            if (tam > maior) {
                maior = tam;
            }
        }
    }
    printf("maior bloco: %d\n", maior);
    return 0;
}

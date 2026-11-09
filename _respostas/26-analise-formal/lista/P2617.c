// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2617 · ★★☆ · CPF repetido no cadastro

#include <stdio.h>
#include <stdlib.h>

#define N 5000
#define K 10000

unsigned semente = 77;

int sorteia(int limite) {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente / 65536u) % (unsigned)limite);
}

int main(void) {
    static int codigo[N];
    for (int i = 0; i < N; i++) {
        codigo[i] = sorteia(K);
    }

    long passos1 = 0;
    int achou1 = -1;
    for (int i = 0; i < N && achou1 < 0; i++) {
        for (int j = i + 1; j < N; j++) {
            passos1++;
            if (codigo[i] == codigo[j]) {
                achou1 = codigo[i];
                break;
            }
        }
    }
    printf("pares:  repetido %d, %7ld passos, %5d bytes\n", achou1, passos1, 0);

    char *visto = calloc(K, 1);
    if (visto == NULL) {
        return 1;
    }
    long passos2 = 0;
    int achou2 = -1;
    for (int i = 0; i < N && achou2 < 0; i++) {
        passos2++;
        if (visto[codigo[i]]) {
            achou2 = codigo[i];
        }
        visto[codigo[i]] = 1;
    }
    free(visto);
    printf("tabela: repetido %d, %7ld passos, %5d bytes\n", achou2, passos2, K);
    return 0;
}

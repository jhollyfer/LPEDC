// Lista · Módulo 21 · Programação dinâmica
// Exercício P2116 · ★★☆ · Corte de haste com custo de corte

#include <stdio.h>

#define TAM 8

const int preco[TAM + 1] = {0, 2, 6, 9, 12, 15, 18, 20, 22};

void resolve(int custo) {
    int melhor[TAM + 1], corte[TAM + 1];
    melhor[0] = 0;
    for (int j = 1; j <= TAM; j++) {
        melhor[j] = preco[j];
        corte[j] = j;
        for (int i = 1; i < j; i++) {
            int v = preco[i] + melhor[j - i] - custo;
            if (v > melhor[j]) {
                melhor[j] = v;
                corte[j] = i;
            }
        }
    }
    printf("Custo por corte R$ %d: R$ %d, pedaços:", custo, melhor[TAM]);
    for (int j = TAM; j > 0; j -= corte[j]) {
        printf(" %d", corte[j]);
    }
    printf("\n");
}

int main(void) {
    resolve(0);
    resolve(3);
    return 0;
}

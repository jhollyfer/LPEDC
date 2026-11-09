// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1826 · ★★★ · Os números mais sorteados: frequência, depois valor

#include <stdio.h>

#define N 40
#define K 61 // dezenas de 1 a 60

unsigned semente = 1996;

int sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente >> 16) % 60) + 1;
}

int main(void) {
    int dez[N];
    for (int i = 0; i < N; i++) dez[i] = sorteia();

    int freq[K] = {0}, maior = 0;
    for (int i = 0; i < N; i++) freq[dez[i]]++; // 1) frequência
    for (int d = 1; d < K; d++)
        if (freq[d] > maior) maior = freq[d];

    int distintas[K], m = 0;
    for (int d = 1; d < K; d++) // 2) já em ordem crescente
        if (freq[d]) distintas[m++] = d;

    int c[K] = {0}, ord[K]; // 3) estável pela chave maior - freq
    for (int i = 0; i < m; i++) c[maior - freq[distintas[i]]]++;
    for (int x = 1; x < maior; x++) c[x] += c[x - 1];
    for (int i = m - 1; i >= 0; i--) ord[--c[maior - freq[distintas[i]]]] = distintas[i];

    printf("Dezenas (frequência):");
    for (int i = 0; i < m; i++) {
        if (i % 10 == 0) printf("\n ");
        printf(" %d(%d)", ord[i], freq[ord[i]]);
    }
    printf("\nLista:");
    int k = 0;
    for (int i = 0; i < m; i++) // 4) cada dezena freq vezes
        for (int r = 0; r < freq[ord[i]]; r++, k++) {
            if (k % 10 == 0) printf("\n ");
            printf(" %2d", ord[i]);
        }
    printf("\nTotal: %d números\n", k);
    return 0;
}

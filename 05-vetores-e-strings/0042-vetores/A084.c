// A084 · Inicializar, contar e copiar

#include <stdio.h>

int main(void) {
    // só 3 valores para 6 gavetas: as outras 3 viram 0
    int gols[6] = {2, 0, 3};

    // sem tamanho: o compilador conta os valores (5)
    int precos[] = {12, 7, 30, 4, 18};
    int n = sizeof(precos) / sizeof(precos[0]); // bytes do vetor / bytes de um item

    printf("gols: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", gols[i]);
    }
    printf("\n");

    printf("precos tem %d itens em %zu bytes\n", n, sizeof(precos));

    // copia = precos; não compila: vetor se copia gaveta por gaveta
    int copia[5];
    for (int i = 0; i < n; i++) {
        copia[i] = precos[i];
    }
    copia[0] = 99; // mexer na cópia não mexe no original

    printf("precos[0] = %d, copia[0] = %d\n", precos[0], copia[0]);
    return 0;
}
// Saída:
// gols: 2 0 3 0 0 0
// precos tem 5 itens em 20 bytes
// precos[0] = 12, copia[0] = 99

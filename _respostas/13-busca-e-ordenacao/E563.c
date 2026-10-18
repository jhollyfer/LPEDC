// 0094 · Busca sequencial
// Exercício E563 · ★★★
//
// Resposta: (1) o laço vai até i <= n e lê v[n], uma gaveta depois do fim (o
// AddressSanitizer acusa stack-buffer-overflow); (2) sem parar no primeiro
// encontro, pos é sobrescrita e a função devolve a ÚLTIMA ocorrência. Conserto:
// i < n e return i assim que achar.

#include <stdio.h>

int primeira(const int v[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int senhas[] = {12, 7, 30, 7, 18, 7};
    int n = 6;

    printf("Primeira senha 7: posição %d\n", primeira(senhas, n, 7));
    printf("Primeira senha 99: posição %d\n", primeira(senhas, n, 99));
    return 0;
}

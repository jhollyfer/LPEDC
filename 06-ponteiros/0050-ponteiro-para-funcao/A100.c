// A100 · A tabela do campeonato com qsort

#include <stdio.h>
#include <stdlib.h>

// o qsort entrega ENDEREÇOS de dois elementos como const void *; a função
// converte para o tipo certo e diz quem vem antes (negativo, zero, positivo)
int crescente(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int decrescente(const void *a, const void *b) {
    return crescente(b, a); // inverte a ordem dos argumentos
}

void mostra(const char *titulo, const int *v, int n) {
    printf("%s:", titulo);
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int pontos[6] = {45, 61, 38, 52, 57, 40};

    qsort(pontos, 6, sizeof pontos[0], crescente);
    mostra("Crescente", pontos, 6);

    qsort(pontos, 6, sizeof pontos[0], decrescente); // mesmo qsort, outra regra
    mostra("Tabela", pontos, 6);
    return 0;
}
// Saída:
// Crescente: 38 40 45 52 57 61
// Tabela: 61 57 52 45 40 38

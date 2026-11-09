// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1816 · ★★☆ · Os rios do Amazonas ordenados pelo tamanho do nome

#include <stdio.h>
#include <string.h>

#define N 11
#define MAXLEN 12

int main(void) {
    const char *rio[N] = {"Solimoes", "Madeira", "Negro", "Purus", "Japura", "Jurua",
                          "Tapajos", "Trombetas", "Javari", "Ica", "Uatuma"};
    const char *saida[N];
    int tam[N], c[MAXLEN + 1] = {0};

    for (int i = 0; i < N; i++) {
        tam[i] = (int)strlen(rio[i]); // uma vez só por nome
        c[tam[i]]++;
    }
    for (int x = 1; x <= MAXLEN; x++) c[x] += c[x - 1];
    for (int i = N - 1; i >= 0; i--) saida[--c[tam[i]]] = rio[i]; // copia o ponteiro

    int atual = -1;
    for (int i = 0; i < N; i++) {
        int t = (int)strlen(saida[i]);
        if (t != atual) {
            printf("%s%d letras:", atual == -1 ? "" : "\n", t);
            atual = t;
        }
        printf(" %s", saida[i]);
    }
    printf("\nC (depois da colocação, início de cada bloco):");
    for (int x = 0; x <= MAXLEN; x++) printf(" %d", c[x]);
    printf("\n");
    return 0;
}

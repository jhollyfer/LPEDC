// Lista · Módulo 08 · Tipos compostos
// Exercício P0820 · ★★☆ · A série do tamanho certo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[16];
    int n;
    double v[]; // membro flexível: o tamanho vem no malloc
} Serie;

Serie *nova_serie(const char *nome, const double *dados, int n) {
    if (strlen(nome) >= 16) {
        return NULL;
    }
    Serie *s = malloc(sizeof *s + n * sizeof s->v[0]);
    if (s == NULL) {
        return NULL;
    }
    strcpy(s->nome, nome);
    s->n = n;
    for (int i = 0; i < n; i++) {
        s->v[i] = dados[i];
    }
    return s;
}

void mostrar(const Serie *s) {
    double soma = 0;
    printf("%s (%d dias):", s->nome, s->n);
    for (int i = 0; i < s->n; i++) {
        printf(" %4.1f", s->v[i]);
        soma += s->v[i];
    }
    printf("\n  média %.2f mm, bloco de %zu bytes\n", soma / s->n,
           sizeof *s + s->n * sizeof s->v[0]);
}

int main(void) {
    double belem[3] = {12.5, 30.0, 8.0};
    double manaus[7] = {0.0, 4.5, 22.0, 18.0, 0.0, 6.5, 11.0};

    Serie *a = nova_serie("Belém", belem, 3);
    Serie *b = nova_serie("Manaus", manaus, 7);
    if (a == NULL || b == NULL) {
        free(a);
        free(b);
        return 1;
    }
    printf("sizeof(Serie) = %zu bytes\n", sizeof(Serie));
    mostrar(a);
    mostrar(b);
    free(a); // um free: struct e vetor estão no mesmo bloco
    free(b);
    return 0;
}

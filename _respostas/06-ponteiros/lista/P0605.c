// Lista · Módulo 06 · Ponteiros
// Exercício P0605 · ★☆☆ · Troca de plantão

#include <stdio.h>

void troca_plantao(const char **a, const char **b) {
    const char *aux = *a; // *a é o ponteiro do main
    *a = *b;
    *b = aux;
}

int main(void) {
    const char *dia = "Dra. Socorro";
    const char *noite = "Dr. Wanderley";
    const char *dia_antes = dia;

    printf("Antes:  dia = %s, noite = %s\n", dia, noite);
    troca_plantao(&dia, &noite);
    printf("Depois: dia = %s, noite = %s\n", dia, noite);
    printf("dia antes:    %p\n", (void *) dia_antes);
    printf("noite depois: %p\n", (void *) noite);
    return 0;
}

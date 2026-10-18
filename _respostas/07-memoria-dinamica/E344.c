// 0058 · Juntando tudo
// Exercício E344 · ★☆☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void liberar_lista(char **lista, int n) {
    if (lista == NULL) {
        return;
    }
    for (int i = 0; i < n; i++) {
        free(lista[i]);
    }
    free(lista);
}

char **criar_lista(const char *itens[], int n) {
    char **lista = malloc(n * sizeof *lista);
    if (lista == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        lista[i] = malloc(strlen(itens[i]) + 1);
        if (lista[i] == NULL) {
            liberar_lista(lista, i);
            return NULL;
        }
        strcpy(lista[i], itens[i]);
    }
    return lista;
}

int main(void) {
    const char *compras[] = {"pao", "leite", "cafe", "manteiga"};
    int n = 4;
    char **lista = criar_lista(compras, n);
    if (lista == NULL) {
        return 1;
    }
    size_t bytes = n * sizeof *lista; // o vetor de ponteiros
    for (int i = 0; i < n; i++) {
        printf("- %s\n", lista[i]);
        bytes += strlen(lista[i]) + 1; // cada item
    }
    printf("%d blocos, %zu bytes\n", n + 1, bytes);
    liberar_lista(lista, n);
    return 0;
}
// Saída:
// - pao
// - leite
// - cafe
// - manteiga
// 5 blocos, 56 bytes

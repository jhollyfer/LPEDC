// 0086 · Fila encadeada
// Exercício E512 · ★☆☆

#include <stdio.h>
// Na pasta do assunto basta #include "fila.h" (o rodar compila o fila.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0086-fila-encadeada/fila.c"

int main(void) {
    Fila *ubs = fila_cria();
    if (ubs == NULL) {
        return 1;
    }
    printf("Senhas (0 para terminar): ");
    int s;
    while (scanf("%d", &s) == 1 && s != 0) {
        fila_insere(ubs, s);
    }

    if (fila_vazia(ubs)) {
        printf("Ninguém na fila\n");
    }
    while (fila_retira(ubs, &s)) {
        printf("Chamando senha %d\n", s);
    }
    fila_libera(ubs);
    return 0;
}

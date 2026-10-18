// 0086 · Fila encadeada
// Exercício E511 · ★☆☆

#include <stdio.h>
// Na pasta do assunto basta #include "fila.h" (o rodar compila o fila.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0086-fila-encadeada/fila.c"

void mostra(Fila *f) {
    int n = fila_tamanho(f);
    if (n == 0) {
        printf("vazia\n");
        return;
    }
    for (int i = 0; i < n; i++) { // uma volta completa: a fila termina igual
        int v;
        fila_retira(f, &v);
        printf(i == 0 ? "%d" : " -> %d", v);
        fila_insere(f, v);
    }
    if (n == 1) {
        printf(" (um nó só: início e fim apontam para ele)");
    }
    printf("\n");
}

int main(void) {
    Fila *f = fila_cria();
    if (f == NULL) {
        return 1;
    }
    int entram[] = {7, 4, 9, 1};
    int x;

    for (int i = 0; i < 4; i++) {
        fila_insere(f, entram[i]);
        printf("insere %d: ", entram[i]);
        mostra(f);
        if (i > 0 && fila_retira(f, &x)) { // a partir do segundo, sai um
            printf("retira %d: ", x);
            mostra(f);
        }
    }
    if (fila_retira(f, &x)) {
        printf("retira %d: ", x);
        mostra(f);
    }
    fila_libera(f);
    return 0;
}

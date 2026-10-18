// 0086 · Fila encadeada
// Exercício E515 · ★★★

#include <stdio.h>
// Na pasta do assunto basta #include "fila.h" (o rodar compila o fila.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0086-fila-encadeada/fila.c"

int main(void) {
    Fila *pref = fila_cria();
    Fila *comum = fila_cria();
    if (pref == NULL || comum == NULL) {
        if (pref != NULL) {
            fila_libera(pref);
        }
        if (comum != NULL) {
            fila_libera(comum);
        }
        return 1;
    }
    for (int s = 101; s <= 103; s++) {
        fila_insere(pref, s);
    }
    for (int s = 1; s <= 4; s++) {
        fila_insere(comum, s);
    }

    printf("Chamando:");
    int seguidas = 0; // preferenciais chamadas desde a última comum
    while (!fila_vazia(pref) || !fila_vazia(comum)) {
        int s;
        bool vez_da_pref = seguidas < 2 || fila_vazia(comum);
        if (vez_da_pref && fila_retira(pref, &s)) {
            printf(" P%d", s);
            seguidas++;
        } else if (fila_retira(comum, &s)) {
            printf(" C%d", s);
            seguidas = 0;
        }
    }
    printf("\n");

    fila_libera(pref);
    fila_libera(comum);
    return 0;
}

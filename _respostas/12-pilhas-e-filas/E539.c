// 0090 · Fila
// Exercício E539 · ★★★

#include <stdio.h>
// Na pasta do assunto basta #include "fila.h" (o rodar compila o fila.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0090-fila/fila.c"

int main(void) {
    Fila *roda = fila_cria();
    if (roda == NULL) {
        return 1;
    }
    for (int p = 1; p <= 7; p++) {
        fila_insere(roda, p);
    }

    printf("Saíram:");
    int p;
    while (fila_tamanho(roda) > 1) {
        for (int passe = 1; passe < 3; passe++) { // passa a batata: volta para o fim
            fila_retira(roda, &p);
            fila_insere(roda, p);
        }
        fila_retira(roda, &p); // o 3º sai da roda
        printf(" %d", p);
    }
    fila_retira(roda, &p);
    printf("\nSobrou: %d\n", p);

    fila_libera(roda);
    return 0;
}

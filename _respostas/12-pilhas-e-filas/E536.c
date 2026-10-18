// 0090 · Fila
// Exercício E536 · ★☆☆

#include <stdio.h>
// Na pasta do assunto basta #include "fila.h" (o rodar compila o fila.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0090-fila/fila.c"

int main(void) {
    Fila *impressora = fila_cria();
    if (impressora == NULL) {
        return 1;
    }
    int paginas[] = {3, 10, 2, 5};
    for (int i = 0; i < 4; i++) {
        fila_insere(impressora, paginas[i]);
    }

    int trabalhos = fila_tamanho(impressora);
    int total = 0;
    int p;
    for (int i = 1; fila_retira(impressora, &p); i++) {
        printf("Trabalho %d: %d páginas\n", i, p);
        total += p;
    }
    printf("Total: %d páginas em %d trabalhos\n", total, trabalhos);

    fila_libera(impressora);
    return 0;
}

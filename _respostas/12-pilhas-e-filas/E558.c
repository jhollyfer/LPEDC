// 0093 · Juntando tudo: a calculadora de expressões
// Exercício E558 · ★★★

#include <stdio.h>
// Na pasta do assunto basta incluir os .h (o rodar compila o pilha.c e o
// fila.c junto). Aqui a resolução inclui as implementações para compilar
// sozinha.
#include "../../12-pilhas-e-filas/0093-juntando-tudo/fila.c"
#include "../../12-pilhas-e-filas/0093-juntando-tudo/pilha.c"

#define QUANTUM 2
#define PROCESSOS 4

int main(void) {
    int restante[PROCESSOS + 1] = {0, 5, 3, 1, 4}; // índice = número do processo
    Fila *prontos = fila_cria();
    if (prontos == NULL) {
        return 1;
    }
    for (int p = 1; p <= PROCESSOS; p++) {
        fila_insere(prontos, p);
    }

    int relogio = 0, soma_termino = 0;
    int p;
    while (fila_retira(prontos, &p)) {
        int fatia = restante[p] < QUANTUM ? restante[p] : QUANTUM;
        relogio += fatia;
        restante[p] -= fatia;
        if (restante[p] > 0) {
            fila_insere(prontos, p); // volta para o fim
        } else {
            printf("t = %d ms: P%d terminou\n", relogio, p);
            soma_termino += relogio;
        }
    }
    printf("Tempo médio de término: %.1f ms\n", (double)soma_termino / PROCESSOS);
    fila_libera(prontos);
    return 0;
}

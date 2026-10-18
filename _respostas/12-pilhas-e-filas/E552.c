// 0092 · Deque
// Exercício E552 · ★★★

#include <stdio.h>
// Na pasta do assunto basta #include "deque.h" (o rodar compila o deque.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0092-deque/deque.c"

#define DIAS 8
#define JANELA 3

int main(void) {
    int temp[DIAS] = {24, 27, 22, 25, 30, 21, 19, 23};
    Deque *d = deque_cria(); // índices, com temperaturas decrescentes
    if (d == NULL) {
        return 1;
    }

    for (int i = 0; i < DIAS; i++) {
        int j;
        // quem está no fundo e não passa de temp[i] nunca mais será máximo
        while (deque_ultimo(d, &j) && temp[j] <= temp[i]) {
            deque_retira_fim(d, &j);
        }
        deque_insere_fim(d, i);
        // a frente saiu da janela?
        if (deque_primeiro(d, &j) && i - j >= JANELA) {
            deque_retira_inicio(d, &j);
        }
        if (i >= JANELA - 1 && deque_primeiro(d, &j)) {
            printf("Dias %d-%d: máxima %d\n", i - JANELA + 2, i + 1, temp[j]);
        }
    }

    deque_libera(d);
    return 0;
}

// 0092 · Deque
// Exercício E549 · ★★☆

#include <stdio.h>
// Na pasta do assunto basta #include "deque.h" (o rodar compila o deque.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0092-deque/deque.c"

void mostra(Deque *d) {
    int n = deque_tamanho(d);
    for (int i = 0; i < n; i++) { // uma volta completa: termina como começou
        int x;
        deque_retira_inicio(d, &x);
        printf(" %d", x);
        deque_insere_fim(d, x);
    }
    printf("\n");
}

void gira_esquerda(Deque *d, int k) {
    for (int i = 0; i < k; i++) {
        int x;
        if (deque_retira_inicio(d, &x)) {
            deque_insere_fim(d, x);
        }
    }
}

void gira_direita(Deque *d, int k) {
    for (int i = 0; i < k; i++) {
        int x;
        if (deque_retira_fim(d, &x)) {
            deque_insere_inicio(d, x);
        }
    }
}

int main(void) {
    Deque *time = deque_cria();
    if (time == NULL) {
        return 1;
    }
    for (int j = 1; j <= 6; j++) {
        deque_insere_fim(time, j);
    }
    printf("Início:");
    mostra(time);
    gira_esquerda(time, 2);
    printf("Esquerda 2:");
    mostra(time);
    gira_direita(time, 3);
    printf("Direita 3:");
    mostra(time);
    deque_libera(time);
    return 0;
}

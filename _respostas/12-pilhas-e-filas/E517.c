// 0087 · Deque
// Exercício E517 · ★☆☆

#include <stdio.h>
// Na pasta do assunto basta #include "deque.h" (o rodar compila o deque.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0087-deque/deque.c"

int main(void) {
    Deque *d = deque_cria();
    if (d == NULL) {
        return 1;
    }
    int x = 0, y = 0;

    deque_insere_fim(d, 1);    // 1
    deque_insere_inicio(d, 2); // 2 1
    deque_insere_fim(d, 3);    // 2 1 3
    deque_insere_inicio(d, 4); // 4 2 1 3

    if (deque_retira_fim(d, &x)) {
        printf("saiu do fim: %d\n", x);
    }
    if (deque_retira_inicio(d, &x)) {
        printf("saiu da frente: %d\n", x);
    }
    if (deque_primeiro(d, &x) && deque_ultimo(d, &y)) {
        printf("frente %d, fundo %d, tamanho %d\n", x, y, deque_tamanho(d));
    }

    deque_libera(d);
    return 0;
}

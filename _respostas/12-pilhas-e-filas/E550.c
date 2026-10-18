// 0092 · Deque
// Exercício E550 · ★★☆
//
// Resposta: em entra_na_frente, (e->inicio - 1) % TAM dava -1 com inicio 0,
// porque em C o resto acompanha o sinal do dividendo. Somar TAM antes do %
// mantém o índice entre 0 e TAM - 1.

#include <stdbool.h>
#include <stdio.h>

#define TAM 5

typedef struct {
    int poltronas[TAM];
    int inicio;
    int n;
} Embarque;

bool entra_no_fim(Embarque *e, int poltrona) {
    if (e->n == TAM) {
        return false;
    }
    e->poltronas[(e->inicio + e->n) % TAM] = poltrona;
    e->n++;
    return true;
}

bool entra_na_frente(Embarque *e, int poltrona) {
    if (e->n == TAM) {
        return false;
    }
    e->inicio = (e->inicio - 1 + TAM) % TAM;
    e->poltronas[e->inicio] = poltrona;
    e->n++;
    return true;
}

bool embarca(Embarque *e, int *poltrona) {
    if (e->n == 0) {
        return false;
    }
    *poltrona = e->poltronas[e->inicio];
    e->inicio = (e->inicio + 1) % TAM;
    e->n--;
    return true;
}

int main(void) {
    Embarque e = {.inicio = 0, .n = 0};

    entra_no_fim(&e, 10);
    entra_no_fim(&e, 20);
    entra_no_fim(&e, 30);
    entra_na_frente(&e, 40); // passageiro com criança de colo

    printf("Embarcando:");
    int p;
    while (embarca(&e, &p)) {
        printf(" %d", p);
    }
    printf("\n");
    return 0;
}

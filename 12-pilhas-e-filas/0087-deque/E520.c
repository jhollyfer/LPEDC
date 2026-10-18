// 0087 · Deque
// Exercício E520 · ★★☆
//
// Embarque no avião: quem viaja com criança de colo entra na frente da fila;
// o resto entra no fim. Este programa traz o próprio deque circular e
// compila sem aviso, mas o sanitizer reclama logo no primeiro passageiro
// com criança. Rode, leia a mensagem ("index -1 out of bounds") e conserte.
//
//   Saída esperada depois do conserto:
//   Embarcando: 40 10 20 30
//
// Dicas:
// 1. Com inicio = 0, quanto vale (inicio - 1) % TAM em C?
// 2. Releia a pegadinha do resto negativo no texto do assunto.
// 3. Resposta esperada: em entra_na_frente, (e->inicio - 1) % TAM dá -1
//    quando inicio é 0, porque em C o resto acompanha o sinal do dividendo.
//    Conserto: e->inicio = (e->inicio - 1 + TAM) % TAM;
//
// Escreva sua resposta abaixo (conserte o código):

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
    e->inicio = (e->inicio - 1) % TAM;
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

// 0087 · Deque
// Exercício E520 · ★★☆
//
// No embarque do avião, quem viaja com criança de colo entra na frente da fila e
// o resto entra no fim. Com a fila circular abaixo (TAM 5, campos poltronas,
// inicio e n), escreva bool entra_no_fim(Embarque *e, int poltrona), bool
// entra_na_frente(Embarque *e, int poltrona) e bool embarca(Embarque *e, int
// *poltrona). No main, entrem no fim as poltronas 10, 20 e 30, entre na frente a
// 40 e embarque todos, mostrando a ordem.
//
//   Saída esperada:
//   Embarcando: 40 10 20 30
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define TAM 5

typedef struct {
    int poltronas[TAM];
    int inicio;
    int n;
} Embarque;

int main(void) {

    return 0;
}

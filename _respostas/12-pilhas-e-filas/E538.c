// 0090 · Fila
// Exercício E538 · ★★☆
//
// Resposta: tamanho fazia fim - inicio, que só funciona enquanto a fila não
// deu a volta no vetor. Depois que fim volta para o começo (inicio = 4,
// fim = 2), a conta dá -2. Somando TAM antes do %, o resultado fica certo
// nos dois casos: (2 - 4 + 6) % 6 = 4.

#include <stdio.h>

#define TAM 6

typedef struct {
    int carros[TAM];
    int inicio;
    int fim;
} DriveThru;

void entra(DriveThru *f, int placa) {
    if ((f->fim + 1) % TAM != f->inicio) {
        f->carros[f->fim] = placa;
        f->fim = (f->fim + 1) % TAM;
    }
}

void sai(DriveThru *f) {
    if (f->inicio != f->fim) {
        f->inicio = (f->inicio + 1) % TAM;
    }
}

int tamanho(const DriveThru *f) {
    return (f->fim - f->inicio + TAM) % TAM;
}

int main(void) {
    DriveThru f = {.inicio = 0, .fim = 0};

    for (int placa = 1; placa <= 5; placa++) {
        entra(&f, placa);
    }
    printf("Carros na fila: %d\n", tamanho(&f));

    for (int i = 0; i < 4; i++) {
        sai(&f);
    }
    printf("Carros na fila: %d\n", tamanho(&f));

    for (int placa = 6; placa <= 8; placa++) {
        entra(&f, placa);
    }
    printf("Carros na fila: %d\n", tamanho(&f));
    return 0;
}

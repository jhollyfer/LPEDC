// 0085 · Fila
// Exercício E508 · ★★☆
//
// O drive-thru da lanchonete usa uma fila circular com inicio, fim (próxima
// vaga) e uma gaveta sacrificada. O programa compila sem aviso, nenhum
// sanitizer reclama, e mesmo assim o telão mostra que há -2 carros na fila.
// Ache o erro, conserte e rode até as três linhas baterem com a saída
// esperada.
//
//   Saída esperada depois do conserto:
//   Carros na fila: 5
//   Carros na fila: 1
//   Carros na fila: 4
//
// Escreva sua resposta abaixo (conserte o código):

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
    return f->fim - f->inicio;
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

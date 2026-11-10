// 0085 · Fila
// Exercício E508 · ★★☆
//
// O drive-thru da lanchonete usa uma fila circular com inicio, fim (a próxima
// vaga) e uma gaveta sacrificada (TAM 6, cabem 5 carros). Com o tipo abaixo,
// escreva void entra(DriveThru *f, int placa) (ignora o carro se não couber),
// void sai(DriveThru *f) e int tamanho(const DriveThru *f), que tem que acertar
// mesmo depois que a fila deu a volta no vetor. No main, entre os carros 1 a 5 e
// mostre "Carros na fila: N"; saiam 4 e mostre; entrem 6, 7 e 8 e mostre.
//
//   Saída esperada:
//   Carros na fila: 5
//   Carros na fila: 1
//   Carros na fila: 4
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define TAM 6

typedef struct {
    int carros[TAM];
    int inicio;
    int fim;
} DriveThru;

int main(void) {

    return 0;
}

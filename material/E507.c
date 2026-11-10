// 0085 · Fila
// Exercício E507 · ★★☆
//
// Outra convenção de fila circular não guarda o contador: ela guarda inicio (o
// próximo a sair) e fim (a próxima vaga) e SACRIFICA uma gaveta, então com TAM 5
// cabem só 4. Com o tipo abaixo, escreva fc_vazia, fc_cheia, fc_insere e
// fc_retira (bool). No main, insira 1 a 5 (avisando "N recusado: fila cheia"
// quando não couber), retire dois mostrando "saiu X", insira 6, 7 e 8 (mesmo
// aviso) e esvazie a fila mostrando o que sobrou.
//
//   Saída esperada:
//   5 recusado: fila cheia
//   saiu 1
//   saiu 2
//   8 recusado: fila cheia
//   Na fila: 3 4 6 7
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define TAM 5

typedef struct {
    int itens[TAM];
    int inicio; // próximo a sair
    int fim;    // próxima vaga (sempre livre)
} FilaSacrificada;

int main(void) {

    return 0;
}

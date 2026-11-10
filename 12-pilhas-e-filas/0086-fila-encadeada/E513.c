// 0086 · Fila encadeada
// Exercício E513 · ★★☆
//
// A fila do caixa da padaria guarda o NOME de cada cliente, com um texto em cada
// nó. Com os tipos abaixo, escreva bool entra(FilaPadaria *f, const char *nome),
// que pendura o cliente no fim, e bool sai(FilaPadaria *f, char *destino), que
// copia o nome do primeiro para destino, tira o nó e o libera (false se não
// tinha ninguém). No main, entrem Ana, Bruno e Carla; atenda um; entre Davi; e
// atenda todos até esvaziar, mostrando "Atendendo NOME" e, no fim, "Fila vazia".
//
//   Saída esperada:
//   Atendendo Ana
//   Atendendo Bruno
//   Atendendo Carla
//   Atendendo Davi
//   Fila vazia
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente {
    char nome[30];
    struct cliente *prox;
} Cliente;

typedef struct {
    Cliente *inicio;
    Cliente *fim;
} FilaPadaria;

int main(void) {

    return 0;
}

// 0086 · Fila encadeada
// Exercício E513 · ★★☆
//
// A fila do caixa da padaria guarda o NOME de cada cliente, então o programa
// traz a própria fila encadeada, com um texto em cada nó. Complete:
//
// - entra: cria um nó com o nome e pendura no fim (cuidado com a fila vazia);
// - sai: copia o nome do primeiro para destino, tira o nó e libera (cuidado
// com a fila que fica vazia). Devolve false se não tinha ninguém.
//
//   Saída esperada:
//   Atendendo Ana
//   Atendendo Bruno
//   Atendendo Carla
//   Atendendo Davi
//   Fila vazia
//
// Dicas:
// 1. Copie o nome com strcpy (os nomes do teste cabem em 30 bytes).
// 2. Em entra: se f->fim == NULL, o novo também vira f->inicio.
// 3. Em sai: se f->inicio virou NULL, f->fim também precisa virar NULL.
// 4. Resposta esperada: as cinco linhas acima, sem erro do sanitizer.
//
// Escreva sua resposta abaixo (complete entra e sai):

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

bool entra(FilaPadaria *f, const char *nome) {
    (void)f; // apague estas linhas
    (void)nome;
    return false;
}

bool sai(FilaPadaria *f, char *destino) {
    (void)f; // apague estas linhas
    (void)destino;
    return false;
}

int main(void) {
    FilaPadaria f = {NULL, NULL};
    char nome[30];

    entra(&f, "Ana");
    entra(&f, "Bruno");
    entra(&f, "Carla");
    if (sai(&f, nome)) {
        printf("Atendendo %s\n", nome);
    }
    entra(&f, "Davi");
    while (sai(&f, nome)) {
        printf("Atendendo %s\n", nome);
    }
    printf("Fila vazia\n");
    return 0;
}

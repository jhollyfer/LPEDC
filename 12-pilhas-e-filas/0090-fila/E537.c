// 0090 · Fila
// Exercício E537 · ★★☆
//
// Outra convenção muito comum de fila circular não guarda o contador n. Ela
// guarda inicio (o próximo a sair) e fim (a próxima vaga) e SACRIFICA uma
// gaveta: a fila está vazia quando inicio == fim e cheia quando
// (fim + 1) % TAM == inicio. Com TAM 5, cabem só 4.
//
// Complete as quatro funções. O main testa: insere 1 a 5 (o 5 é recusado),
// retira dois, insere 6 e 7, tenta o 8 (recusado) e esvazia a fila.
//
//   Saída esperada:
//   5 recusado: fila cheia
//   saiu 1
//   saiu 2
//   8 recusado: fila cheia
//   Na fila: 3 4 6 7
//
// Dicas:
// 1. fc_vazia e fc_cheia são uma linha cada, com as fórmulas do enunciado.
// 2. fc_insere grava em itens[fim] e avança fim com % TAM.
// 3. fc_retira lê itens[inicio] e avança inicio com % TAM.
// 4. Resposta esperada: as cinco linhas acima. O 6 entra na gaveta 4 e fim
//    dá a volta para 0; o 7 entra na 0 e fim vira 1. Aí (1 + 1) % 5 == 2,
//    que é o inicio: cheia, e o 8 é recusado.
//
// Escreva sua resposta abaixo (complete as funções):

#include <stdbool.h>
#include <stdio.h>

#define TAM 5

typedef struct {
    int itens[TAM];
    int inicio; // próximo a sair
    int fim;    // próxima vaga (sempre livre)
} FilaSacrificada;

bool fc_vazia(const FilaSacrificada *f) {
    (void)f; // apague esta linha
    return true;
}

bool fc_cheia(const FilaSacrificada *f) {
    (void)f; // apague esta linha
    return false;
}

bool fc_insere(FilaSacrificada *f, int valor) {
    (void)f; // apague estas linhas
    (void)valor;
    return false;
}

bool fc_retira(FilaSacrificada *f, int *valor) {
    (void)f; // apague estas linhas
    (void)valor;
    return false;
}

int main(void) {
    FilaSacrificada f = {.inicio = 0, .fim = 0};
    int x;

    for (int v = 1; v <= 5; v++) {
        if (!fc_insere(&f, v)) {
            printf("%d recusado: fila cheia\n", v);
        }
    }
    for (int i = 0; i < 2; i++) {
        if (fc_retira(&f, &x)) {
            printf("saiu %d\n", x);
        }
    }
    for (int v = 6; v <= 8; v++) {
        if (!fc_insere(&f, v)) {
            printf("%d recusado: fila cheia\n", v);
        }
    }
    printf("Na fila:");
    while (fc_retira(&f, &x)) {
        printf(" %d", x);
    }
    printf("\n");
    return 0;
}

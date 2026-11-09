// Lista · Módulo 11 · Listas
// Exercício P1104 · ★☆☆ · Quem desistiu da fila do restaurante
//
// A fila de espera do restaurante é uma lista encadeada de nomes. Escreva
//
//   Cliente *remove_nome(Cliente *inicio, const char *nome, bool *removeu)
//
// que tira da lista o primeiro cliente com aquele nome (liberando o nó),
// devolve o novo início e diz em *removeu se achou. Monte a fila Ana, Bia,
// Caio, Duda (nesta ordem, inserindo no fim) e remova Bia, depois Ana,
// depois Zeca, mostrando a fila depois de cada tentativa.
//
//   Saída esperada:
//   Fila: Ana Bia Caio Duda
//   Sem Bia: Ana Caio Duda
//   Sem Ana: Caio Duda
//   Zeca não estava: Caio Duda
//
// Dicas:
// 1. Ande com dois ponteiros: ant (o anterior) e p (o atual). Compare com
//    strcmp(p->nome, nome) == 0.
// 2. Se o removido é o primeiro (ant == NULL), o início muda para
//    p->prox. Senão, ant->prox = p->prox. Só depois, free(p).
// 3. Resposta esperada: a saída acima, sem vazamento no sanitizer.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente {
    char nome[20];
    struct cliente *prox;
} Cliente;

Cliente *insere_fim(Cliente *inicio, const char *nome) {
    Cliente *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    if (inicio == NULL) {
        return novo;
    }
    Cliente *p = inicio;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = novo;
    return inicio;
}

void imprime(const char *rotulo, const Cliente *inicio) {
    printf("%s:", rotulo);
    for (const Cliente *p = inicio; p != NULL; p = p->prox) {
        printf(" %s", p->nome);
    }
    printf("\n");
}

void libera(Cliente *inicio) {
    while (inicio != NULL) {
        Cliente *seguinte = inicio->prox;
        free(inicio);
        inicio = seguinte;
    }
}

int main(void) {

    return 0;
}

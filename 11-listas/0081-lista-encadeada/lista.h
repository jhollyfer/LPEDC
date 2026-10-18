// lista.h · lista simplesmente encadeada de inteiros
//
// Aqui a struct do nó fica no .h DE PROPÓSITO: o assunto é justamente mexer
// nos nós (p->valor, p->prox). A lista é um ponteiro para o primeiro nó, e a
// lista vazia é NULL:  No *inicio = NULL;

#ifndef LISTA_H
#define LISTA_H

typedef struct no {
    int valor;
    struct no *prox; // o próximo nó, ou NULL no último
} No;

// cria um nó com "valor" na frente da lista e devolve o NOVO início:
//   inicio = lista_insere_inicio(inicio, 20);
No *lista_insere_inicio(No *inicio, int valor);

// mostra a lista assim: 80 -> 10 -> 45 -> NULL
void lista_imprime(const No *inicio);

// quantos nós a lista tem
int lista_tamanho(const No *inicio);

// devolve a memória de todos os nós
void lista_libera(No *inicio);

#endif

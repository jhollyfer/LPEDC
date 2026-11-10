// lista.h · TAD lista sequencial (vetor que cresce)
//
// Interface: o que a lista faz. A struct fica escondida em lista.c (tipo
// opaco): quem usa a lista só conversa com ela por estas funções.

#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef struct lista Lista;

// cria uma lista vazia com espaço para "capacidade" itens (NULL se faltar memória)
Lista *lista_cria(int capacidade);

// devolve a memória da lista e dos itens
void lista_libera(Lista *l);

// põe "valor" no fim; dobra a capacidade quando enche (false se faltar memória)
bool lista_insere_fim(Lista *l, int valor);

// põe "valor" na posição "pos" (0 a tamanho), empurrando os outros para a direita
bool lista_insere_em(Lista *l, int pos, int valor);

// tira o item da posição "pos", puxando os outros para a esquerda;
// guarda o valor tirado em *removido (se removido não for NULL)
bool lista_remove_em(Lista *l, int pos, int *removido);

// copia o item da posição "pos" para *valor (false se a posição não existe)
bool lista_pega(const Lista *l, int pos, int *valor);

// quantos itens a lista tem / quantos cabem sem crescer
int lista_tamanho(const Lista *l);
int lista_capacidade(const Lista *l);

// mostra a lista assim: [12, 35, 8]
void lista_imprime(const Lista *l);

#endif

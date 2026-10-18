// 0075 · Vetor dinâmico
// Exercício E447 · ★★☆

#include <stdio.h>

// ---- lista.h e lista.c colados aqui, para esta resolução rodar sozinha ----
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

// lista.c · implementação da lista sequencial (vetor que cresce)

#include <stdio.h>
#include <stdlib.h>

struct lista {
    int *itens; // vetor no heap
    int tam;    // quantos itens estão em uso
    int cap;    // quantos itens cabem no vetor
};

Lista *lista_cria(int capacidade) {
    if (capacidade < 1) capacidade = 1;
    Lista *l = malloc(sizeof(Lista));
    if (l == NULL) return NULL;
    l->itens = malloc(capacidade * sizeof(int));
    if (l->itens == NULL) {
        free(l);
        return NULL;
    }
    l->tam = 0;
    l->cap = capacidade;
    return l;
}

void lista_libera(Lista *l) {
    if (l == NULL) return;
    free(l->itens); // primeiro o vetor...
    free(l);        // ...depois a struct que apontava para ele
}

// garante espaço para mais um item: se encheu, dobra
static bool garante_espaco(Lista *l) {
    if (l->tam < l->cap) return true;
    int nova_cap = l->cap * 2;
    int *novo = realloc(l->itens, nova_cap * sizeof(int));
    if (novo == NULL) return false; // l->itens continua valendo
    l->itens = novo;
    l->cap = nova_cap;
    return true;
}

bool lista_insere_fim(Lista *l, int valor) {
    if (!garante_espaco(l)) return false;
    l->itens[l->tam] = valor;
    l->tam++;
    return true;
}

bool lista_insere_em(Lista *l, int pos, int valor) {
    if (pos < 0 || pos > l->tam) return false;
    if (!garante_espaco(l)) return false;
    for (int i = l->tam; i > pos; i--) { // abre o buraco, de trás para frente
        l->itens[i] = l->itens[i - 1];
    }
    l->itens[pos] = valor;
    l->tam++;
    return true;
}

bool lista_remove_em(Lista *l, int pos, int *removido) {
    if (pos < 0 || pos >= l->tam) return false;
    if (removido != NULL) *removido = l->itens[pos];
    for (int i = pos; i < l->tam - 1; i++) { // fecha o buraco
        l->itens[i] = l->itens[i + 1];
    }
    l->tam--;
    return true;
}

bool lista_pega(const Lista *l, int pos, int *valor) {
    if (pos < 0 || pos >= l->tam) return false;
    *valor = l->itens[pos];
    return true;
}

int lista_tamanho(const Lista *l) {
    return l->tam;
}

int lista_capacidade(const Lista *l) {
    return l->cap;
}

void lista_imprime(const Lista *l) {
    printf("[");
    for (int i = 0; i < l->tam; i++) {
        if (i > 0) printf(", ");
        printf("%d", l->itens[i]);
    }
    printf("]\n");
}
// ---- fim de lista.h e lista.c ----

// devolve a primeira posição de "valor" na lista, ou -1 se não tiver
int posicao_de(const Lista *l, int valor) {
    for (int i = 0; i < lista_tamanho(l); i++) {
        int v;
        lista_pega(l, i, &v);
        if (v == valor) return i;
    }
    return -1;
}

// tira todas as ocorrências de "valor" e devolve quantas tirou
int remove_todos(Lista *l, int valor) {
    int tirou = 0;
    int pos;
    while ((pos = posicao_de(l, valor)) != -1) {
        lista_remove_em(l, pos, NULL);
        tirou++;
    }
    return tirou;
}

int main(void) {
    int chuva[] = {4, -1, 0, 12, -1, -1, 7};
    Lista *l = lista_cria(4);
    if (l == NULL) return 1;
    for (int i = 0; i < 7; i++) lista_insere_fim(l, chuva[i]);

    printf("antes:  ");
    lista_imprime(l);
    int tirou = remove_todos(l, -1);
    printf("depois: ");
    lista_imprime(l);
    printf("%d falhas removidas\n", tirou);

    lista_libera(l);
    return 0;
}

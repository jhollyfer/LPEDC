// skip.h · interface do TAD skip list (chaves int, em ordem crescente)
#ifndef SKIP_H
#define SKIP_H

#include <stdbool.h>

#define SKIP_MAX 12 // andares no máximo (do 0 ao 11): bom para uns 4 mil nós

// a struct fica à mostra no .h porque os exercícios andam pelos andares
typedef struct NoSkip {
    int chave;
    int andares;                   // em quantos andares o nó aparece (1 a SKIP_MAX)
    struct NoSkip *prox[SKIP_MAX]; // prox[k]: o próximo nó no andar k
} NoSkip;

typedef struct {
    NoSkip cabeca;    // sentinela sem chave: está em todos os andares
    int andares;      // andares em uso (o mais alto ocupado + 1)
    int n;            // quantas chaves
    unsigned semente; // estado da "moeda" que sorteia os andares
} Skip;

// cria vazia; a mesma semente sorteia sempre os mesmos andares
Skip *skip_cria(unsigned semente);

// insere sorteando os andares (cara: sobe mais um); repetida devolve false
bool skip_insere(Skip *s, int chave);

// insere com os andares escolhidos por você (para estudar um desenho fixo)
bool skip_insere_andares(Skip *s, int chave, int andares);

// procura a chave; em *passos (se não for NULL) conta os nós olhados
bool skip_busca(const Skip *s, int chave, int *passos);

bool skip_remove(Skip *s, int chave);

void skip_mostra(const Skip *s); // um andar por linha, do mais alto ao 0
void skip_libera(Skip *s);

#endif

// autolista.h · interface do TAD lista autoajustável (nomes)
#ifndef AUTOLISTA_H
#define AUTOLISTA_H

#include <stdbool.h>

// a struct fica à mostra no .h porque os exercícios andam pelos nós
typedef struct NoAuto {
    char nome[20];
    int acessos; // quantas vezes foi achado (usado pela contagem)
    struct NoAuto *prox;
} NoAuto;

typedef struct {
    NoAuto *inicio;
    int n;
} AutoLista;

AutoLista *al_cria(void);
void al_insere_fim(AutoLista *l, const char *nome); // monta a ordem inicial

// as quatro buscas devolvem true se acharam e guardam em *custo (se não for
// NULL) quantos nós foram comparados; elas só mudam a lista quando acham
//   al_busca:          não mexe em nada (a lista fixa, para comparar)
//   al_busca_mtf:      mover para a frente: o achado vira o primeiro
//   al_busca_transpoe: transposição: o achado troca de lugar com o anterior
//   al_busca_conta:    contagem: soma 1 nos acessos e mantém a lista em
//                      ordem decrescente de acessos (empate: quem já estava
//                      na frente continua na frente)
bool al_busca(const AutoLista *l, const char *nome, int *custo);
bool al_busca_mtf(AutoLista *l, const char *nome, int *custo);
bool al_busca_transpoe(AutoLista *l, const char *nome, int *custo);
bool al_busca_conta(AutoLista *l, const char *nome, int *custo);

void al_mostra(const AutoLista *l); // os nomes separados por espaço, sem \n
void al_libera(AutoLista *l);

#endif

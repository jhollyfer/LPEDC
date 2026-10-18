// tabela.h · TAD tabela hash com encadeamento (chave texto -> valor int)
#ifndef TABELA_H
#define TABELA_H

#include <stdbool.h>

typedef struct Tabela Tabela; // tipo opaco: o cliente não vê os baldes

// cria uma tabela vazia com m baldes; devolve NULL se faltar memória
Tabela *tabela_cria(int m);

// guarda chave -> valor; se a chave já existe, troca o valor.
// devolve false se faltar memória
bool tabela_insere(Tabela *t, const char *chave, int valor);

// procura a chave; se achar, copia o valor em *valor e devolve true.
// *comparacoes recebe quantos nós foram olhados (pode ser NULL)
bool tabela_busca(const Tabela *t, const char *chave, int *valor, int *comparacoes);

// tira a chave da tabela; devolve false se ela não estava lá
bool tabela_remove(Tabela *t, const char *chave);

// quantos itens estão guardados
int tabela_tamanho(const Tabela *t);

// mostra cada balde e a sua corrente
void tabela_mostra(const Tabela *t);

// libera todos os nós e a tabela
void tabela_libera(Tabela *t);

#endif

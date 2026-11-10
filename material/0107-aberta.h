// aberta.h · TAD tabela hash com endereçamento aberto (sondagem linear)
// chave int (o apartamento) -> valor int (a hora em que o carro entrou)
#ifndef ABERTA_H
#define ABERTA_H

#include <stdbool.h>

typedef struct Aberta Aberta;

// cria uma tabela com m posições, todas livres; NULL se faltar memória
Aberta *aberta_cria(int m);

// guarda chave -> valor (se a chave já existe, troca o valor).
// devolve a posição usada, ou -1 se a tabela estiver cheia.
// *sondagens recebe quantas posições foram olhadas (pode ser NULL)
int aberta_insere(Aberta *t, int chave, int valor, int *sondagens);

// procura a chave; se achar, copia o valor e devolve true
bool aberta_busca(const Aberta *t, int chave, int *valor, int *sondagens);

// tira a chave, deixando a marca de "removida"; false se não estava lá
bool aberta_remove(Aberta *t, int chave);

// mostra todas as posições
void aberta_mostra(const Aberta *t);

void aberta_libera(Aberta *t);

#endif

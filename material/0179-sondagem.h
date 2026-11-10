// sondagem.h · TAD tabela hash com endereçamento aberto: sondagem linear,
// quadrática ou dispersão dupla, com remoção por lápide
#ifndef SONDAGEM_H
#define SONDAGEM_H

#include <stdbool.h>

typedef enum { SD_LINEAR, SD_QUADRATICA, SD_DUPLA } ModoSondagem;

typedef struct Sondagem Sondagem;

// m posições, todas livres; para a dupla, m deve ser primo. NULL se faltar memória
Sondagem *sd_cria(int m, ModoSondagem modo);

// a i-ésima posição da sequência de sondagem da chave (i = 0, 1, 2...)
int sd_posicao(const Sondagem *t, int chave, int i);

// guarda a chave (se já existe, nada muda); devolve a posição ou -1 se não
// achou lugar. *sondagens recebe quantas posições foram olhadas (pode ser NULL)
int sd_insere(Sondagem *t, int chave, int *sondagens);

bool sd_busca(const Sondagem *t, int chave, int *sondagens);

// troca a chave por uma lápide; false se não estava lá
bool sd_remove(Sondagem *t, int chave);

int sd_tamanho(const Sondagem *t); // chaves guardadas (lápides não contam)
int sd_lapides(const Sondagem *t);
double sd_carga(const Sondagem *t); // fator de carga: n / m

// uma linha: a chave em cada posição, "." livre, "x" lápide
void sd_mostra(const Sondagem *t);

void sd_libera(Sondagem *t);

#endif

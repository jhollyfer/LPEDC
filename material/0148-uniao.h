// uniao.h · interface do TAD union-find (conjuntos disjuntos)
#ifndef UNIAO_H
#define UNIAO_H

#include <stdbool.h>

typedef struct {
    int n;       // elementos de 0 a n - 1
    int *pai;    // pai[x] == x: x é a raiz (o representante) do grupo
    int *tam;    // tam[r]: quantos elementos o grupo da raiz r tem
    int grupos;  // quantos grupos existem agora
} UF;

UF *uf_cria(int n);            // n grupos de um elemento só

int uf_acha(UF *u, int x);     // o representante do grupo de x (comprime o caminho)

// junta os grupos de a e b (o menor vai para baixo do maior);
// devolve false se eles já estavam no mesmo grupo
bool uf_une(UF *u, int a, int b);

bool uf_juntos(UF *u, int a, int b);
int uf_grupos(const UF *u);
int uf_tamanho(UF *u, int x);  // quantos elementos tem o grupo de x

void uf_mostra(const UF *u);   // imprime o vetor pai
void uf_libera(UF *u);

#endif

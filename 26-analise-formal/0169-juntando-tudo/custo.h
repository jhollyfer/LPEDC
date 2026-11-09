// custo.h · cinco funções instrumentadas: passos, bytes de heap e frames
#ifndef CUSTO_H
#define CUSTO_H

#include <stddef.h>

// medidas da última sequência de chamadas (zere com custo_zera)
extern long custo_passos;      // passos contados pela própria função
extern size_t custo_bytes;     // bytes pedidos ao malloc
extern int custo_prof_max;     // maior número de frames vivos ao mesmo tempo

void custo_zera(void);

long custo_soma(const int v[], int n);          // Θ(n) tempo, Θ(1) espaço
int custo_busca(const int v[], int n, int x);   // Θ(log n) tempo, Θ(1) espaço
long custo_pares(const int v[], int n, int alvo); // Θ(n²) tempo, Θ(1) espaço
void custo_merge(int v[], int n);               // Θ(n log n) tempo, Θ(n) espaço
long custo_soma_rec(const int v[], int n);      // Θ(n) tempo, Θ(n) de pilha

#endif

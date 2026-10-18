// pix.h · registros de Pix e ordenações lineares por campo
#ifndef PIX_H
#define PIX_H

#include <stdbool.h>
#include <stdint.h>

#define PIX_SEGUNDOS 86400 // segundos num dia: 0 a 86399

typedef struct {
    uint32_t id;       // número da transação, na ordem em que chegou
    int32_t segundo;   // hora do dia, em segundos desde a meia-noite
    int32_t centavos;  // valor, em centavos (sempre positivo)
} Pix;

// preenche v com n transações de mentira; a mesma semente dá os mesmos dados
void pix_gera(Pix v[], int n, unsigned semente);

// counting sort estável pelo segundo do dia (k = 86400). Usa aux como rascunho
bool pix_por_horario(Pix v[], Pix aux[], int n);

// radix sort estável pelo valor, em base 256 (4 passadas). Usa aux como rascunho
void pix_por_valor(Pix v[], Pix aux[], int n);

// função de comparação pelo valor, para o qsort
int pix_compara_valor(const void *a, const void *b);

// mostra uma transação numa linha: id, hora e valor
void pix_mostra(const Pix *p);

#endif

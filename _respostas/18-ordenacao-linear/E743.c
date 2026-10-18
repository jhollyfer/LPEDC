// 0124 · Juntando tudo
// Exercício E743 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pix.h"

// counting sort estável pelo segundo do dia, escrito à mão
bool ordena_horario(Pix v[], Pix aux[], int n) {
    int *c = calloc(PIX_SEGUNDOS, sizeof(int));
    if (c == NULL) {
        return false;
    }
    for (int i = 0; i < n; i++) {
        c[v[i].segundo]++;
    }
    for (int s = 1; s < PIX_SEGUNDOS; s++) {
        c[s] += c[s - 1];
    }
    for (int i = n - 1; i >= 0; i--) {   // de trás para a frente: estável
        aux[--c[v[i].segundo]] = v[i];
    }
    for (int i = 0; i < n; i++) {        // o resultado volta para v
        v[i] = aux[i];
    }
    free(c);
    return true;
}

int main(void) {
    // Pix da virada do horário de almoço: vários no mesmo segundo
    Pix v[] = {
        {1, 43201, 5000}, {2, 43200, 1250}, {3, 43201, 990},  {4, 43202, 30000},
        {5, 43200, 870},  {6, 43201, 2500}, {7, 43200, 15000}, {8, 43202, 640},
    };
    Pix aux[8];
    int n = 8;

    pix_por_valor(v, aux, n);            // desempate: valor
    if (!ordena_horario(v, aux, n)) {    // chave principal: horário
        return 1;
    }
    for (int i = 0; i < n; i++) {
        pix_mostra(&v[i]);
    }
    return 0;
}

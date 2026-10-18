// 0124 · Juntando tudo
// Exercício E741 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pix.h"

#define N 200000

// em ordem de (horário, valor)? Com horario_primeiro = false, (valor, horário)
bool em_ordem(const Pix v[], int n, bool horario_primeiro) {
    for (int i = 1; i < n; i++) {
        int32_t a1 = horario_primeiro ? v[i - 1].segundo : v[i - 1].centavos;
        int32_t b1 = horario_primeiro ? v[i].segundo : v[i].centavos;
        int32_t a2 = horario_primeiro ? v[i - 1].centavos : v[i - 1].segundo;
        int32_t b2 = horario_primeiro ? v[i].centavos : v[i].segundo;
        if (a1 > b1 || (a1 == b1 && a2 > b2)) {
            return false;
        }
    }
    return true;
}

int main(void) {
    Pix *a = malloc(N * sizeof(Pix));
    Pix *b = malloc(N * sizeof(Pix));
    Pix *aux = malloc(N * sizeof(Pix));
    if (a == NULL || b == NULL || aux == NULL) {
        free(a);
        free(b);
        free(aux);
        return 1;
    }
    pix_gera(a, N, 77);
    memcpy(b, a, N * sizeof(Pix));

    pix_por_valor(a, aux, N);              // chave menos importante primeiro
    bool ok = pix_por_horario(a, aux, N);
    ok = pix_por_horario(b, aux, N) && ok; // ao contrário
    pix_por_valor(b, aux, N);
    if (!ok) {
        printf("faltou memória para os contadores\n");
    }

    printf("valor, depois horário: (horário, valor)? %s\n", em_ordem(a, N, true) ? "sim" : "não");
    printf("horário, depois valor: (horário, valor)? %s\n", em_ordem(b, N, true) ? "sim" : "não");
    printf("horário, depois valor: (valor, horário)? %s\n", em_ordem(b, N, false) ? "sim" : "não");
    free(a);
    free(b);
    free(aux);
    return 0;
}

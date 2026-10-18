// 0074 · TAD: interface (.h) e implementação (.c)
// Exercício E444 · ★★★
//
// Resposta: a mesma saída (22:50, 00:15, 430 min). Com minutos totais,
// avanca e minutos_ate viram uma linha cada; hora e minuto viram contas. O
// cliente não muda porque só conhece as funções: é a promessa do TAD.

#include <stdio.h>
#include <stdlib.h>

// ---- horario.h ----------------------------------------------------------
typedef struct horario Horario;

Horario *horario_cria(int hora, int minuto); // NULL se faltar memória
void horario_libera(Horario *h);
void horario_avanca(Horario *h, int minutos); // passa da meia-noite se precisar
int horario_hora(const Horario *h);
int horario_minuto(const Horario *h);
int horario_minutos_ate(const Horario *a, const Horario *b); // de a até b, para a frente

// ---- horario.c (versão 2: minutos desde a meia-noite) -----------------
// Invariante: 0 <= total < 1440.
struct horario {
    int total;
};

Horario *horario_cria(int hora, int minuto) {
    Horario *h = malloc(sizeof *h);
    if (h == NULL) {
        return NULL;
    }
    h->total = hora * 60 + minuto;
    return h;
}

void horario_libera(Horario *h) {
    free(h);
}

void horario_avanca(Horario *h, int minutos) {
    h->total = (h->total + minutos) % 1440;
}

int horario_hora(const Horario *h) {
    return h->total / 60;
}

int horario_minuto(const Horario *h) {
    return h->total % 60;
}

int horario_minutos_ate(const Horario *a, const Horario *b) {
    return (b->total - a->total + 1440) % 1440;
}

// ---- cliente --------------------------------------------------------------
int main(void) {
    Horario *saida = horario_cria(22, 50);
    Horario *chegada = horario_cria(22, 50);
    Horario *alvorada = horario_cria(6, 0);
    if (saida == NULL || chegada == NULL || alvorada == NULL) {
        horario_libera(saida);
        horario_libera(chegada);
        horario_libera(alvorada);
        return 1;
    }

    printf("Ônibus sai às %02d:%02d\n", horario_hora(saida), horario_minuto(saida));
    horario_avanca(chegada, 85);
    printf("Viagem de 85 min: chega às %02d:%02d\n", horario_hora(chegada),
           horario_minuto(chegada));
    printf("Do embarque até 06:00: %d min\n", horario_minutos_ate(saida, alvorada));

    horario_libera(saida);
    horario_libera(chegada);
    horario_libera(alvorada);
    return 0;
}

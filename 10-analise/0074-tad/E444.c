// 0074 · TAD: interface (.h) e implementação (.c)
// Exercício E444 · ★★★
//
// O TAD Horario abaixo guarda a hora e o minuto em dois campos. Reescreva SÓ
// a parte "horario.c" para guardar um campo único: os minutos desde a
// meia-noite (0 a 1439). A parte "horario.h" e o cliente (main) não podem
// mudar nem uma letra, e a saída tem de continuar idêntica:
//
//   Saída esperada:
//   Ônibus sai às 22:50
//   Viagem de 85 min: chega às 00:15
//   Do embarque até 06:00: 430 min
//
// Depois responda: qual das duas versões deixou horario_minutos_ate mais
// simples? E o que isso mostra sobre esconder a struct?
//
// Dicas:
// 1. h:m vira h * 60 + m. De volta: hora = total / 60, minuto = total % 60.
// 2. Avançar com a volta do dia: total = (total + minutos) % 1440.
// 3. Diferença para a frente: (b - a + 1440) % 1440.
// 4. Resposta esperada: a mesma saída. A versão com minutos totais deixa
//    avanca e minutos_ate com uma linha cada; hora e minuto viram contas.
//    Como o cliente só usa as funções, a troca não o afeta: é a promessa do
//    TAD.
//
// Escreva sua resposta abaixo (reescreva a parte horario.c):

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

// ---- horario.c (versão 1: hora e minuto) -------------------------------
struct horario {
    int hora;
    int minuto;
};

Horario *horario_cria(int hora, int minuto) {
    Horario *h = malloc(sizeof *h);
    if (h == NULL) {
        return NULL;
    }
    h->hora = hora;
    h->minuto = minuto;
    return h;
}

void horario_libera(Horario *h) {
    free(h);
}

void horario_avanca(Horario *h, int minutos) {
    h->minuto += minutos;
    h->hora += h->minuto / 60;
    h->minuto %= 60;
    h->hora %= 24;
}

int horario_hora(const Horario *h) {
    return h->hora;
}

int horario_minuto(const Horario *h) {
    return h->minuto;
}

int horario_minutos_ate(const Horario *a, const Horario *b) {
    int horas = b->hora - a->hora;
    int minutos = b->minuto - a->minuto;
    if (minutos < 0) {
        minutos += 60;
        horas -= 1;
    }
    if (horas < 0) {
        horas += 24;
    }
    return horas * 60 + minutos;
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

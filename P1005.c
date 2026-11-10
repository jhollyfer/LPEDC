// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1005 · ★☆☆ · O termômetro do freezer (só pela interface)
//
// O TAD Termometro abaixo já está pronto: a parte "termometro.h" é a
// interface, e a "termometro.c", a implementação. Escreva SÓ o cliente (o
// main), sem tocar nos campos da struct: registre as leituras do freezer
// -18, -20, -15, -22 e -19 graus e mostre o resumo. Conte também, no
// cliente, quantas leituras passaram de -16 graus (o alarme do freezer).
//
//   Saída esperada:
//   Leituras: 5
//   Mínima: -22.0
//   Máxima: -15.0
//   Média: -18.8
//   Alarmes (acima de -16): 1
//
// Dicas:
// 1. Comece com Termometro *t = termometro_cria(); e confira se veio NULL.
// 2. Para o alarme, compare a leitura ANTES de registrá-la: o TAD não
//    guarda a lista de leituras, só o resumo.
// 3. Não esqueça termometro_libera(t) no fim.
// 4. Resposta esperada: a saída acima (média -94 / 5 = -18.8).
//
// Escreva sua resposta abaixo (só o main):

#include <stdio.h>
#include <stdlib.h>

// ---- termometro.h ---------------------------------------------------------
typedef struct termometro Termometro;

Termometro *termometro_cria(void);          // NULL se faltar memória
void termometro_registra(Termometro *t, double graus);
int termometro_quantidade(const Termometro *t);
double termometro_minima(const Termometro *t);  // só com quantidade > 0
double termometro_maxima(const Termometro *t);
double termometro_media(const Termometro *t);
void termometro_libera(Termometro *t);

// ---- termometro.c ---------------------------------------------------------
struct termometro {
    int n;
    double min, max, soma;
};

Termometro *termometro_cria(void) {
    Termometro *t = malloc(sizeof *t);
    if (t != NULL) {
        t->n = 0;
        t->min = t->max = t->soma = 0;
    }
    return t;
}

void termometro_registra(Termometro *t, double graus) {
    if (t->n == 0 || graus < t->min) {
        t->min = graus;
    }
    if (t->n == 0 || graus > t->max) {
        t->max = graus;
    }
    t->soma += graus;
    t->n++;
}

int termometro_quantidade(const Termometro *t) {
    return t->n;
}

double termometro_minima(const Termometro *t) {
    return t->min;
}

double termometro_maxima(const Termometro *t) {
    return t->max;
}

double termometro_media(const Termometro *t) {
    return t->n > 0 ? t->soma / t->n : 0;
}

void termometro_libera(Termometro *t) {
    free(t);
}

// ---- cliente --------------------------------------------------------------
int main(void) {

    return 0;
}

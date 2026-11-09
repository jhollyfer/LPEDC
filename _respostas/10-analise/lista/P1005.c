// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1005 · ★☆☆ · O termômetro do freezer (só pela interface)

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
    double leituras[5] = {-18, -20, -15, -22, -19};
    Termometro *t = termometro_cria();
    if (t == NULL) {
        printf("Sem memória\n");
        return 1;
    }
    int alarmes = 0;
    for (int i = 0; i < 5; i++) {
        if (leituras[i] > -16) {
            alarmes++;
        }
        termometro_registra(t, leituras[i]);
    }
    printf("Leituras: %d\n", termometro_quantidade(t));
    printf("Mínima: %.1f\n", termometro_minima(t));
    printf("Máxima: %.1f\n", termometro_maxima(t));
    printf("Média: %.1f\n", termometro_media(t));
    printf("Alarmes (acima de -16): %d\n", alarmes);
    termometro_libera(t);
    return 0;
}

// A214 · Fila de prioridade com nome

#include <stdio.h>

#define CAP 8

// um heap de structs: a prioridade decide, o nome vai junto
typedef struct {
    int gravidade;
    const char *nome;
} Paciente;

typedef struct {
    Paciente v[CAP];
    int n;
} Triagem;

void troca(Paciente *a, Paciente *b) {
    Paciente t = *a; // struct inteira copiada de uma vez
    *a = *b;
    *b = t;
}

void chega(Triagem *t, int gravidade, const char *nome) {
    int i = t->n++;
    t->v[i] = (Paciente){gravidade, nome};
    while (i > 0 && t->v[(i - 1) / 2].gravidade < t->v[i].gravidade) {
        troca(&t->v[(i - 1) / 2], &t->v[i]);
        i = (i - 1) / 2;
    }
}

Paciente atende(Triagem *t) {
    Paciente primeiro = t->v[0];
    t->v[0] = t->v[--t->n];
    int i = 0;
    while (2 * i + 1 < t->n) {
        int f = 2 * i + 1;
        if (f + 1 < t->n && t->v[f + 1].gravidade > t->v[f].gravidade) {
            f++;
        }
        if (t->v[i].gravidade >= t->v[f].gravidade) {
            break;
        }
        troca(&t->v[i], &t->v[f]);
        i = f;
    }
    return primeiro;
}

int main(void) {
    Triagem t = {.n = 0};
    chega(&t, 40, "Ana (febre)");
    chega(&t, 70, "Bruno (fratura)");
    chega(&t, 20, "Carla (receita)");
    chega(&t, 90, "Davi (infarto)");
    chega(&t, 50, "Eva (corte)");

    while (t.n > 0) {
        Paciente p = atende(&t);
        printf("%2d  %s\n", p.gravidade, p.nome);
    }
    return 0;
}
// Saída:
// 90  Davi (infarto)
// 70  Bruno (fratura)
// 50  Eva (corte)
// 40  Ana (febre)
// 20  Carla (receita)

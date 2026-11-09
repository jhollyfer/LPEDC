// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1026 · ★★★ · Duas implementações da lista de presença

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ---- presenca.h (as duas versões têm a mesma interface) -------------------
typedef struct presenca Presenca;

Presenca *pres_cria_A(int capacidade);
void pres_marca_A(Presenca *p, int cracha);
bool pres_entrou_A(Presenca *p, int cracha);
long pres_passos_A(const Presenca *p);
void pres_libera_A(Presenca *p);

Presenca *pres_cria_B(int capacidade);
void pres_marca_B(Presenca *p, int cracha);
bool pres_entrou_B(Presenca *p, int cracha);
long pres_passos_B(const Presenca *p);
void pres_libera_B(Presenca *p);

// ---- presenca.c -----------------------------------------------------------
struct presenca {
    int *v;
    int n, cap;
    long passos; // instrumentação: muda até nas consultas
};

static Presenca *cria(int capacidade) {
    Presenca *p = malloc(sizeof *p);
    if (p == NULL) {
        return NULL;
    }
    p->v = malloc(capacidade * sizeof(int));
    if (p->v == NULL) {
        free(p);
        return NULL;
    }
    p->n = 0;
    p->cap = capacidade;
    p->passos = 0;
    return p;
}

static void libera(Presenca *p) {
    if (p != NULL) {
        free(p->v);
        free(p);
    }
}

// versão A: vetor desordenado
Presenca *pres_cria_A(int capacidade) {
    return cria(capacidade);
}

void pres_marca_A(Presenca *p, int cracha) {
    if (p->n < p->cap) {
        p->v[p->n++] = cracha;
        p->passos++;
    }
}

bool pres_entrou_A(Presenca *p, int cracha) {
    for (int i = 0; i < p->n; i++) {
        p->passos++;
        if (p->v[i] == cracha) {
            return true;
        }
    }
    return false;
}

long pres_passos_A(const Presenca *p) {
    return p->passos;
}

void pres_libera_A(Presenca *p) {
    libera(p);
}

// versão B: vetor ordenado
Presenca *pres_cria_B(int capacidade) {
    return cria(capacidade);
}

void pres_marca_B(Presenca *p, int cracha) {
    if (p->n == p->cap) {
        return;
    }
    int i = p->n;
    while (i > 0 && p->v[i - 1] > cracha) {
        p->v[i] = p->v[i - 1];
        i--;
        p->passos++;
    }
    p->v[i] = cracha;
    p->n++;
    p->passos++;
}

bool pres_entrou_B(Presenca *p, int cracha) {
    int ini = 0, fim = p->n - 1;
    while (ini <= fim) {
        p->passos++;
        int meio = (ini + fim) / 2;
        if (p->v[meio] == cracha) {
            return true;
        }
        if (p->v[meio] < cracha) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return false;
}

long pres_passos_B(const Presenca *p) {
    return p->passos;
}

void pres_libera_B(Presenca *p) {
    libera(p);
}

// ---- cliente --------------------------------------------------------------
int main(void) {
    Presenca *a = pres_cria_A(1000), *b = pres_cria_B(1000);
    if (a == NULL || b == NULL) {
        pres_libera_A(a);
        pres_libera_B(b);
        return 1;
    }
    for (int k = 0; k < 1000; k++) {
        pres_marca_A(a, (7 * k) % 1000);
        pres_marca_B(b, (7 * k) % 1000);
    }
    long marca_a = pres_passos_A(a), marca_b = pres_passos_B(b);
    bool iguais = true;
    for (int x = 0; x < 2000; x++) {
        if (pres_entrou_A(a, x) != pres_entrou_B(b, x)) {
            iguais = false;
        }
    }
    printf("A (desordenado): marcar %ld passos, consultar %ld passos\n", marca_a, pres_passos_A(a) - marca_a);
    printf("B (ordenado):    marcar %ld passos, consultar %ld passos\n", marca_b, pres_passos_B(b) - marca_b);
    printf("Respostas iguais: %s\n", iguais ? "sim" : "não");
    pres_libera_A(a);
    pres_libera_B(b);
    return 0;
}

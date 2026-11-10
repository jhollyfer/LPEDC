// A131 · Os alunos da academia

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { MENSAL, TRIMESTRAL, ANUAL, QTD_PLANOS } Plano;

// modalidades: cada uma é um bit
#define MUSCULACAO (1u << 0)
#define NATACAO    (1u << 1)
#define YOGA       (1u << 2)

typedef struct {
    char nome[16];
    Plano plano;
    unsigned modalidades;
} Aluno;

typedef struct {
    Aluno *v;
    int n, cap;
} Academia;

bool matricular(Academia *a, const char *nome, Plano plano, unsigned mods) {
    if (a->n == a->cap) {
        int nova = a->cap == 0 ? 2 : 2 * a->cap;
        Aluno *novo = realloc(a->v, nova * sizeof *novo);
        if (novo == NULL) {
            return false;
        }
        a->v = novo;
        a->cap = nova;
    }
    Aluno *al = &a->v[a->n]; // ponteiro usado logo, antes de outro realloc
    strcpy(al->nome, nome);
    al->plano = plano;
    al->modalidades = mods;
    a->n++;
    return true;
}

// devolve o índice (e não um ponteiro: o vetor pode mudar de lugar)
int procurar(const Academia *a, const char *nome) {
    for (int i = 0; i < a->n; i++) {
        if (strcmp(a->v[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

// "alguma" das modalidades da máscara, não "todas"
void listar_alguma(const Academia *a, unsigned mascara) {
    for (int i = 0; i < a->n; i++) {
        if ((a->v[i].modalidades & mascara) != 0) {
            printf("  %s\n", a->v[i].nome);
        }
    }
}

int main(void) {
    const char *planos[QTD_PLANOS] = {"mensal", "trimestral", "anual"};
    Academia a = {NULL, 0, 0};

    bool ok = matricular(&a, "Bruna", ANUAL, MUSCULACAO | YOGA) &&
              matricular(&a, "Davi", MENSAL, NATACAO) &&
              matricular(&a, "Elis", MENSAL, MUSCULACAO) &&
              matricular(&a, "Fabio", TRIMESTRAL, MUSCULACAO | NATACAO | YOGA) &&
              matricular(&a, "Gil", ANUAL, 0);
    if (!ok) {
        free(a.v);
        return 1;
    }

    int i = procurar(&a, "Davi");
    if (i != -1) {
        a.v[i].modalidades |= YOGA; // Davi entrou na yoga
        a.v[i].plano = ANUAL;       // e trocou de plano
    }

    int por_plano[QTD_PLANOS] = {0};
    for (int k = 0; k < a.n; k++) {
        por_plano[a.v[k].plano]++;
    }
    for (Plano p = MENSAL; p < QTD_PLANOS; p++) {
        printf("%s: %d aluno(s)\n", planos[p], por_plano[p]);
    }

    printf("Fazem natação ou yoga:\n");
    listar_alguma(&a, NATACAO | YOGA);
    printf("%d alunos, capacidade %d\n", a.n, a.cap);

    free(a.v);
    return 0;
}
// Saída:
// mensal: 1 aluno(s)
// trimestral: 1 aluno(s)
// anual: 3 aluno(s)
// Fazem natação ou yoga:
//   Bruna
//   Davi
//   Fabio
// 5 alunos, capacidade 8

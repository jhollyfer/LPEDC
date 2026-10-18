// 0066 · Juntando tudo: o cardápio
// Exercício E392 · ★☆☆

#include <stdio.h>

typedef enum { BAIXA = 1, MEDIA, ALTA = 5, URGENTE } Prioridade;

#define FEITA     1u
#define FIXADA    2u
#define ARQUIVADA 4u

typedef struct {
    char titulo[12];
    Prioridade p;
    unsigned flags;
} Tarefa;

void mostrar(const char *rotulo, const Tarefa *t) {
    printf("%s: %s, prioridade %d, flags %u%s%s%s\n", rotulo, t->titulo, t->p, t->flags,
           (t->flags & FEITA) ? " [feita]" : "",
           (t->flags & FIXADA) ? " [fixada]" : "",
           (t->flags & ARQUIVADA) ? " [arquivada]" : "");
}

int main(void) {
    Tarefa t = {"Pagar luz", URGENTE, FIXADA};
    Tarefa u = t; // cópia: mudar u não muda t
    u.flags |= FEITA;
    u.p = MEDIA;

    mostrar("t", &t);
    mostrar("u", &u);
    u.flags ^= FIXADA | ARQUIVADA; // 011 ^ 110 = 101
    mostrar("u", &u);
    printf("sizeof(Tarefa) = %zu\n", sizeof(Tarefa));
    return 0;
}

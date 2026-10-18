// 0066 · Juntando tudo: o cardápio
// Exercício E392 · ★☆☆
//
// Resposta: "6 2" (URGENTE = ALTA + 1; u é cópia); "2 3" (só u ganhou FEITA:
// 010 | 001 = 011); 20 (12 + 4 + 4, já alinhado); ativa (o bit 4 está
// desligado); 5 (011 ^ 110 = 101: FIXADA desligou e ARQUIVADA ligou).

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

int main(void) {
    Tarefa t = {"Pagar luz", URGENTE, FIXADA};
    Tarefa u = t;
    u.flags |= FEITA;
    u.p = MEDIA;
    printf("%d %d\n", t.p, u.p);
    printf("%u %u\n", t.flags, u.flags);
    printf("%zu\n", sizeof(Tarefa));
    printf("%s\n", (u.flags & ARQUIVADA) ? "arquivada" : "ativa");
    u.flags ^= FIXADA | ARQUIVADA;
    printf("%u\n", u.flags);
    return 0;
}

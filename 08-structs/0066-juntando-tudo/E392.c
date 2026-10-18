// 0066 · Juntando tudo: o cardápio
// Exercício E392 · ★☆☆
//
// Complete o programa da lista de tarefas. Escreva
// void mostrar(const char *rotulo, const Tarefa *t), que mostra o rótulo, o
// título, a prioridade (como número), as flags (como número) e, para cada
// flag ligada, uma etiqueta: [feita], [fixada], [arquivada]. No main:
//
//   1. t começa com "Pagar luz", URGENTE e FIXADA; u é uma cópia de t;
//   2. ligue FEITA em u e troque a prioridade de u para MEDIA;
//   3. mostre t e u;
//   4. inverta FIXADA e ARQUIVADA de u numa operação só e mostre u;
//   5. mostre o sizeof(Tarefa).
//
//   Saída esperada (num PC de 64 bits):
//   t: Pagar luz, prioridade 6, flags 2 [fixada]
//   u: Pagar luz, prioridade 2, flags 3 [feita] [fixada]
//   u: Pagar luz, prioridade 2, flags 5 [feita] [arquivada]
//   sizeof(Tarefa) = 20
//
// Dicas:
// 1. URGENTE vem logo depois de ALTA = 5, por isso vale 6.
// 2. Tarefa u = t; faz uma cópia: mudar u não muda t.
// 3. Ligar: |=. Inverter dois bits de uma vez: u.flags ^= FIXADA | ARQUIVADA;
//    (011 ^ 110 = 101).
// 4. Resposta esperada: a saída acima. O sizeof é 12 + 4 + 4, sem sobras.
//
// Escreva sua resposta abaixo (complete o código):

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

// escreva mostrar aqui

int main(void) {

    return 0;
}

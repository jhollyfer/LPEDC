// 0066 · Juntando tudo: o cardápio
// Exercício E392 · ★☆☆
//
// Preveja cada linha da saída (num PC de 64 bits):
//
//   typedef enum { BAIXA = 1, MEDIA, ALTA = 5, URGENTE } Prioridade;
//
//   #define FEITA     1u
//   #define FIXADA    2u
//   #define ARQUIVADA 4u
//
//   typedef struct {
//       char titulo[12];
//       Prioridade p;
//       unsigned flags;
//   } Tarefa;
//
//   Tarefa t = {"Pagar luz", URGENTE, FIXADA};
//   Tarefa u = t;
//   u.flags |= FEITA;
//   u.p = MEDIA;
//   printf("%d %d\n", t.p, u.p);
//   printf("%u %u\n", t.flags, u.flags);
//   printf("%zu\n", sizeof(Tarefa));
//   printf("%s\n", (u.flags & ARQUIVADA) ? "arquivada" : "ativa");
//   u.flags ^= FIXADA | ARQUIVADA;
//   printf("%u\n", u.flags);
//
// Dicas:
// 1. URGENTE vem logo depois de ALTA = 5.
// 2. u = t faz uma cópia: mudar u não muda t.
// 3. 3 ^ 6 em binário: 011 ^ 110.
// 4. Resposta esperada: "6 2"; "2 3"; 20 (12 + 4 + 4, sem sobras); ativa; 5.
//
// Escreva sua resposta abaixo (como comentário; depois cole e confira):

#include <stdio.h>

int main(void) {

    return 0;
}

// Lista · Módulo 11 · Listas
// Exercício P1107 · ★☆☆ · A roda-gigante do parque
//
// As 6 cabines da roda-gigante formam uma lista circular: depois da 6 vem a
// 1. Cada nó guarda o número da cabine e quantas pessoas estão nela. A
// lista é guardada pelo ponteiro para o ÚLTIMO nó. Escreva:
//
//   No *insere_fim(No *ultimo, int cabine, int pessoas)  // devolve o novo último
//   int total_pessoas(const No *ultimo)
//   void mostra_a_partir(const No *ultimo, int cabine)   // dá uma volta
//                                                         // começando nela
//
// Cadastre as cabines 1 a 6 com 2, 4, 0, 3, 1 e 4 pessoas, mostre o total e
// a volta começando na cabine 4. Libere tudo no fim.
//
//   Saída esperada:
//   Total: 14 pessoas
//   A partir da 4: [4:3] [5:1] [6:4] [1:2] [2:4] [3:0]
//
// Dicas:
// 1. Inserir no fim da circular: o novo aponta para o primeiro
//    (ultimo->prox) e o antigo último aponta para o novo. Com a lista vazia,
//    o novo aponta para si mesmo.
// 2. Percorrer uma volta: do { ... p = p->prox; } while (p != comeco);.
//    O do-while garante que a primeira cabine é visitada.
// 3. Para liberar, quebre o círculo antes (ultimo->prox = NULL, depois de
//    guardar o primeiro) e libere como uma lista comum.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int cabine;
    int pessoas;
    struct no *prox;
} No;

int main(void) {

    return 0;
}

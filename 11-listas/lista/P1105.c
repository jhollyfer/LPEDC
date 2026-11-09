// Lista · Módulo 11 · Listas
// Exercício P1105 · ★☆☆ · Engatar o trem da tarde no da manhã em O(1)
//
// Guardando o início, o fim e o tamanho da lista numa struct, inserir no fim
// e concatenar duas listas custam O(1). Escreva:
//
//   void insere_fim(Lista *l, int valor)
//   void concatena(Lista *a, Lista *b)   // passa os nós de b para o fim de
//                                        // a; b fica vazia
//
// Monte a com os vagões 1, 2 e 3 e b com 4 e 5. Mostre as duas, concatene,
// mostre de novo e mostre o último de a (sem percorrer). Depois concatene
// a com a b vazia (nada muda) e libere tudo.
//
//   Saída esperada:
//   a: 1 -> 2 -> 3 -> NULL (3 nós)
//   b: 4 -> 5 -> NULL (2 nós)
//   a depois: 1 -> 2 -> 3 -> 4 -> 5 -> NULL (5 nós)
//   b depois: NULL (0 nós)
//   último de a: 5
//   a com b vazia: 1 -> 2 -> 3 -> 4 -> 5 -> NULL (5 nós)
//
// Dicas:
// 1. typedef struct { No *inicio, *fim; int n; } Lista; começa com
//    {NULL, NULL, 0}.
// 2. Em concatena: se b está vazia, nada a fazer. Se a está vazia, a
//    recebe os ponteiros de b. Senão, a->fim->prox = b->inicio e
//    a->fim = b->fim. Nos dois últimos casos, some os tamanhos e zere b.
// 3. Resposta esperada: a saída acima. Só a lista a é liberada no fim (os
//    nós de b agora são dela).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct {
    No *inicio, *fim;
    int n;
} Lista;

int main(void) {

    return 0;
}

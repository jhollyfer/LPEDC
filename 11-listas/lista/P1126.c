// Lista · Módulo 11 · Listas
// Exercício P1126 · ★★★ · Lista encadeada sem malloc (cursores)
//
// Em sistemas embarcados (e em muita prova antiga), a lista encadeada vive
// dentro de um VETOR: cada célula tem valor e o ÍNDICE da próxima (-1 é o
// "NULL"). As células sem uso formam uma segunda lista, a dos LIVRES, de
// onde se tira célula para inserir e para onde ela volta ao remover.
//
//   typedef struct { int valor; int prox; } Celula;
//   typedef struct { Celula c[6]; int inicio; int livre; } Estatica;
//
// Escreva inicializa (todas livres: 0 -> 1 -> ... -> 5 -> -1, lista vazia),
// bool insere_ordenado(Estatica *l, int x) (false se não há célula livre),
// bool remove_valor(Estatica *l, int x) e mostra. Faça: insere 30, 10, 20;
// mostre; remove 10; mostre; insere 25, 5, 40, 50; mostre; tente inserir
// 60; e mostre a tabela das células.
//
//   Saída esperada:
//   lista: 10 20 30 | início 1, livre 3
//   lista: 20 30 | início 2, livre 1
//   lista: 5 20 25 30 40 50 | início 3, livre -1
//   60: sem célula livre
//   célula 0: 30 -> 4
//   célula 1: 25 -> 0
//   célula 2: 20 -> 1
//   célula 3: 5 -> 2
//   célula 4: 40 -> 5
//   célula 5: 50 -> -1
//
// Dicas:
// 1. Pegar célula: i = l->livre; l->livre = l->c[i].prox. Devolver célula
//    i: l->c[i].prox = l->livre; l->livre = i. A lista de livres funciona
//    como uma pilha.
// 2. A inserção ordenada é a mesma da lista com ponteiros, trocando p->prox
//    por l->c[p].prox e NULL por -1.
// 3. Repare na célula 1: o 10 saiu e o 25 reaproveitou a mesma célula.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define CAP 6

typedef struct {
    int valor;
    int prox; // índice da próxima célula, ou -1
} Celula;

typedef struct {
    Celula c[CAP];
    int inicio; // primeira célula da lista, ou -1
    int livre;  // primeira célula livre, ou -1
} Estatica;

int main(void) {

    return 0;
}

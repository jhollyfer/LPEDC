// Lista · Módulo 14 · Árvores
// Exercício P1425 · ★★★ · O paciente que piorou na fila
//
// No pronto-socorro, a fila é um heap de máximo pela gravidade (no empate,
// sai a ficha menor). Mas um paciente pode PIORAR enquanto espera, e aí ele
// tem que subir na fila. Para isso, o heap precisa saber onde cada paciente
// está: guarde no heap só os ids (fichas) e mantenha pos[id] = índice do
// paciente no heap, atualizado em TODA troca.
//
//   typedef struct {
//       int heap[MAX];       // ids
//       int pos[MAX];        // pos[id]
//       int gravidade[MAX];  // gravidade[id]
//       int n;
//   } Fila;
//
// Escreva antes, troca (que corrige pos[] dos dois), sobe, desce,
// chega(f, id, g), piorou(f, id, g) (a gravidade só aumenta, então só sobe)
// e atende(f), que devolve o id atendido.
//
// Chegam as fichas 0 a 5 com gravidades 3, 5, 2, 4, 2, 1. Atenda uma; a
// ficha 5 piora para 4; a ficha 2 piora para 6; atenda todo mundo.
//
//   Saída esperada:
//   atendido: ficha 1
//   ficha 5 piorou para 4
//   ficha 2 piorou para 6
//   atendido: ficha 2 (gravidade 6)
//   atendido: ficha 3 (gravidade 4)
//   atendido: ficha 5 (gravidade 4)
//   atendido: ficha 0 (gravidade 3)
//   atendido: ficha 4 (gravidade 2)
//
// Dicas:
// 1. troca(f, i, j) troca heap[i] com heap[j] e depois faz
//    pos[heap[i]] = i e pos[heap[j]] = j.
// 2. piorou: grava a gravidade nova e chama sobe(f, f->pos[id]). Sem pos[],
//    achar o paciente custaria O(n); com ele, a operação toda é O(log n).
// 3. É a operação HEAP-INCREASE-KEY do Cormen, a mesma que o Dijkstra
//    (módulo 23) usa para diminuir distâncias.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define MAX 10

typedef struct {
    int heap[MAX];
    int pos[MAX];
    int gravidade[MAX];
    int n;
} Fila;

int main(void) {

    return 0;
}

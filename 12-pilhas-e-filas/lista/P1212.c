// Lista · Módulo 12 · Pilhas e filas
// Exercício P1212 · ★★☆ · Uma pilha feita com duas filas
//
// A recíproca da fila com duas pilhas: faça uma PILHA usando só duas FILAS.
// Escreva uma fila circular de int sobre vetor (capacidade 8: insere,
// retira, vazia, tamanho) e, em cima dela, o tipo
//
//   typedef struct { Fila a, b; } PilhaDeFilas;
//
// com pdf_empilha e pdf_desempilha. Regra: a fila a guarda os itens com o
// TOPO NA FRENTE. Para empilhar x, ponha x na fila b vazia, passe todos de
// a para b (atrás do x) e troque os papéis de a e b. Conte quantos itens
// passaram de uma fila para outra. Faça: empilha 1, 2 e 3; desempilha;
// empilha 4; desempilha até esvaziar.
//
//   Saída esperada:
//   desempilha: 3
//   desempilha até o fim: 4 2 1
//   itens movidos entre as filas: 4
//
// Dicas:
// 1. Com a regra acima, desempilhar é só retirar da frente de a: O(1).
//    O custo fica no empilha: O(n), porque passa a fila inteira.
// 2. Para trocar os papéis, troque as duas structs inteiras (Fila t = p->a;
//    p->a = p->b; p->b = t;).
// 3. Movidos: empilha 1 move 0, empilha 2 move 1, empilha 3 move 2; depois
//    de tirar o 3 sobram dois, então empilha 4 move 1 a mais... confira com
//    o programa: são 4 no total (0 + 1 + 2 + 1).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define CAP 8

typedef struct {
    int v[CAP];
    int inicio, n;
} Fila;

int main(void) {

    return 0;
}

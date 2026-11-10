// Lista · Módulo 14 · Árvores
// Exercício P1426 · ★★★ · Juntando k listas com um heap
//
// Quatro lojas de uma rede mandam os valores das vendas do dia, cada lista
// já em ordem crescente:
//
//   loja 0: 12 40 77
//   loja 1: 5 18 19 60 95
//   loja 2: 33
//   loja 3: 7 21 50 88
//
// Junte tudo numa sequência ordenada usando um heap de MÍNIMO com no máximo
// k = 4 itens. Cada item guarda o valor, de qual lista veio e o índice nela:
//
//   typedef struct { int valor; int lista; int indice; } Item;
//
// Comece pondo a frente de cada lista no heap. Repita: a raiz é o menor de
// todos; imprima; se a lista dela tem próximo, ele toma o lugar da raiz;
// senão, o último do heap vai para a raiz e o heap encolhe; desça a raiz.
//
//   Saída esperada:
//   juntas: 5 7 12 18 19 21 33 40 50 60 77 88 95
//
// Dicas:
// 1. Guarde as listas num vetor de ponteiros: const int *listas[] = {loja0,
//    loja1, loja2, loja3}; e os tamanhos em int tam[].
// 2. Um literal composto monta o item numa linha: heap[0] = (Item){v, l, i};
// 3. Custa O(N log k) para N valores no total: com k listas, cada valor
//    entra e sai do heap uma vez. Compare com intercalar duas a duas.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    int valor;
    int lista;
    int indice;
} Item;

int main(void) {
    int loja0[] = {12, 40, 77};
    int loja1[] = {5, 18, 19, 60, 95};
    int loja2[] = {33};
    int loja3[] = {7, 21, 50, 88};
    (void)loja0;
    (void)loja1;
    (void)loja2;
    (void)loja3;

    return 0;
}

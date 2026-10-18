// 0081 · Lista encadeada
// Exercício E481 · ★☆☆
//
// O app do banco quer destacar os Pix "grandes". Monte o extrato inserindo
// no início os Pix 30, 75, 12, 50, 120 e 64 (nesta ordem), mostre a lista e
// escreva a função
//
//   int conta_maiores(const No *inicio, int limite)
//
// que devolve quantos valores são MAIORES que o limite. Use limite 50.
//
//   Saída esperada:
//   64 -> 120 -> 50 -> 12 -> 75 -> 30 -> NULL
//   3 Pix acima de R$ 50
//
// Dicas:
// 1. Toda inserção é "extrato = lista_insere_inicio(extrato, valor);".
// 2. O percurso é sempre o mesmo: for (const No *p = inicio; p != NULL;
//    p = p->prox).
// 3. O 50 não conta: "maior que", não "maior ou igual".
// 4. Resposta esperada: a saída acima (64, 120 e 75). Libere a lista no fim.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "lista.h"

int main(void) {

    return 0;
}

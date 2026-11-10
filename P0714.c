// Lista · Módulo 07 · Memória dinâmica
// Exercício P0714 · ★★☆ · Inserir em ordem num vetor que cresce
//
// A loja guarda os preços dos produtos em ordem crescente num vetor dinâmico
// que começa com capacidade 2 e dobra quando enche. Escreva
//
//   bool inserir(int **v, int *n, int *cap, int valor);
//
// que garante espaço (com realloc, dentro da função) e encaixa o valor no
// lugar certo, empurrando os maiores. Insira os preços abaixo, um por vez,
// mostrando a capacidade sempre que ela mudar, e mostre o vetor no fim:
//
//   int novos[7] = {45, 12, 89, 30, 12, 70, 5};
//
//   Saída esperada:
//   (capacidade 2)
//   (capacidade 4)
//   (capacidade 8)
//   Preços (7 de 8): 5 12 12 30 45 70 89
//
// Dicas:
// 1. A função muda o PONTEIRO do main quando faz realloc, por isso recebe
//    int **v: o realloc é feito em *v, e o novo endereço volta para lá.
// 2. Dentro: int *p = *v; e o mesmo deslocamento do P0514 (comece do fim,
//    empurre os maiores, guarde em i + 1).
// 3. Comece no main com int *v = NULL, n = 0, cap = 0: realloc(NULL, x) é o
//    mesmo que malloc(x). A primeira capacidade é 2; depois, dobra.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int novos[7] = {45, 12, 89, 30, 12, 70, 5};
    (void) novos; // apague esta linha quando escrever

    return 0;
}

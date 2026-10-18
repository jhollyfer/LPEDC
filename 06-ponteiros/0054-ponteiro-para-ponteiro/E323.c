// 0054 · Ponteiro para ponteiro
// Exercício E323 · ★★★
//
// Quatro jurados deram notas a uma escola de samba, cada uma numa variável:
//
//   int j1 = 9, j2 = 7, j3 = 10, j4 = 8;
//
// Você quer mostrar as notas em ordem crescente SEM mexer nas variáveis.
// Monte um vetor de ponteiros int *ordem[4] = {&j1, &j2, &j3, &j4}; e
// ordene OS PONTEIROS pelo valor apontado. Para trocar dois ponteiros do
// vetor, escreva
//
//   void troca_ptr(int **a, int **b)
//
// No fim, mostre as notas pela ordem e depois as variáveis originais.
//
//   Saída esperada:
//   Em ordem: 7 8 9 10
//   Originais: j1=9 j2=7 j3=10 j4=8
//
// Dicas:
// 1. Para ordenar, use dois for (i e j > i): se *ordem[j] < *ordem[i],
//    troca_ptr(&ordem[i], &ordem[j]).
// 2. Dentro de troca_ptr, o temporário é um int *: int *tmp = *a;
// 3. Resposta esperada: 7 8 9 10, e as variáveis continuam 9, 7, 10, 8.
//    Só os endereços mudaram de lugar no vetor.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

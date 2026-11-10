// Lista · Módulo 06 · Ponteiros
// Exercício P0611 · ★★☆ · Lado par, lado ímpar
//
// O carteiro recebeu as cartas de uma rua fora de ordem e quer separar o lado
// par do lado ímpar antes de sair:
//
//   int casas[10] = {15, 8, 23, 42, 7, 10, 31, 6, 19, 4};
//
// Escreva int separar(int *v, int n), que deixa os pares no começo e os
// ímpares no fim, NO PRÓPRIO VETOR, e devolve quantos pares há. Use dois
// ponteiros: esq começa no
// primeiro elemento e dir no último. Enquanto esq < dir: avance esq enquanto
// ele for par, recue dir enquanto ele for ímpar e, se os dois ainda não se
// cruzaram, troque *esq com *dir. Mostre o vetor e onde começa o lado ímpar:
//
//   Saída esperada:
//   4 8 6 42 10 7 31 23 19 15
//   Pares: 5 casas; o lado ímpar começa na posição 5
//
// Dicas:
// 1. int *esq = v; int *dir = v + n - 1;
// 2. Os laços internos também precisam do esq < dir, senão eles passam do
//    fim do vetor quando todos são pares (ou todos ímpares).
// 3. Escreva void troca(int *a, int *b) e chame troca(esq, dir): os dois já
//    são endereços.
// 4. Quando o laço termina, esq == dir. Se *esq for par, ele também é do lado
//    par: os pares são (esq - v) + 1; senão, são esq - v.
// 5. A ordem dentro de cada lado muda; isso é normal (é a mesma partição do
//    quicksort, no módulo 13).
// 6. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int casas[10] = {15, 8, 23, 42, 7, 10, 31, 6, 19, 4};
    (void) casas; // apague esta linha quando escrever

    return 0;
}

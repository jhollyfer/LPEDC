// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1904 · ★☆☆ · Quantas vezes a função foi chamada
//
// O programa abaixo gera os subconjuntos dos 4 ingredientes da tapioca
// (queijo, coco, banana, tucumã) com a recursão "leva ou não leva". Ele já
// funciona. Instrumente: conte quantas vezes gera() é chamada (contando a
// primeira) e quantas chamadas chegam ao fim (as folhas), e mostre os dois
// números no fim, sem mudar o resto da saída.
//
//   Saída esperada:
//   { queijo coco banana tucumã }
//   { queijo coco banana }
//   { queijo coco tucumã }
//   { queijo coco }
//   { queijo banana tucumã }
//   { queijo banana }
//   { queijo tucumã }
//   { queijo }
//   { coco banana tucumã }
//   { coco banana }
//   { coco tucumã }
//   { coco }
//   { banana tucumã }
//   { banana }
//   { tucumã }
//   { }
//   Chamadas: 31, folhas: 16
//
// Dicas:
// 1. Uma variável global chamadas++ na primeira linha de gera(); outra,
//    folhas++, dentro do if (i == N).
// 2. A árvore de decisões tem 1 + 2 + 4 + 8 + 16 nós.
// 3. Resposta esperada: 31 chamadas e 16 folhas (2^(n+1) - 1 e 2^n).
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdio.h>

#define N 4

const char *ingr[N] = {"queijo", "coco", "banana", "tucumã"};
int leva[N];

void gera(int i) {
    if (i == N) {
        printf("{");
        for (int j = 0; j < N; j++) {
            if (leva[j]) {
                printf(" %s", ingr[j]);
            }
        }
        printf(" }\n");
        return;
    }
    leva[i] = 1;
    gera(i + 1);
    leva[i] = 0;
    gera(i + 1);
}

int main(void) {
    gera(0);
    return 0;
}

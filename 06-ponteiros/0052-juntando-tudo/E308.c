// 0052 · Juntando tudo: o ranking da feira
// Exercício E308 · ★☆☆
//
// Estenda o programa abaixo para ele imprimir o próprio teste de mesa.
// Escreva a função
//
//   void estado(const char *rotulo, const int *v, const int *p, const char *s)
//
// que mostra o rótulo, os 4 valores de v, em que índice de v o ponteiro p
// está (use p - v) e a string s. Chame estado antes da primeira linha e
// depois de cada uma das quatro linhas do meio.
//
//   Saída esperada:
//   antes     5 10 15 20 | p em v[3] | feira
//   troca     20 10 15 5 | p em v[3] | feira
//   *c = 'E'  20 10 15 5 | p em v[3] | fEira
//   p--       20 10 15 5 | p em v[2] | fEira
//   *p += ... 20 10 25 5 | p em v[2] | fEira
//   20 10 25 5 | fEira | r
//
// Dicas:
// 1. p começa em v[3]; troca(&v[0], p) troca o primeiro com o último.
// 2. c aponta para s[1]; c + 2 é s[3]. p - v dá um ptrdiff_t: mostre com
//    %td.
// 3. Resposta esperada: as seis linhas acima; a última é a do printf que
//    já está no programa.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

void troca(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void) {
    int v[4] = {5, 10, 15, 20};
    int *p = v + 3;
    char s[] = "feira";
    char *c = s + 1;

    troca(&v[0], p);
    *c = 'E';
    p--;
    *p += *(v + 1);

    printf("%d %d %d %d | %s | %c\n", v[0], v[1], v[2], v[3], s, *(c + 2));
    return 0;
}

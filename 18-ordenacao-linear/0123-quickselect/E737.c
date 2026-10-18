// 0123 · Quickselect
// Exercício E737 · ★★★
//
// Ache os bugs. A secretaria da faculdade tem 10001 matrículas, numeradas de
// 1 a 10001 e já em ordem, e quer a matrícula mediana. Para fugir do pior
// caso do vetor ordenado, o programador sorteou o pivô. Mas a resposta está
// errada E o programa ainda faz milhares de separações. São DOIS erros:
// conserte os dois e rode.
//
//   Saída esperada:
//   mediana: 5001 (19 separações)
//
//   Saída que aparece:
//   mediana: 5002 (3849 separações)
//
// Dicas:
// 1. Com 10001 elementos, quantos ficam antes da mediana? Em que posição do
//    vetor (contando de 0) ela está?
// 2. Mostre p, r e o pivô de cada separação. A partir da segunda, o pivô
//    ainda é sorteado?
// 3. Resposta esperada: a mediana fica na posição N / 2 = 5000, e não em
//    (N + 1) / 2 = 5001, que é a posição do 5002. E o sorteio está antes do
//    while: só a primeira separação usa pivô sorteado; nas outras, o pivô
//    volta a ser o último de um pedaço quase ordenado. A troca com o
//    sorteado tem que ficar dentro do laço, antes de cada separa.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

#define N 10001

static long separacoes;
static unsigned semente = 2025;

int sorteia(int p, int r) {
    semente = semente * 1103515245u + 12345u;
    return p + (int) ((semente >> 16) % (unsigned) (r - p + 1));
}

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

// Lomuto: o pivô é SEMPRE o v[r]
int separa(int v[], int p, int r) {
    int pivo = v[r], j = p;
    separacoes++;
    for (int k = p; k < r; k++) {
        if (v[k] <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

int quickselect(int v[], int n, int k) {
    int p = 0, r = n - 1;
    troca(&v[sorteia(p, r)], &v[r]);        // o sorteado vai para o fim
    while (p < r) {
        int j = separa(v, p, r);
        if (j == k) {
            return v[j];
        }
        if (k < j) {
            r = j - 1;
        } else {
            p = j + 1;
        }
    }
    return v[p];
}

int main(void) {
    // números de matrícula 1 a 10001, já em ordem: a mediana é 5001
    int *v = malloc(N * sizeof(int));
    if (v == NULL) {
        return 1;
    }
    for (int i = 0; i < N; i++) {
        v[i] = i + 1;
    }
    int m = quickselect(v, N, (N + 1) / 2); // a do meio
    printf("mediana: %d (%ld separações)\n", m, separacoes);
    free(v);
    return 0;
}

// 0103 · Heapsort
// Exercício E617 · ★★★
//
// Ache o bug. Este heapsort ordena os tempos de uma corrida infantil:
//
//   Saída esperada:
//   1 2 3 4 5 6 7
//
// Mas a saída sai fora de ordem. A fase 2 está certa e o desce também. O
// erro está numa linha só da fase 1. Ache, conserte e rode até sair a
// saída esperada.
//
// Dicas:
// 1. Mostre o vetor logo depois da fase 1 e confira: ele é um heap?
// 2. O desce só funciona se as duas subárvores do nó JÁ forem heaps.
//    Descendo de cima para baixo, quando a raiz desce, os filhos dela já
//    foram arrumados?
// 3. Resposta esperada: o laço da fase 1 vai de 0 até n / 2 - 1 (de cima
//    para baixo). Depois dele o vetor é [3 5 7 4 2 6 1], que não é heap (o 3
//    está acima do 5 e do 7). O certo é de n / 2 - 1 até 0: assim cada pai
//    desce sobre subárvores que já são heaps. Consertado: 1 2 3 4 5 6 7.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void desce(int v[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1] > v[f]) {
            f++;
        }
        if (v[i] >= v[f]) {
            break;
        }
        troca(&v[i], &v[f]);
        i = f;
    }
}

void heapsort(int v[], int n) {
    for (int i = 0; i <= n / 2 - 1; i++) {
        desce(v, n, i);
    }
    for (int fim = n - 1; fim > 0; fim--) {
        troca(&v[0], &v[fim]);
        desce(v, fim, 0);
    }
}

int main(void) {
    int tempos[] = {1, 2, 3, 4, 5, 6, 7};
    heapsort(tempos, 7);
    for (int i = 0; i < 7; i++) {
        printf(i == 0 ? "%d" : " %d", tempos[i]);
    }
    printf("\n");
    return 0;
}

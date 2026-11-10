// 0095 · Quick sort
// Exercício E568 · ★★☆
//
// Este quick sort deveria ordenar os andares das entregas do prédio: 4, 9, 2,
// 7. Ele tem UM erro, de propósito, numa única linha. Rode: o programa morre
// e o AddressSanitizer fala em "stack-overflow". Ache a linha que faz a
// recursão nunca terminar, conserte e rode de novo.
//
//   Saída esperada (depois de consertar):
//   2 4 7 9
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int separa(int v[], int p, int r) {
    int pivo = v[r], j = p;
    for (int k = p; k < r; k++) {
        if (v[k] <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

void quick_sort(int v[], int p, int r) {
    if (p >= r) {
        return;
    }
    int j = separa(v, p, r);
    quick_sort(v, p, j);
    quick_sort(v, j + 1, r);
}

int main(void) {
    int andares[] = {4, 9, 2, 7};
    quick_sort(andares, 0, 3);
    for (int i = 0; i < 4; i++) {
        printf("%d ", andares[i]);
    }
    printf("\n");
    return 0;
}

// 0100 · Quick sort
// Exercício E598 · ★★☆
//
// Resposta: a chamada da esquerda é quick_sort(v, p, j), que inclui o pivô.
// Na primeira separação, [4 9 2 7] vira [4 2 7 9] com j = 2, e a chamada
// quick_sort(v, 0, 2) recebe [4 2 7], onde o 7 é o pivô e o maior. A
// separação devolve j = 2 = r, e quick_sort(v, 0, 2) chama quick_sort(v, 0, 2)
// de novo, para sempre: estouro de pilha (stack-overflow). Conserto:
// quick_sort(v, p, j - 1), deixando o pivô de fora.

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
    quick_sort(v, p, j - 1);
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

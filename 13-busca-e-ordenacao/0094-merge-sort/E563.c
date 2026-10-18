// 0094 · Merge sort
// Exercício E563 · ★★★
//
// Este merge sort deveria ordenar as distâncias de corrida da semana, em km:
// 21, 5, 42, 10, 15, 3. Ele compila sem aviso, roda sem reclamação do
// sanitizer e mostra
//
//   10 10 15 3 15 3
//
// Números somem e outros se repetem. Há UM erro, de propósito, numa única
// linha. Ache, conserte e rode de novo.
//
//   Saída esperada (depois de consertar):
//   3 5 10 15 21 42
//
// Dicas:
// 1. Coloque um printf no fim de intercala mostrando p, r e o vetor inteiro.
// 2. A primeira intercalação junta [1, 2) com [2, 3), os números 5 e 42.
//    Depois dela, em que gavetas o 5 e o 42 aparecem? E o 21, onde foi parar?
// 3. Para onde vai o conteúdo do rascunho na cópia de volta?
// 4. Resposta esperada: a cópia de volta faz v[k] = w[k], que escreve no
//    começo do vetor; o certo é v[p + k] = w[k]. Só a intercalação com
//    p = 0 cai no lugar certo; as outras escrevem por cima de v[0..].
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

void intercala(int v[], int w[], int p, int q, int r) {
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            w[k++] = v[j++];
        }
    }
    while (i < q) {
        w[k++] = v[i++];
    }
    while (j < r) {
        w[k++] = v[j++];
    }
    for (k = 0; k < r - p; k++) {
        v[k] = w[k];
    }
}

void merge_sort(int v[], int w[], int p, int r) {
    if (r - p < 2) {
        return;
    }
    int q = p + (r - p) / 2;
    merge_sort(v, w, p, q);
    merge_sort(v, w, q, r);
    intercala(v, w, p, q, r);
}

int main(void) {
    int km[] = {21, 5, 42, 10, 15, 3};
    int n = 6;
    int *w = malloc(n * sizeof *w);
    if (w == NULL) {
        return 1;
    }
    merge_sort(km, w, 0, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", km[i]);
    }
    printf("\n");
    free(w);
    return 0;
}

// 0123 · Quickselect
// Exercício E735 · ★★☆
//
// Com um número PAR de valores, a mediana é a média dos dois do meio. O app
// de entregas quer a mediana dos tempos de 10 entregas, sem ordenar o vetor.
// Escreva double mediana(int v[], int n), que funciona para n par e ímpar,
// usando UM quickselect só. Confira no fim com o qsort.
//
//   Saída esperada:
//   10 entregas: mediana 39.5 min
//   9 entregas:  mediana 41.0 min
//   conferindo: 38 e 41 no meio
//
// Dicas:
// 1. n ímpar: é o quickselect em k = n / 2, como no texto.
// 2. n par: os do meio estão nas posições n/2 - 1 e n/2. Rode o quickselect
//    em k = n/2 - 1. Depois disso, tudo à direita de k é maior ou igual a
//    v[k]: o outro do meio é o MENOR desse lado, e um laço simples acha.
// 3. Divida por 2.0, não por 2: (38 + 41) / 2 em int dá 39.
// 4. A compara do qsort já está no arquivo: qsort(v, 10, sizeof(int), compara).
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

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

int quickselect(int v[], int n, int k) {
    int p = 0, r = n - 1;
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
    // tempos de entrega do app, em minutos
    int tempos[] = {42, 28, 55, 31, 47, 35, 61, 41, 26, 38};
    int impar[] = {42, 28, 55, 31, 47, 35, 61, 41, 26};

    (void) tempos; // apague estas duas linhas
    (void) impar;

    return 0;
}

// 0132 · Inversões e subvetor de soma máxima
// Exercício E788 · ★☆☆
//
// Oito candidatos entregaram a prova e, na ordem de entrega, tiveram as
// colocações 6 2 8 4 1 7 3 5. Quantas inversões tem esse vetor? O programa
// abaixo é o merge sort que conta inversões, mas falta a linha mais
// importante, no lugar marcado com "COMPLETE AQUI". Hoje ele ordena e
// mostra 0 inversões.
//
//   Saída esperada:
//   Inversões: 15
//   Ordenado: 1 2 3 4 5 6 7 8
//
// Dicas:
// 1. Você está no else: v[j], da metade direita, é menor que v[i].
// 2. A metade esquerda está ordenada. Com quantos elementos dela o v[j]
//    forma inversão? Eles vão de v[i] até v[q - 1].
// 3. Resposta esperada: inv += q - i; e a saída acima. Confira com o
//    programa de força bruta do E787.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

int intercala(int v[], int w[], int p, int q, int r) {
    int inv = 0;
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            // COMPLETE AQUI
            w[k++] = v[j++];
        }
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (k = 0; k < r - p; k++) {
        v[p + k] = w[k];
    }
    return inv;
}

int conta(int v[], int w[], int p, int r) {
    if (r - p < 2) {
        return 0;
    }
    int q = p + (r - p) / 2;
    return conta(v, w, p, q) + conta(v, w, q, r) + intercala(v, w, p, q, r);
}

int main(void) {
    // posição de cada candidato na prova, na ordem em que entregaram
    int pos[] = {6, 2, 8, 4, 1, 7, 3, 5};
    int w[8];
    int total = conta(pos, w, 0, 8);
    printf("Inversões: %d\n", total);
    printf("Ordenado:");
    for (int i = 0; i < 8; i++) {
        printf(" %d", pos[i]);
    }
    printf("\n");
    return 0;
}

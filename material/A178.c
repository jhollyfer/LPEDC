// A178 · A sentinela no fim da fila

#include <stdio.h>

#define N 6

// busca comum: a cada volta, duas perguntas (i < n? e v[i] == x?)
int busca_comum(const int v[], int n, int x, int *perguntas) {
    *perguntas = 0;
    for (int i = 0; i < n; i++) {
        *perguntas += 2;          // i < n  e  v[i] == x
        if (v[i] == x) {
            return i;
        }
    }
    *perguntas += 1;              // o último i < n, que deu falso
    return -1;
}

// busca com sentinela: v precisa ter uma gaveta livre em v[n]
int busca_sentinela(int v[], int n, int x, int *perguntas) {
    v[n] = x;                     // a sentinela: agora o laço sempre acha
    int i = 0;
    *perguntas = 1;               // o primeiro v[i] != x
    while (v[i] != x) {
        i++;
        (*perguntas)++;
    }
    (*perguntas)++;               // i < n: achou a de verdade ou a sentinela?
    return i < n ? i : -1;
}

int main(void) {
    int matriculas[N + 1] = {4172, 3305, 8821, 1290, 5567, 7034}; // v[6] fica livre
    int procuradas[] = {4172, 7034, 9999};
    int p1, p2;

    printf("chave  posição  comum  sentinela\n");
    for (int k = 0; k < 3; k++) {
        int x = procuradas[k];
        int pos = busca_comum(matriculas, N, x, &p1);
        busca_sentinela(matriculas, N, x, &p2);
        printf("%5d  %7d  %5d  %9d\n", x, pos, p1, p2);
    }
    return 0;
}
// Saída:
// chave  posição  comum  sentinela
//  4172        0      2          2
//  7034        5     12          7
//  9999       -1     13          8

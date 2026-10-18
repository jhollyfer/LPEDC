// A182 · A bandeirinha que economiza passadas

#include <stdio.h>
#include <stdbool.h>

// versão básica: sempre faz todas as passadas
int bubble_basico(int v[], int n) {
    int comparacoes = 0;
    for (int passada = 1; passada < n; passada++) {
        for (int j = 0; j < n - passada; j++) {
            comparacoes++;
            if (v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
    return comparacoes;
}

// com a bandeira: para na primeira passada sem troca
int bubble_bandeira(int v[], int n) {
    int comparacoes = 0;
    bool trocou = true;
    for (int passada = 1; passada < n && trocou; passada++) {
        trocou = false;
        for (int j = 0; j < n - passada; j++) {
            comparacoes++;
            if (v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                trocou = true;
            }
        }
    }
    return comparacoes;
}

int main(void) {
    // ranking quase em ordem: só o último está fora do lugar
    int a[] = {12, 15, 21, 30, 34, 47, 52, 49};
    int b[] = {12, 15, 21, 30, 34, 47, 52, 49};
    // ao contrário: o pior caso
    int c[] = {52, 49, 47, 34, 30, 21, 15, 12};
    int d[] = {52, 49, 47, 34, 30, 21, 15, 12};

    printf("quase ordenado: básico %d, com bandeira %d\n",
           bubble_basico(a, 8), bubble_bandeira(b, 8));
    printf("invertido:      básico %d, com bandeira %d\n",
           bubble_basico(c, 8), bubble_bandeira(d, 8));
    return 0;
}
// Saída:
// quase ordenado: básico 28, com bandeira 13
// invertido:      básico 28, com bandeira 28

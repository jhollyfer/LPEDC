// 0168 · Complexidade espacial
// Exercício E1007 · ★★★

#include <stdio.h>

// deixa só uma cópia de cada placa no começo do vetor (ordenado) e devolve
// quantas sobraram; dois índices, nenhum vetor extra: Θ(1) de espaço
int sem_repetidas(int placas[], int n) {
    if (n == 0) {
        return 0;
    }
    int escreve = 1;
    for (int le = 1; le < n; le++) {
        if (placas[le] != placas[escreve - 1]) {
            placas[escreve] = placas[le];
            escreve++;
        }
    }
    return escreve;
}

int main(void) {
    int placas[12] = {1020, 1020, 1033, 1047, 1047, 1047, 1050, 1062, 1062, 1071, 1088, 1088};
    int m = sem_repetidas(placas, 12);
    printf("12 placas, %d distintas:", m);
    for (int i = 0; i < m; i++) {
        printf(" %d", placas[i]);
    }
    printf("\n");
    return 0;
}

// Lista · Módulo 06 · Ponteiros
// Exercício P0621 · ★★★ · O ranking do processo seletivo

#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
    const int *x = a; // x[0] inscrição, x[1] nota, x[2] idade
    const int *y = b;
    if (x[1] != y[1]) {
        return y[1] - x[1]; // nota maior primeiro
    }
    if (x[2] != y[2]) {
        return y[2] - x[2]; // mais velho primeiro
    }
    return x[0] - y[0];     // menor inscrição primeiro
}

int main(void) {
    int cand[7][3] = {{1043, 82, 29}, {1007, 91, 33}, {1120, 82, 41},
                      {1088, 75, 26}, {1015, 91, 33}, {1102, 82, 41},
                      {1061, 68, 52}};

    qsort(cand, 7, sizeof cand[0], compara);
    printf("Pos Inscr Nota Idade\n");
    for (int i = 0; i < 7; i++) {
        printf("%2dº %5d %4d %5d\n", i + 1, cand[i][0], cand[i][1], cand[i][2]);
    }
    return 0;
}

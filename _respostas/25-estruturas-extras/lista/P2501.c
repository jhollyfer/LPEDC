// Lista · Módulo 25 · Estruturas especiais
// Exercício P2501 · ★☆☆ · As poltronas ocupadas do cinema

#include <stdio.h>

#define L 6
#define C 10

typedef struct {
    int lin, col, valor;
} Tripla;

int main(void) {
    // idade de quem comprou cada poltrona; 0 = vazia
    int sala[L][C] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 34, 31, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 12, 40, 41, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {70, 0, 0, 0, 0, 0, 0, 0, 0, 68},
    };
    Tripla t[L * C];
    int n = 0;
    for (int i = 0; i < L; i++)
        for (int j = 0; j < C; j++)
            if (sala[i][j] != 0) t[n++] = (Tripla){i, j, sala[i][j]};

    for (int k = 0; k < n; k++) printf("(%d, %d, %d)\n", t[k].lin, t[k].col, t[k].valor);
    printf("Ocupadas: %d de %d\n", n, L * C);
    printf("Números guardados: matriz %d, triplas %d\n", L * C, 3 * n);
    printf("As triplas compensam enquanto houver menos de %d ocupadas\n", L * C / 3);
    return 0;
}

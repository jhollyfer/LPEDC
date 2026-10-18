// A323 · As entregas em triplas

#include <stdio.h>
#include <stdlib.h>

#define LIN 5 // entregadores
#define COL 6 // bairros

typedef struct {
    int lin, col, valor;
} Tripla;

// ordem de leitura: por linha e, dentro da linha, por coluna
int compara(const void *a, const void *b) {
    const Tripla *x = a;
    const Tripla *y = b;
    if (x->lin != y->lin) {
        return x->lin - y->lin;
    }
    return x->col - y->col;
}

int main(void) {
    int entregas[LIN][COL] = {
        {0, 0, 7, 0, 0, 0},
        {3, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0},
        {0, 4, 1, 0, 0, 0},
        {0, 0, 5, 0, 6, 0},
    };

    // compactar: uma tripla para cada valor diferente de zero
    Tripla t[LIN * COL];
    int n = 0;
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            if (entregas[i][j] != 0) {
                t[n++] = (Tripla){i, j, entregas[i][j]};
            }
        }
    }
    printf("%d triplas:", n);
    for (int k = 0; k < n; k++) {
        printf(" (%d,%d,%d)", t[k].lin, t[k].col, t[k].valor);
    }
    printf("\nCheia: %zu bytes; triplas: %zu bytes\n", sizeof entregas, n * sizeof(Tripla));

    // transpor: troca linha com coluna e reordena (agora bairro x entregador)
    for (int k = 0; k < n; k++) {
        int aux = t[k].lin;
        t[k].lin = t[k].col;
        t[k].col = aux;
    }
    qsort(t, n, sizeof(Tripla), compara);

    // as triplas de um mesmo bairro ficaram juntas: uma passada soma cada um
    printf("Entregas por bairro:\n"); // bairro sem tripla não aparece
    for (int k = 0; k < n;) {
        int bairro = t[k].lin, soma = 0;
        printf("  bairro %d:", bairro);
        while (k < n && t[k].lin == bairro) {
            printf(" e%d=%d", t[k].col, t[k].valor);
            soma += t[k].valor;
            k++;
        }
        printf(" -> %d\n", soma);
    }
    return 0;
}
// Saída:
// 7 triplas: (0,2,7) (1,0,3) (1,5,2) (3,1,4) (3,2,1) (4,2,5) (4,4,6)
// Cheia: 120 bytes; triplas: 84 bytes
// Entregas por bairro:
//   bairro 0: e1=3 -> 3
//   bairro 1: e3=4 -> 4
//   bairro 2: e0=7 e3=1 e4=5 -> 13
//   bairro 4: e4=6 -> 6
//   bairro 5: e1=2 -> 2

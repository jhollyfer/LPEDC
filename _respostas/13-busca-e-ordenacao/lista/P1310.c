// Lista · Módulo 13 · Busca e ordenação
// Exercício P1310 · ★☆☆ · Todas as vezes que o ônibus passou

#include <stdio.h>

// guarda em pos[] as posições de x e devolve quantas achou
int todas(const int v[], int n, int x, int pos[]) {
    int achou = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == x) {
            pos[achou++] = i;
        }
    }
    return achou;
}

int main(void) {
    int linhas[] = {302, 115, 302, 640, 115, 302, 88, 640, 302, 115};
    int n = 10;
    int consultas[] = {302, 640, 500};
    int pos[10];

    for (int k = 0; k < 3; k++) {
        int q = todas(linhas, n, consultas[k], pos);
        printf("linha %d: %d vez(es)", consultas[k], q);
        if (q > 0) {
            printf(", posições");
            for (int i = 0; i < q; i++) {
                printf(" %d", pos[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

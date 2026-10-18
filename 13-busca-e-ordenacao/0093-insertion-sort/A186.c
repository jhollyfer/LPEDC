// A186 · Quase em ordem custa quase nada

#include <stdio.h>

// insertion sort que devolve as comparações e os deslocamentos
void insertion_sort(int v[], int n, int *comparacoes, int *deslocamentos) {
    *comparacoes = 0;
    *deslocamentos = 0;
    for (int j = 1; j < n; j++) {
        int x = v[j];
        int i = j - 1;
        while (i >= 0) {
            (*comparacoes)++;
            if (v[i] <= x) {
                break;                  // achou o lugar: para de empurrar
            }
            v[i + 1] = v[i];
            (*deslocamentos)++;
            i--;
        }
        v[i + 1] = x;
    }
}

void testa(const char *nome, int v[], int n) {
    int c, d;
    insertion_sort(v, n, &c, &d);
    printf("%-15s %2d comparações, %2d deslocamentos\n", nome, c, d);
}

int main(void) {
    // senhas de atendimento, n = 8
    int ordenado[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int quase[] = {10, 20, 40, 30, 50, 60, 80, 70};  // dois pares trocados
    int invertido[] = {80, 70, 60, 50, 40, 30, 20, 10};

    testa("ordenado:", ordenado, 8);
    testa("quase ordenado:", quase, 8);
    testa("invertido:", invertido, 8);
    return 0;
}
// Saída:
// ordenado:        7 comparações,  0 deslocamentos
// quase ordenado:  9 comparações,  2 deslocamentos
// invertido:      28 comparações, 28 deslocamentos

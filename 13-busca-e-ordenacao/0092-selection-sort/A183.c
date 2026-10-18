// A183 · Selection não se importa com a ordem de entrada

#include <stdio.h>

// selection sort que devolve comparações e trocas
void selection_sort(int v[], int n, int *comparacoes, int *trocas) {
    *comparacoes = 0;
    *trocas = 0;
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            (*comparacoes)++;           // o laço de dentro roda inteiro, sempre
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        if (menor != i) {
            int aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
            (*trocas)++;
        }
    }
}

void testa(const char *nome, int v[], int n) {
    int c, t;
    selection_sort(v, n, &c, &t);
    printf("%-11s %2d comparações, %d trocas\n", nome, c, t);
}

int main(void) {
    // pesos de caixas de mudança (kg): trocar caixa é caro, olhar é barato
    int ordenado[] = {5, 8, 12, 20, 25, 31};
    int invertido[] = {31, 25, 20, 12, 8, 5};
    int misturado[] = {20, 5, 31, 8, 25, 12};
    int menor_no_fim[] = {8, 12, 20, 25, 31, 5};

    testa("ordenado:", ordenado, 6);
    testa("invertido:", invertido, 6);
    testa("misturado:", misturado, 6);
    testa("5 no fim:", menor_no_fim, 6);
    return 0;
}
// Saída (comparações: sempre 5+4+3+2+1 = 15; trocas: nunca mais que n - 1 = 5):
// ordenado:   15 comparações, 0 trocas
// invertido:  15 comparações, 3 trocas
// misturado:  15 comparações, 3 trocas
// 5 no fim:   15 comparações, 5 trocas

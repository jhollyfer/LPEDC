// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0515 · ★★☆ · Tirar da vitrine o que acabou

#include <stdio.h>

int compactar(int cod[], int est[], int n) {
    int k = 0; // próxima posição livre
    for (int i = 0; i < n; i++) {
        if (est[i] != 0) {
            cod[k] = cod[i];
            est[k] = est[i];
            k++;
        }
    }
    return k;
}

void mostrar(const int cod[], const int est[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:%d%s", cod[i], est[i], i < n - 1 ? " " : "\n");
    }
}

int main(void) {
    int codigo[9]  = {11, 12, 13, 14, 15, 16, 17, 18, 19};
    int estoque[9] = { 4,  0,  7,  0,  0,  2,  9,  0,  1};
    int n = 9;

    printf("Antes (%d):  ", n);
    mostrar(codigo, estoque, n);
    n = compactar(codigo, estoque, n);
    printf("Depois (%d): ", n);
    mostrar(codigo, estoque, n);
    return 0;
}

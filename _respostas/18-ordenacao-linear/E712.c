// 0119 · Shell sort
// Exercício E712 · ★★☆

#include <stdio.h>
#include <stdbool.h>

// toda fileira de passo h está em ordem?
bool esta_h_ordenado(const int v[], int n, int h) {
    for (int i = h; i < n; i++) {
        if (v[i - h] > v[i]) {
            return false;
        }
    }
    return true;
}

void confere(const int v[], int n) {
    int testes[] = {13, 4, 1};
    for (int t = 0; t < 3; t++) {
        printf("%s%d-ordenado? %s", t == 0 ? " " : ", ", testes[t],
               esta_h_ordenado(v, n, testes[t]) ? "sim" : "não");
    }
    printf("\n");
}

int main(void) {
    int v[40];
    int n = 40;
    for (int i = 0; i < n; i++) {
        v[i] = (i * 17 + 5) % 40; // os números de 0 a 39, embaralhados
    }

    printf("início:");
    confere(v, n);
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }
    for (; h >= 1; h /= 3) {
        for (int i = h; i < n; i++) {
            int x = v[i];
            int j = i;
            while (j >= h && v[j - h] > x) {
                v[j] = v[j - h];
                j -= h;
            }
            v[j] = x;
        }
        printf("h = %2d:", h);
        confere(v, n);
    }
    return 0;
}

// 0119 · Shell sort
// Exercício E710 · ★☆☆

#include <stdio.h>

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
}

// insertion sort entre os elementos que estão a h casas de distância
void rodada(int v[], int n, int h) {
    for (int i = h; i < n; i++) {
        int x = v[i];
        int j = i;
        while (j >= h && v[j - h] > x) {
            v[j] = v[j - h];
            j -= h;
        }
        v[j] = x;
    }
}

int main(void) {
    int idades[] = {31, 19, 27, 22, 35, 18, 24, 29, 20, 33, 26};
    int n = 11;
    int saltos[] = {5, 3, 1};

    printf("início:");
    mostra(idades, n);
    for (int s = 0; s < 3; s++) {
        rodada(idades, n, saltos[s]);
        printf("h = %d:", saltos[s]);
        mostra(idades, n);
    }
    return 0;
}

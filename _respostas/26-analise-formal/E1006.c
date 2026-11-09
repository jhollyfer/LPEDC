// 0168 · Complexidade espacial
// Exercício E1006 · ★★☆

#include <stdio.h>

// inverte v[ini..fim] no lugar
void inverte(int v[], int ini, int fim) {
    while (ini < fim) {
        int tmp = v[ini];
        v[ini] = v[fim];
        v[fim] = tmp;
        ini++;
        fim--;
    }
}

// gira k posições para a direita com três inversões: Θ(n) tempo, Θ(1) extra
void gira(int v[], int n, int k) {
    k %= n;
    inverte(v, 0, n - 1);
    inverte(v, 0, k - 1);
    inverte(v, k, n - 1);
}

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%d" : " %d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int plantao[7] = {1, 2, 3, 4, 5, 6, 7};
    gira(plantao, 7, 3);
    mostra(plantao, 7);
    gira(plantao, 7, 11);                // 11 = 7 + 4
    mostra(plantao, 7);
    return 0;
}

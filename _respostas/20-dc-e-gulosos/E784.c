// 0131 · Divisão e conquista
// Exercício E784 · ★★☆

#include <stdio.h>

static int olhadas = 0;

// v[ini..fim] sobe e depois desce; devolve o índice do ponto mais alto
int pico(const int v[], int ini, int fim) {
    if (ini == fim) {
        return ini;                       // sobrou um ponto: é o pico
    }
    int meio = ini + (fim - ini) / 2;
    olhadas++;
    if (v[meio] < v[meio + 1]) {
        return pico(v, meio + 1, fim);    // ainda subindo: o pico está à direita
    }
    return pico(v, ini, meio);            // já descendo (ou no topo): à esquerda, com o meio
}

int main(void) {
    int altitude[] = {820, 905, 1010, 1180, 1340, 1415, 1390, 1250, 1100, 960, 870};
    int n = 11;
    int k = pico(altitude, 0, n - 1);
    printf("Pico: %d m no km %d\n", altitude[k], k);
    printf("Comparações: %d\n", olhadas);
    return 0;
}

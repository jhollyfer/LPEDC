// Lista · Módulo 13 · Busca e ordenação
// Exercício P1326 · ★★★ · Busca binária na escala que deu a volta

#include <stdio.h>

// posição do menor elemento (o "começo" da escala)
int ponto_de_giro(const int v[], int n) {
    int ini = 0, fim = n - 1;
    while (ini < fim) {
        int meio = ini + (fim - ini) / 2;
        if (v[meio] > v[fim]) {
            ini = meio + 1; // o giro está à direita do meio
        } else {
            fim = meio;     // o meio pode ser o próprio menor
        }
    }
    return ini;
}

int busca(const int v[], int ini, int fim, int x, int *voltas) {
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        (*voltas)++;
        if (v[meio] == x) {
            return meio;
        }
        if (v[meio] < x) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int busca_girada(const int v[], int n, int x, int *voltas) {
    int g = ponto_de_giro(v, n);
    *voltas = 0;
    if (g > 0 && x >= v[0]) {
        return busca(v, 0, g - 1, x, voltas);
    }
    return busca(v, g, n - 1, x, voltas);
}

int main(void) {
    // senhas do plantão: a contagem passou de 99 e recomeçou
    int escala[] = {61, 67, 72, 80, 94, 3, 9, 18, 26, 33, 40, 52};
    int n = 12;
    int consultas[] = {80, 3, 33, 61, 52, 50};

    printf("giro na posição %d\n", ponto_de_giro(escala, n));
    for (int k = 0; k < 6; k++) {
        int voltas;
        int pos = busca_girada(escala, n, consultas[k], &voltas);
        printf("%d: posição %d (voltas: %d)\n", consultas[k], pos, voltas);
    }
    return 0;
}

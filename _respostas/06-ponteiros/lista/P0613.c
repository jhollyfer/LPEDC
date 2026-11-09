// Lista · Módulo 06 · Ponteiros
// Exercício P0613 · ★★☆ · O filtro do extrato do Pix

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool entrada(int x) { return x > 0; }
bool saida_grande(int x) { return x < -100; }
bool miudo(int x) { return abs(x) < 100; }

int filtrar(const int *v, int n, int *saida, bool (*passa)(int)) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (passa(v[i])) {
            saida[k++] = v[i];
        }
    }
    return k;
}

void relatorio(const char *nome, const int *v, int n, bool (*passa)(int)) {
    int saida[10];
    int k = filtrar(v, n, saida, passa);
    int soma = 0;
    printf("%s:", nome);
    for (int i = 0; i < k; i++) {
        printf(" %d", saida[i]);
        soma += saida[i];
    }
    printf(" (%d itens, soma %d)\n", k, soma);
}

int main(void) {
    int pix[10] = {1500, -89, -230, 45, -12, 3200, -1450, -75, 300, -640};

    relatorio("Entradas", pix, 10, entrada);
    relatorio("Saídas grandes", pix, 10, saida_grande);
    relatorio("Miúdos", pix, 10, miudo);
    return 0;
}

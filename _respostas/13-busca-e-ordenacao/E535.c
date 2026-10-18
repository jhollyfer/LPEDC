// 0090 · Busca binária
// Exercício E535 · ★☆☆

#include <stdio.h>

void procura(const int v[], int n, int x) {
    int ini = 0, fim = n - 1;
    int voltas = 0;
    printf("Procurando %d\n", x);
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        voltas++;
        printf("ini=%d fim=%d meio=%d (%d)\n", ini, fim, meio, v[meio]);
        if (v[meio] == x) {
            printf("achou na posição %d em %d voltas\n", meio, voltas);
            return;
        }
        if (v[meio] < x) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    printf("não achou em %d voltas (parou com ini=%d fim=%d)\n", voltas, ini, fim);
}

int main(void) {
    int armarios[] = {4, 9, 13, 21, 30, 38, 47, 55, 62};
    procura(armarios, 9, 47);
    procura(armarios, 9, 5);
    procura(armarios, 9, 62);
    return 0;
}

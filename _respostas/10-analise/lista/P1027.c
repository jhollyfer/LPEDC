// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1027 · ★★★ · O topo da trilha em O(log n)

#include <assert.h>
#include <stdio.h>

int pico_sequencial(const int v[], int n, int *comp) {
    *comp = 0;
    for (int i = 0; i < n - 1; i++) {
        (*comp)++;
        if (v[i] >= v[i + 1]) {
            return i;
        }
    }
    return n - 1;
}

int pico_binario(const int v[], int n, int *comp) {
    int ini = 0, fim = n - 1;
    *comp = 0;
    while (ini < fim) {
        assert((ini == 0 || v[ini - 1] < v[ini]) && (fim == n - 1 || v[fim] >= v[fim + 1]));
        (*comp)++;
        int meio = (ini + fim) / 2;
        if (v[meio] < v[meio + 1]) {
            ini = meio + 1; // sobe para a direita: há pico lá
        } else {
            fim = meio;
        }
    }
    return ini;
}

void testa(const char *nome, const int v[], int n) {
    int cb, cs;
    int pb = pico_binario(v, n, &cb);
    int ps = pico_sequencial(v, n, &cs);
    (void) ps;
    printf("%s: pico na posição %d (%d m), binária %d, sequencial %d\n", nome, pb, v[pb], cb, cs);
}

int main(void) {
    int trilha[10] = {120, 340, 560, 610, 580, 430, 470, 520, 300, 150};
    int rampa[16];
    for (int i = 0; i < 16; i++) {
        rampa[i] = 100 * (i + 1);
    }
    testa("Trilha", trilha, 10);
    testa("Rampa", rampa, 16);
    return 0;
}

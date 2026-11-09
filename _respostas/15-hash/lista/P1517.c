// Lista · Módulo 15 · Tabelas hash
// Exercício P1517 · ★★☆ · O primeiro crachá repetido na catraca

#include <stdio.h>
#include <stdbool.h>

#define M 17
#define VAZIO -1

// devolve true se k já estava; senão, guarda k
bool ja_viu(int t[], int k) {
    int pos = k % M;
    while (t[pos] != VAZIO) {
        if (t[pos] == k) {
            return true;
        }
        pos = (pos + 1) % M;
    }
    t[pos] = k;
    return false;
}

int main(void) {
    int passagens[] = {4821, 3307, 9954, 1220, 6638, 3307, 4821, 7012, 9954};
    int n = 9;
    int t[M];
    for (int i = 0; i < M; i++) {
        t[i] = VAZIO;
    }

    for (int i = 0; i < n; i++) {
        if (ja_viu(t, passagens[i])) {
            printf("primeiro repetido: %d, na passagem %d\n", passagens[i], i + 1);
            return 0;
        }
    }
    printf("nenhum repetido\n");
    return 0;
}

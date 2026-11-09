// 0186 · P e NP
// Exercício E1113 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define NV 4
#define NC 5

const char *nomes[NV + 1] = {"", "Ana", "Beto", "Caio", "Davi"};
const int formula[NC][3] = {{1, 2, 0}, {-1, -3, 0}, {3, 4, 0}, {-2, 4, 0}, {-4, -1, 3}};

bool satisfaz(const bool vai[]) {
    for (int c = 0; c < NC; c++) {
        bool algum = false;
        for (int i = 0; i < 3 && formula[c][i] != 0; i++) {
            int lit = formula[c][i];
            if (lit > 0 ? vai[lit] : !vai[-lit]) algum = true;
        }
        if (!algum) return false;
    }
    return true;
}

int main(void) {
    int total = 0;
    for (int m = 0; m < (1 << NV); m++) {
        bool vai[NV + 1] = {false};
        for (int v = 1; v <= NV; v++) vai[v] = (m >> (v - 1)) & 1;
        if (!satisfaz(vai)) continue;
        total++;
        printf("Grupo %d:", total);
        for (int v = 1; v <= NV; v++)
            if (vai[v]) printf(" %s", nomes[v]);
        printf("\n");
    }
    printf("Total: %d de %d atribuições\n", total, 1 << NV);
    return 0;
}

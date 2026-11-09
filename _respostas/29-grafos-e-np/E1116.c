// 0186 · P e NP
// Exercício E1116 · ★★★

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
        if (!algum) return false; // uma cláusula falsa derruba a fórmula inteira
    }
    return true; // só depois de conferir TODAS
}

int main(void) {
    bool palpites[3][NV + 1] = {
        {false, true, false, false, true}, // Ana e Davi
        {false, false, true, false, true}, // Beto e Davi
        {false, true, true, true, false},  // Ana, Beto e Caio
    };
    for (int p = 0; p < 3; p++) {
        printf("Palpite %d:", p + 1);
        for (int v = 1; v <= NV; v++)
            if (palpites[p][v]) printf(" %s", nomes[v]);
        printf(" -> %s\n", satisfaz(palpites[p]) ? "satisfaz" : "não satisfaz");
    }
    return 0;
}

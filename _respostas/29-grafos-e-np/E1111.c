// 0186 · P e NP
// Exercício E1111 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define NV 3
#define NC 4

// x1 = abrir sábado, x2 = abrir domingo, x3 = contratar folguista
const int formula[NC][3] = {{1, 2, 0}, {-1, 3, 0}, {-2, 3, 0}, {-1, -2, -3}};

// devolve 0 se todas as cláusulas são verdadeiras, ou o número da primeira falsa
int primeira_falsa(const bool x[]) {
    for (int c = 0; c < NC; c++) {
        bool algum = false;
        for (int i = 0; i < 3 && formula[c][i] != 0; i++) {
            int lit = formula[c][i];
            if (lit > 0 ? x[lit] : !x[-lit]) algum = true;
        }
        if (!algum) return c + 1;
    }
    return 0;
}

void testa(int numero, const bool x[]) {
    int c = primeira_falsa(x);
    if (c == 0) printf("Atribuição %d: satisfaz\n", numero);
    else printf("Atribuição %d: não satisfaz (cláusula %d falsa)\n", numero, c);
}

int main(void) {
    bool a[NV + 1] = {false, true, false, true};
    bool b[NV + 1] = {false, true, true, true};
    bool c[NV + 1] = {false, false, true, false};
    testa(1, a);
    testa(2, b);
    testa(3, c);
    return 0;
}

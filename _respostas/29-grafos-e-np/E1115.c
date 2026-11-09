// 0186 · P e NP
// Exercício E1115 · ★★★

#include <stdbool.h>
#include <stdio.h>

#define K 5            // literais da cláusula longa: x1 ou x2 ou x3 ou x4 ou x5
#define NY (K - 3)     // variáveis novas y1..y(K-3)
#define NC (K - 2)     // cláusulas de 3 literais

int nova[NC][3]; // literais: 1..K são os x; K+1..K+NY são os y

void transforma(void) {
    // (x1 ou x2 ou y1), (não y1 ou x3 ou y2), ..., (não y(K-3) ou x(K-1) ou xK)
    nova[0][0] = 1, nova[0][1] = 2, nova[0][2] = K + 1;
    for (int c = 1; c < NC - 1; c++) {
        nova[c][0] = -(K + c);
        nova[c][1] = c + 2;
        nova[c][2] = K + c + 1;
    }
    nova[NC - 1][0] = -(K + NY);
    nova[NC - 1][1] = K - 1;
    nova[NC - 1][2] = K;
}

void mostra_literal(int lit) {
    int v = lit > 0 ? lit : -lit;
    printf("%s%c%d", lit < 0 ? "não " : "", v <= K ? 'x' : 'y', v <= K ? v : v - K);
}

bool vale(const bool val[], int lit) {
    return lit > 0 ? val[lit] : !val[-lit];
}

int main(void) {
    transforma();
    for (int c = 0; c < NC; c++) {
        printf("(");
        for (int i = 0; i < 3; i++) {
            mostra_literal(nova[c][i]);
            printf("%s", i < 2 ? " ou " : ")\n");
        }
    }

    int iguais = 0;
    for (int mx = 0; mx < (1 << K); mx++) {
        bool val[K + NY + 1] = {false};
        bool original = false;
        for (int v = 1; v <= K; v++) {
            val[v] = (mx >> (v - 1)) & 1;
            if (val[v]) original = true;
        }
        bool existe_y = false; // alguma escolha dos y satisfaz as 3 cláusulas?
        for (int my = 0; my < (1 << NY) && !existe_y; my++) {
            for (int y = 1; y <= NY; y++) val[K + y] = (my >> (y - 1)) & 1;
            bool todas = true;
            for (int c = 0; c < NC; c++)
                if (!vale(val, nova[c][0]) && !vale(val, nova[c][1]) && !vale(val, nova[c][2])) todas = false;
            existe_y = todas;
        }
        if (original == existe_y) iguais++;
    }
    printf("Equivalentes em %d de %d atribuições dos x\n", iguais, 1 << K);
    return 0;
}

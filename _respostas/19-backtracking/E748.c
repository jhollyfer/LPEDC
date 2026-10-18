// 0125 · Subconjuntos
// Exercício E748 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define N 6

const char *nomes[N] = {"bicicleta", "patinete", "skate", "patins", "bola", "livro"};
const int valores[N] = {500, 300, 250, 200, 150, 100};
bool da_ana[N];
int justas = 0;

void mostra_lado(bool ana) {
    for (int j = 0; j < N; j++) {
        if (da_ana[j] == ana) {
            printf(" %s", nomes[j]);
        }
    }
}

void divide(int i) {
    if (i == N) {
        int total = 0, ana = 0;
        for (int j = 0; j < N; j++) {
            total += valores[j];
            if (da_ana[j]) {
                ana += valores[j];
            }
        }
        if (2 * ana != total || !da_ana[0]) { // injusta ou repetida
            return;
        }
        justas++;
        printf("Ana:");
        mostra_lado(true);
        printf(" | Beto:");
        mostra_lado(false);
        printf("\n");
        return;
    }
    da_ana[i] = true;
    divide(i + 1);
    da_ana[i] = false;
    divide(i + 1);
}

int main(void) {
    divide(0);
    printf("%d divisões justas\n", justas);
    return 0;
}

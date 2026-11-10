// A253 · Lote de 40 kg: a segunda poda, "o que falta não alcança"

#include <stdbool.h>
#include <stdio.h>

#define N 7
#define ALVO 40

const int pesos[N] = {18, 15, 12, 9, 7, 4, 2}; // caixas de doação, em kg
int resto[N + 1];   // resto[i] = soma dos pesos de i até o fim
bool leva[N];
int chamadas;

// modo 0: sem poda; 1: só "passou do alvo"; 2: as duas podas
void tenta(int i, int soma, int modo, bool mostrar) {
    chamadas++;
    if (modo >= 1 && soma > ALVO) {
        return;                       // poda 1: passou
    }
    if (modo >= 2 && soma + resto[i] < ALVO) {
        return;                       // poda 2: nem levando tudo chega
    }
    if (i == N) {
        if (soma == ALVO && mostrar) {
            printf("  40 kg:");
            for (int j = 0; j < N; j++) {
                if (leva[j]) {
                    printf(" %d", pesos[j]);
                }
            }
            printf("\n");
        }
        return;
    }
    leva[i] = true;
    tenta(i + 1, soma + pesos[i], modo, mostrar);
    leva[i] = false;
    tenta(i + 1, soma, modo, mostrar);
}

int main(void) {
    resto[N] = 0;
    for (int i = N - 1; i >= 0; i--) {
        resto[i] = resto[i + 1] + pesos[i];  // somas do fim para o começo
    }
    printf("Lotes possíveis:\n");
    tenta(0, 0, 2, true);

    const char *nomes[3] = {"sem poda", "poda 1", "podas 1 e 2"};
    for (int modo = 0; modo <= 2; modo++) {
        chamadas = 0;
        tenta(0, 0, modo, false);
        printf("%-12s %3d chamadas\n", nomes[modo], chamadas);
    }
    return 0;
}
// Saída:
// Lotes possíveis:
//   40 kg: 18 15 7
//   40 kg: 18 9 7 4 2
//   40 kg: 15 12 9 4
//   40 kg: 15 12 7 4 2
// sem poda     255 chamadas
// poda 1       193 chamadas
// podas 1 e 2   55 chamadas

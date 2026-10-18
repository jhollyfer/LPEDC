// A136 · O troco em notas

#include <stdio.h>

// cada nome vale o que está escrito na nota: os valores não precisam ser seguidos
typedef enum {
    DOIS = 2,
    CINCO = 5,
    DEZ = 10,
    VINTE = 20,
    CINQUENTA = 50,
    CEM = 100,
} Nota;

int main(void) {
    const Nota notas[] = {CEM, CINQUENTA, VINTE, DEZ, CINCO, DOIS};
    int n = sizeof notas / sizeof notas[0];
    int troco = 137;

    printf("Troco de R$ %d:\n", troco);
    for (int i = 0; i < n; i++) {
        int qtd = troco / notas[i];
        if (qtd > 0) {
            printf("  %d nota(s) de R$ %d\n", qtd, notas[i]);
            troco %= notas[i];
        }
    }
    if (troco > 0) {
        printf("  sobrou R$ %d sem nota\n", troco);
    }
    printf("sizeof(Nota) = %zu bytes\n", sizeof(Nota));
    return 0;
}
// Saída:
// Troco de R$ 137:
//   1 nota(s) de R$ 100
//   1 nota(s) de R$ 20
//   1 nota(s) de R$ 10
//   1 nota(s) de R$ 5
//   1 nota(s) de R$ 2
// sizeof(Nota) = 4 bytes

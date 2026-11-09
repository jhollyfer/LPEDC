// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2728 · ★★★ · O crivo de Eratóstenes em bits

#include <stdint.h>
#include <stdio.h>

#define LIMITE 100
#define PALAVRAS ((LIMITE + 1 + 31) / 32)
#define MARCAR(v, k) ((v)[(k) / 32] |= (uint32_t)1 << ((k) % 32))
#define MARCADO(v, k) (((v)[(k) / 32] >> ((k) % 32)) & 1u)

int main(void) {
    uint32_t composto[PALAVRAS] = {0};
    MARCAR(composto, 0);
    MARCAR(composto, 1);
    for (int p = 2; p * p <= LIMITE; p++) {
        if (!MARCADO(composto, p)) {
            for (int k = p * p; k <= LIMITE; k += p) {
                MARCAR(composto, k);
            }
        }
    }
    int qtd = 0;
    for (int k = 0; k <= LIMITE; k++) {
        if (!MARCADO(composto, k)) {
            qtd++;
        }
    }
    printf("primos até %d: %d\n", LIMITE, qtd);
    printf("maiores que 80:");
    for (int k = 81; k <= LIMITE; k++) {
        if (!MARCADO(composto, k)) {
            printf(" %d", k);
        }
    }
    printf("\nvetor de bits: %zu bytes\n", sizeof composto);
    return 0;
}

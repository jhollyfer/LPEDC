// 0012 · Relacionais e a verdade em C
// Exercício E071 · ★★★
//
// Resposta: 0, 1, 1, 0, 0.
// 5 > 4 > 3   → (5 > 4) > 3   → 1 > 3  → 0
// 3 < 2 < 1   → (3 < 2) < 1   → 0 < 1  → 1
// 1 == 1 == 1 → (1 == 1) == 1 → 1 == 1 → 1
// 2 == 2 == 2 → (2 == 2) == 2 → 1 == 2 → 0
// -1 < 0 < 1  → (-1 < 0) < 1  → 1 < 1  → 0
// Os parênteses abaixo deixam explícito o que o C faz (e calam o aviso).

#include <stdio.h>

int main(void) {
    printf("%d\n", (5 > 4) > 3);
    printf("%d\n", (3 < 2) < 1);
    printf("%d\n", (1 == 1) == 1);
    printf("%d\n", (2 == 2) == 2);
    printf("%d\n", (-1 < 0) < 1);
    return 0;
}

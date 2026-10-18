// 0018 · Lógicos: E, OU, NÃO
// Exercício E107 · ★★★
//
// Resposta: 0 1 0 3 1
// r1: a++ > 0 é 0 > 0 (falso), a vira 1; o && para, b++ não roda. r1 = 0.
// r2: a++ > 0 é 1 > 0 (verdade), a vira 2; o || para, b++ não roda. r2 = 1.
// r3: b++ > 0 é 0 > 0 (falso), b vira 1; precisa do lado direito:
//     a++ > 5 é 2 > 5 (falso), a vira 3. r3 = 0.

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int a = 0, b = 0;
    bool r1 = (a++ > 0) && (b++ > 0);
    bool r2 = (a++ > 0) || (b++ > 0);
    bool r3 = (b++ > 0) || (a++ > 5);
    printf("%d %d %d %d %d\n", r1, r2, r3, a, b);
    return 0;
}

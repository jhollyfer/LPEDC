// 0005 · Do .c ao executável
// Exercício E029 · ★★★
//
// Resposta: "total" é usada sem nunca ter recebido valor (-Wuninitialized). Sem conserto, mostraria um número imprevisível. A correção é "int total = 0;".

#include <stdio.h>

int main(void) {
    int total = 0;
    total = total + 10;
    printf("Total: %d\n", total);
    return 0;
}

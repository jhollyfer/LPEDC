// 0006 · O primeiro programa
// Exercício E033 · ★★☆
//
// Resposta: (1) o /* da primeira linha nunca fechava ("unterminated
// comment"); (2) Int com maiúscula não é tipo ("unknown type name 'Int'");
// (3) faltava ; depois do primeiro printf ("expected ';' before 'print'").
// Esses três são do compilador. (4) print não existe ("implicit declaration of function 'print'" no
// compilador e "undefined reference to `print'" no ligador).

/* Aviso da farmácia */
#include <stdio.h>

int main(void) {
    printf("Farmácia aberta 24h\n");
    printf("Plantão: (11) 5555-0199\n");
    return 0;
}

// 0012 · Relacionais e a verdade em C
// Exercício E071 · ★★★
//
// 0 <= nota <= 10 vira (0 <= nota) <= 10, que é sempre 1; e j1 == j2 == j3
// vira (j1 == j2) == j3, que compara 0 ou 1 com a nota do terceiro jurado.
// Multiplicar duas comparações dá 1 só quando as duas valem 1.

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int nota = 0, j1 = 0, j2 = 0, j3 = 0;
    printf("Nota: ");
    scanf("%d", &nota);
    printf("Jurados: ");
    scanf("%d %d %d", &j1, &j2, &j3);

    bool valida = (nota >= 0) * (nota <= 10);
    bool unanime = (j1 == j2) * (j2 == j3);

    printf("Nota válida? %d\n", valida);
    printf("Unanimidade? %d\n", unanime);
    return 0;
}

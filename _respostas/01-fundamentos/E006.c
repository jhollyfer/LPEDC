// 0001 · O primeiro programa
// Exercício E006 · ★★★
//
// Consertos: stdoi.h -> stdio.h (pré-processador); o ; que faltava no
// primeiro printf (compilador); Main -> main (ligador); 9,40 -> 4,90 (erro
// de execução, que só aparece comparando a saída).

#include <stdio.h>

int main(void) {
    printf("Linha 077 - Terminal Centro\n");
    printf("Via Av. Brasil\n");
    printf("Tarifa: R$ 4,90\n");
    return 0;
}

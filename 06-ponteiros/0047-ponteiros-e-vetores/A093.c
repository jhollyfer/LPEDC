// A093 · De trás para frente, um passo por tipo

#include <stdio.h>

int main(void) {
    double temp[5] = {18.5, 21.0, 24.5, 23.0, 19.5}; // de segunda a sexta
    char turno[3] = {'M', 'T', 'N'};                   // manhã, tarde, noite

    // andar para trás: comece em temp + 5 (um depois do último) e recue
    // ANTES de usar. Parar em p >= temp obrigaria p a ir para temp - 1,
    // um endereço que o C não garante que exista
    printf("De sexta para segunda:");
    for (const double *p = temp + 5; p > temp;) {
        p--;
        printf(" %.1f", *p);
    }
    printf("\n");

    // p + 1 anda UM elemento: para double são 8 bytes, para char, 1
    printf("temp  em %p, temp + 1  em %p\n", (void *)temp, (void *)(temp + 1));
    printf("turno em %p, turno + 1 em %p\n", (void *)turno, (void *)(turno + 1));

    // a distância entre ponteiros também é contada em elementos
    const double *quarta = &temp[2];
    printf("de segunda até quarta: %td elementos\n", quarta - temp);
    printf("turno[2] = %c, *(turno + 2) = %c\n", turno[2], *(turno + 2));
    return 0;
}
// Saída (os endereços mudam a cada execução; repare no último dígito):
// De sexta para segunda: 19.5 23.0 24.5 21.0 18.5
// temp  em 0x7ff177100030, temp + 1  em 0x7ff177100038
// turno em 0x7ff177100080, turno + 1 em 0x7ff177100081
// de segunda até quarta: 2 elementos
// turno[2] = N, *(turno + 2) = N

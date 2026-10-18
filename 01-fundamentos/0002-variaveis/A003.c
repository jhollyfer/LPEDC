// A003 · A cópia que não acompanha e o float que arredonda

#include <stdio.h>

int main(void) {
    // = copia o VALOR: depois disso, as duas variáveis seguem separadas
    int pao_manha = 40;
    int pao_tarde = pao_manha;  // a tarde começa com uma cópia: 40
    pao_manha = 25;             // mudar uma não mexe na outra
    printf("Pães de manhã: %d, de tarde: %d\n", pao_manha, pao_tarde);

    // várias variáveis do mesmo tipo numa linha, separadas por vírgula
    char fila = 'C', caixa = '3';
    printf("Fila %c, caixa %c\n", fila, caixa);

    // o float guarda uns 7 dígitos; o double, uns 15
    float premio_float = 12345678.9;
    double premio_double = 12345678.9;
    printf("Prêmio no float:  %.1f\n", premio_float);
    printf("Prêmio no double: %.1f\n", premio_double);
    return 0;
}
// Saída:
// Pães de manhã: 25, de tarde: 40
// Fila C, caixa 3
// Prêmio no float:  12345679.0
// Prêmio no double: 12345678.9
//
// O 12345678.9 tem 9 dígitos: o float não dá conta e guarda o valor mais
// perto que ele consegue representar. Dinheiro e medidas: use double.

// A069 · A macro não tem tipo nem é função

#include <stdio.h>

#define DIAS_UTEIS 22
#define HORAS_POR_DIA 8
#define HORAS_NO_MES (DIAS_UTEIS * HORAS_POR_DIA) // macro feita de macros

#define MAIOR(a, b) ((a) > (b) ? (a) : (b)) // serve para int, double...

int maior_int(int a, int b) { // a função tem tipo: só int
    return a > b ? a : b;
}

int main(void) {
    double salario = 3520.00;

    printf("Horas no mês: %d\n", HORAS_NO_MES);
    printf("Valor da hora: R$ %.2f\n", salario / HORAS_NO_MES);

    // a macro só cola texto: com double, a comparação é feita em double
    printf("MAIOR(4.75, 4.70)     = %.2f\n", MAIOR(4.75, 4.70));
    // a função converte os argumentos para int antes: 4 e 4
    printf("maior_int(4.75, 4.70) = %d\n", maior_int(4.75, 4.70));

    // com int, as duas concordam
    printf("MAIOR(12, 30) = %d, maior_int(12, 30) = %d\n",
           MAIOR(12, 30), maior_int(12, 30));
    return 0;
}
// Saída:
// Horas no mês: 176
// Valor da hora: R$ 20.00
// MAIOR(4.75, 4.70)     = 4.75
// maior_int(4.75, 4.70) = 4
// MAIOR(12, 30) = 30, maior_int(12, 30) = 30

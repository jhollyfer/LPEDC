// Lista · Módulo 02 · Decisões
// Exercício P0222 · ★★★ · A data por extenso

#include <stdio.h>

int main(void) {
    int dia, mes, ano;

    printf("Data (dd/mm/aaaa): ");
    if (scanf("%d/%d/%d", &dia, &mes, &ano) != 3 || mes < 1 || mes > 12) {
        printf("Data inválida.\n");
        return 1;
    }

    int a = (14 - mes) / 12;
    int y = ano - a;
    int m = mes + 12 * a - 2;
    int semana = (dia + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;

    printf("%d de ", dia);
    switch (mes) {
        case 1: printf("janeiro"); break;
        case 2: printf("fevereiro"); break;
        case 3: printf("março"); break;
        case 4: printf("abril"); break;
        case 5: printf("maio"); break;
        case 6: printf("junho"); break;
        case 7: printf("julho"); break;
        case 8: printf("agosto"); break;
        case 9: printf("setembro"); break;
        case 10: printf("outubro"); break;
        case 11: printf("novembro"); break;
        default: printf("dezembro"); break;
    }
    printf(" de %d, ", ano);
    switch (semana) {
        case 0: printf("domingo"); break;
        case 1: printf("segunda-feira"); break;
        case 2: printf("terça-feira"); break;
        case 3: printf("quarta-feira"); break;
        case 4: printf("quinta-feira"); break;
        case 5: printf("sexta-feira"); break;
        default: printf("sábado"); break;
    }
    printf("\n");
    return 0;
}

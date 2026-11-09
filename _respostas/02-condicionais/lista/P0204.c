// Lista · Módulo 02 · Decisões
// Exercício P0204 · ★☆☆ · A bandeira da conta de luz

#include <stdio.h>

int main(void) {
    int consumo = 220;
    char bandeira = 'A';
    double por_100 = 0.0;

    switch (bandeira) {
        case 'V':
            por_100 = 0.0;
            break;
        case 'A':
            por_100 = 1.885;
            break;
        case 'R':
            por_100 = 4.463;
            break;
        case 'P':
            por_100 = 7.877;
            break;
        default:
            printf("Bandeira desconhecida\n");
            return 1;
    }

    double adicional = consumo / 100.0 * por_100;
    printf("Consumo: %d kWh\n", consumo);
    printf("Adicional da bandeira: R$ %.2f\n", adicional);
    printf("Total: R$ %.2f\n", consumo * 0.80 + adicional);
    return 0;
}

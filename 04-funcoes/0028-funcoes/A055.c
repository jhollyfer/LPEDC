// A055 · A conta de luz: funções que chamam funções

#include <stdio.h>

int consumo(int leitura_anterior, int leitura_atual);
double tarifa(int kwh);
double valor_conta(int kwh);

int main(void) {
    int janeiro = consumo(4210, 4390);
    int fevereiro = consumo(4390, 4625);

    printf("Janeiro: %d kWh, R$ %.2f\n", janeiro, valor_conta(janeiro));
    printf("Fevereiro: %d kWh, R$ %.2f\n", fevereiro, valor_conta(fevereiro));

    // a chamada de dentro roda primeiro e o resultado vira o argumento
    printf("Março: R$ %.2f\n", valor_conta(consumo(4625, 4720)));

    // o retorno serve até como condição de um if
    if (valor_conta(fevereiro) > 150.00) {
        printf("Fevereiro passou de R$ 150.00\n");
    }
    return 0;
}

int consumo(int leitura_anterior, int leitura_atual) {
    return leitura_atual - leitura_anterior;
}

// quem gasta mais paga mais caro por kWh
double tarifa(int kwh) {
    if (kwh <= 100) {
        return 0.60;
    }
    return 0.80;
}

// valor_conta não sabe a tarifa: ela pergunta para outra função
double valor_conta(int kwh) {
    double iluminacao_publica = 12.00;
    return kwh * tarifa(kwh) + iluminacao_publica;
}
// Saída:
// Janeiro: 180 kWh, R$ 156.00
// Fevereiro: 235 kWh, R$ 200.00
// Março: R$ 69.00
// Fevereiro passou de R$ 150.00

// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2703 · ★☆☆ · A conta de luz
//
// A conta de luz cobra cada kWh pela tarifa mais a bandeira, e soma uma taxa
// fixa. Com 250 kWh, tarifa de 80 centavos, bandeira de 10 centavos por kWh e
// taxa de R$ 15,00, a conta é R$ 240,00. O programa abaixo compila sem aviso,
// mas as duas contas estão erradas. Conserte só com parênteses e com a ordem
// das operações.
//
//   Saída esperada:
//   total: R$ 240.00
//   bandeira: 11% do preço do kWh
//
// Dicas:
// 1. Rode antes: sai R$ 215.10 e 0%.
// 2. O consumo multiplica a soma da tarifa com a bandeira.
// 3. 10 / 90 em inteiros é 0: multiplique por 100 antes de dividir.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int consumo = 250;  // kWh
    int tarifa = 80;    // centavos por kWh
    int bandeira = 10;  // centavos por kWh
    int taxa = 1500;    // centavos

    int total = consumo * tarifa + bandeira + taxa;
    printf("total: R$ %.2f\n", total / 100.0);

    int pct = bandeira / (tarifa + bandeira) * 100;
    printf("bandeira: %d%% do preço do kWh\n", pct);
    return 0;
}

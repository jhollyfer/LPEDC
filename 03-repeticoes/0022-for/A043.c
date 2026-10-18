// A043 · O carnê da TV em 6 parcelas

#include <stdio.h>

int main(void) {
    double preco = 1800.0;
    int total_parcelas = 6;
    double valor = preco / total_parcelas;
    double falta = preco;

    for (int parcela = 1; parcela <= total_parcelas; parcela++) {
        falta = falta - valor;
        printf("Parcela %d/%d: R$ %.2f (falta R$ %.2f)\n",
               parcela, total_parcelas, valor, falta);
    }
    printf("Carnê quitado!\n");
    return 0;
}
// Saída:
// Parcela 1/6: R$ 300.00 (falta R$ 1500.00)
// Parcela 2/6: R$ 300.00 (falta R$ 1200.00)
// Parcela 3/6: R$ 300.00 (falta R$ 900.00)
// Parcela 4/6: R$ 300.00 (falta R$ 600.00)
// Parcela 5/6: R$ 300.00 (falta R$ 300.00)
// Parcela 6/6: R$ 300.00 (falta R$ 0.00)
// Carnê quitado!

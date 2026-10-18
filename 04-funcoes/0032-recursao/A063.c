// A063 · Em quantos meses a dívida dobra

#include <stdio.h>

// o caso base não é um contador chegando a zero: é uma condição
int meses_para_chegar(double divida, double meta, double juros) {
    if (divida >= meta) {
        return 0; // caso base: já chegou, não falta nenhum mês
    }
    // um mês de juros e o mesmo problema, um pouco mais perto da meta
    return 1 + meses_para_chegar(divida * (1 + juros / 100), meta, juros);
}

int main(void) {
    printf("Cartão (12%% ao mês): %d meses\n", meses_para_chegar(1000, 2000, 12));
    printf("Empréstimo (3%% ao mês): %d meses\n", meses_para_chegar(1000, 2000, 3));
    // caso de borda: a meta já foi batida, nenhuma chamada recursiva
    printf("Já dobrou: %d meses\n", meses_para_chegar(2500, 2000, 3));
    return 0;
}
// Saída:
// Cartão (12% ao mês): 7 meses
// Empréstimo (3% ao mês): 24 meses
// Já dobrou: 0 meses

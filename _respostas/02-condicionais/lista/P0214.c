// Lista · Módulo 02 · Decisões
// Exercício P0214 · ★★☆ · O financiamento aprovado

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    double renda = 4200.00;
    int idade = 34;
    bool nome_limpo = true;

    printf("Renda: R$ %.2f, idade: %d, nome limpo: %d\n", renda, idade, nome_limpo);
    if (renda >= 3000 && idade >= 18 && idade <= 65 && nome_limpo) {
        printf("Financiamento aprovado.\n");
    } else {
        printf("Financiamento recusado.\n");
    }
    return 0;
}

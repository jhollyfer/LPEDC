// Lista · Módulo 02 · Decisões
// Exercício P0214 · ★★☆ · O financiamento aprovado
//
// O programa abaixo aprova o financiamento com três if aninhados: renda de pelo
// menos R$ 3000, idade de 18 a 65 anos e nome limpo. Ele funciona, mas é
// difícil de ler. Refatore: troque os três if por um if só, com && e ||, e um
// else. A saída tem que continuar a mesma:
//
//   Saída esperada:
//   Renda: R$ 4200.00, idade: 34, nome limpo: 1
//   Financiamento aprovado.
//
// Dicas:
// 1. As três condições têm que valer ao mesmo tempo: junte com &&.
// 2. Os três else do original mostram a mesma mensagem: no novo, um else só.
// 3. Resposta esperada: Financiamento aprovado.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    double renda = 4200.00;
    int idade = 34;
    bool nome_limpo = true;

    printf("Renda: R$ %.2f, idade: %d, nome limpo: %d\n", renda, idade, nome_limpo);
    if (renda >= 3000) {
        if (idade >= 18) {
            if (idade <= 65) {
                if (nome_limpo) {
                    printf("Financiamento aprovado.\n");
                } else {
                    printf("Financiamento recusado.\n");
                }
            } else {
                printf("Financiamento recusado.\n");
            }
        } else {
            printf("Financiamento recusado.\n");
        }
    } else {
        printf("Financiamento recusado.\n");
    }
    return 0;
}

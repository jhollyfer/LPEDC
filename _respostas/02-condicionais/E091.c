// 0016 · else if, if aninhado e o else pendurado
// Exercício E091 · ★☆☆

#include <stdio.h>

int main(void) {
    int idade;
    printf("Idade: ");
    if (scanf("%d", &idade) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    double mensalidade;
    if (idade <= 18) {
        mensalidade = 150;
    } else if (idade <= 38) {
        mensalidade = 280;
    } else if (idade <= 58) {
        mensalidade = 520;
    } else {
        mensalidade = 900;
    }
    printf("Mensalidade: R$ %.2f\n", mensalidade);
    return 0;
}

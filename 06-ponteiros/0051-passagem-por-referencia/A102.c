// A102 · Rachando a conta do bar

#include <stdio.h>

// "devolve" dois resultados: escreve nas variáveis de quem chamou
void racha(int total, int pessoas, int *cada, int *sobra) {
    *cada = total / pessoas;
    *sobra = total % pessoas;
}

int main(void) {
    int total, pessoas;
    int cada, sobra; // a função vai preencher

    printf("Total da conta (R$): ");
    if (scanf("%d", &total) != 1) { // & : o scanf precisa saber ONDE guardar
        return 1;
    }
    printf("Quantas pessoas: ");
    if (scanf("%d", &pessoas) != 1 || pessoas <= 0) {
        return 1;
    }

    racha(total, pessoas, &cada, &sobra);
    printf("Cada um paga R$ %d e sobram R$ %d para a gorjeta\n", cada, sobra);
    return 0;
}
// Exemplo de execução:
// Total da conta (R$): 187
// Quantas pessoas: 4
// Cada um paga R$ 46 e sobram R$ 3 para a gorjeta

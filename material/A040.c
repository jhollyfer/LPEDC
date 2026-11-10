// A040 · Desmontando um número, dígito por dígito

#include <stdio.h>

int main(void) {
    int numero = 4093;
    int resto = numero;   // cópia que vai sendo "comida"
    int quantidade = 0;
    int soma = 0;

    printf("Dígitos de %d, da direita para a esquerda:", numero);
    while (resto > 0) {
        int digito = resto % 10; // o último dígito
        printf(" %d", digito);
        soma = soma + digito;
        quantidade++;
        resto = resto / 10;      // tira o último dígito
    }
    printf("\n");

    printf("Quantidade: %d\n", quantidade);
    printf("Soma: %d\n", soma);
    return 0;
}
// Saída:
// Dígitos de 4093, da direita para a esquerda: 3 9 0 4
// Quantidade: 4
// Soma: 16

// A079 · O dígito '7' não vale 7

#include <stdio.h>
#include <ctype.h>

#define TAM 8

int main(void) {
    // código de um boleto, guardado como caracteres (do jeito que foi digitado)
    char codigo[TAM] = {'3', '4', '1', '9', '1', '0', '7', '8'};

    int soma_codigos = 0; // soma os códigos ASCII: '3' é 51, não 3
    int soma_valores = 0; // soma o que cada dígito vale

    for (int i = 0; i < TAM; i++) {
        if (!isdigit(codigo[i])) {
            printf("Posição %d não é dígito\n", i);
            return 1;
        }
        soma_codigos += codigo[i];
        soma_valores += codigo[i] - '0'; // '7' - '0' = 55 - 48 = 7
    }

    printf("Somando os códigos: %d\n", soma_codigos);
    printf("Somando os valores: %d\n", soma_valores);

    // o caminho de volta: um número de 0 a 9 vira o caractere do dígito
    int resto = soma_valores % 10;
    char dv = (char) ('0' + resto);
    printf("Último dígito da soma: %c (código %d)\n", dv, dv);
    return 0;
}
// Saída:
// Somando os códigos: 417
// Somando os valores: 33
// Último dígito da soma: 3 (código 51)

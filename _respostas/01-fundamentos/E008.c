// 0002 · Variáveis
// Exercício E008 · ★☆☆
//
// 2via começava com dígito, valor-final tinha o sinal de menos, float é
// palavra reservada e "dia util" tinha espaço. preco e Preco são variáveis
// diferentes: o C diferencia maiúsculas de minúsculas.

#include <stdio.h>

int main(void) {
    int via = 2;
    double valor_final = 89.90;
    int parcelas = 3;
    char dia_util = 'S';
    int preco = 10;
    int Preco = 20;

    printf("Via: %d\n", via);
    printf("Valor final: R$ %.2f\n", valor_final);
    printf("Parcelas: %d\n", parcelas);
    printf("Dia útil: %c\n", dia_util);
    printf("preco: %d, Preco: %d\n", preco, Preco);
    return 0;
}

// 0002 · Variáveis
// Exercício E008 · ★☆☆
//
// O colega começou o pedido de segunda via do boleto, mas escolheu nomes de
// variável que o C não aceita, e o programa não compila. Renomeie as
// variáveis inválidas (snake_case, sem acento, sem espaço), sem mudar os
// valores, até compilar e mostrar a saída abaixo. As variáveis preco e
// Preco estão certas: deixe as duas como estão e repare que o programa
// mostra valores diferentes para elas.
//
//   Saída esperada (depois de consertar):
//   Via: 2
//   Valor final: R$ 89.90
//   Parcelas: 3
//   Dia útil: S
//   preco: 10, Preco: 20
//
// Dicas:
// 1. Nome só com letras, dígitos e _, sem começar por dígito, sem espaço.
//    O - é o sinal de menos. Palavras do C (int, float, return...) são
//    reservadas.
// 2. Troque o nome na declaração E no printf.
// 3. Resposta esperada: 2via vira via (ou segunda_via), valor-final vira
//    valor_final, float vira parcelas (ou qtd_parcelas) e dia util vira
//    dia_util. preco e Preco são variáveis diferentes. E as cinco linhas
//    acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int 2via = 2;
    double valor-final = 89.90;
    int float = 3;
    char dia util = 'S';
    int preco = 10;
    int Preco = 20;

    printf("Via: %d\n", 2via);
    printf("Valor final: R$ %.2f\n", valor-final);
    printf("Parcelas: %d\n", float);
    printf("Dia útil: %c\n", dia util);
    printf("preco: %d, Preco: %d\n", preco, Preco);
    return 0;
}

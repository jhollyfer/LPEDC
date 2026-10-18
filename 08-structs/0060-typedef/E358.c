// 0060 · Typedef
// Exercício E358 · ★★☆
//
// Este programa NÃO compila, de propósito: há três erros com typedef. Rode,
// leia as mensagens e conserte. O programa mostra o saldo do vale-refeição
// depois de um almoço.
//
//   Saída esperada (depois de consertado):
//   Ana: R$ 600.00 -> R$ 563.50
//
// Dicas:
// 1. Comece pelo primeiro erro: um typedef quebrado faz aparecer vários
//    erros em cascata. Na linha do typedef, o tipo existente vem primeiro e
//    o apelido por último.
// 2. Um typedef de struct sem nome só pode ser usado pelo apelido: "struct
//    Cartao" não existe.
// 3. O C lê de cima para baixo: um tipo precisa estar declarado antes de
//    aparecer num protótipo.
// 4. Resposta esperada: typedef double Reais; trocar struct Cartao c por
//    Cartao c; e mover o protótipo de pagar para depois do typedef.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

typedef Reais double;

Cartao pagar(Cartao c, Reais valor);

typedef struct {
    char titular[20];
    Reais saldo;
} Cartao;

int main(void) {
    struct Cartao c = {"Ana", 600.00};
    Cartao depois = pagar(c, 36.50);

    printf("%s: R$ %.2f -> R$ %.2f\n", c.titular, c.saldo, depois.saldo);
    return 0;
}

Cartao pagar(Cartao c, Reais valor) {
    c.saldo = c.saldo - valor;
    return c;
}

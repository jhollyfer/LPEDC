// 0030 · Escopo e tempo de vida
// Exercício E178 · ★★☆
//
// O vale-refeição abaixo foi escrito com uma variável global, e a função que
// deveria só calcular um preço cobra uma "taxa escondida" de R$ 1.00 na
// global. Os gastos são R$ 45.00 e R$ 32.50, então o certo seria
// 300 - 45 - 1 - 32.50 - 1 = R$ 220.50. Rode: aqui ele mostra R$ 222.50.
//
// Refatore: tire a global, troque as duas funções por
// "double gastar(double saldo, double valor)", que recebe o saldo e devolve o
// saldo novo, já com a taxa, e faça o main guardar o retorno numa local.
// Depois acrescente um terceiro gasto de R$ 18.00 e mostre o saldo de novo.
//
//   Saída esperada:
//   Saldo: R$ 220.50
//   Saldo: R$ 201.50
//
// Dicas:
// 1. Em "saldo = saldo - preco_com_taxa(valor);" o compilador pode ler o
//    saldo ANTES de a função tirar a taxa, e depois grava por cima: a taxa
//    some. O C não define essa ordem. Global mudada no meio de uma conta é
//    bug esperando para acontecer.
// 2. Na versão nova, gastar devolve saldo - valor - 1.00, e o main faz
//    saldo = gastar(saldo, 45.00). O saldo vira uma local do main.
// 3. Resposta esperada: 220.50 e, depois do gasto de 18.00 (mais 1.00 de
//    taxa), 201.50. Sem global, a taxa fica visível na função que a cobra.
//
// Escreva sua resposta abaixo (refatore o código):

#include <stdio.h>

double saldo = 300.00;

double preco_com_taxa(double valor) {
    saldo = saldo - 1.00; // "taxa escondida"
    return valor;
}

void gastar(double valor) {
    saldo = saldo - preco_com_taxa(valor);
}

int main(void) {
    gastar(45.00);
    gastar(32.50);
    printf("Saldo: R$ %.2f\n", saldo);
    return 0;
}

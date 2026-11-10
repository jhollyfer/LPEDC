// 0068 · Arquivos binários
// Exercício E405 · ★★☆
//
// Crie o tipo Conta (int numero, double saldo). No main, grave com UM fwrite
// em /tmp/contas.bin as contas 1001 (250.00), 1002 (80.50) e 1003 (1200.00).
// Escreva void listar(void), que mostra as contas lendo registro por registro,
// e int depositar(int posicao, double valor): abre em "rb+", vai até o
// registro da posição com fseek, lê, soma o valor ao saldo, volta ao começo
// do mesmo registro e grava por cima (1 se deu certo, 0 se não). Liste,
// deposite R$ 100.00 na posição 1 e liste de novo.
//
//   Saída esperada:
//   Antes:
//   1001  R$   250.00
//   1002  R$    80.50
//   1003  R$  1200.00
//   Depois:
//   1001  R$   250.00
//   1002  R$   180.50
//   1003  R$  1200.00
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

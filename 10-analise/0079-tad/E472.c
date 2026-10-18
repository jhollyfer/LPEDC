// 0079 · TAD: interface (.h) e implementação (.c)
// Exercício E472 · ★★☆
//
// O TAD Conta desta pasta (conta.h) não tem transferência. Você não pode
// mexer no conta.c nem no conta.h. Escreva, no cliente, a função
//
//   bool transfere(Conta *de, Conta *para, int centavos);
//
// que só move o dinheiro se der para sacar da origem, e devolve se deu certo.
// Teste com um Pix da Bia para o Caio: a Bia tem R$ 80,00 e o Caio, R$ 10,00.
// Primeiro ela tenta mandar R$ 100,00; depois, R$ 35,50.
//
//   Saída esperada:
//   Pix de R$ 100,00: negado
//   Pix de R$ 35,50: ok
//   Bia: R$ 44,50 | Caio: R$ 45,50
//
// Dicas:
// 1. Saque primeiro. Só deposite se o saque deu certo; assim ninguém ganha
//    dinheiro do nada.
// 2. Os valores são centavos: R$ 35,50 é 3550.
// 3. Para mostrar: saldo / 100 e saldo % 100 com %02d.
// 4. Resposta esperada: a saída acima. Repare que a nova operação respeita o
//    invariante (saldo >= 0) de graça, porque só usa operações que já o
//    respeitam.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#include "conta.h"

int main(void) {

    return 0;
}

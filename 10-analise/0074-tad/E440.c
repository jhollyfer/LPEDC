// 0074 · TAD: interface (.h) e implementação (.c)
// Exercício E440 · ★☆☆
//
// Este cliente NÃO COMPILA, de propósito. Ele controla as senhas da fila da
// lotérica e tenta mexer direto nos campos do contador. Rode, leia o erro do
// gcc e responda:
//
// a) O que quer dizer "invalid use of incomplete typedef"?
// b) Por que o autor do TAD quis que isso desse erro?
//
// Depois conserte usando só as funções do contador.h.
//
//   Saída esperada:
//   Na fila: 2
//   Na fila: 0
//
// Dicas:
// 1. O contador.h só diz que existe uma struct contador, sem os campos.
// 2. Procure no contador.h uma função que zera e outra que lê o valor.
// 3. Resposta esperada: a) no cliente, struct contador é um tipo incompleto:
//    o compilador não sabe os campos nem o tamanho, então não deixa usar ->;
//    b) para proteger o invariante 0 <= valor <= limite: só o contador.c
//    mexe nos campos. Conserto: contador_valor(fila) para ler e
//    contador_zera(fila) para zerar.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#include "contador.h"

int main(void) {
    Contador *fila = contador_cria(50);
    if (fila == NULL) {
        return 1;
    }
    contador_incrementa(fila);
    contador_incrementa(fila);
    printf("Na fila: %d\n", fila->valor);

    fila->valor = 0; // fim do expediente
    printf("Na fila: %d\n", fila->valor);

    contador_libera(fila);
    return 0;
}

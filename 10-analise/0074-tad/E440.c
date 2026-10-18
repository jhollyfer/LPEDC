// 0074 · TAD: interface (.h) e implementação (.c)
// Exercício E440 · ★☆☆
//
// Este cliente NÃO COMPILA, de propósito. Ele controla as senhas da fila da
// lotérica e tenta mexer direto nos campos do contador. Rode, leia o erro do
// gcc e conserte usando só as funções do contador.h. Depois acrescente, antes
// do contador_libera, uma tentativa de tirar uma senha da fila vazia, e
// mostre se o TAD deixou.
//
//   Saída esperada:
//   Na fila: 2
//   Na fila: 0
//   Tirar da fila vazia: negado
//
// Dicas:
// 1. "invalid use of incomplete typedef": o contador.h só diz que existe uma
//    struct contador, sem os campos. O cliente não pode usar ->.
// 2. Procure no contador.h uma função que zera, outra que lê o valor e outra
//    que tira 1 (ela devolve bool).
// 3. Resposta esperada: a saída acima, com contador_valor(fila) para ler,
//    contador_zera(fila) para zerar e contador_decrementa(fila), que devolve
//    false com a fila em 0. É o invariante 0 <= valor <= limite protegido:
//    só o contador.c mexe nos campos.
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

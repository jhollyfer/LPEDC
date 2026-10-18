// 0077 · Busca e remoção
// Exercício E458 · ★☆☆
//
// A lotérica anotou os valores dos boletos pagos numa lista com valores
// repetidos: monte-a inserindo no início 5, 9, 5, 2 e 5. Escreva a função
//
//   int conta(const No *inicio, int valor)
//
// que devolve quantas vezes o valor aparece. Depois, no main:
//
//   mostre a lista e quantos 5 ela tem;
//   o 9 foi digitado errado: troque por 4 usando o nó que lista_busca
//   devolve, e mostre a lista;
//   tire TODOS os 5 chamando lista_remove num laço, conte quantas remoções
//   deram certo e mostre a lista e o tamanho.
//
//   Saída esperada:
//   5 -> 2 -> 5 -> 9 -> 5 -> NULL
//   quantos 5: 3
//   5 -> 2 -> 5 -> 4 -> 5 -> NULL
//   removidos: 3
//   2 -> 4 -> NULL
//   tamanho: 2
//
// Dicas:
// 1. conta é o "for de lista" com um if e um contador.
// 2. lista_busca devolve o endereço do nó: mudar p->valor muda a lista.
//    Confira se não voltou NULL antes de mexer.
// 3. lista_remove tira só o PRIMEIRO nó com o valor e devolve true se
//    tirou: while (lista_remove(&l, 5)) removidos++;
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "lista.h"

int main(void) {

    return 0;
}

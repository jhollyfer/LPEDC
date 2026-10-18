// 0077 · Busca e remoção
// Exercício E462 · ★★★
//
// O vagão do MEIO do trem precisa ir para a manutenção, e você só pode
// percorrer a lista UMA vez (sem contar os nós antes). Escreva
//
//   bool remove_meio(No **inicio)
//
// usando a técnica da lebre e da tartaruga: dois ponteiros saem do início;
// a tartaruga anda um nó por vez e a lebre anda dois. Quando a lebre chega
// ao fim, a tartaruga está no meio. Com quantidade par, o meio é o SEGUNDO
// dos dois do centro.
//
//   Saída esperada:
//   1 -> 2 -> 3 -> 5 -> 6 -> 7 -> NULL
//   10 -> 20 -> 30 -> 50 -> 60 -> NULL
//   NULL
//
// Dicas:
// 1. Condição do laço: lebre != NULL && lebre->prox != NULL.
// 2. A cada volta: ant = tartaruga; tartaruga = tartaruga->prox;
//    lebre = lebre->prox->prox.
// 3. No fim, remova a tartaruga com o ant, como no texto (ant == NULL quer
//    dizer que ela é o primeiro).
// 4. Resposta esperada: a saída acima (saem o 4, o 40 e o único nó, 99).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

int main(void) {
    No *a = NULL;
    for (int i = 7; i >= 1; i--) a = lista_insere_inicio(a, i);
    No *b = NULL;
    for (int i = 60; i >= 10; i -= 10) b = lista_insere_inicio(b, i);
    No *c = lista_insere_inicio(NULL, 99);

    // chame remove_meio para as três listas e imprima cada uma

    lista_libera(a);
    lista_libera(b);
    lista_libera(c);
    return 0;
}

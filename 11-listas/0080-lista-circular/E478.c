// 0080 · Lista circular
// Exercício E478 · ★★☆
//
// Dois salões do restaurante vão virar um só. Cada salão é uma lista
// circular de mesas, guardada pelo último nó. Escreva
//
//   No *concatena(No *ult_a, No *ult_b)
//
// que emenda b depois de a e devolve o último da lista nova, em O(1): sem
// percorrer nada, só trocando ponteiros. Trate as listas vazias.
//
//   Saída esperada:
//   A: 1 -> 2 -> 3 -> (volta ao 1)
//   B: 10 -> 20 -> (volta ao 10)
//   juntas: 1 -> 2 -> 3 -> 10 -> 20 -> (volta ao 1)
//   com vazia: 1 -> 2 -> 3 -> 10 -> 20 -> (volta ao 1)
//
// Dicas:
// 1. Desenhe os dois círculos. Quem precisa mudar? O último de a, que
//    passa a apontar para o primeiro de b, e o último de b, que passa a
//    apontar para o primeiro de a.
// 2. Guarde o primeiro de a (ult_a->prox) antes de mexer.
// 3. O último da lista nova é o último de b. Se uma das listas for NULL,
//    devolva a outra.
// 4. Resposta esperada: a saída acima. Com ponteiro para o PRIMEIRO, você
//    teria que andar até o último de cada lista: O(n).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "lista.h"

int main(void) {
    No *a = NULL;
    No *b = NULL;
    for (int i = 1; i <= 3; i++) a = lista_insere_fim(a, i);
    b = lista_insere_fim(b, 10);
    b = lista_insere_fim(b, 20);
    printf("A: ");
    lista_imprime(a);
    printf("B: ");
    lista_imprime(b);

    // junte a e b com concatena, mostre; depois junte o resultado com uma
    // lista vazia (NULL) e mostre de novo. No fim, libere uma vez só.

    lista_libera(a); // troque estas duas linhas por um lista_libera
    lista_libera(b); // da lista juntada
    return 0;
}

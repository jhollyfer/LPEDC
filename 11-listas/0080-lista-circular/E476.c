// 0080 · Lista circular
// Exercício E476 · ★☆☆
//
// Girar uma roda circular não mexe em nenhuma seta: basta mudar QUEM é o
// último. Escreva a função
//
//   No *gira(No *ultimo, int k)
//
// que anda k nós com o ponteiro do último e devolve o novo último (assim o
// primeiro passa a ser o que estava k casas à frente). O main já monta a
// roda. Complete o main para: mostrar a roda e o primeiro e o último; girar
// 2 casas e mostrar; tirar o 10 e mostrar; e mostrar quantos nós sobraram.
//
//   Saída esperada:
//   5 -> 10 -> 20 -> 30 -> (volta ao 5)
//   primeiro 5, último 30
//   girou 2: 20 -> 30 -> 5 -> 10 -> (volta ao 20)
//   sem o 10: 20 -> 30 -> 5 -> (volta ao 20)
//   3 nós
//
// Dicas:
// 1. A lista é guardada pelo ponteiro para o ÚLTIMO: o primeiro é u->prox.
// 2. gira é um for de k voltas com ultimo = ultimo->prox. Na lista vazia
//    (NULL), devolva NULL sem andar.
// 3. Depois de girar, guarde o resultado: u = gira(u, 2);
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "lista.h"

int main(void) {
    No *u = NULL;
    u = lista_insere_fim(u, 10);
    u = lista_insere_fim(u, 20);
    u = lista_insere_inicio(u, 5);
    u = lista_insere_fim(u, 30);

    // escreva aqui, antes de liberar

    lista_libera(u);
    return 0;
}

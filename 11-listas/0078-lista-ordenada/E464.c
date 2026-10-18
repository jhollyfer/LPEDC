// 0078 · Lista ordenada
// Exercício E464 · ★☆☆
//
// Teste de mesa. O programa insere 25, 10, 40, 10 e 30 numa lista vazia com
// lista_insere_ordenado. Para cada inserção, diga onde ant e p estão quando
// o laço "while (p != NULL && p->valor < valor)" para, e como fica a lista.
// Depois rode e confira as listas.
//
// Por fim: se a condição fosse "p->valor <= valor", onde entraria o segundo
// 10?
//
// O código está no arquivo, logo abaixo deste enunciado.
//
// Dicas:
// 1. ant == NULL quer dizer "o novo vira o início"; p == NULL quer dizer
//    "o novo vai para o fim".
// 2. No segundo 10, compare 10 < 10.
// 3. Resposta esperada:
//    25: ant NULL, p NULL (lista vazia)  -> 25
//    10: ant NULL, p no 25               -> 10 25
//    40: ant no 25, p NULL               -> 10 25 40
//    10: ant NULL, p no primeiro 10      -> 10 10 25 40 (o novo entra ANTES)
//    30: ant no 25, p no 40              -> 10 10 25 30 40
//    Com <=, o segundo 10 entraria DEPOIS do primeiro (ant no 10, p no 25).
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>
#include "lista.h"

int main(void) {
    int valores[] = {25, 10, 40, 10, 30};
    No *l = NULL;
    for (int i = 0; i < 5; i++) {
        l = lista_insere_ordenado(l, valores[i]);
        printf("inseriu %d: ", valores[i]);
        lista_imprime(l);
    }
    lista_libera(l);
    return 0;
}

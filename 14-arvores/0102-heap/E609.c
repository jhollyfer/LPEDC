// 0102 · Heap e fila de prioridade
// Exercício E609 · ★★☆
//
// SEM RODAR, escreva a saída do programa. Desenhe a árvore a cada passo
// (comece com o heap vazio). Depois rode e confira.
//
// Dicas:
// 1. Inserir: entra no fim e sobe enquanto for maior que o pai.
// 2. Remover: o último vai para a raiz e desce pelo filho MAIOR.
// 3. Resposta esperada:
//    depois das 5 inserções: [45 35 25 15 5]
//    saiu 45: [35 15 25 5]
//    entrou 40: [40 35 25 5 15]
//    saiu 40: [35 15 25 5]
//    saiu 35: [25 15 5]
//
// Escreva sua resposta abaixo (a saída, como comentário):

#include <stdio.h>
#include "heap.h"

void mostra(const char *rotulo, const Heap *h) {
    printf("%s: ", rotulo);
    heap_mostra(h);
    printf("\n");
}

int main(void) {
    Heap *h = heap_cria(8);
    int valores[] = {15, 35, 25, 45, 5};
    for (int i = 0; i < 5; i++) {
        heap_insere(h, valores[i]);
    }
    mostra("depois das 5 inserções", h);

    printf("saiu %d", heap_remove(h));
    mostra("", h);
    heap_insere(h, 40);
    mostra("entrou 40", h);
    printf("saiu %d", heap_remove(h));
    mostra("", h);
    printf("saiu %d", heap_remove(h));
    mostra("", h);

    heap_libera(h);
    return 0;
}

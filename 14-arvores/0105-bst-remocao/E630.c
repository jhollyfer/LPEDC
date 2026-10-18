// 0105 · BST: remoção
// Exercício E630 · ★★★
//
// Ache o bug (este programa quebra de propósito). A recepção guarda um
// ponteiro para a ficha do aluno 35, porque vai precisar dela depois. Em
// seguida cancela a matrícula 30 e tenta mostrar a ficha do 35:
//
//   Saída esperada:
//   Ficha guardada: 35
//   Ficha depois de remover o 30: 35
//
// Mas o AddressSanitizer para o programa com "heap-use-after-free". O 35
// nem foi removido! Rode, leia o relatório (procure "freed by") e explique o
// que aconteceu. Conserte sem mexer no bst.c.
//
// Dicas:
// 1. O 30 tem dois filhos. Quem é o sucessor dele? O que o bst_remove faz com
//    o NÓ do sucessor depois de copiar a chave?
// 2. A chave 35 continua na árvore, mas em outro nó (o que antes era do 30).
// 3. Resposta esperada: o bst_remove copiou o 35 para o nó do 30 e deu free
//    no nó original do 35, justamente o que o ponteiro "ficha" guardava. A
//    ficha virou um ponteiro solto. Conserto: depois de qualquer remoção,
//    busque de novo (ficha = bst_busca(raiz, 35)). Moral: um ponteiro para
//    um nó só vale até a próxima mudança na árvore.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include "bst.h"

int main(void) {
    int matriculas[] = {50, 30, 70, 20, 40, 60, 80, 35, 45};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = bst_insere(raiz, matriculas[i]);
    }

    No *ficha = bst_busca(raiz, 35);
    printf("Ficha guardada: %d\n", ficha->chave);

    raiz = bst_remove(raiz, 30);
    printf("Ficha depois de remover o 30: %d\n", ficha->chave);

    raiz = bst_libera(raiz);
    return 0;
}

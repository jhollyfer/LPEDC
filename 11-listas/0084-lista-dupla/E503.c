// 0084 · Lista dupla
// Exercício E503 · ★★★
//
// As funções engata_inicio e desengata montam e desmontam um trem, mas cada
// uma esquece UMA seta de propósito. Lista dupla com seta faltando é traiçoeira:
// andando para frente tudo parece certo. Rode, compare os dois sentidos,
// leia o relatório do AddressSanitizer e conserte as duas funções.
//
//   Saída esperada depois do conserto:
//   98 <-> 105 <-> 87
//   87 <-> 105 <-> 98
//   98 <-> 105
//   105 <-> 98
//
// Dicas:
// 1. A segunda linha mostra só "87": de trás para frente, o 87 não sabe quem
//    vem antes dele. Quem deveria ter preenchido o ant do antigo primeiro?
//    (A terceira linha sai "(vazia)" pelo mesmo motivo: com ant NULL, o
//    desengata acha que o 87 é o primeiro.)
// 2. Conserte e rode de novo: agora é "heap-use-after-free" no
//    lista_imprime_reverso. Tirar o último nó deixou o fim apontando para o
//    nó liberado.
// 3. Resposta esperada: em engata_inicio, "if (l->inicio != NULL)
//    l->inicio->ant = novo;"; em desengata, "if (p->prox == NULL) l->fim =
//    p->ant; else p->prox->ant = p->ant;".
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

static void engata_inicio(Lista *l, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) exit(1);
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = l->inicio;
    if (l->inicio == NULL) l->fim = novo;
    l->inicio = novo;
    l->tamanho++;
}

static void desengata(Lista *l, No *p) {
    if (p->ant == NULL) l->inicio = p->prox;
    else p->ant->prox = p->prox;
    if (p->prox != NULL) p->prox->ant = p->ant;
    free(p);
    l->tamanho--;
}

int main(void) {
    Lista trem;
    lista_inicia(&trem);
    engata_inicio(&trem, 87);
    engata_inicio(&trem, 105);
    engata_inicio(&trem, 98);
    lista_imprime(&trem);
    lista_imprime_reverso(&trem);

    desengata(&trem, trem.fim);
    lista_imprime(&trem);
    lista_imprime_reverso(&trem);

    lista_libera(&trem);
    return 0;
}

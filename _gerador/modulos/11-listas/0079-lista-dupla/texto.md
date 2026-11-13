## 0079 · Lista dupla

- **Lista duplamente encadeada** (no Cormen, **duplamente ligada**, com
  `next` e `prev`): cada nó guarda `prox` e `ant` (CORMEN et al., 2024,
  cap. 10).
- **Por que existe**: na lista simples não se anda de trás para frente e,
  para remover um nó conhecido, ainda é preciso achar o anterior
  (CELES; RANGEL, 2002).
- **O que ganha**: anda nos **dois sentidos**, remove um nó conhecendo **só
  ele** em O(1) e, com ponteiro para o **último**, insere no fim em O(1)
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 4).
- **Regra das setas**: para todo nó `p` que não é o último,
  `p->prox->ant == p`. As setas mudam **aos pares** (FEOFILOFF, 2009, cap. 4).
- **Remover `p`**: desvia as duas setas que chegam nele, cada uma com seu
  caso de borda: primeiro nó (muda o `inicio`) e último nó (muda o `fim`)
  (CELES; RANGEL, 2002).
- **Custo de memória**: em 64 bits, `sizeof(No)` passa de 16 para 24 bytes,
  um ponteiro a mais por nó.

A lista desta pasta é uma struct com as duas pontas e o tamanho:

```c
typedef struct no {
    int valor;
    struct no *ant;  // o anterior, ou NULL no primeiro
    struct no *prox; // o próximo, ou NULL no último
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;
```

> [!WARNING]
> Com uma seta faltando, a lista dupla **parece certa**: se a inserção
> esquecer o `ant`, só a volta sai errada. Imprima **nos dois sentidos**. Na
> remoção, `p->ant->prox` no primeiro nó acessa `NULL`.

{{exemplo}}

Um trem de minério tem vagões de 98, 105, 87 e 110 toneladas, e o de 87 está
com o freio travado. Com `p` nele, o 105 passa a apontar para o 110, e o 110
aponta de volta para o 105:

{{ideia}}

A remoção, sem procurar o anterior:

```c
void lista_remove_no(Lista *l, No *p) {
    if (p->ant == NULL) l->inicio = p->prox;  // era o primeiro
    else p->ant->prox = p->prox;              // o anterior pula o p
    if (p->prox == NULL) l->fim = p->ant;     // era o último
    else p->prox->ant = p->ant;               // o seguinte pula o p para trás
    free(p);
    l->tamanho--;
}
```

```c
#include <stdio.h>
#include "lista.h"

int main(void) {
    Lista trem;
    lista_inicia(&trem);
    int cargas[] = {98, 105, 87, 110}; // toneladas, da locomotiva para o fim
    for (int i = 0; i < 4; i++) lista_insere_fim(&trem, cargas[i]);

    printf("da locomotiva: ");
    lista_imprime(&trem);
    printf("do fim:        ");
    lista_imprime_reverso(&trem);

    No *vagao = lista_busca(&trem, 87);
    if (vagao != NULL) {
        lista_remove_no(&trem, vagao); // sem procurar o anterior: p->ant
        printf("desengatou o vagão de 87 t (%d vagões)\n", trem.tamanho);
    }

    printf("da locomotiva: ");
    lista_imprime(&trem);
    printf("do fim:        ");
    lista_imprime_reverso(&trem);

    lista_libera(&trem);
    return 0;
}
// Saída:
// da locomotiva: 98 <-> 105 <-> 87 <-> 110
// do fim:        110 <-> 87 <-> 105 <-> 98
// desengatou o vagão de 87 t (3 vagões)
// da locomotiva: 98 <-> 105 <-> 110
// do fim:        110 <-> 105 <-> 98
```

Duas perguntas, uma por ponta. O vagão de 87 passa pelos dois Não; o primeiro
vagão daria Sim na primeira, o último na segunda:

{{fluxograma}}

## 0079 · Lista dupla

No pátio, o terceiro vagão de um trem de minério está com o freio travado. O
manobrista solta os dois engates dele e liga o segundo vagão ao quarto, sem
voltar à locomotiva para descobrir quem vem antes.

Na lista simples, remover exige o anterior, e achá-lo custa percorrer desde o
início. Na **lista duplamente encadeada** (no
Cormen, **duplamente ligada**, com `next` e `prev`), cada nó guarda `prox` e
`ant`. Assim:

- dá para andar nos **dois sentidos**;
- dá para remover um nó conhecendo **só ele**, em O(1);
- com um ponteiro para o **último** nó, inserir no fim vira O(1).

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

Uma regra não pode quebrar: para todo nó `p` que não é o último,
`p->prox->ant == p`. As setas mudam **aos pares**; o erro comum é esquecer uma.

Remover `p` desvia as duas setas que chegam nele, cada uma com seu caso de
borda:

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

O trem tem vagões de 98, 105, 87 e 110 toneladas. Com `p` no de 87, o 105
passa a apontar para o 110, e o 110 aponta de volta para o 105:

{{ideia}}

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

O fluxograma faz duas perguntas, uma por ponta. O vagão de 87 passa pelos dois
Não. Para o primeiro vagão, a primeira daria Sim; para o último, a segunda:

{{fluxograma}}

Imprimir de trás para frente é o `for` de sempre, de `l->fim` com `p =
p->ant`. O exemplo A158 usa a ida e volta num controle remoto ("canal
seguinte", "canal anterior").

> [!WARNING]
> Com uma seta faltando, a lista dupla **parece certa**: se a inserção esquecer
> o `ant`, só a volta sai errada. Imprima **nos dois sentidos**. Na remoção,
> os dois casos de borda são obrigatórios: `p->ant->prox` no primeiro nó
> acessa `NULL`, e esquecer o `fim` o deixa apontando para memória liberada.

> [!TIP]
> **Por dentro do C:** em 64 bits, `sizeof(No)` passa de 16 para 24 bytes (4 do
> `int`, 4 de preenchimento, dois ponteiros de 8): 50% a mais por nó, o preço
> das remoções em O(1) e da volta.

> [!NOTE]
> **Pergunta para você:** se `lista_insere_fim` esquecesse a linha `novo->ant =
> l->fim;`, o que `lista_imprime` mostraria para o trem do exemplo? E
> `lista_imprime_reverso`?

{{pratique}}

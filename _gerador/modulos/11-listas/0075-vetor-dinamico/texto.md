## 0075 · Vetor dinâmico

Você anota as despesas de uma viagem e não sabe quantas serão. Um
`int despesas[100]` desperdiça memória se forem 5 e estoura se forem 101.

A saída é um vetor que, quando a folga acaba, pede um vetor maior e copia os
itens.

Uma **lista sequencial** (ou **lista em vetor**) guarda os itens lado a lado,
na ordem da lista. Três campos a controlam: o endereço do vetor no heap
(`itens`), quantos itens estão em uso (`tam`) e quantos cabem (`cap`).
Enquanto `tam < cap`, inserir no fim é escrever em `itens[tam]`.

Com `tam == cap`, o `realloc` (assunto 0055) pede um bloco maior, copia os
itens e devolve o antigo. A prática é **dobrar a capacidade**.

O conjunto é um **TAD** (assunto 0074): `lista.h` diz **o que** a lista faz e
`lista.c` diz **como**, com a `struct lista` escondida.

A lista do exemplo começa com espaço para 2 despesas. A 3ª dobra para 4 e a
5ª (R$ 27) dobra para 8, copia os quatro valores e deixa três vagas:

{{ideia}}

A peça central do `lista.c` é a função que garante espaço antes de cada
inserção:

```c
struct lista {
    int *itens; // vetor no heap
    int tam;    // quantos itens estão em uso
    int cap;    // quantos itens cabem no vetor
};

// garante espaço para mais um item: se encheu, dobra
static bool garante_espaco(Lista *l) {
    if (l->tam < l->cap) return true;
    int nova_cap = l->cap * 2;
    int *novo = realloc(l->itens, nova_cap * sizeof(int));
    if (novo == NULL) return false; // l->itens continua valendo
    l->itens = novo;
    l->cap = nova_cap;
    return true;
}

bool lista_insere_fim(Lista *l, int valor) {
    if (!garante_espaco(l)) return false;
    l->itens[l->tam] = valor;
    l->tam++;
    return true;
}
```

E quem usa a lista só enxerga a interface de `lista.h`:

```c
#include <stdio.h>
#include "lista.h"

int main(void) {
    int despesas[] = {12, 35, 8, 50, 27}; // em reais
    Lista *viagem = lista_cria(2);        // começa com espaço para 2
    if (viagem == NULL) return 1;

    for (int i = 0; i < 5; i++) {
        lista_insere_fim(viagem, despesas[i]);
        printf("inseriu %2d: tam %d, cap %d\n", despesas[i],
               lista_tamanho(viagem), lista_capacidade(viagem));
    }
    lista_imprime(viagem);

    int total = 0;
    for (int i = 0; i < lista_tamanho(viagem); i++) {
        int valor;
        lista_pega(viagem, i, &valor);
        total += valor;
    }
    printf("total: R$ %d\n", total);

    lista_libera(viagem);
    return 0;
}
// Saída:
// inseriu 12: tam 1, cap 2
// inseriu 35: tam 2, cap 2
// inseriu  8: tam 3, cap 4
// inseriu 50: tam 4, cap 4
// inseriu 27: tam 5, cap 8
// [12, 35, 8, 50, 27]
// total: R$ 132
```

No fluxograma, "está cheio?" vem antes de escrever. Para o 27 a resposta é
Sim: o vetor dobra e só então o valor entra em `itens[4]`. Se o `realloc`
falhar, a função devolve `false` e a lista continua intacta:

{{fluxograma}}

Inserir ou remover no **meio** desloca todos os itens seguintes: O(n) no pior
caso, a posição 0 (exemplo A150). Ler a posição `i` é O(1).

> [!WARNING]
> Um `int *p = &itens[0];` guardado antes de inserir pode apontar para o bloco
> antigo, que o `realloc` devolveu. Guarde o índice. E nunca escreva
> `l->itens = realloc(l->itens, ...)`: com `NULL`, você perde o bloco antigo.

> [!TIP]
> **Por dentro do C:** dobrando, inserir n itens copia menos de 2n itens (1 +
> 2 + 4 + ... + n): O(1) **em média** por inserção (custo amortizado). De um
> em um, são cerca de n²/2 cópias. `lista_libera` faz dois `free`, o do vetor
> primeiro.

> [!NOTE]
> **Pergunta para você:** começando com `lista_cria(2)`, quantas vezes o
> `realloc` roda até a lista ter 100 itens? E qual é a capacidade final?
> Quantas vagas ficam sobrando?

{{pratique}}

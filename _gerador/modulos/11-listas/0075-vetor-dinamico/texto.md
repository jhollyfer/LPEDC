## 0075 · Vetor dinâmico

- **Lista sequencial** (ou **lista em vetor**): guarda os itens lado a lado,
  na ordem da lista, num vetor (ZIVIANI, 2010, cap. 3).
- **Vetor fixo**: se sobra espaço, desperdiça; se falta, não há jeito barato
  de crescer (CELES; RANGEL, 2002).
- **Três campos**: o endereço do vetor no heap (`itens`), quantos itens estão
  em uso (`tam`) e quantos cabem (`cap`). Com `tam < cap`, inserir no fim é
  escrever em `itens[tam]` (FEOFILOFF, 2009, cap. 3).
- **Crescer**: com `tam == cap`, o `realloc` (0055) pede um bloco maior,
  copia os itens e libera o antigo. Se falhar, devolve `NULL` e o bloco
  antigo continua válido (CPPREFERENCE, s.d.).
- **Dobrar a capacidade**: inserir n itens copia menos de 2n itens (1 + 2 + 4
  + ... + n), O(1) em média por inserção, o **custo amortizado**. Crescendo de
  um em um, são cerca de n²/2 cópias (CORMEN et al., 2024).
- **TAD** (0074): `lista.h` diz **o que** a lista faz; `lista.c` diz **como**,
  com a `struct lista` escondida (CELES; CERQUEIRA; RANGEL, 2016).

| Operação | Custo |
| --- | --- |
| ler a posição `i` | O(1) |
| inserir no fim | O(1) amortizado |
| inserir ou remover no meio | O(n): desloca os seguintes |

> [!WARNING]
> Nunca escreva `l->itens = realloc(l->itens, ...)`: se vier `NULL`, o bloco
> antigo se perde. E um `int *p = &itens[0]` guardado antes de inserir pode
> apontar para o bloco que o `realloc` liberou. Guarde o índice.

{{exemplo}}

As despesas de uma viagem, numa lista que começa com espaço para 2. A 3ª
dobra para 4; a 5ª (R$ 27) dobra para 8, copia os quatro valores e deixa
três vagas:

{{ideia}}

A peça central do `lista.c` garante espaço antes de cada inserção:

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

Quem usa a lista só enxerga a interface de `lista.h`:

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

"Está cheio?" vem antes de escrever. Para o 27 a resposta é Sim: o vetor
dobra e só então o valor entra em `itens[4]`:

{{fluxograma}}

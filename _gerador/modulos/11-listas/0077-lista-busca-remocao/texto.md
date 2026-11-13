## 0077 · Busca e remoção

- **Buscar**: percorrer até achar, O(n). A função devolve o **endereço do
  nó** ou `NULL`; com ele você lê ou muda o valor (FEOFILOFF, 2009, cap. 4).
- **Remover** o nó `p`: o **anterior** passa a apontar para o seguinte. A
  lista simples não volta, então se percorre com **dois ponteiros**: `ant`
  anda um passo atrás de `p` (CELES; RANGEL, 2002).
- **Dois casos**: `ant == NULL` quer dizer que o nó é o **primeiro**, e o
  início muda; senão, `ant->prox = p->prox` e o anterior pula o `p`. O
  `free(p)` vem depois de religar (CELES; RANGEL, 2002).
- **`No **inicio`**: como remover o primeiro muda o início, a função recebe o
  endereço dele (0049). É o outro estilo comum; a inserção do 0076 devolvia o
  início novo (FEOFILOFF, 2009, cap. 4).
- **Nó-cabeça**: um nó de mentira no começo faz todo nó de verdade ter
  anterior, e o caso especial some. O Cormen usa a **sentinela** `L.nil`
  (CORMEN et al., 2024, cap. 10).
- **Custo**: religar é O(1); achar o nó é O(n) (FEOFILOFF, 2009, cap. 4).

> [!WARNING]
> A ordem do `&&` importa. Em `while (p->valor != valor && p != NULL)`, o
> `p->valor` é lido antes de testar `p` e quebra quando o valor não está na
> lista. Com `p != NULL` primeiro, o curto-circuito (0013) evita a leitura.

{{exemplo}}

Na barbearia, as senhas 31, 17, 42 e 8 esperam numa lista. O 42 desiste: o
laço para com `p` no 42 e `ant` no 17, a seta do 17 passa a apontar para o 8
e o nó do 42 volta para o heap:

{{ideia}}

A busca e a remoção do `lista.c`:

```c
No *lista_busca(No *inicio, int valor) {
    No *p = inicio;
    while (p != NULL && p->valor != valor) { // o teste do NULL vem primeiro
        p = p->prox;
    }
    return p; // o nó, ou NULL se a lista acabou
}
```

```c
bool lista_remove(No **inicio, int valor) {
    No *ant = NULL;    // sempre um passo atrás de p
    No *p = *inicio;
    while (p != NULL && p->valor != valor) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) return false; // não achou
    if (ant == NULL) {
        *inicio = p->prox;       // era o primeiro: o início anda
    } else {
        ant->prox = p->prox;     // o anterior pula o p
    }
    free(p);
    return true;
}
```

E a fila da barbearia:

```c
#include <stdio.h>
#include "lista.h"

int main(void) {
    No *fila = NULL;
    fila = lista_insere_inicio(fila, 8);
    fila = lista_insere_inicio(fila, 42);
    fila = lista_insere_inicio(fila, 17);
    fila = lista_insere_inicio(fila, 31);
    lista_imprime(fila);

    // a senha 42 ainda está esperando?
    No *achou = lista_busca(fila, 42);
    if (achou != NULL) printf("senha %d: na fila\n", achou->valor);

    // o 42 desistiu: sai do meio
    lista_remove(&fila, 42);
    lista_imprime(fila);

    // o 31 foi atendido: sai do começo (o início muda)
    lista_remove(&fila, 31);
    lista_imprime(fila);

    // o 99 nunca esteve na fila
    if (!lista_remove(&fila, 99)) printf("senha 99: não está na fila\n");

    lista_libera(fila);
    return 0;
}
// Saída:
// 31 -> 17 -> 42 -> 8 -> NULL
// senha 42: na fila
// 31 -> 17 -> 8 -> NULL
// 17 -> 8 -> NULL
// senha 99: não está na fila
```

Na saída do 42, `ant` é o 17 (não `NULL`) e o caminho vai por `ant->prox =
p->prox`; na saída do 31, iria por `início = p->prox`:

{{fluxograma}}

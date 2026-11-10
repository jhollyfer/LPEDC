## 0077 · Busca e remoção

Na barbearia, as senhas esperam numa lista: 31, 17, 42, 8. O 42 desiste e sai
do meio: o 17 passa a ter o 8 como próximo.

**Buscar** é percorrer até achar, O(n). A função devolve o **endereço do nó**
(ou `NULL`), e com ele você lê ou muda o valor:

```c
No *lista_busca(No *inicio, int valor) {
    No *p = inicio;
    while (p != NULL && p->valor != valor) { // o teste do NULL vem primeiro
        p = p->prox;
    }
    return p; // o nó, ou NULL se a lista acabou
}
```

**Remover** o nó `p` exige que o **anterior** aponte para o seguinte, e a
lista simples não tem caminho de volta. Percorra com **dois ponteiros**:
`ant` anda um passo atrás de `p`.

Achado o nó, são dois casos:

- `ant == NULL`: o nó é o **primeiro**; é a variável `inicio` do `main` que
  precisa mudar.
- senão: `ant->prox = p->prox`, e o anterior pula o `p`.

O `free(p)` vem depois de religar. Como remover o primeiro muda o início, a
função recebe o **endereço** do início: `No **inicio` (assunto 0049). É o
outro estilo comum; a inserção do 0076 devolvia o início novo.

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

Para tirar o 42, o laço para com `p` no 42 e `ant` no 17. A seta do 17 passa
a apontar para o 8, e o nó do 42 volta para o heap:

{{ideia}}

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

No fluxograma, `ant` é o 17 (não `NULL`), então o caminho vai por `ant->prox =
p->prox`. Na remoção do 31, iria por `início = p->prox`:

{{fluxograma}}

O exemplo A154 elimina o caso especial com um **nó-cabeça**, um nó de mentira
no começo: todo nó de verdade passa a ter anterior. O Cormen usa a
**sentinela** `L.nil` (assunto 0174).

> [!WARNING]
> A ordem do `&&` importa. Em `while (p->valor != valor && p != NULL)`, o
> `p->valor` é lido antes de testar `p` e quebra quando o valor não está na
> lista. Com `p != NULL` primeiro, o curto-circuito (assunto 0013) evita a
> leitura.

> [!TIP]
> **Por dentro do C:** `*inicio = p->prox` altera a variável `fila` do `main`.
> Um `No **pp` que anda por `pp = &(*pp)->prox` dispensa o `ant` (aponta para
> "quem aponta para o nó atual"), e a remoção vira `No *p = *pp; *pp =
> p->prox; free(p);`, sem `if`. Religar é O(1); achar o nó é O(n).

> [!NOTE]
> **Pergunta para você:** se a lista fosse `42 -> 17 -> 42 -> 8` e você
> chamasse `lista_remove(&fila, 42)` uma vez, qual 42 sairia? Por qual caminho
> do fluxograma a remoção passaria?

{{pratique}}

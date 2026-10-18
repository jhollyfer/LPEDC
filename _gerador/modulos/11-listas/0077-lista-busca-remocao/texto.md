## 0077 · Busca e remoção

Sábado de manhã, barbearia lotada. Cada cliente pega uma senha e o barbeiro
anota numa lista: 31, 17, 42, 8. Aí o 42 cansa de esperar e vai embora. Ele
sai do meio da fila, e ninguém precisa trocar de cadeira: basta o 17 passar
a ter o 8 como próximo.

**Buscar** numa lista encadeada é percorrer até achar. Não existe atalho: sem
acesso direto, a busca é sempre sequencial, O(n). A função devolve o
**endereço do nó** (ou `NULL` se não achou), e com ele você lê ou até muda o
valor:

```c
No *lista_busca(No *inicio, int valor) {
    No *p = inicio;
    while (p != NULL && p->valor != valor) { // o teste do NULL vem primeiro
        p = p->prox;
    }
    return p; // o nó, ou NULL se a lista acabou
}
```

**Remover** pede um cuidado a mais. Para tirar o nó `p`, quem aponta para ele
precisa passar a apontar para o seguinte. E quem aponta para `p` é o nó
**anterior**, que numa lista simples não tem caminho de volta. A saída é
percorrer com **dois ponteiros**: `ant` anda sempre um passo atrás de `p`.

Achado o nó, há dois casos:

- `ant == NULL`: o nó é o **primeiro**. Quem aponta para ele é a variável
  `inicio` do `main`, e é ela que precisa mudar.
- senão: `ant->prox = p->prox`, e o anterior pula o `p`.

Nos dois casos, só depois de religar vem o `free(p)`. Como remover o primeiro
muda o início e a função ainda quer devolver se achou ou não, ela recebe o
**endereço** do início: `No **inicio` (ponteiro para ponteiro, assunto 0049).
No assunto anterior a inserção devolvia o início novo. São os dois estilos que
você vai encontrar por aí.

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

Vamos ver na prática. Para tirar o 42, o laço para com `p` no 42 e `ant` no
17. Uma única atribuição desvia a seta do 17 para o 8, e o nó do 42, que
ninguém mais aponta, volta para o heap:

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

Repara no fluxograma: o laço anda até achar o 42 ou a lista acabar. Achou, e
como `ant` não é `NULL` (é o 17), o caminho vai pelo `ant->prox = p->prox`.
Na remoção do 31, o caminho seria o outro, `início = p->prox`:

{{fluxograma}}

O exemplo A154 mostra um truque para sumir com o caso especial: o
**nó-cabeça**, um nó "de mentira" no começo. Com ele, todo nó de verdade tem
um anterior, e o primeiro deixa de ser especial.

> [!WARNING]
> A ordem do `&&` importa. `while (p->valor != valor && p != NULL)` lê
> `p->valor` **antes** de saber se `p` é `NULL`. Quando o valor não está na
> lista, `p` vira `NULL` e o programa quebra. Com `p != NULL` primeiro, o
> curto-circuito (assunto 0013) nem chega a olhar o `p->valor`. E nunca
> inverta "religar" e "liberar": depois do `free(p)`, `p->prox` não é mais
> seu.

> [!TIP]
> **Por dentro do C:** em `lista_remove(&fila, 42)`, a função recebe o
> endereço da variável `fila`, que mora na pilha do `main`. Escrever
> `*inicio = p->prox` muda a `fila` lá do `main`. Dá para ir além e eliminar o
> `ant`: um `No **pp` que começa em `inicio` e anda com `pp = &(*pp)->prox`
> aponta sempre para "o lugar que aponta para o nó atual", seja a `fila`, seja
> o `prox` de alguém. A remoção vira `No *p = *pp; *pp = p->prox; free(p);`,
> sem `if`. E repare no custo: religar é O(1), sem deslocar nada como no
> vetor. O que custa O(n) é achar o nó.

> [!NOTE]
> **Pergunta para você:** se a lista fosse `42 -> 17 -> 42 -> 8` e você
> chamasse `lista_remove(&fila, 42)` uma vez, qual 42 sairia? Por qual caminho
> do fluxograma a remoção passaria?

{{pratique}}

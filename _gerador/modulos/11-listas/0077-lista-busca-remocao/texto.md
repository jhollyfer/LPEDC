## 0077 · Busca e remoção

O assunto 0076 sabe criar, percorrer e liberar uma lista encadeada. Falta
achar um item e tirá-lo do meio sem desmontar o resto. No vetor, remover do
meio obrigava a deslocar os seguintes. Na lista, ninguém se move: basta
trocar uma seta. O trabalho está em descobrir **qual** seta trocar.

Na barbearia, as senhas esperam numa lista: 31, 17, 42, 8. O cliente da senha
42 desiste e vai embora. Os outros não mudam de cadeira; só o 17 passa a ter
o 8 como próximo a ser chamado. É exatamente o que a remoção numa lista
encadeada faz.

**Buscar** é percorrer a lista até achar o valor, comparando nó por nó, e
custa O(n) no pior caso. A função de busca devolve o **endereço do nó** que
tem o valor, ou `NULL` se a lista acabou sem achar. Com o endereço em mãos,
você lê o valor ou o altera direto no nó (FEOFILOFF, 2009, cap. 4):

```c
No *p = inicio;
while (p != NULL && p->valor != valor) { // o teste do NULL vem primeiro
    p = p->prox;
}
// aqui p é o nó com o valor, ou NULL se não achou
```

**Remover** o nó `p` exige que o nó **anterior** passe a apontar para o nó
seguinte, pulando o `p`. O problema é que a lista simples só tem setas para
a frente: parado no `p`, você não tem como voltar ao anterior. A saída é
percorrer com **dois ponteiros**, `ant` e `p`, em que `ant` anda sempre um
passo atrás. Antes de avançar `p`, você faz `ant = p`; assim, quando `p`
para no nó procurado, `ant` está no nó de antes (CELES; RANGEL, 2002).

Achado o nó, há dois casos, e a diferença está em `ant` (CELES; RANGEL,
2002). Se `ant` ainda vale `NULL`, o laço nem andou: o nó é o **primeiro** da
lista, e quem precisa mudar é o próprio início, que passa a ser `p->prox`. Se
`ant` não é `NULL`, o nó está no meio ou no fim, e `ant->prox = p->prox` faz
o anterior pular o `p`. Nos dois casos, o `free(p)` vem **depois** de religar,
porque é preciso ler `p->prox` antes de devolver o nó.

O primeiro caso traz uma complicação. Remover o primeiro nó muda a variável
`inicio` de quem chamou, e a função recebe só uma cópia dela. A inserção do
assunto 0076 resolvia isso devolvendo o início novo. A remoção usa o outro
estilo comum: recebe o **endereço** do início, `No **inicio`, como no
assunto 0049, e escreve `*inicio = p->prox` para mudar a variável do `main`
(FEOFILOFF, 2009, cap. 4). Quem chama passa `&fila`.

O caso especial do primeiro nó existe porque o primeiro é o único sem
anterior. Um truque o elimina: pôr no começo um **nó-cabeça**, um nó de
mentira que não guarda dado nenhum e nunca sai. Com ele, todo nó de verdade
tem um anterior, e a remoção vira um caso só. O Cormen usa a mesma ideia com
o nome de **sentinela**, `L.nil` (CORMEN et al., 2024, cap. 10). O exemplo
A154 mostra o nó-cabeça, e o assunto 0174 volta à sentinela.

Há ainda um terceiro jeito, sem `ant`. Um ponteiro `No **pp` que aponta para
"quem aponta para o nó atual" começa em `inicio` e anda com
`pp = &(*pp)->prox`. Achado o nó, `No *p = *pp; *pp = p->prox; free(p);`
resolve o primeiro nó e os do meio com o mesmo código, sem `if`.

Quanto ao custo, religar as setas é O(1), não importa o tamanho da lista. O
que custa é achar o nó, O(n) no pior caso (FEOFILOFF, 2009, cap. 4). Se você
já tem o anterior em mãos, remover sai de graça.

> [!WARNING]
> A ordem do `&&` importa. Em `while (p->valor != valor && p != NULL)`, o
> `p->valor` é lido antes de testar `p` e quebra quando o valor não está na
> lista. Com `p != NULL` primeiro, o curto-circuito (assunto 0013) evita a
> leitura.

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

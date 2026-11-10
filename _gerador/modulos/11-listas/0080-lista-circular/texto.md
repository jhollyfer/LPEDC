## 0080 · Lista circular

O garçom do rodízio serve as mesas 3, 7, 12 e 15 e, na última, volta à 3: para
ele não existe fim, só "a próxima mesa".

Uma **lista circular** é uma lista encadeada em que o último nó aponta para o
**primeiro**, e não para `NULL`: os nós formam um anel. Serve para rodízios,
como a vez dos jogadores e a divisão da CPU. Na lista dupla, o círculo fecha
nos dois sentidos, como no Cormen, com uma sentinela (assunto 0174).

Convém guardar o ponteiro para o **último** nó: o primeiro é `ultimo->prox`.
Assim, inserir no início **e** no fim custa O(1); inserir no fim é inserir no
início e declarar o novo como último.

```c
No *lista_insere_inicio(No *ultimo, int valor) {
    No *novo = cria_no(valor);       // cria_no faz novo->prox = novo
    if (ultimo == NULL) return novo; // único nó: primeiro e último
    novo->prox = ultimo->prox;       // o novo aponta para o antigo primeiro
    ultimo->prox = novo;             // o último fecha o círculo no novo
    return ultimo;
}

No *lista_insere_fim(No *ultimo, int valor) {
    // inserir no fim = inserir no início e dizer que o novo é o último
    ultimo = lista_insere_inicio(ultimo, valor);
    return ultimo->prox;
}
```

Sem `NULL`, percorrer para ao **voltar ao ponto de partida**. Como o primeiro
passo já começa nele, o laço certo é o **do-while** (assunto 0021), que roda
o corpo antes de testar. A lista vazia (`ultimo == NULL`) é tratada antes.

No exemplo, o ponteiro da lista está na mesa 15 e a mesa 3 é `ultimo->prox`.
O garçom serve 6 vezes sem testar nada:

{{ideia}}

```c
#include <stdio.h>
#include "lista.h"

int main(void) {
    No *salao = NULL; // ponteiro para a ÚLTIMA mesa
    int mesas[] = {3, 7, 12, 15};
    for (int i = 0; i < 4; i++) salao = lista_insere_fim(salao, mesas[i]);
    lista_imprime(salao);

    // o garçom sai da primeira mesa e serve 6 vezes, sem nunca achar um fim
    printf("serve:");
    No *garcom = salao->prox;
    for (int i = 0; i < 6; i++) {
        printf(" %d", garcom->valor);
        garcom = garcom->prox;
    }
    printf("\n");

    lista_remove(&salao, 12);
    printf("a mesa 12 pagou e foi embora\n");
    lista_imprime(salao);

    lista_libera(salao);
    return 0;
}
// Saída:
// 3 -> 7 -> 12 -> 15 -> (volta ao 3)
// serve: 3 7 12 15 3 7
// a mesa 12 pagou e foi embora
// 3 -> 7 -> 15 -> (volta ao 3)
```

O fluxograma é o do `lista_imprime`: testa a lista vazia, põe `p` na mesa 3 e
repete mostrar, andar e perguntar "já voltei ao primeiro?". Com 4 mesas, a
resposta é Não três vezes e Sim na quarta:

{{fluxograma}}

No **problema de Josephus**, pessoas em roda eliminam uma a cada k passos. O
exemplo A160 o resolve com a batata quente, tirando nós do anel até sobrar
um que aponta para si mesmo.

> [!WARNING]
> Numa lista circular, `p` **nunca** vira `NULL`: um laço `p != NULL` não
> termina. No `libera`, o "seguinte" do último é o primeiro, já liberado:
> **corte o círculo** antes (`ultimo->prox = NULL`) e trate como lista comum.
> E um `while (p != ultimo->prox)` começando no primeiro não roda nem uma vez.

> [!TIP]
> **Por dentro do C:** o nó é o da lista simples, 16 bytes. **Girar** a roda é
> `ultimo = ultimo->prox`, e **juntar** duas listas circulares é trocar dois
> ponteiros, O(1).

> [!NOTE]
> **Pergunta para você:** se a lista guardasse o ponteiro para o **primeiro**
> nó em vez do último, quanto custaria inserir no fim? E no início? (Lembre
> que o último precisa apontar para o novo primeiro.)

{{pratique}}

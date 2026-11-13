## 0080 · Lista circular

- **Lista circular**: lista encadeada em que o último nó aponta para o
  **primeiro**, e não para `NULL`. Os nós formam um anel (FEOFILOFF, 2009,
  cap. 4).
- **Para que serve**: rodízios, como a vez dos jogadores e a divisão da CPU
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 4).
- **Ponteiro para o último**: o primeiro é `ultimo->prox`. Inserir no início
  **e** no fim custa O(1); inserir no fim é inserir no início e declarar o
  novo como último (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 4).
- **Percorrer**: sem `NULL`, o laço para ao **voltar ao ponto de partida**.
  O certo é o **do-while** (0021), que roda o corpo antes de testar; a lista
  vazia (`ultimo == NULL`) é tratada antes (CELES; RANGEL, 2002).
- **Girar e juntar**: girar a roda é `ultimo = ultimo->prox`; juntar duas
  listas circulares é trocar dois ponteiros, O(1).
- **Circular dupla**: o círculo fecha nos dois sentidos, como no Cormen, com
  uma sentinela (CORMEN et al., 2024, cap. 10).
- **Problema de Josephus**: pessoas em roda eliminam uma a cada k passos;
  tira-se nós do anel até sobrar um que aponta para si mesmo (FEOFILOFF,
  2009, cap. 4).

> [!WARNING]
> Na lista circular, `p` **nunca** vira `NULL`: um laço `p != NULL` não
> termina. No `libera`, **corte o círculo** antes (`ultimo->prox = NULL`):
> o seguinte do último é o primeiro, já liberado.

{{exemplo}}

O garçom do rodízio serve as mesas 3, 7, 12 e 15 e, na última, volta à 3. O
ponteiro da lista fica na mesa 15, e a 3 é `ultimo->prox`:

{{ideia}}

As duas inserções do `lista.c`:

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

O `lista_imprime` testa a lista vazia, põe `p` na mesa 3 e pergunta "já
voltei ao primeiro?": com 4 mesas, Não três vezes e Sim na quarta:

{{fluxograma}}

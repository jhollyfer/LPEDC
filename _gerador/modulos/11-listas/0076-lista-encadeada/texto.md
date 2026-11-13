## 0076 · Lista encadeada

- **Lista encadeada** (ou **lista ligada**): cada item fica num pedaço
  separado de memória, o **nó**, com o valor e o endereço do próximo. O
  último aponta para `NULL` (FEOFILOFF, 2009, cap. 4).
- **Início**: a lista inteira é o endereço do primeiro nó (o `L.head` do
  Cormen). Lista vazia é `inicio == NULL` (CORMEN et al., 2024, cap. 10).
- **Struct autorreferenciada**: uma struct não pode conter a si mesma, mas
  pode conter um **ponteiro** para a própria struct (KERNIGHAN; RITCHIE, 1989).

```c
typedef struct no {
    int valor;
    struct no *prox; // o próximo nó, ou NULL no último
} No;
```

- **Sem acesso direto**: cada nó vem de um `malloc` e cai onde o heap tiver
  espaço; a ordem está nas setas. Não existe `lista[2]`: para chegar ao
  terceiro nó, siga duas setas (CELES; RANGEL, 2002).
- **Inserir no início**: cria o nó, aponta o `prox` dele para o antigo início
  e devolve o novo nó. É O(1) (CELES; RANGEL, 2002).
- **Percorrer**: `for (p = inicio; p != NULL; p = p->prox)`, o "for de
  lista" (FEOFILOFF, 2009, cap. 4).
- **Liberar**: um `free` por nó, guardando o próximo **antes** do `free`
  (CELES; RANGEL, 2002).
- **Inserir no fim** com só o início guardado é O(n); com um ponteiro para o
  último, vira O(1) (0079 e 0086).

> [!WARNING]
> `lista_insere_inicio(inicio, 20);` sem o `inicio =` na frente compila e
> está errado: o novo início se perde e o nó vaza. No `libera`, o erro comum é ler
> `p->prox` depois de `free(p)`.

{{exemplo}}

Chegam quatro Pix: R$ 20, 45, 10 e 80, e o 80 aparece primeiro no extrato.
Embaixo, a lista no heap, com endereços fora de ordem:

{{ideia}}

A inserção no início, do `lista.c` desta pasta:

```c
No *lista_insere_inicio(No *inicio, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) { // num programa pequeno, desistir é o mais honesto
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = inicio; // o antigo primeiro vira o segundo
    return novo;         // o novo nó é o novo início
}
```

E o extrato montado no `main`:

```c
#include <stdio.h>
#include "lista.h"

int main(void) {
    No *extrato = NULL; // lista vazia

    // os Pix chegam nesta ordem: 20, 45, 10, 80
    extrato = lista_insere_inicio(extrato, 20);
    extrato = lista_insere_inicio(extrato, 45);
    extrato = lista_insere_inicio(extrato, 10);
    extrato = lista_insere_inicio(extrato, 80);

    lista_imprime(extrato); // o último a chegar aparece primeiro

    int total = 0;
    for (No *p = extrato; p != NULL; p = p->prox) { // percorrer: siga os prox
        total += p->valor;
    }
    printf("%d Pix, total R$ %d\n", lista_tamanho(extrato), total);

    lista_libera(extrato);
    return 0;
}
// Saída:
// 80 -> 10 -> 45 -> 20 -> NULL
// 4 Pix, total R$ 155
```

O laço pergunta "ainda tem nó?" antes de cada passo; o `p` vai do 80 ao 20,
vira `NULL` e o laço para com total R$ 155:

{{fluxograma}}

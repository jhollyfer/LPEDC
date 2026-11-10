## 0076 · Lista encadeada

No extrato do Pix, cada Pix novo entra na frente sem empurrar os antigos. No
vetor, inserir na posição 0 move todo mundo. A lista encadeada evita isso.

Uma **lista encadeada** (no Cormen, **lista ligada**) guarda cada item num
pedaço separado de memória, o **nó**: o valor e o endereço do próximo. O
último aponta para `NULL`. A lista inteira é o endereço do primeiro nó, o
**início** (o `L.head` do Cormen). Lista vazia é `inicio == NULL`.

O nó é uma **struct autorreferenciada**:

```c
typedef struct no {
    int valor;
    struct no *prox; // o próximo nó, ou NULL no último
} No;
```

Uma struct não pode conter a si mesma (teria tamanho infinito), mas pode
conter um **ponteiro** para si mesma: ele tem sempre 8 bytes.

Cada nó vem de um `malloc` e cai onde o heap tiver espaço: a ordem está nas
**setas**. Não existe `lista[2]`; para chegar ao terceiro nó, siga duas setas
a partir do início.

Três operações formam a base (no `lista.c` desta pasta):

- **inserir no início**: cria o nó, aponta o `prox` dele para o antigo início
  e devolve o novo nó como início. É O(1).
- **percorrer**: `for (p = inicio; p != NULL; p = p->prox)`, o "for de lista".
- **liberar**: um `free` por nó, guardando o próximo **antes** do `free`.

Inserir no **fim** com só o início guardado exige andar até o último nó,
O(n). Com um ponteiro para o último, vira O(1) (0079 e 0086).

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

Aqui o nó fica à vista no `lista.h`; no módulo 12 volta a ficar escondido.

Chegam quatro Pix: R$ 20, 45, 10 e 80, e o 80 aparece primeiro. Embaixo, a
lista no heap: endereços fora de ordem, cada nó com o endereço do próximo:

{{ideia}}

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

No fluxograma, o laço pergunta "ainda tem nó?" antes de cada passo. O `p` vai
do 80 ao 10, ao 45 e ao 20, vira `NULL` e o laço para, com total R$ 155:

{{fluxograma}}

> [!WARNING]
> `lista_insere_inicio(extrato, 20);` sem o `extrato =` compila sem aviso e
> está errado: o novo início se perde e o nó vira vazamento. No `libera`, o
> erro comum é ler `p->prox` depois de `free(p)`.

> [!TIP]
> **Por dentro do C:** em 64 bits, `sizeof(No)` é 16: 4 bytes do `int`, 4 de
> **preenchimento** (o ponteiro começa em múltiplo de 8) e 8 do ponteiro. Cada
> `malloc` ainda gasta uns 16 bytes de controle. Percorrer é O(n) como no
> vetor, mas mais lento: o **cache** lê blocos de 64 bytes e os nós ficam
> espalhados.

> [!NOTE]
> **Pergunta para você:** se você inserir no início o 5, depois o 6 e depois
> o 7, o que `lista_imprime` mostra? E quantas vezes `lista_libera` chama
> `free`?

{{pratique}}

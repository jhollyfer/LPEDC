## 0081 · Lista encadeada

Abra o extrato do Pix no app do banco: o mais recente aparece em cima. Cada
Pix novo entra na frente, e ninguém precisa empurrar os antigos para baixo.
No vetor do assunto anterior, inserir na posição 0 faria todos andarem uma
casa. Existe um jeito em que ninguém anda.

Uma **lista encadeada** guarda cada item num pedaço separado de memória, o
**nó**. Além do valor, cada nó guarda o endereço do próximo. O último aponta
para `NULL`. Para usar a lista, você só precisa do endereço do primeiro nó, o
**início**. Lista vazia é `inicio == NULL`.

O nó é uma struct que aponta para o próprio tipo, uma **struct
autorreferenciada**:

```c
typedef struct no {
    int valor;
    struct no *prox; // o próximo nó, ou NULL no último
} No;
```

Repare no `struct no *prox` dentro da própria `struct no`. Uma struct não pode
conter a si mesma (teria tamanho infinito), mas pode conter um **ponteiro**
para si mesma: um ponteiro tem sempre 8 bytes, aponte para o que apontar.

Os nós não ficam lado a lado na memória. Cada um nasce de um `malloc`
diferente e cai onde o heap tiver espaço. A ordem da lista não está nas
posições: está nas **setas**. Por isso não existe `lista[2]`: para chegar no
terceiro nó, você segue duas setas a partir do início.

Três operações formam a base, e todas estão no `lista.c` desta pasta:

- **inserir no início**: cria o nó, aponta o `prox` dele para o antigo
  início e devolve o novo nó, que passa a ser o início. É O(1): não importa o
  tamanho da lista.
- **percorrer**: `for (p = inicio; p != NULL; p = p->prox)`. É o "for de
  lista", e você vai escrever ele mil vezes.
- **liberar**: um `free` por nó, guardando o próximo **antes** do `free`.

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

Aqui a struct do nó fica no `lista.h`, à vista, de propósito: o assunto é
justamente mexer em `p->valor` e `p->prox`. Na pilha e na fila (módulo 12) ela
volta a ficar escondida no `.c`.

Vamos ver na prática. Chegam quatro Pix: R$ 20, 45, 10 e 80. Cada um entra na
frente, então o extrato mostra o 80 primeiro. Embaixo, a mesma lista como ela
está de verdade no heap: endereços fora de ordem, com outros dados no meio, e
cada nó guardando o endereço do próximo:

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

Repara no fluxograma: percorrer é um laço que pergunta "ainda tem nó?" antes
de cada passo. O `p` começa no 80, pula para o 10, o 45, o 20, e então vira
`NULL`. Aí o laço para, com o total em R$ 155:

{{fluxograma}}

> [!WARNING]
> `lista_insere_inicio(extrato, 20);` sozinho, sem o `extrato =` na frente,
> compila sem aviso e está errado. A função devolve o novo início, e você
> jogou fora. O `extrato` continua apontando para o nó antigo (ou para
> `NULL`), e o nó novo vira vazamento. Toda função que pode mudar o início
> devolve o início novo, e você **sempre** guarda: `extrato =
> lista_insere_inicio(extrato, 20);`. No `libera`, o erro clássico é o
> contrário: ler `p->prox` depois de `free(p)`.

> [!TIP]
> **Por dentro do C:** num PC de 64 bits, `sizeof(No)` é 16: 4 bytes do `int`,
> 4 de **preenchimento** (o ponteiro precisa começar num endereço múltiplo de
> 8) e 8 do ponteiro. E cada `malloc` ainda gasta uns 16 bytes de controle.
> Guardar 4 inteiros numa lista custa umas 8 vezes mais memória que num
> vetor. E tem o **cache**: o processador lê a memória em blocos de 64 bytes.
> No vetor, ler `itens[0]` já traz os vizinhos de brinde. Na lista, cada nó
> pode estar longe do anterior. Percorrer a lista é O(n), igual ao vetor, mas
> na prática bem mais lento.

> [!NOTE]
> **Pergunta para você:** se você inserir no início o 5, depois o 6 e depois
> o 7, o que `lista_imprime` mostra? E quantas vezes `lista_libera` chama
> `free`?

{{pratique}}

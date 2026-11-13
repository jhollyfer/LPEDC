## 0076 · Lista encadeada

No extrato do Pix, cada transferência nova aparece no topo, e as antigas
descem. No vetor dinâmico do assunto 0075, pôr um item na posição 0 obriga
todos os outros a andarem uma casa, O(n) a cada Pix. E quando o vetor enche,
o `realloc` copia tudo. A lista encadeada troca o vetor por peças soltas, e
inserir na frente passa a custar sempre o mesmo, com 4 itens ou com 4
milhões.

Pense numa caça ao tesouro. Cada pista está num lugar diferente da cidade e
traz o endereço da próxima; a última diz "fim". Ninguém precisa que as pistas
fiquem lado a lado, só que cada uma saiba onde está a seguinte. Uma **lista
encadeada**, que o Cormen chama de **lista ligada**, guarda cada item num
pedaço separado de memória, o **nó**. Cada nó traz o valor e o endereço do
próximo nó, e o último aponta para `NULL` (FEOFILOFF, 2009, cap. 4).

A lista inteira é representada pelo endereço do primeiro nó, o **início**
(no Cormen, `L.head`). Com ele você chega a todos os outros, seguindo as
setas. A lista vazia é simplesmente `inicio == NULL`: não há primeiro nó
(CORMEN et al., 2024, cap. 10).

O nó é uma struct com um detalhe novo: um dos campos aponta para outro nó do
mesmo tipo. Uma struct assim se chama **struct autorreferenciada**:

```c
typedef struct no {
    int valor;
    struct no *prox; // o próximo nó, ou NULL no último
} No;
```

Uma struct não pode conter a si mesma, porque teria tamanho infinito: o nó
teria um nó dentro, que teria outro, e assim por diante. Mas pode conter um
**ponteiro** para a própria struct, porque um ponteiro tem tamanho fixo, 8
bytes em 64 bits, aponte para o que apontar (KERNIGHAN; RITCHIE, 1989). Por
isso o campo é `struct no *prox`, com o nome completo da struct: dentro das
chaves, o apelido `No` ainda não existe.

Cada nó vem de um `malloc` separado e cai onde o heap tiver espaço. Os
endereços ficam fora de ordem, e a ordem da lista está só nas setas. A
consequência é que não existe `lista[2]`: para chegar ao terceiro nó, você
parte do início e segue duas setas (CELES; RANGEL, 2002). Ler a posição `i`,
que no vetor era O(1), aqui custa O(i).

Três operações formam a base. **Inserir no início** cria o nó com `malloc`,
põe o valor, aponta o `prox` dele para o antigo início e devolve o novo nó,
que passa a ser o início. São sempre os mesmos passos, sem andar pela lista:
O(1) (CELES; RANGEL, 2002). Quem chama precisa guardar o retorno, com
`inicio = lista_insere_inicio(inicio, 20);`.

**Percorrer** usa um ponteiro auxiliar `p` que começa no início e anda de nó
em nó: `for (p = inicio; p != NULL; p = p->prox)`. Esse é o "for de lista",
que você vai escrever em quase toda função do módulo. A cada volta, `p->valor`
é o valor do nó atual; quando `p` vira `NULL`, a lista acabou (FEOFILOFF,
2009, cap. 4).

**Liberar** pede um `free` por nó, porque cada nó veio de um `malloc`. O
cuidado está na ordem: guarde `p->prox` numa variável **antes** de chamar
`free(p)`, porque depois do `free` o nó não existe mais e ler o campo dele é
ler memória devolvida (CELES; RANGEL, 2002).

Inserir no **fim** é outra história. Guardando só o início, é preciso andar
até o último nó, O(n). Guardando também um ponteiro para o último, vira O(1);
os assuntos 0079 e 0086 fazem isso. O nó ocupa 16 bytes em 64 bits: 4 do
`int`, 4 de preenchimento para alinhar o ponteiro e 8 do ponteiro.

> [!WARNING]
> `lista_insere_inicio(inicio, 20);` sem o `inicio =` na frente compila sem
> aviso e está errado: o novo início se perde e o nó vira vazamento. No
> `libera`, o erro comum é ler `p->prox` depois de `free(p)`.

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

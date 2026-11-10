## 0082 · Pilha

Você monta o pedido no app de delivery: pizza, refrigerante, pudim. Toca em
"desfazer" e sai o pudim, o último que entrou.

Esse comportamento é a **pilha** (*stack*). Só o **topo** está ao alcance:
o último a entrar é o primeiro a sair, **LIFO** (*last in, first out*). A
pilha de pratos e a pilha de chamadas (assunto 0031) funcionam assim.

Quatro operações:

- **empilhar** (*push*): põe um item no topo;
- **desempilhar** (*pop*): tira o item do topo e devolve o valor;
- **olhar o topo** (*peek*): lê o topo sem tirar;
- **vazia?**: pergunta se ainda tem alguma coisa.

No Cormen, são PUSH, POP e STACK-EMPTY.

O C não traz pilha pronta. Você monta uma como **TAD** (assunto 0074): o
`pilha.h` diz **o que** a pilha faz e o `pilha.c` decide **como**. Quem usa
só inclui o `.h`:

```c
typedef struct pilha Pilha; // tipo opaco: os campos ficam no pilha.c

Pilha *pilha_cria(void);                     // pilha vazia (NULL se faltar memória)
void pilha_libera(Pilha *p);                 // devolve toda a memória da pilha
bool pilha_vazia(const Pilha *p);            // true se não tem nada
int pilha_tamanho(const Pilha *p);           // quantos itens tem
bool pilha_empilha(Pilha *p, int valor);     // push: false se não coube
bool pilha_desempilha(Pilha *p, int *valor); // pop: false se estava vazia
bool pilha_topo(const Pilha *p, int *valor); // peek: olha o topo sem tirar
```

O valor desempilhado vem pelo ponteiro; o `bool` diz se deu certo. Tirar de
pilha vazia é **underflow**; empilhar em pilha cheia é **overflow**, possível
porque o vetor tem tamanho fixo.

Esta versão usa um **vetor** e um contador `n`: o fundo fica em `itens[0]`, o
topo em `itens[n - 1]` e `n` é a próxima vaga. Trecho do
[`pilha.c`](material/0082-pilha.c):

```c
struct pilha {
    int itens[CAPACIDADE]; // CAPACIDADE = 100
    int n;                 // quantos itens estão na pilha
};

bool pilha_empilha(Pilha *p, int valor) {
    if (p->n == CAPACIDADE) {
        return false; // cheia: estouro (overflow)
    }
    p->itens[p->n] = valor;
    p->n++;
    return true;
}

bool pilha_desempilha(Pilha *p, int *valor) {
    if (p->n == 0) {
        return false; // vazia: nada para tirar (underflow)
    }
    p->n--;
    *valor = p->itens[p->n]; // o valor continua no vetor, mas saiu da pilha
    return true;
}
```

Os preços entram em centavos (2590, 800 e 1200) nas gavetas 0, 1 e 2, com `n`
igual a 3. O desfazer tira o 1200:

{{ideia}}

O programa só usa as funções do `pilha.h`:

```c
#include <stdio.h>
#include "pilha.h"

int main(void) {
    Pilha *pedido = pilha_cria();
    if (pedido == NULL) {
        return 1;
    }

    // preços em centavos: inteiro não tem erro de arredondamento
    pilha_empilha(pedido, 2590); // pizza: R$ 25,90
    pilha_empilha(pedido, 800);  // refrigerante: R$ 8,00
    pilha_empilha(pedido, 1200); // pudim: R$ 12,00

    int preco;
    if (pilha_desempilha(pedido, &preco)) { // "desfazer": sai o último que entrou
        printf("Desfeito: R$ %d,%02d\n", preco / 100, preco % 100);
    }
    if (pilha_topo(pedido, &preco)) { // só olha, não tira
        printf("Agora no topo: R$ %d,%02d\n", preco / 100, preco % 100);
    }
    printf("Itens no pedido: %d\n", pilha_tamanho(pedido));

    pilha_libera(pedido);
    return 0;
}
// Saída:
// Desfeito: R$ 12,00
// Agora no topo: R$ 8,00
// Itens no pedido: 2
```

O fluxograma do desfazer testa se a pilha está vazia antes de diminuir `n`:

{{fluxograma}}

> [!WARNING]
> Ler `itens[n]` antes de diminuir `n` pega a gaveta **vazia** acima do topo
> (lixo). Aqui `n` é a próxima vaga: empilha em `itens[n]` e depois `n++`;
> desempilha com `n--` e depois lê. Muito livro usa `topo = -1` para pilha
> vazia; não misture as convenções. O Cormen indexa a partir de 1: pilha vazia
> é `S.top = 0`.

> [!TIP]
> Desempilhar não apaga: o 1200 continua na gaveta 2 e o próximo `push`
> escreve por cima. Por isso as duas operações custam **O(1)**.

> [!NOTE]
> **Pergunta para você:** no programa do pedido, se o cliente tocar em
> "desfazer" mais três vezes seguidas, o que cada chamada de
> `pilha_desempilha` devolve? E o que fica em `preco` na última?

{{pratique}}

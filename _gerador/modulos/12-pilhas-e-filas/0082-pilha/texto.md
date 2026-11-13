## 0082 · Pilha

- **Pilha** (*stack*): só o **topo** está ao alcance. O último a entrar é o
  primeiro a sair, **LIFO** (*last in, first out*) (FEOFILOFF, 2009).
- **Operações**: **empilhar** (*push*) põe no topo; **desempilhar** (*pop*)
  tira do topo e devolve o valor; **olhar o topo** (*peek*) lê sem tirar;
  **vazia?** No Cormen, PUSH, POP e STACK-EMPTY (CORMEN et al., 2024,
  cap. 10).
- **Underflow e overflow**: tirar de pilha vazia é **underflow**; empilhar
  em pilha cheia é **overflow**, possível porque o vetor tem tamanho fixo
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 2).
- **Em vetor**: um contador `n`; o fundo fica em `itens[0]`, o topo em
  `itens[n - 1]` e `n` é a próxima vaga (FEOFILOFF, 2009).
- **Custo**: empilhar e desempilhar são O(1). Desempilhar não apaga: o valor
  fica no vetor e o próximo `push` escreve por cima (CELES; RANGEL, 2002).
- **TAD** (0074): o C não traz pilha pronta. O `pilha.h` diz **o que** a
  pilha faz; o `pilha.c` decide **como**. O valor desempilhado vem pelo
  ponteiro e o `bool` diz se deu certo (CELES; RANGEL, 2002).

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

> [!WARNING]
> Ler `itens[n]` antes de diminuir `n` pega a gaveta **vazia** acima do topo.
> Aqui `n` é a próxima vaga: empilha em `itens[n]` e depois `n++`; desempilha
> com `n--` e depois lê. Muito livro usa `topo = -1`: não misture convenções.

{{exemplo}}

No app de delivery, os preços entram em centavos (2590, 800 e 1200) nas
gavetas 0, 1 e 2, com `n` igual a 3. O "desfazer" tira o 1200, o último:

{{ideia}}

Trecho do `pilha.c`:

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

O desfazer testa se a pilha está vazia antes de diminuir `n`:

{{fluxograma}}

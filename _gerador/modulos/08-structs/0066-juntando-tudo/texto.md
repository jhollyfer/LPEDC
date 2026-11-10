## 0066 · Juntando tudo: o cardápio

A lanchonete quer um cardápio no app. Cada item tem nome, preço, categoria
(lanche, bebida ou sobremesa) e marcações: vegano, sem glúten, picante. O
cliente quer filtrar "só o que é vegano **e** sem glúten", e o dono quer
cadastrar itens sem mexer no código.

Cada peça do módulo resolve uma parte. A struct `Item` junta os dados e o
typedef encurta os tipos. O enum `Categoria` nomeia as categorias, e o
`QTD_CATEGORIAS` dimensiona o vetor de nomes. As marcações são flags num
`unsigned tags`, e o filtro é uma máscara. Os itens moram num vetor de structs
no heap, que cresce com `realloc`. As funções recebem ponteiros: `Cardapio *c`
para mexer no cardápio e `const Item *it` para só ler um item sem copiá-lo.

O `Cardapio` é uma struct que administra um vetor: guarda o ponteiro para os
itens, quantos existem (`n`) e quantos cabem (`cap`). Quando enche, dobra a
capacidade: de 0 vai a 2, 4 e 8, e com 6 itens sobram 2 vagas. Esse trio
(ponteiro, tamanho, capacidade) é a semente do **vetor dinâmico** que o
módulo 11 transforma em tipo abstrato de dados.

O filtro cabe numa linha. O item passa se tem **todas** as tags da máscara:
`(tags & mascara) == mascara`. O `&` apaga as tags fora da máscara; se sobra a
própria máscara, nenhuma faltou. Com máscara 0, todo item passa, e o mesmo
`filtrar` lista o cardápio inteiro.

O suco de caju tem as tags `011` (vegano e sem glúten). Contra a máscara
`011`, o `&` devolve `011`: passa. O burger de grão-de-bico tem `001`: o `&`
devolve `001`, falta o sem glúten, e ele fica de fora:

{{ideia}}

```c
#include <stdio.h>
#include <stdlib.h>

typedef enum { LANCHE, BEBIDA, SOBREMESA, QTD_CATEGORIAS } Categoria;

// flags: cada característica é um bit
#define VEGANO     (1u << 0)
#define SEM_GLUTEN (1u << 1)
#define PICANTE    (1u << 2)

typedef struct {
    char nome[32];
    Categoria categoria;
    double preco;
    unsigned tags;
} Item;

typedef struct {
    Item *itens; // vetor no heap
    int n;       // quantos itens tem
    int cap;     // quantos cabem
} Cardapio;

int cardapio_adicionar(Cardapio *c, Item it) {
    if (c->n == c->cap) {
        int nova = c->cap == 0 ? 2 : 2 * c->cap;
        Item *novo = realloc(c->itens, nova * sizeof *novo);
        if (novo == NULL) {
            return 0;
        }
        c->itens = novo;
        c->cap = nova;
    }
    c->itens[c->n++] = it; // copia a struct inteira para dentro do vetor
    return 1;
}

void mostrar_item(const Item *it) {
    const char *categorias[QTD_CATEGORIAS] = {"lanche", "bebida", "sobremesa"};
    printf("  R$ %5.2f  %s (%s)%s%s%s\n", it->preco, it->nome, categorias[it->categoria],
           (it->tags & VEGANO) ? " [V]" : "",
           (it->tags & SEM_GLUTEN) ? " [SG]" : "",
           (it->tags & PICANTE) ? " [P]" : "");
}

// mostra os itens que têm TODAS as tags da máscara
void filtrar(const Cardapio *c, unsigned mascara) {
    for (int i = 0; i < c->n; i++) {
        if ((c->itens[i].tags & mascara) == mascara) {
            mostrar_item(&c->itens[i]);
        }
    }
}

int main(void) {
    Cardapio c = {NULL, 0, 0};
    Item itens[] = {
        {"X-Burger", LANCHE, 28.90, 0},
        {"Burger de grão-de-bico", LANCHE, 32.00, VEGANO},
        {"Tapioca de frango", LANCHE, 18.50, SEM_GLUTEN},
        {"Asinha apimentada", LANCHE, 24.00, PICANTE | SEM_GLUTEN},
        {"Suco de caju", BEBIDA, 9.00, VEGANO | SEM_GLUTEN},
        {"Pudim", SOBREMESA, 12.00, SEM_GLUTEN},
    };
    int n = sizeof itens / sizeof itens[0];

    for (int i = 0; i < n; i++) {
        if (!cardapio_adicionar(&c, itens[i])) {
            free(c.itens);
            return 1;
        }
    }

    printf("Cardápio (%d itens, capacidade %d):\n", c.n, c.cap);
    filtrar(&c, 0); // máscara vazia: todo item passa
    printf("Veganos e sem glúten:\n");
    filtrar(&c, VEGANO | SEM_GLUTEN);

    free(c.itens);
    return 0;
}
// Saída:
// Cardápio (6 itens, capacidade 8):
//   R$ 28.90  X-Burger (lanche)
//   R$ 32.00  Burger de grão-de-bico (lanche) [V]
//   R$ 18.50  Tapioca de frango (lanche) [SG]
//   R$ 24.00  Asinha apimentada (lanche) [SG] [P]
//   R$  9.00  Suco de caju (bebida) [V] [SG]
//   R$ 12.00  Pudim (sobremesa) [SG]
// Veganos e sem glúten:
//   R$  9.00  Suco de caju (bebida) [V] [SG]
```

O fluxograma é o do `filtrar`: um laço sobre o vetor e uma pergunta de bits
por item, para qualquer máscara:

{{fluxograma}}

> [!WARNING]
> `c->itens[c->n++] = it` copia o item para **dentro** do vetor: mexer depois
> em `it` (ou no vetor `itens` do `main`) não muda o cardápio. O inverso
> também engana: `Item *p = &c.itens[0]` fica **solto** após o próximo
> `realloc`, porque o vetor pode ter mudado de endereço. Em vetor que cresce,
> guarde índices, não ponteiros.

> [!TIP]
> Um `Item` ocupa 56 bytes: 32 do nome, 4 da categoria, 4 de preenchimento
> para alinhar o `double`, 8 do preço, 4 das tags e 4 de preenchimento no fim,
> para o próximo item também começar alinhado. Confira com
> `printf("%zu\n", sizeof(Item))`.

> [!NOTE]
> **Pergunta para você:** que máscara lista os itens que são sem glúten **e**
> picantes? E como você escreveria um filtro "tem **alguma** destas tags", em
> vez de "tem todas"?

{{pratique}}

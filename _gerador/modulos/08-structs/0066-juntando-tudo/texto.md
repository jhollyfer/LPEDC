## 0066 · Juntando tudo: o cardápio

A lanchonete quer um cardápio no app. Cada item tem nome, preço, categoria
(lanche, bebida ou sobremesa) e marcações: vegano, sem glúten, picante. O
cliente quer filtrar "só o que é vegano **e** sem glúten", e o dono quer
cadastrar itens novos sem mudar o código. Nenhuma peça do módulo resolve isso
sozinha; juntas, resolvem com pouco código.

Pense numa ficha de cardápio impressa: cada prato tem as suas informações
numa linha, e símbolos pequenos ao lado do nome marcam as restrições. O
programa monta essa ficha com uma struct. `Item` junta nome, categoria, preço
e marcações, e o `typedef` dá a ela um nome curto, como nos assuntos 0059 e
0060 (BACKES, 2013, cap. 8).

A categoria é uma escolha entre três valores fixos, o caso exato do enum do
assunto 0063. `Categoria` dá nome a `LANCHE`, `BEBIDA` e `SOBREMESA`, e um
último nome, `QTD_CATEGORIAS`, vale 3 e dimensiona o vetor de textos que
traduz cada categoria para a tela (DEITEL; DEITEL, 2011, cap. 10). Se a
lanchonete criar a categoria "porção", o vetor acompanha.

As marcações são sim ou não, e um item pode ter várias ao mesmo tempo. Isso
pede as flags do assunto 0065: vegano é o bit 0, sem glúten o bit 1, picante
o bit 2, todos num `unsigned tags` (DEITEL; DEITEL, 2011, cap. 10). O suco
de caju, vegano e sem glúten, tem `tags = VEGANO | SEM_GLUTEN`, o binário
`011`.

O filtro "tem todas estas marcações" cabe numa linha:
`(tags & mascara) == mascara`. A máscara traz ligados os bits que o cliente
exige. O `&` apaga as tags do item que estão fora da máscara; se o que sobra
é a própria máscara, nenhuma exigência faltou. O suco (`011`) contra a máscara
`011` dá `011`, e passa. O burger de grão-de-bico (`001`) dá `001`: falta o
sem glúten, e ele fica de fora. Com máscara 0, a conta sempre dá 0, que é
igual à máscara, e todo item passa; a mesma função lista o cardápio inteiro.

Os itens moram num vetor de structs, como a tabela do assunto 0061, mas no
heap, porque o dono não sabe quantos vão ser. Uma struct `Cardapio`
administra esse vetor com três dados: o ponteiro para os itens, quantos
existem (`n`) e quantos cabem (`cap`). Quando `n` chega a `cap`, o
`realloc` dobra a capacidade: de 0 vai a 2, depois 4, depois 8. Com 6 itens,
sobram 2 vagas. Esse trio de ponteiro, tamanho e capacidade é a semente do
**vetor dinâmico** que o módulo 11 transforma em tipo abstrato (CELES; RANGEL,
2002).

As funções recebem ponteiros, como no assunto 0062. `cardapio_adicionar`
recebe `Cardapio *c`, porque precisa mudar `n`, `cap` e o próprio ponteiro
dos itens. `mostrar_item` recebe `const Item *it`, porque só lê: o ponteiro
evita copiar os 56 bytes de cada item, e o `const` garante que nada muda
(FEOFILOFF, 2009, ap. E). Esses 56 bytes são 32 do nome, 4 da categoria, 4 de
preenchimento para alinhar o `double`, 8 do preço, 4 das tags e mais 4 de
preenchimento no fim, para o próximo item do vetor também começar alinhado.

> [!WARNING]
> `c->itens[c->n++] = it` copia o item para **dentro** do vetor: mexer depois
> em `it` não muda o cardápio. E `Item *p = &c.itens[0]` fica **solto** após o
> próximo `realloc`, porque o vetor pode ter mudado de endereço. Em vetor que
> cresce, guarde índices, não ponteiros.

{{exemplo}}

O cardápio da lanchonete tem 6 itens. O suco de caju tem as tags `011` (vegano
e sem glúten) e passa na máscara `011`; o burger de grão-de-bico tem `001`,
falta o sem glúten, e fica de fora:

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

O fluxograma é o do `filtrar`: um laço sobre o vetor e uma pergunta de bits por
item, para qualquer máscara:

{{fluxograma}}

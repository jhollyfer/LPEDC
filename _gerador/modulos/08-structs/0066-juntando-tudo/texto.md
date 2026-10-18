## 0066 · Juntando tudo: o cardápio

A lanchonete do bairro quer um cardápio no app. Cada item tem nome, preço,
uma categoria (lanche, bebida ou sobremesa) e algumas marcações: vegano, sem
glúten, picante. O cliente quer filtrar: "só o que é vegano **e** sem glúten".
E o dono quer cadastrar itens novos sem mexer no código toda vez.

Cada peça do módulo resolve uma parte. A **struct** `Item` junta os dados de
um item, e o **typedef** dá nomes curtos aos tipos. O **enum** `Categoria`
nomeia as categorias, e o truque do `QTD_CATEGORIAS` dimensiona o vetor de
nomes. As marcações são **flags** num `unsigned tags`, e o filtro é uma
**máscara**. Os itens moram num **vetor de structs no heap**, que cresce com
`realloc`, e as funções recebem **ponteiros para struct**: `Cardapio *c` para
mexer no cardápio, `const Item *it` para só ler um item sem copiá-lo.

O `Cardapio` é uma struct que **administra** um vetor: guarda o ponteiro para
os itens, quantos existem (`n`) e quantos cabem (`cap`). Quando enche, dobra a
capacidade. Começando em 0, ela vira 2, 4 e 8: com 6 itens, sobram 2 vagas.
Esse trio (ponteiro, tamanho, capacidade) é a semente do **vetor dinâmico**
que o módulo 11 transforma num tipo abstrato de dados.

O filtro é a parte mais elegante. Um item passa se tem **todas** as tags da
máscara: `(tags & mascara) == mascara`. O `&` apaga as tags que não estão na
máscara; se o que sobra é a própria máscara, nenhuma faltou. Com a máscara 0,
qualquer item passa, e o mesmo `filtrar` lista o cardápio inteiro.

Vamos ver na prática. O suco de caju tem as tags `011` (vegano e sem glúten).
Contra a máscara `011`, o `&` devolve `011`, igual à máscara: passa. O burger
de grão-de-bico tem `001`: o `&` devolve `001`, falta o sem glúten, e ele fica
de fora:

{{ideia}}

O programa completo:

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

Repara no fluxograma do `filtrar`: um laço sobre o vetor e uma única
pergunta de bits por item. O mesmo desenho serve para qualquer máscara:

{{fluxograma}}

> [!WARNING]
> `c->itens[c->n++] = it` copia o item para **dentro** do vetor. Depois disso,
> mexer na variável `it` (ou no vetor `itens` do `main`) não muda o cardápio.
> O contrário também pega muita gente: um ponteiro para um item,
> `Item *p = &c.itens[0]`, pode ficar **solto** depois do próximo `realloc`,
> porque o vetor inteiro pode ter mudado de endereço. Guarde índices, não
> ponteiros, para elementos de um vetor que cresce.

> [!TIP]
> **Por dentro do C:** um `Item` ocupa 56 bytes: 32 do nome, 4 da categoria
> (um enum é um `int`), 4 de sobra para alinhar o `double`, 8 do preço, 4 das
> tags e mais 4 de sobra no fim, para o próximo item do vetor também começar
> alinhado. As três marcações, como três `bool`, custariam 3 bytes e três
> `if` no filtro. Como flags, custam 4 bytes para até 32 marcações, e o teste
> de "tem todas" é um `and` e uma comparação, qualquer que seja a máscara.
> Confira com `printf("%zu\n", sizeof(Item))`.

> [!NOTE]
> **Pergunta para você:** que máscara lista os itens que são sem glúten **e**
> picantes? E como você escreveria um filtro "tem **alguma** destas tags", em
> vez de "tem todas"?

{{pratique}}

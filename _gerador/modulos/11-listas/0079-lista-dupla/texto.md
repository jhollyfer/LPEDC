## 0079 · Lista dupla

A lista simples dos assuntos anteriores só anda para a frente. Isso cobra
dois preços (CELES; RANGEL, 2002). Para mostrar os itens de trás para frente,
não há caminho de volta. E para remover um nó que você já tem em mãos, ainda
é preciso achar o anterior dele, percorrendo a lista desde o início, O(n),
porque só o anterior pode ser religado.

No pátio da ferrovia, o terceiro vagão de um trem de minério está com o
freio travado. O manobrista solta os dois engates dele e liga o segundo vagão
direto ao quarto. Ele não volta à locomotiva para descobrir quem vem antes:
cada vagão está preso ao da frente e ao de trás, e ele vê os dois. A **lista
duplamente encadeada** (no Cormen, **duplamente ligada**, com os campos
`next` e `prev`) faz o mesmo: cada nó guarda o próximo, `prox`, e também o
anterior, `ant` (CORMEN et al., 2024, cap. 10).

Com a seta a mais, três coisas ficam possíveis (TENENBAUM; LANGSAM;
AUGENSTEIN, 1995, cap. 4). Você anda nos **dois sentidos**: de trás para a
frente é o "for de lista" de sempre, começando no último nó e andando com
`p = p->ant`. Você remove um nó conhecendo **só ele**, em O(1), porque o
anterior está em `p->ant`. E, guardando um ponteiro para o **último** nó,
inserir no fim também vira O(1), sem percorrer nada.

A lista desta pasta junta essas peças numa struct com as duas pontas e o
tamanho:

```c
typedef struct no {
    int valor;
    struct no *ant;  // o anterior, ou NULL no primeiro
    struct no *prox; // o próximo, ou NULL no último
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;
```

Repare que agora a lista não é mais só um ponteiro para o primeiro nó. A
struct `Lista` carrega o `inicio`, o `fim` e quantos nós existem, e as
funções recebem `Lista *` para poder atualizar os três.

As setas de ida e as de volta precisam concordar. Para todo nó `p` que não é
o último, vale `p->prox->ant == p`: o anterior do meu próximo sou eu. Essa
regra é o invariante da lista dupla, e ela tem uma consequência prática: as
setas mudam sempre **aos pares**. Toda operação que mexe na seta de ida de um
nó precisa mexer na seta de volta correspondente (FEOFILOFF, 2009, cap. 4).

Remover um nó `p` mostra isso. Chegam duas setas em `p`: a do anterior, que
aponta para ele pela frente, e a do seguinte, que aponta para ele por trás.
As duas precisam ser desviadas, e cada uma tem o seu caso de borda (CELES;
RANGEL, 2002):

```c
if (p->ant == NULL) l->inicio = p->prox;  // era o primeiro
else p->ant->prox = p->prox;              // o anterior pula o p
if (p->prox == NULL) l->fim = p->ant;     // era o último
else p->prox->ant = p->ant;               // o seguinte pula o p para trás
free(p);
```

Se `p` é o primeiro, não há anterior para religar, e quem muda é o
`inicio`. Se `p` é o último, não há seguinte, e quem muda é o `fim`. Um nó
do meio passa pelos dois `else`. Um nó sozinho na lista passa pelos dois
`if`, e a lista fica vazia, com `inicio` e `fim` em `NULL`.

A seta a mais tem um preço em memória. Em 64 bits, `sizeof(No)` passa de 16
para 24 bytes: 4 do `int`, 4 de preenchimento e dois ponteiros de 8. São 50%
a mais por nó, o custo de poder voltar e de remover em O(1).

> [!WARNING]
> Com uma seta faltando, a lista dupla **parece certa**: se a inserção
> esquecer o `ant`, só a volta sai errada. Imprima **nos dois sentidos**. Na
> remoção, `p->ant->prox` no primeiro nó acessa `NULL`, e esquecer o `fim` o
> deixa apontando para memória liberada.

{{exemplo}}

Um trem de minério tem vagões de 98, 105, 87 e 110 toneladas, e o de 87 está
com o freio travado. Com `p` nele, o 105 passa a apontar para o 110, e o 110
aponta de volta para o 105:

{{ideia}}

A remoção, sem procurar o anterior:

```c
void lista_remove_no(Lista *l, No *p) {
    if (p->ant == NULL) l->inicio = p->prox;  // era o primeiro
    else p->ant->prox = p->prox;              // o anterior pula o p
    if (p->prox == NULL) l->fim = p->ant;     // era o último
    else p->prox->ant = p->ant;               // o seguinte pula o p para trás
    free(p);
    l->tamanho--;
}
```

```c
#include <stdio.h>
#include "lista.h"

int main(void) {
    Lista trem;
    lista_inicia(&trem);
    int cargas[] = {98, 105, 87, 110}; // toneladas, da locomotiva para o fim
    for (int i = 0; i < 4; i++) lista_insere_fim(&trem, cargas[i]);

    printf("da locomotiva: ");
    lista_imprime(&trem);
    printf("do fim:        ");
    lista_imprime_reverso(&trem);

    No *vagao = lista_busca(&trem, 87);
    if (vagao != NULL) {
        lista_remove_no(&trem, vagao); // sem procurar o anterior: p->ant
        printf("desengatou o vagão de 87 t (%d vagões)\n", trem.tamanho);
    }

    printf("da locomotiva: ");
    lista_imprime(&trem);
    printf("do fim:        ");
    lista_imprime_reverso(&trem);

    lista_libera(&trem);
    return 0;
}
// Saída:
// da locomotiva: 98 <-> 105 <-> 87 <-> 110
// do fim:        110 <-> 87 <-> 105 <-> 98
// desengatou o vagão de 87 t (3 vagões)
// da locomotiva: 98 <-> 105 <-> 110
// do fim:        110 <-> 105 <-> 98
```

Duas perguntas, uma por ponta. O vagão de 87 passa pelos dois Não; o primeiro
vagão daria Sim na primeira, o último na segunda:

{{fluxograma}}

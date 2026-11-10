## 0106 · Encadeamento

No hortifrúti, o estoque fica em 5 prateleiras. Quando duas frutas caem na
mesma, ficam **lado a lado**, e achar o kiwi é olhar só a prateleira 1.

Esse é o **encadeamento** (ou encadeamento separado), a primeira forma de
tratar colisão. Cada balde guarda a **cabeça de uma lista encadeada** com os
itens cujo hash caiu ali, e a tabela vira um vetor de ponteiros: `No *baldes[m]`.

As operações são as de lista do módulo 11, precedidas do cálculo do balde
`i = hash(chave) % m`:

- **inserir**: procura a chave na lista de `baldes[i]`; se achar, troca o
  valor; se não, cria um nó **no início** da lista, em O(1);
- **buscar**: percorre só a lista de `baldes[i]`;
- **remover**: remoção de lista, guardando o anterior.

Com hash que espalha bem, cada lista tem em média `α = n / m` nós, e buscar
custa Θ(1 + α) (teorema do Cormen, com hashing uniforme). Se `m` cresce junto
com `n`, α fica constante e a busca é O(1) na média. No pior caso, com um hash
ruim que joga tudo num balde, a tabela vira uma lista única e a busca é O(n).

A tabela **nunca enche**: α pode passar de 1 (exemplo A211: 8 itens em 2 baldes).

Seis frutas entram na ordem banana, uva, pera, kiwi, manga e caju, com o hash
polinomial do assunto 0105 e `m = 5`. Os índices saem 4, 2, 4, 1, 1 e 4. Como
cada nova entra no início, o balde 4 termina com caju, pera, banana. Buscar
"kiwi" leva ao balde 1: compara com "manga" e com "kiwi", 2 comparações:

{{ideia}}

A estrutura segue o padrão TAD: `tabela.h` com a interface e o tipo opaco,
`tabela.c` com o nó, os baldes e as operações:

```c
typedef struct No {
    char chave[TAM_CHAVE]; // cópia da chave (não um ponteiro emprestado)
    int valor;
    struct No *prox;
} No;

struct Tabela {
    int m;       // número de baldes
    int n;       // número de itens
    No **baldes; // vetor de m cabeças de lista
};

bool tabela_busca(const Tabela *t, const char *chave, int *valor, int *comparacoes) {
    int i = (int)(hash(chave) % (unsigned)t->m);
    int olhados = 0;
    for (No *p = t->baldes[i]; p != NULL; p = p->prox) {
        olhados++;
        if (strcmp(p->chave, chave) == 0) {
            *valor = p->valor;
            if (comparacoes != NULL) {
                *comparacoes = olhados;
            }
            return true;
        }
    }
    if (comparacoes != NULL) {
        *comparacoes = olhados;
    }
    return false;
}
```

O cliente conhece só o `tabela.h`:

```c
#include <stdio.h>
#include "tabela.h"

int main(void) {
    Tabela *estoque = tabela_cria(5);
    if (estoque == NULL) {
        return 1;
    }
    const char *frutas[] = {"banana", "uva", "pera", "kiwi", "manga", "caju"};
    int caixas[] = {12, 30, 8, 5, 20, 14};
    for (int i = 0; i < 6; i++) {
        tabela_insere(estoque, frutas[i], caixas[i]);
    }
    tabela_mostra(estoque);

    int qtd, olhados;
    if (tabela_busca(estoque, "kiwi", &qtd, &olhados)) {
        printf("kiwi: %d caixas (%d comparações)\n", qtd, olhados);
    }
    if (!tabela_busca(estoque, "limao", &qtd, &olhados)) {
        printf("limao: não tem (%d comparações)\n", olhados);
    }
    tabela_libera(estoque);
    return 0;
}
// Saída:
// [0]
// [1] -> manga:20 -> kiwi:5
// [2] -> uva:30
// [3]
// [4] -> caju:14 -> pera:8 -> banana:12
// kiwi: 5 caixas (2 comparações)
// limao: não tem (0 comparações)
```

No fluxograma da busca, o hash leva ao balde e o resto é o laço de lista. O
"kiwi" dá uma volta (passa pela manga) e para no Sim. O "limao" cai no balde 0,
vazio, e sai pelo Não na primeira pergunta:

{{fluxograma}}

> [!WARNING]
> Compare chave de texto com `strcmp`, nunca com `==`: `p->chave == chave`
> compara **endereços**. Pode funcionar com literais e quebra com chave vinda do
> teclado. O nó guarda a sua **cópia** da chave, porque o buffer de quem
> chamou é reaproveitado.

> [!TIP]
> **Por dentro do C:** cada nó é um `malloc` separado (`sizeof(No)` = 48).
> `tabela_libera` precisa dar `free` em **todos** os nós, guardando o `prox`
> antes; `free(t->baldes)` sozinho vaza as correntes.

> [!NOTE]
> **Pergunta para você:** insira "limao" com 9 caixas e busque "coco" (também
> do balde 0): quantas comparações? E se a inserção fosse no fim da corrente?
> Teste no `main` acima.

{{pratique}}

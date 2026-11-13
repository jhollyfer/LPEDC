## 0083 · Pilha encadeada

- **Pilha encadeada**: cada item fica num **nó** alocado com `malloc`, como
  na lista do módulo 11. A pilha só "enche" quando acaba a memória
  (CELES; RANGEL, 2002).
- **Topo no começo da lista**: inserir e remover no início é O(1). Remover
  do fim exigiria achar o penúltimo, O(n) (FEOFILOFF, 2009).
- **Empilhar** = inserir no início: o novo nó aponta para o antigo topo, e o
  topo passa a ser o novo (DEITEL; DEITEL, 2011, cap. 12).
- **Desempilhar** = remover do início: guarda o valor, avança o topo e
  libera o nó velho. **Vazia** é `topo == NULL` (DEITEL; DEITEL, 2011,
  cap. 12).
- **Mesma interface**: o `pilha.h` é idêntico ao do 0082; só o `pilha.c`
  muda, e quem usa não percebe a troca (CELES; RANGEL, 2002).
- **Custo de espaço**: cada nó ocupa 16 bytes em 64 bits, contra 4 por item
  no vetor. A encadeada troca espaço por não ter teto.

> [!WARNING]
> Trocar a ordem destrói a pilha: com `p->topo = novo` antes de
> `novo->prox = p->topo`, o nó aponta para **ele mesmo** e os de baixo vazam.
> No desempilhar, ler `velho->valor` **depois** do `free` é
> `heap-use-after-free`.

{{exemplo}}

Na planilha, a célula B2 foi de R$ 1500 para 1800, 2100 e 2500. Antes de cada
edição, o valor antigo vai para a pilha; o 2100 fica no primeiro nó e o
primeiro Ctrl+Z o devolve:

{{ideia}}

A struct agora guarda um ponteiro:

```c
typedef struct no {
    int valor;
    struct no *prox; // o nó de baixo
} No;

struct pilha {
    No *topo; // NULL quando a pilha está vazia
    int n;    // quantos itens (para pilha_tamanho não percorrer a lista)
};

bool pilha_empilha(Pilha *p, int valor) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return false; // só "enche" quando acaba a memória
    }
    novo->valor = valor;
    novo->prox = p->topo; // o novo aponta para o antigo topo
    p->topo = novo;       // e passa a ser o topo
    p->n++;
    return true;
}

bool pilha_desempilha(Pilha *p, int *valor) {
    if (p->topo == NULL) {
        return false;
    }
    No *velho = p->topo;
    *valor = velho->valor; // lê ANTES de liberar
    p->topo = velho->prox;
    free(velho);
    p->n--;
    return true;
}
```

O programa da planilha:

```c
#include <stdio.h>
#include "pilha.h"

int main(void) {
    Pilha *desfazer = pilha_cria();
    if (desfazer == NULL) {
        return 1;
    }

    int celula = 1500; // B2: orçamento do mês, em R$
    int novos[] = {1800, 2100, 2500};
    for (int i = 0; i < 3; i++) {
        pilha_empilha(desfazer, celula); // guarda o valor antigo antes de mudar
        celula = novos[i];
        printf("B2 = %d\n", celula);
    }

    // a pilha agora é: topo -> 2100 -> 1800 -> 1500 -> NULL
    for (int i = 0; i < 2; i++) { // Ctrl+Z duas vezes
        if (pilha_desempilha(desfazer, &celula)) {
            printf("Ctrl+Z: B2 = %d\n", celula);
        }
    }
    printf("Ainda dá para desfazer %d vez(es)\n", pilha_tamanho(desfazer));

    pilha_libera(desfazer); // libera o nó que sobrou e a própria pilha
    return 0;
}
// Saída:
// B2 = 1800
// B2 = 2100
// B2 = 2500
// Ctrl+Z: B2 = 2100
// Ctrl+Z: B2 = 1800
// Ainda dá para desfazer 1 vez(es)
```

Ao empilhar o 2100, o novo nó aponta primeiro para o topo antigo; só depois o
topo muda:

{{fluxograma}}

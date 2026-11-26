## 0083 · Pilha encadeada

A pilha do 0082 mora num vetor de 100 posições. Isso basta para um pedido de
delivery, mas não para o Ctrl+Z de uma planilha: ninguém sabe quantas edições
a pessoa vai fazer antes de desfazer. Com teto fixo, a edição 101 dá overflow
e o histórico se perde. O que falta é uma pilha que cresça enquanto houver
memória.

A saída é a lista encadeada do módulo 11. Em vez de gavetas lado a lado, cada
item fica num **nó**, um bloco alocado com `malloc` que guarda o valor e o
endereço do nó seguinte. A **pilha encadeada** é uma pilha montada sobre essa
lista: ela só "enche" quando o `malloc` não consegue mais memória e devolve
`NULL` (CELES; RANGEL, 2002). Pense numa corrente de clipes: você engata um
clipe novo na ponta e a corrente cresce um elo, sem precisar reservar espaço
antes.

A primeira escolha é em que ponta da lista fica o topo. Fica no **começo**.
Inserir ou remover o primeiro nó custa O(1), porque só o ponteiro de entrada
muda. Remover o último exigiria achar o **penúltimo** para que ele passasse a
apontar para `NULL`, e numa lista simples isso obriga a percorrer todos os
nós, O(n) (FEOFILOFF, 2009). Como a pilha só mexe numa ponta, você escolhe a
ponta barata.

**Empilhar**, então, é inserir no início. O nó novo recebe o valor, passa a
apontar para o antigo topo, e o topo passa a ser o nó novo (DEITEL; DEITEL,
2011, cap. 12). A ordem dessas duas atribuições é tudo: primeiro o nó novo
segura o resto da pilha, depois a pilha passa a começar nele.

```c
novo->prox = p->topo; // 1º: o novo segura o resto da pilha
p->topo = novo;       // 2º: a pilha passa a começar no novo
```

**Desempilhar** é remover do início. Você guarda o endereço do nó do topo,
copia o valor dele, avança o topo para o nó de baixo e só então libera o nó
velho com `free`. A pilha está **vazia** quando `topo == NULL`, e esse é o
teste de underflow desta versão (DEITEL; DEITEL, 2011, cap. 12).

O melhor da troca é que quem usa a pilha não percebe nada. O `pilha.h` é
idêntico ao do 0082; só o `pilha.c` muda. O programa do delivery compila e
roda sem alterar uma linha, porque ele conhece as operações e não os campos
(CELES; RANGEL, 2002). É para isso que serve o tipo opaco do TAD: trocar a
implementação sem mexer em quem usa.

Não ter teto tem preço em espaço. Num sistema de 64 bits, cada nó ocupa 16
bytes: 4 do `int`, 4 de preenchimento para alinhar o ponteiro e 8 do próprio
ponteiro, como você viu no 0076. No vetor, o mesmo item ocupa 4 bytes. A
pilha encadeada gasta quatro vezes mais memória por item e, em troca, nunca
recusa um `push` enquanto houver memória livre.

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

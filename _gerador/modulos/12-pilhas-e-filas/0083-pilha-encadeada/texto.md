## 0083 · Pilha encadeada

Na planilha do orçamento, a célula B2 começou em R$ 1500 e você mudou para
1800, 2100 e 2500. Agora aperta Ctrl+Z duas vezes. A planilha não sabe quantas
vezes você vai editar: pode ser 3, pode ser 3 mil. Uma pilha com
`CAPACIDADE 100` fixa não serve.

A pilha do 0082 tem um teto porque mora num vetor. A saída é guardar cada item
num **nó** alocado com `malloc`, como na lista encadeada do módulo 11. A pilha
cresce um nó por vez e só "enche" quando acaba a memória.

A pergunta que decide tudo: **o topo fica no começo ou no fim da lista?** No
começo. Inserir e remover no início de uma lista simples custa O(1): você
mexe só no ponteiro de entrada. No fim, para remover o último você precisaria
achar o **penúltimo**, e isso exige percorrer a lista inteira, O(n). Então:

- **empilhar** = inserir no início: o novo nó aponta para o antigo topo, e o
  topo passa a ser o novo;
- **desempilhar** = remover do início: guarda o valor, avança o topo, libera
  o nó velho;
- **vazia** = `topo == NULL`.

O melhor: o [`pilha.h`](0083-pilha-encadeada/pilha.h) é **idêntico** ao do
0082. Só o [`pilha.c`](0083-pilha-encadeada/pilha.c) mudou. Esse é o ganho do
TAD: o programa do delivery do 0082 roda sem mudar uma vírgula com esta
implementação.
Por dentro, a struct agora guarda um ponteiro:

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

Vamos ver na prática. Antes de cada edição, o valor antigo da B2 vai para a
pilha: 1500, depois 1800, depois 2100. O último a entrar, 2100, fica no
primeiro nó, e é ele que o primeiro Ctrl+Z devolve:

{{ideia}}

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

Repara no fluxograma do empilhar o 2100: a ordem das duas ligações importa.
Primeiro o novo nó aponta para o topo antigo, só depois o topo muda:

{{fluxograma}}

> [!WARNING]
> Troque a ordem e você perde a pilha inteira. Se fizer `p->topo = novo`
> antes de `novo->prox = p->topo`, o novo nó aponta para **ele mesmo**, e os
> nós 1800 e 1500 ficam sem ninguém apontando para eles: vazamento de memória
> e uma pilha que só tem o 2100 em loop. No desempilhar, o perigo é o
> contrário: ler `velho->valor` **depois** do `free(velho)` é usar memória
> liberada, e o AddressSanitizer acusa `heap-use-after-free`.

> [!TIP]
> **Por dentro do C:** cada nó ocupa 16 bytes: 4 do `int`, 4 de
> **preenchimento** (*padding*) para alinhar o ponteiro e 8 do ponteiro, num
> sistema de 64 bits. Para guardar 4 bytes de dado, você gasta 16, mais o
> controle interno do `malloc`. O vetor do 0082 gasta 4 bytes por item, todos
> juntos na memória, o que o cache do processador adora. A encadeada troca
> espaço e velocidade por **não ter teto**. E todo `malloc` do empilhar
> precisa de um `free`: é por isso que `pilha_libera` percorre a lista toda
> antes de liberar a struct.

> [!NOTE]
> **Pergunta para você:** no programa da planilha, se o laço do Ctrl+Z
> rodasse 5 vezes em vez de 2, quantas linhas `Ctrl+Z` apareceriam e qual seria o último valor de B2?
> Siga a lista do desenho antes de rodar.

{{pratique}}

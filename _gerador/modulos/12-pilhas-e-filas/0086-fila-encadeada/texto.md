## 0086 · Fila encadeada

Sexta à noite, a cozinha da pizzaria recebe os pedidos do app numa fila. O
painel de 8 lugares do 0085 lotou às 20h, e o nono pedido foi recusado com
overflow. É o mesmo problema que a pilha teve no 0082, e a solução é a mesma:
trocar o vetor por nós alocados com `malloc`.

A **fila encadeada** é uma fila montada sobre uma lista encadeada: cada pedido
fica num nó com o valor e o endereço do próximo, e a fila só recusa um item
quando a memória acaba (CELES; RANGEL, 2002). A diferença para a pilha
encadeada está nas pontas. A pilha mexe numa ponta só, e por isso um ponteiro
bastava. A fila retira de uma ponta e insere na outra, então precisa de dois.

O primeiro ponteiro é o **início**, que aponta o próximo a sair. Retirar dele
é fácil: você avança com `inicio = inicio->prox` e libera o nó velho, em
O(1). O segundo é o **fim**, que aponta o último que entrou. Sem ele, inserir
exigiria andar a lista toda até achar o último nó, O(n). Com ele, basta
pendurar o nó novo atrás do último e mover o fim: `fim->prox = novo; fim =
novo`, também O(1) (DEITEL; DEITEL, 2011, cap. 12). Na fila vazia, os dois
ponteiros valem `NULL` (FEOFILOFF, 2009).

A escolha das pontas não é arbitrária. A fila **sai pelo início e entra pelo
fim**, e o contrário não funcionaria bem. Numa lista simples, cada nó conhece
o seguinte, mas não o anterior. Remover o último obrigaria a achar o
penúltimo para fazê-lo apontar para `NULL`, e achar o penúltimo é percorrer a
lista (CELES; RANGEL, 2002). Já inserir depois do último e remover o primeiro
não pedem conhecer ninguém para trás.

Os cuidados ficam nas bordas, quando a fila passa de vazia para um item ou de
um item para vazia. Inserir na fila vazia precisa atualizar também o
`inicio`, porque o nó novo é ao mesmo tempo o primeiro e o último. Retirar o
último item precisa zerar também o `fim`, porque o nó para o qual ele
apontava acabou de ser liberado (CELES; RANGEL, 2002). Os dois casos são
testes de uma linha, e esquecer qualquer um deles quebra a fila.

Quem usa a fila de novo não percebe a troca. O `fila.h` é o mesmo do 0085, e
só o `fila.c` muda. O que muda é o custo de cada operação: a fila circular só
escreve numa gaveta, enquanto a encadeada chama `malloc` a cada inserção e
`free` a cada retirada, e essas chamadas são bem mais caras. Você troca
velocidade por não ter limite de tamanho.

> [!WARNING]
> Retirar o **último** sem zerar o `fim` deixa o `fim` apontando para o nó
> liberado, e o próximo `fila_insere` escreve `fim->prox` em memória liberada
> (`heap-use-after-free`). Inserir na fila vazia sem atualizar o `inicio`
> deixa a fila "vazia" para sempre.

{{exemplo}}

Na pizzaria, chegam os pedidos 501, 502 e 503. A cozinha pega o 501: o início
anda para o 502 e o nó do 501 é liberado. Chega o 504, pendurado depois do
503, e o fim passa a apontar para ele:

{{ideia}}

O `fila.c` guarda os dois ponteiros:

```c
struct fila {
    NoFila *inicio; // o próximo a sair; NULL se vazia
    NoFila *fim;    // o último que entrou; NULL se vazia
    int n;
};

bool fila_insere(Fila *f, int valor) {
    NoFila *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return false;
    }
    novo->valor = valor;
    novo->prox = NULL; // vai ser o último
    if (f->fim == NULL) {
        f->inicio = novo; // fila vazia: o novo também é o primeiro
    } else {
        f->fim->prox = novo; // pendura atrás do último
    }
    f->fim = novo;
    f->n++;
    return true;
}

bool fila_retira(Fila *f, int *valor) {
    if (f->inicio == NULL) {
        return false;
    }
    NoFila *velho = f->inicio;
    *valor = velho->valor;
    f->inicio = velho->prox;
    if (f->inicio == NULL) {
        f->fim = NULL; // saiu o último: o fim não pode apontar para o nó liberado
    }
    free(velho);
    f->n--;
    return true;
}
```

Programa da cozinha:

```c
#include <stdio.h>
#include "fila.h"

int main(void) {
    Fila *pedidos = fila_cria();
    if (pedidos == NULL) {
        return 1;
    }

    fila_insere(pedidos, 501); // chegam três pedidos do app
    fila_insere(pedidos, 502);
    fila_insere(pedidos, 503);

    int p;
    if (fila_retira(pedidos, &p)) { // a cozinha pega o mais antigo
        printf("Preparando: %d\n", p);
    }
    fila_insere(pedidos, 504); // entra mais um, lá no fim

    // a fila agora é: inicio -> 502 -> 503 -> 504 <- fim
    if (fila_primeiro(pedidos, &p)) {
        printf("Próximo: %d (%d esperando)\n", p, fila_tamanho(pedidos));
    }

    fila_libera(pedidos); // libera os 3 nós que sobraram
    return 0;
}
// Saída:
// Preparando: 501
// Próximo: 502 (3 esperando)
```

Na entrada do 504 a fila não estava vazia: o caminho passa por
`fim->prox = novo`. Na fila vazia, o `inicio` recebe o novo nó:

{{fluxograma}}

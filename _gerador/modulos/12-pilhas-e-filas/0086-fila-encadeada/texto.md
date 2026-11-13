## 0086 · Fila encadeada

- **Fila encadeada**: troca o vetor por **nós**, como a pilha encadeada. Só
  recusa um item quando acaba a memória (CELES; RANGEL, 2002).
- **Dois ponteiros**: `inicio`, o próximo a sair, e `fim`, o último que
  entrou. Na fila vazia, os dois são `NULL` (FEOFILOFF, 2009).
- **Retirar** do começo é `inicio = inicio->prox`, O(1). **Inserir** no fim
  é `fim->prox = novo; fim = novo`, também O(1) graças ao `fim`
  (DEITEL; DEITEL, 2011, cap. 12).
- **Sai pelo início, entra pelo fim**: o contrário não serve numa lista
  simples, porque remover o último exige o penúltimo (CELES; RANGEL, 2002).
- **Casos de borda**: inserir na fila vazia atualiza também o `inicio`;
  retirar o último zera também o `fim` (CELES; RANGEL, 2002).
- **Mesma interface**: o `fila.h` é o do 0085; só o `fila.c` muda. Cada
  inserção chama `malloc` e cada retirada `free`, mais caros que uma gaveta
  de vetor.

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

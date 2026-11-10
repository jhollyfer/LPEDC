## 0086 · Fila encadeada

Sexta à noite, a cozinha da pizzaria recebe os pedidos do app. O painel de 8
lugares do 0085 lotou às 20h, e o nono pedido foi recusado.

A solução é a da pilha: trocar o vetor por **nós**. Como a fila usa as duas
pontas, o desenho muda:

- **retirar** do começo é fácil: `inicio = inicio->prox`, O(1);
- **inserir** no fim exigiria andar até o último, O(n), a menos que você
  guarde um segundo ponteiro, o **fim**, sempre no último nó. Então
  `fim->prox = novo; fim = novo` também é O(1).

A fila **sai pelo início e entra pelo fim**. O contrário não funciona bem numa
lista simples: remover o último exige o penúltimo, e o nó não sabe quem vem
antes.

O [`fila.h`](0086-fila-encadeada/fila.h) é o do 0085. O
[`fila.c`](0086-fila-encadeada/fila.c) guarda dois ponteiros, e os casos de
borda moram neles:

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

Chegam os pedidos 501, 502 e 503. A cozinha pega o 501: o início anda para o
502 e o nó do 501 é liberado. Chega o 504, pendurado depois do 503, e o fim
passa a apontar para ele:

{{ideia}}

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

> [!WARNING]
> Os dois bugs comuns estão nas bordas. Inserir na fila **vazia** sem
> atualizar o `inicio` deixa a fila "vazia" para sempre, mesmo com nós dentro.
> Retirar o **último** sem zerar o `fim` é pior: o `fim` continua apontando
> para o nó liberado, e o próximo `fila_insere` escreve `fim->prox` em memória
> liberada (`heap-use-after-free` no AddressSanitizer).

> [!TIP]
> A encadeada nunca recusa pedido (só se acabar a memória), mas cada inserção
> chama `malloc` e cada retirada chama `free`, bem mais caros que escrever
> numa gaveta de vetor.

> [!NOTE]
> **Pergunta para você:** no A172, se o cliente 3 levasse 1 minuto em vez de
> 4, quanto cada um esperaria? A maior fila mudaria? Simule à mão antes de
> rodar.

{{pratique}}

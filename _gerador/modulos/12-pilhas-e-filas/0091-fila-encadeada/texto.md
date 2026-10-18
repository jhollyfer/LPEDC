## 0091 · Fila encadeada

Sexta à noite, a cozinha da pizzaria recebe os pedidos do app. O painel de 8
lugares do 0090 lotou às 20h, e o nono pedido foi recusado. Pedido recusado é
cliente perdido. A fila precisa crescer o quanto for preciso.

A solução é a mesma da pilha: trocar o vetor por **nós** encadeados. Só que a
fila mexe nas duas pontas, e isso muda o desenho. Pense nos ponteiros de uma
lista simples:

- **retirar** do começo é fácil: `inicio = inicio->prox`, O(1);
- **inserir** no fim exigiria andar a lista até o último, O(n)... a não ser
  que você guarde um segundo ponteiro, o **fim**, sempre apontando para o
  último nó. Aí inserir também é O(1): `fim->prox = novo; fim = novo`.

Repare na direção: a fila **sai pelo início e entra pelo fim**. O contrário
(entrar pelo início, sair pelo fim) não funciona bem numa lista simples,
porque para remover o último você precisaria do penúltimo, e o nó não sabe
quem está antes dele.

O [`fila.h`](0091-fila-encadeada/fila.h) é o mesmo do 0090, palavra por
palavra. O [`fila.c`](0091-fila-encadeada/fila.c) agora guarda dois
ponteiros, e os casos de borda moram neles:

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

Vamos ver na prática. Chegam os pedidos 501, 502 e 503. A cozinha pega o
501: o início anda para o 502 e o nó do 501 é liberado. Chega o 504, que é
pendurado depois do 503, e o fim passa a apontar para ele:

{{ideia}}

O programa da cozinha:

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

Repara no fluxograma da entrada do 504: a fila não estava vazia, então o
caminho passa por `fim->prox = novo`. Na fila vazia, quem recebe o novo nó é
o `inicio`:

{{fluxograma}}

> [!WARNING]
> Os dois bugs clássicos estão nas bordas. Ao inserir na fila **vazia**,
> esquecer de atualizar o `inicio` deixa a fila "vazia" para sempre, mesmo
> com nós dentro. Ao retirar o **último**, esquecer de zerar o `fim` é pior:
> o `fim` continua apontando para o nó que acabou de levar `free`, e o
> próximo `fila_insere` escreve `fim->prox` em memória liberada. O
> AddressSanitizer acusa `heap-use-after-free`; sem ele, o programa às vezes
> funciona e às vezes corrompe o heap.

> [!TIP]
> **Por dentro do C:** a encadeada nunca recusa um pedido (só se acabar a
> memória), mas cada `fila_insere` chama o `malloc` e cada `fila_retira`
> chama o `free`. Essas chamadas custam bem mais que escrever numa gaveta de
> vetor: o alocador procura um bloco livre, guarda o tamanho dele num
> cabeçalho escondido e, de vez em quando, pede memória ao sistema
> operacional. Em sistemas que fazem milhões de operações por segundo, como
> servidores e jogos, o normal é a fila circular, crescendo com `realloc`
> quando enche, ou uma lista de nós reaproveitados.

> [!NOTE]
> **Pergunta para você:** no A182, se o cliente 3 levasse 1 minuto em vez de
> 4, quanto cada um esperaria? A maior fila mudaria? Simule à mão antes de
> rodar.

{{pratique}}

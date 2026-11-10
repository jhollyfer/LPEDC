## 0087 · Deque

No app de música, a fila tem as faixas 5, 8 e 3. Você toca em "tocar em
seguida" e a faixa 11 vai para a **frente**; depois tira a última adicionada,
pelo **fim**. Nem pilha nem fila fazem isso.

É o **deque** (*double-ended queue*, pronuncia-se "deck"): uma **fila dupla**,
que entra e sai pelas **duas** pontas. Quatro operações:

- `deque_insere_inicio` e `deque_retira_inicio`: mexem na frente;
- `deque_insere_fim` e `deque_retira_fim`: mexem no fundo.

O deque generaliza as duas estruturas anteriores. Com uma ponta só (insere e
retira no fim), é uma **pilha**; inserindo no fim e retirando no início, uma
**fila**. Se sai o de maior prioridade, é a **fila de prioridade** (assunto
0102, com heap). Aqui as quatro operações custam **O(1)**, enquanto num vetor
comum mexer no início custa O(n).

O [`deque.c`](0087-deque.c) é a fila circular do 0085 com o `inicio`
andando também para **trás**: para inserir na frente, ele recua uma gaveta, e
da 0 volta para a última. A conta fica numa função auxiliar `static`, visível
só no `deque.c`:

```c
#define CAPACIDADE 8

// gaveta anterior a i, dando a volta: anterior(0) = CAPACIDADE - 1
static int anterior(int i) {
    return (i - 1 + CAPACIDADE) % CAPACIDADE; // (i - 1) % CAPACIDADE daria -1 com i = 0
}

bool deque_insere_inicio(Deque *d, int valor) {
    if (d->n == CAPACIDADE) {
        return false;
    }
    d->inicio = anterior(d->inicio); // o início recua uma gaveta
    d->itens[d->inicio] = valor;
    d->n++;
    return true;
}

bool deque_retira_fim(Deque *d, int *valor) {
    if (d->n == 0) {
        return false;
    }
    *valor = d->itens[(d->inicio + d->n - 1) % CAPACIDADE]; // o último ocupado
    d->n--;
    return true;
}
```

`deque_insere_fim` e `deque_retira_inicio` são iguais aos da fila. Retirar do
fim só diminui `n`.

As faixas 5, 8 e 3 entram pelo fim, nas gavetas 0, 1 e 2. A 11 entra pela
frente: o início recua da gaveta 0 e dá a volta para a 7. A ordem fica 11, 5,
8, 3:

{{ideia}}

Programa da fila de músicas:

```c
#include <stdio.h>
#include "deque.h"

int main(void) {
    Deque *fila = deque_cria(); // guarda o número da faixa do álbum
    if (fila == NULL) {
        return 1;
    }

    deque_insere_fim(fila, 5); // "adicionar à fila": vai para o fim
    deque_insere_fim(fila, 8);
    deque_insere_fim(fila, 3);
    deque_insere_inicio(fila, 11); // "tocar em seguida": fura a fila

    // ordem agora: 11 5 8 3
    int faixa;
    if (deque_retira_inicio(fila, &faixa)) {
        printf("Tocando a faixa %d\n", faixa);
    }
    if (deque_retira_fim(fila, &faixa)) { // desistiu da última que adicionou
        printf("Removida a faixa %d\n", faixa);
    }

    printf("Ainda na fila:");
    while (deque_retira_inicio(fila, &faixa)) {
        printf(" %d", faixa);
    }
    printf("\n");

    deque_libera(fila);
    return 0;
}
// Saída:
// Tocando a faixa 11
// Removida a faixa 3
// Ainda na fila: 5 8
```

Na entrada da faixa 11, o fluxograma difere do da fila só no recuo do início
com `anterior`, que soma 8 antes do `%` para o índice não ficar negativo:

{{fluxograma}}

> [!WARNING]
> Em C, o resto de número negativo é **negativo**: `-1 % 8` vale `-1`, não 7.
> O C17 trunca a divisão em direção ao zero, e o resto acompanha o sinal do
> dividendo. Assim, `(inicio - 1) % CAPACIDADE` com `inicio = 0` dá `-1`, e
> `itens[-1]` escreve **fora** do vetor. Some a capacidade antes do `%`:
> `(inicio - 1 + CAPACIDADE) % CAPACIDADE`.

> [!TIP]
> `static` numa função fora de bloco não cria variável estática: tira a função
> da **ligação externa** e a torna **privada** do arquivo. O deque encadeado
> exige lista **dupla** (assunto 0079): para retirar do fim, o último nó
> precisa conhecer o penúltimo.

> [!NOTE]
> **Pergunta para você:** se o programa da fila de músicas fizesse mais um
> `deque_insere_inicio` logo depois do 11, em que gaveta o novo item cairia?
> E se o deque estivesse com as 8 gavetas ocupadas?

{{pratique}}

## 0087 · Deque

No app de música, você monta a fila: faixa 5, faixa 8, faixa 3. Aí lembra de
uma que quer ouvir agora e toca em "tocar em seguida": a faixa 11 fura a fila
e vai para a **frente**. Depois desiste da última que adicionou e a tira do
**fim**. Nem pilha nem fila fazem isso.

Essa estrutura é o **deque** (*double-ended queue*, fala-se "deck"): uma
**fila dupla**, que entra e sai pelas **duas** pontas. São quatro operações
principais:

- `deque_insere_inicio` e `deque_retira_inicio`: mexem na frente;
- `deque_insere_fim` e `deque_retira_fim`: mexem no fundo.

O deque generaliza as duas estruturas que você já viu. Usando só uma ponta
(insere e retira no fim), ele é uma **pilha**. Inserindo no fim e retirando
no início, é uma **fila**. Num vetor comum, inserir ou retirar no início custa O(n),
porque desloca todo mundo. Aqui as quatro operações custam **O(1)**.

A implementação do [`deque.c`](0087-deque/deque.c) é a fila circular do 0085
com uma novidade: o `inicio` agora também anda para **trás**. Para inserir na
frente, ele recua uma gaveta, e da gaveta 0 ele volta para a última. A conta
de "gaveta anterior" mora numa função auxiliar `static`, que só o `deque.c`
enxerga:

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

`deque_insere_fim` e `deque_retira_inicio` são iguais aos da fila. Retirar
do fim é o mais simples de todos: basta diminuir `n`.

Vamos ver na prática. As faixas 5, 8 e 3 entram pelo fim, nas gavetas 0, 1
e 2. A faixa 11 entra pela frente: o início, que estava na gaveta 0, recua e
dá a volta para a gaveta 7. A ordem da fila fica 11, 5, 8, 3:

{{ideia}}

O programa da fila de músicas:

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

Repara no fluxograma da entrada da faixa 11: a única diferença para a fila é
o passo que faz o início recuar com `anterior`, que soma 8 antes do `%` para
o índice não ficar negativo:

{{fluxograma}}

> [!WARNING]
> Em C, o resto de um número negativo é **negativo**: `-1 % 8` vale `-1`, não
> 7. (A matemática diria 7; o C17 manda a divisão truncar em direção ao zero,
> e o resto acompanha o sinal do dividendo.) Então `(inicio - 1) %
> CAPACIDADE`, com `inicio = 0`, dá `-1`, e `itens[-1]` escreve **fora** do
> vetor. Some a capacidade antes do `%`: `(inicio - 1 + CAPACIDADE) %
> CAPACIDADE`.

> [!TIP]
> **Por dentro do C:** a palavra `static` numa função fora de qualquer bloco
> não tem nada a ver com variável estática: ela tira a função da **ligação
> externa**. O ligador nem fica sabendo que `anterior` existe, então outro
> arquivo pode ter a sua própria `anterior` sem conflito. É o jeito do C de
> fazer uma função **privada** do módulo. O
> deque com lista encadeada também é possível, mas precisa de lista **dupla**
> (assunto 0079): para retirar do fim, o último nó tem que saber quem é o
> penúltimo.

> [!NOTE]
> **Pergunta para você:** se o A173 fizesse mais um `deque_insere_inicio`
> logo depois do 11, em que gaveta o novo item cairia? E se o deque estivesse
> com as 8 gavetas ocupadas?

{{pratique}}

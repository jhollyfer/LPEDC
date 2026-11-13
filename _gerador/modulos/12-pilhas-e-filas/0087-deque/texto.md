## 0087 · Deque

- **Deque** (*double-ended queue*, pronuncia-se "deck"): uma **fila dupla**,
  que entra e sai pelas **duas** pontas (CELES; RANGEL, 2002).
- **Quatro operações**: `deque_insere_inicio` e `deque_retira_inicio` mexem
  na frente; `deque_insere_fim` e `deque_retira_fim`, no fundo
  (CELES; RANGEL, 2002).
- **Generaliza pilha e fila**: inserindo e retirando no fim, é uma
  **pilha**; inserindo no fim e retirando no início, uma **fila**
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 4).
- **Em vetor circular**: é a fila do 0085 com o `inicio` andando também para
  **trás**. Para inserir na frente, ele recua uma gaveta; da 0 volta para a
  última. Retirar do fim só diminui `n`. Tudo O(1) (CELES; RANGEL, 2002).
- **Encadeado**: exige lista **dupla** (0079), porque para retirar do fim o
  último nó precisa conhecer o penúltimo (CELES; RANGEL, 2002).
- **`static` numa função**: tira a função da ligação externa e a torna
  **privada** do arquivo (KERNIGHAN; RITCHIE, 1988).

> [!WARNING]
> Em C, o resto de negativo é **negativo**: `-1 % 8` vale `-1`, não 7. Assim
> `(inicio - 1) % CAPACIDADE` com `inicio = 0` escreve em `itens[-1]`. Some a
> capacidade antes: `(inicio - 1 + CAPACIDADE) % CAPACIDADE`
> (CPPREFERENCE, s.d.).

{{exemplo}}

No app de música, as faixas 5, 8 e 3 entram pelo fim, nas gavetas 0, 1 e 2.
A 11 entra pela frente ("tocar em seguida"): o início recua da gaveta 0 e dá
a volta para a 7. A ordem fica 11, 5, 8, 3:

{{ideia}}

A conta do recuo fica numa função auxiliar `static`:

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

Na entrada da faixa 11, o caminho difere do da fila só no recuo do início com
`anterior`, que soma 8 antes do `%`:

{{fluxograma}}

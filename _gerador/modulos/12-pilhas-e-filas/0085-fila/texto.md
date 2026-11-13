## 0085 · Fila

- **Fila** (*queue*): entra pelo **fim** e sai pelo **início**. O primeiro a
  entrar é o primeiro a sair, **FIFO** (*first in, first out*), o contrário
  da pilha (FEOFILOFF, 2009).
- **TAD**: a mesma cara da pilha, com inserir, retirar, olhar o primeiro e
  vazia? (CELES; RANGEL, 2002).

```c
typedef struct fila Fila; // tipo opaco: os campos ficam no fila.c

Fila *fila_cria(void);                          // fila vazia (NULL se faltar memória)
void fila_libera(Fila *f);                      // devolve toda a memória da fila
bool fila_vazia(const Fila *f);                 // true se não tem ninguém
int fila_tamanho(const Fila *f);                // quantos estão na fila
bool fila_insere(Fila *f, int valor);           // entra no fim: false se não coube
bool fila_retira(Fila *f, int *valor);          // sai do início: false se vazia
bool fila_primeiro(const Fila *f, int *valor);  // olha quem é o próximo, sem tirar
```

- **Fila em vetor**: mexe nas duas pontas. Empurrar todo mundo a cada
  retirada custa O(n); sem empurrar, a fila bate no fim do vetor com as
  primeiras gavetas vazias (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 4).
- **Fila circular**: passou da última gaveta, volta à 0. Guarde o
  **início** e o número de itens `n`; a próxima vaga é
  `(inicio + n) % CAPACIDADE` (CELES; RANGEL, 2002).
- **Cheia ou vazia**: só com `inicio` e `fim`, as duas têm `inicio == fim`.
  Ou se guarda `n`, ou se **sacrifica uma gaveta**: cheia quando
  `(fim + 1) % CAPACIDADE == inicio`, como no Cormen com `Q.head` e `Q.tail`
  (CORMEN et al., 2024, cap. 10).
- **Custo**: inserir e retirar são O(1). Retirar não apaga: o valor fica na
  gaveta até alguém escrever por cima (FEOFILOFF, 2009).

> [!WARNING]
> O tamanho como `fim - inicio` dá negativo depois da volta: com início 4 e
> fim 2, dá -2. Use o contador `n` ou `(fim - inicio + CAPACIDADE) %
> CAPACIDADE`.

{{exemplo}}

Na lotérica, o painel guarda 8 senhas. Chegam as senhas 31 a 36 (gavetas 0 a
5) e o caixa atende 4. Chegam 37 a 40: o 37 e o 38 ocupam as gavetas 6 e 7, e
o 39 e o 40 **dão a volta** para as gavetas 0 e 1:

{{ideia}}

Parte principal do `fila.c`:

```c
#define CAPACIDADE 8

struct fila {
    int itens[CAPACIDADE];
    int inicio; // posição do primeiro da fila (o próximo a sair)
    int n;      // quantos estão na fila: separa "cheia" de "vazia"
};

bool fila_insere(Fila *f, int valor) {
    if (f->n == CAPACIDADE) {
        return false; // cheia
    }
    int fim = (f->inicio + f->n) % CAPACIDADE; // dá a volta no fim do vetor
    f->itens[fim] = valor;
    f->n++;
    return true;
}

bool fila_retira(Fila *f, int *valor) {
    if (f->n == 0) {
        return false; // vazia
    }
    *valor = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % CAPACIDADE;
    f->n--;
    return true;
}
```

O programa só vê as funções do `fila.h`:

```c
#include <stdio.h>
#include "fila.h"

int main(void) {
    Fila *senhas = fila_cria(); // o painel guarda até 8 senhas
    if (senhas == NULL) {
        return 1;
    }

    for (int s = 31; s <= 36; s++) { // chegam 6 pessoas
        fila_insere(senhas, s);
    }

    printf("Atendidas:");
    for (int i = 0; i < 4; i++) { // o caixa chama 4
        int s;
        if (fila_retira(senhas, &s)) {
            printf(" %d", s);
        }
    }

    printf("\nChegaram:");
    for (int s = 37; s <= 40; s++) { // 39 e 40 dão a volta no vetor
        if (fila_insere(senhas, s)) {
            printf(" %d", s);
        }
    }

    printf("\nNa fila (%d):", fila_tamanho(senhas));
    int s;
    while (fila_retira(senhas, &s)) {
        printf(" %d", s);
    }
    printf("\n");

    fila_libera(senhas);
    return 0;
}
// Saída:
// Atendidas: 31 32 33 34
// Chegaram: 37 38 39 40
// Na fila (6): 35 36 37 38 39 40
```

A senha 39 entra com `inicio = 4` e `n = 4`: o `%` a manda para a gaveta 0:

{{fluxograma}}

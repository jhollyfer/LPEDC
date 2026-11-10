## 0085 · Fila

Na lotérica você pega a senha 35 e espera. Quem chegou antes é atendido antes,
e a senha 40, recém-saída da maquininha, espera todo mundo da frente.

Isso é uma **fila** (*queue*): entra pelo **fim**, sai pelo **início**. O
primeiro a entrar é o primeiro a sair, **FIFO** (*first in, first out*), o
contrário da pilha.

O TAD tem a mesma cara da pilha, no [`fila.h`](material/0085-fila.h):

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

Num vetor, a fila mexe nas duas pontas. Empurrar todo mundo uma casa a cada
atendimento custa **O(n)** por retirada; sem empurrar, a fila bate no fim do
vetor com as primeiras gavetas vazias.

A saída é a **fila circular**: passou da última gaveta, volta à 0. Guarde o
**início** e o número de itens `n`; a próxima vaga é
`(inicio + n) % CAPACIDADE`. Com 8 gavetas, depois da 7 vem
`(7 + 1) % 8 = 0`. Parte principal do [`fila.c`](material/0085-fila.c):

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

O painel guarda 8 senhas. Chegam as senhas 31 a 36 (gavetas 0 a 5) e o caixa
atende 4: o início anda até a gaveta 4. Chegam 37 a 40: o 37 e o 38 ocupam as
gavetas 6 e 7, e o 39 e o 40 **dão a volta** para as gavetas 0 e 1:

{{ideia}}

O programa só vê as funções do `fila.h`; a volta fica no `fila.c`:

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

O fluxograma segue a senha 39, com `inicio = 4` e `n = 4`: o `%` a manda para
a gaveta 0:

{{fluxograma}}

> [!WARNING]
> Sem o contador `n`, fila cheia e vazia ficam **iguais**: com só `inicio` e
> `fim`, as duas têm `inicio == fim`. Há duas saídas: guardar `n`, como aqui,
> ou **sacrificar uma gaveta** e declarar a fila cheia quando
> `(fim + 1) % CAPACIDADE == inicio` (cabem 7 em 8). O Cormen usa a segunda:
> com `Q.head` e `Q.tail` (a próxima vaga), ENQUEUE e DEQUEUE num vetor de n
> posições guardam n − 1 itens. Outra armadilha: o tamanho como `fim - inicio`
> dá -2 com início 4 e fim 2.

> [!TIP]
> Retirar não apaga nada: o 33 e o 34 continuam nas gavetas 2 e 3 até alguém
> escrever por cima. Inserir e retirar custam **O(1)**. Com capacidade
> potência de 2, `i % 8` equivale a `i & 7`.

> [!NOTE]
> **Pergunta para você:** depois do último laço do programa da lotérica, a
> fila está vazia. Quanto valem `inicio` e `n` lá dentro? Em que gaveta
> entraria a próxima senha?

{{pratique}}

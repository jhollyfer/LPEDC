## 0090 · Fila

Na lotérica, você pega a senha 35 e espera. Quem chegou antes é atendido
antes, e ninguém fura: a senha 40, que acabou de sair da maquininha, vai
esperar todo mundo da frente.

Isso é uma **fila** (*queue*): entra pelo **fim**, sai pelo **início**. O
primeiro a entrar é o primeiro a sair: **FIFO** (*first in, first out*). É o
contrário da pilha. Na computação, fila aparece onde existe ordem de chegada:
a fila de impressão, as requisições esperando o servidor Fastify, os eventos
esperando o *event loop* do Node, as mensagens de um RabbitMQ.

O TAD tem a mesma cara da pilha, no [`fila.h`](0090-fila/fila.h):

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

Guardar uma fila num vetor tem um problema que a pilha não tinha. A pilha
mexe numa ponta só. A fila mexe nas duas: entra à direita e sai à esquerda.
Se, a cada atendimento, você empurrar todo mundo uma casa para a esquerda
(como o `shift()` do JS faz), cada retirada custa **O(n)**. Se não empurrar,
a fila vai "andando" para a direita e bate no fim do vetor com as primeiras
gavetas vazias.

A saída é a **fila circular**: quando o índice passa da última gaveta, volta
para a 0. O vetor vira um anel. Basta guardar onde está o **início** e
quantos itens tem (`n`); a próxima vaga é `(inicio + n) % CAPACIDADE`. O `%`
faz a volta: com 8 gavetas, depois da 7 vem `(7 + 1) % 8 = 0`. O coração do
[`fila.c`](0090-fila/fila.c):

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

Vamos ver na prática. O painel da lotérica guarda 8 senhas. Chegam as senhas
31 a 36 (gavetas 0 a 5). O caixa atende 4, e o início anda até a gaveta 4.
Chegam 37 a 40: o 37 e o 38 ocupam as gavetas 6 e 7, e o 39 e o 40 **dão a
volta** e caem nas gavetas 0 e 1, que já estavam livres:

{{ideia}}

O programa da lotérica. Ele só vê as funções do `fila.h`; a volta no vetor é
problema do `fila.c`:

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

Repara no fluxograma da entrada da senha 39: naquela hora, `inicio = 4` e
`n = 4`, e o `%` manda o 39 para a gaveta 0:

{{fluxograma}}

> [!WARNING]
> Sem o contador `n`, cheia e vazia ficam **iguais**. Se você guardar só
> `inicio` e `fim`, a fila vazia tem `inicio == fim`, e a fila cheia, depois
> de dar a volta completa, também. Há duas saídas: guardar `n`, como aqui, ou
> **sacrificar uma gaveta** e dizer que está cheia quando
> `(fim + 1) % CAPACIDADE == inicio` (aí só cabem 7 em 8). Muito livro usa a
> segunda. Outra armadilha: calcular o tamanho como `fim - inicio`. Com a
> fila dando a volta (início 4, fim 2) isso dá -2.

> [!TIP]
> **Por dentro do C:** o `%` é uma divisão inteira, uma das instruções mais
> lentas do processador (dezenas de ciclos, contra 1 de uma soma). Por isso
> filas de alto desempenho, como os *ring buffers* do kernel do Linux e das
> placas de rede, usam capacidade **potência de 2**: com 8 gavetas e `i`
> não negativo,
> `i % 8` é o mesmo que `i & 7`, e o compilador já faz essa troca sozinho
> quando a constante é potência de 2. Retirar não apaga nada: o 33 e o 34
> continuam nas gavetas 2 e 3 até alguém escrever por cima. Inserir e retirar
> custam **O(1)**, sem mover ninguém.

> [!NOTE]
> **Pergunta para você:** depois do último laço do A179, a fila está vazia.
> Quanto valem `inicio` e `n` lá dentro? Em que gaveta entraria a próxima
> senha?

{{pratique}}

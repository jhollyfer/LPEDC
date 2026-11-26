## 0085 · Fila

A pilha atende o mais recente primeiro, e isso é justo para o "desfazer", mas
seria um desastre na lotérica. Lá você pega a senha 35 e espera; quem chegou
antes é atendido antes, e a senha 40, recém-saída da maquininha, espera todo
mundo da frente. Para guardar dados nessa ordem, você precisa de outra
estrutura: uma que entregue o item mais **antigo**.

Essa estrutura é a **fila** (*queue*). O item novo entra pelo **fim** e o
próximo a sair está no **início**, como na fila do banco. O primeiro a entrar
é o primeiro a sair: a sigla é **FIFO**, do inglês *first in, first out*, o
contrário do LIFO da pilha (FEOFILOFF, 2009). No Cormen, inserir se chama
ENQUEUE e retirar se chama DEQUEUE (CORMEN et al., 2024, cap. 10).

Como TAD, a fila tem a mesma cara da pilha do 0082: inserir no fim, retirar
do início, olhar quem é o próximo sem tirar e perguntar se está vazia (CELES;
RANGEL, 2002). O valor retirado sai por ponteiro, e o `bool` diz se a
operação deu certo:

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

Guardar a fila num vetor parece simples e esconde um problema. A pilha mexe
numa ponta só; a fila mexe nas duas. Se o início fica sempre em `itens[0]`,
cada retirada obriga a empurrar todos os itens uma casa para a frente, e isso
custa O(n). Se você não empurra e só avança o índice do início, a fila anda
para a direita e bate no fim do vetor com as primeiras gavetas vazias
(TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 4).

A saída é a **fila circular**: quando o índice passa da última gaveta, ele
volta à gaveta 0, como os ponteiros de um relógio voltam ao 12. Você guarda o
**início** (a gaveta do próximo a sair) e o número de itens `n`. A próxima
vaga é `(inicio + n) % CAPACIDADE`: o resto da divisão faz a volta sozinho
(CELES; RANGEL, 2002). Com 8 gavetas, depois da 7 vem `(7 + 1) % 8 = 0`.
Retirar lê `itens[inicio]` e avança o início da mesma forma, com
`(inicio + 1) % CAPACIDADE`.

Por que guardar `n` em vez de um índice de fim? Com só `inicio` e `fim`, a
fila vazia e a fila cheia ficam com a mesma cara: nas duas, `inicio == fim`.
Há duas saídas. A primeira é guardar `n`, como este curso faz. A segunda é
**sacrificar uma gaveta** e declarar a fila cheia quando
`(fim + 1) % CAPACIDADE == inicio`, de modo que cabem 7 itens em 8 gavetas.
O Cormen usa a segunda, com `Q.head` e `Q.tail` (a próxima vaga): num vetor
de n posições, a fila guarda no máximo n − 1 itens (CORMEN et al., 2024,
cap. 10).

Inserir e retirar custam **O(1)**: uma conta de resto, uma atribuição e um
ajuste de contador. Como na pilha, retirar não apaga nada; o valor fica na
gaveta até alguém escrever por cima (FEOFILOFF, 2009). Um detalhe de
desempenho: com capacidade potência de 2, `i % 8` dá o mesmo que `i & 7`, e o
compilador costuma fazer essa troca sozinho.

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

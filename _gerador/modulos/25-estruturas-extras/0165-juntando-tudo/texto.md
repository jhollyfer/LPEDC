## 0165 · Juntando tudo

A loja virtual tem 1000 produtos e recebe 10 mil consultas por dia. Só que a
procura não é igual: os 20 produtos da promoção da semana levam 80% das
consultas. Em qual estrutura guardar o catálogo? Uma BST, uma AVL, uma skip list ou
uma lista que move o achado para a frente?

Cada uma tem a sua promessa. A **BST** (assunto 0099) desce um caminho só, mas a
altura depende da ordem de chegada. A **AVL** (0101) garante altura perto de
log₂ n com rotações. A **skip list** (0163) promete O(log n) na média dos
sorteios, sem rotação nenhuma. A **lista com mover para a frente** (0164) é O(n),
mas aposta que os mais procurados vão ficar na frente. No papel, todas parecem
boas. A pergunta só se responde **medindo**.

Medir com justiça tem três regras. Todo mundo recebe **as mesmas chaves, na mesma
ordem**. Todo mundo responde **as mesmas buscas**, sorteadas uma vez só e
guardadas num vetor. E a medida é a mesma para todos: o **custo** de uma busca é
quantas chaves ela comparou. Contar comparações, em vez de cronometrar, dá o
mesmo número em qualquer computador.

Para o teste não precisar de quatro versões, as estruturas ficam atrás de uma
**interface comum**: uma struct com ponteiros para função (assunto 0050), em que
a estrutura de dados em si viaja como `void *` (0051). É o TAD (0074) levado um
passo adiante: quem mede chama `e->busca(d, chave, &custo)` sem saber se, do
outro lado, há uma árvore ou uma lista:

```c
typedef struct {
    const char *nome;
    void *(*cria)(void);
    void (*insere)(void *e, int chave);            // repetida é ignorada
    bool (*busca)(void *e, int chave, int *custo); // custo: chaves comparadas
    void (*libera)(void *e);
} Estrutura;

extern const Estrutura CONCORRENTES[NUM_CONCORRENTES];
```

O `bancada.c` traz os quatro concorrentes (a skip list é a do `skip.h`, as outras
três vêm dentro dele) e um sorteio repetível, `bc_sorteio`, com o mesmo gerador
de uma linha do `skip.c`.

Vamos ver na prática. Cada concorrente recebe as 1000 chaves duas vezes: uma em
ordem embaralhada, outra em ordem crescente (o catálogo exportado de uma planilha
já ordenada). Depois responde às mesmas 10 mil consultas:

{{ideia}}

O programa monta as duas ordens e as buscas, e a função `mede` faz o resto:

```c
#include <stdio.h>
#include "bancada.h"

#define N 1000       // produtos no catálogo
#define BUSCAS 10000 // consultas do dia
#define QUENTES 20   // os produtos da promoção

// insere as N chaves na ordem dada, faz as buscas e devolve o custo médio
double mede(const Estrutura *e, const int ordem[], const int buscas[]) {
    void *d = e->cria();
    for (int i = 0; i < N; i++) {
        e->insere(d, ordem[i]);
    }
    long total = 0;
    for (int i = 0; i < BUSCAS; i++) {
        int custo;
        e->busca(d, buscas[i], &custo);
        total += custo;
    }
    e->libera(d);
    return (double)total / BUSCAS;
}

int main(void) {
    unsigned estado = 7;
    int crescente[N], embaralhada[N], sorteio[N];
    for (int i = 0; i < N; i++) {
        crescente[i] = embaralhada[i] = sorteio[i] = i + 1;
    }
    bc_embaralha(embaralhada, N, &estado);
    bc_embaralha(sorteio, N, &estado); // os QUENTES primeiros são a promoção

    // 80% das consultas vão para os 20 produtos da promoção
    static int buscas[BUSCAS];
    for (int i = 0; i < BUSCAS; i++) {
        if (bc_sorteio(&estado) % 100 < 80) {
            buscas[i] = sorteio[bc_sorteio(&estado) % QUENTES];
        } else {
            buscas[i] = bc_sorteio(&estado) % N + 1;
        }
    }

    printf("%-10s %12s %10s\n", "", "embaralhada", "crescente");
    for (int k = 0; k < NUM_CONCORRENTES; k++) {
        const Estrutura *e = &CONCORRENTES[k];
        printf("%-10s %12.1f %10.1f\n", e->nome, mede(e, embaralhada, buscas),
               mede(e, crescente, buscas));
    }
    return 0;
}
// Saída:
//             embaralhada  crescente
// BST               11.9      569.7
// AVL                8.9        9.1
// skip list         16.4       18.3
// lista MTF        114.6      114.5
```

Repara no fluxograma: o laço não sabe quem está medindo. Trocar ou acrescentar
um concorrente é mexer no vetor `CONCORRENTES`, nunca no teste:

{{fluxograma}}

Como ler a tabela. A **BST** vai bem com chaves embaralhadas e desaba com a
planilha ordenada: virou uma lista, e a busca média passa de 500 comparações. A
**AVL** nem percebe a diferença: as rotações seguram a altura perto de
log₂ 1000. A **skip list** fica perto dela, também sem ligar para a ordem,
porque quem decide a forma é a moeda, não a chegada. Ela olha uns 18 nós, contra
uns 9 da AVL, mas não tem rotação nenhuma no código. E a **lista MTF** perde feio:
os 20% de consultas espalhadas custam umas 500 comparações cada e ainda empurram
os produtos da promoção para trás. O exemplo A329 mostra quando o jogo vira.

> [!WARNING]
> Gerar as buscas **dentro** de `mede` estraga a comparação. Como o sorteio
> continua de onde parou, cada concorrente receberia uma sequência diferente de
> consultas, e a tabela compararia testes diferentes. Por isso as buscas são
> sorteadas uma vez, antes, e guardadas num vetor. O exercício E989 traz esse
> erro para você caçar.

> [!TIP]
> **Por dentro do C:** `e->busca(d, ...)` é uma chamada **indireta**: o programa
> lê o endereço da função na struct e salta para ele. Por isso, em geral, o
> compilador não consegue copiar o corpo da função no lugar da chamada, como faz
> com funções pequenas chamadas direto, e cada busca paga um salto a mais. Num
> teste que conta comparações isso não aparece, mas num cronômetro aparece.
> Repare também no `static int buscas[BUSCAS]`: com `static`, os 40 KB do vetor
> ficam na área de dados (assunto 0053), e não na pilha do `main`.

> [!NOTE]
> **Pergunta para você:** a coluna da lista MTF quase não muda entre as duas
> ordens. Por quê? E se a promoção tivesse só 5 produtos e 99% das consultas,
> quem você acha que ganharia? Rode o A329 para conferir.

{{pratique}}

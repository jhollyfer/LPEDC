## 0134 · Seleção de intervalos

A quadra do condomínio atende uma reserva por vez, e no sábado chegaram nove
pedidos, cada um com início e fim. Alguns horários se chocam. O síndico quer
aceitar o **maior número possível** de pedidos. Quais?

É a **seleção de atividades**: dado um conjunto de intervalos `[início, fim)`,
achar o maior subconjunto sem sobreposição.

Testar todos os subconjuntos (0125) dá 512 casos para nove pedidos e mais de
um bilhão para trinta. Um **guloso** ordena uma vez, mas por qual critério?

- aceitar primeiro quem **começa** mais cedo;
- aceitar primeiro o pedido mais **curto**;
- aceitar primeiro quem **termina** mais cedo.

Só o terceiro funciona sempre: o pedido que termina primeiro **devolve a
quadra mais cedo** e deixa mais espaço. A prova é uma troca: numa escolha
ótima, troque o primeiro pedido pelo que termina primeiro. Ele termina antes
(ou junto), não choca com os outros e a escolha mantém o tamanho.

O algoritmo (`GREEDY-ACTIVITY-SELECTOR`, do Cormen):

1. **ordene** os pedidos pela hora de **fim**;
2. guarde a hora em que a quadra fica livre (`livre_em`, começando em 0);
3. percorra os pedidos: se começa em `livre_em` ou depois, **aceite** e mova
   `livre_em` para o fim dele; senão, recuse.

O custo é a ordenação, O(n log n), mais uma passada O(n).

No desenho, verdes foram aceitas e cinzas chocaram com alguém aceito. O pedido
da Iara (7h às 17h) seria o primeiro pelo critério "começa antes":

{{ideia}}

Os pedidos são structs, ordenados com `qsort` (0096) por uma função que
compara os fins:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *nome;
    int ini, fim; // horário [ini, fim): quem sai às 10h libera a quadra às 10h
} Reserva;

int por_fim(const void *a, const void *b) {
    const Reserva *x = a;
    const Reserva *y = b;
    return (x->fim > y->fim) - (x->fim < y->fim);
}

int main(void) {
    Reserva r[] = {
        {"Ana", 8, 10},  {"Bruno", 9, 12}, {"Carla", 10, 11},
        {"Davi", 11, 14}, {"Eva", 12, 13},  {"Fred", 13, 16},
        {"Gil", 14, 15},  {"Hugo", 15, 18}, {"Iara", 7, 17},
    };
    int n = 9;

    // guloso: entre os pedidos que cabem, aceite o que TERMINA primeiro
    qsort(r, n, sizeof r[0], por_fim);
    int livre_em = 0; // a quadra fica livre a partir desta hora
    int aceitas = 0;
    for (int i = 0; i < n; i++) {
        printf("%-6s %2dh-%2dh: ", r[i].nome, r[i].ini, r[i].fim);
        if (r[i].ini >= livre_em) {
            printf("aceita\n");
            livre_em = r[i].fim;
            aceitas++;
        } else {
            printf("recusada (quadra ocupada até %dh)\n", livre_em);
        }
    }
    printf("Reservas aceitas: %d de %d\n", aceitas, n);
    return 0;
}
// Saída:
// Ana     8h-10h: aceita
// Carla  10h-11h: aceita
// Bruno   9h-12h: recusada (quadra ocupada até 11h)
// Eva    12h-13h: aceita
// Davi   11h-14h: recusada (quadra ocupada até 13h)
// Gil    14h-15h: aceita
// Fred   13h-16h: recusada (quadra ocupada até 15h)
// Iara    7h-17h: recusada (quadra ocupada até 15h)
// Hugo   15h-18h: aceita
// Reservas aceitas: 5 de 9
```

A Carla (10h às 11h) entra logo depois da Ana (8h às 10h): os intervalos são
**semiabertos** e a Ana libera a quadra às 10h. Por isso o teste é
`ini >= livre_em`, com o igual.

No fluxograma, depois da ordenação, o laço tem uma pergunta só. O caminho
marcado mostra a Ana aceita e o Bruno recusado:

{{fluxograma}}

> [!WARNING]
> Os outros critérios falham. "Começa primeiro" aceita a Iara (7h às 17h) e
> depois só o Hugo cabe: 1 pedido em vez de 5. "Mais curto primeiro" falha com
> 8h às 12h, 11h às 13h e 12h às 16h: o mais curto (11h às 13h) choca com os
> outros dois, que cabem juntos. O programa roda sem reclamar; só a resposta
> piora.

> [!TIP]
> **Por dentro do C:** compare com `(x > y) - (x < y)`, e não
> `x->fim - y->fim`: a subtração pode estourar o `int`.

> [!NOTE]
> **Pergunta para você:** se o pedido do Hugo fosse das 14h às 18h, quantas
> reservas seriam aceitas? Quais? E se fosse das 16h às 18h?

{{pratique}}

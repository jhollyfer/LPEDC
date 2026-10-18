## 0134 · Seleção de intervalos

A quadra de futsal do condomínio só tem uma reserva por vez, e no sábado
chegaram nove pedidos, cada um com hora de início e de fim. Não dá para
atender todo mundo, porque alguns horários se chocam. O síndico quer aceitar
o **maior número possível** de pedidos. Qual escolher?

Esse é o problema da **seleção de atividades** (ou de intervalos): dado um
conjunto de intervalos `[início, fim)`, escolher o maior subconjunto sem
nenhum par que se sobreponha. Ele aparece em sala de reunião, agenda de
consultório, uso de um equipamento caro, horários de uma emissora.

Testar todos os subconjuntos (assunto 0125) daria a resposta, mas são 2⁹ = 512
para nove pedidos e mais de um bilhão para trinta. Um **guloso** resolve
ordenando uma vez. A pergunta é: guloso por qual critério? Três parecem
razoáveis:

- aceitar primeiro quem **começa** mais cedo;
- aceitar primeiro o pedido mais **curto**;
- aceitar primeiro quem **termina** mais cedo.

Só o terceiro funciona sempre. A ideia: o pedido que termina primeiro é o que
**devolve a quadra mais cedo**, e quadra livre cedo é o que deixa mais espaço
para os outros. Dá para provar com uma troca: pegue qualquer escolha ótima e
troque o primeiro pedido dela pelo que termina primeiro. Ele termina antes (ou
junto), então não choca com nenhum dos outros escolhidos, e a escolha continua
do mesmo tamanho. Repetindo para o resto, a escolha gulosa é tão boa quanto a
ótima.

O algoritmo fica assim:

1. **ordene** os pedidos pela hora de **fim**;
2. guarde a hora em que a quadra fica livre (`livre_em`, começando em 0);
3. percorra os pedidos em ordem: se o pedido começa em `livre_em` ou depois,
   **aceite** e mova `livre_em` para o fim dele; senão, recuse.

O custo é o da ordenação, O(n log n), mais uma passada O(n). Cada pedido é
olhado uma vez e a decisão é final: aceitou, aceitou; recusou, recusou.

Vamos ver na prática. No desenho, cada barra é um pedido, na ordem em que o
algoritmo olha para eles (por hora de fim). As verdes foram aceitas; as
cinzas chocaram com alguém já aceito. Repare na Iara: o pedido dela começa
antes de todos, às 7h, e é o primeiro que o critério "quem começa antes"
aceitaria, bloqueando a quadra até as 17h:

{{ideia}}

O mesmo exemplo em C. Os pedidos são structs, ordenados com `qsort` (assunto
0096) por uma função que compara os fins:

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

Repare que a Carla (10h às 11h) foi aceita logo depois da Ana (8h às 10h): os
intervalos são **semiabertos**, e a Ana libera a quadra exatamente às 10h. Por
isso o teste é `ini >= livre_em`, com o igual.

Repara no fluxograma: depois da ordenação, é um laço com uma pergunta só. O
caminho marcado mostra a Ana sendo aceita e o Bruno sendo recusado; o resto
repete esses dois trajetos:

{{fluxograma}}

> [!WARNING]
> Os outros dois critérios parecem bons e falham. "Começa primeiro" aceita a
> Iara (7h às 17h) e depois só o Hugo cabe: 1 pedido em vez de 5. "Mais curto
> primeiro" falha com três pedidos: 8h às 12h, 11h às 13h e 12h às 16h. O mais
> curto (11h às 13h) choca com os outros dois e fica sozinho, quando os dois
> compridos cabem juntos. Ordenar pelo campo errado é o erro mais comum, e o
> programa roda sem reclamar: só a resposta fica pior.

> [!TIP]
> **Por dentro do C:** o `qsort` move os elementos do vetor copiando bytes, e
> cada `Reserva` tem 16 bytes (um ponteiro de 8 e dois `int` de 4). Para
> structs grandes, vale ordenar um vetor de **ponteiros** para as structs: o
> `qsort` passa a mover 8 bytes por troca, e a comparação recebe um
> `const void *` que aponta para um ponteiro (`*(const Reserva * const *)a`).
> E a comparação devolve `(x > y) - (x < y)`, e não `x->fim - y->fim`: com
> horários tanto faz, mas com valores grandes a subtração pode estourar o
> `int`.

> [!NOTE]
> **Pergunta para você:** se o pedido do Hugo fosse das 14h às 18h, quantas
> reservas seriam aceitas? Quais? E se fosse das 16h às 18h?

{{pratique}}

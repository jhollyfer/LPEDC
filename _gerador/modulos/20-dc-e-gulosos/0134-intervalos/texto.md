## 0134 · Seleção de intervalos

A quadra do condomínio atende uma reserva por vez, e no sábado chegaram
nove pedidos, cada um com hora de início e de fim. Alguns horários se
chocam. O síndico quer aceitar o **maior número possível** de pedidos, sem
dois na quadra ao mesmo tempo. Quais ele aceita?

Esse é um problema clássico de escalonamento. Na **seleção de atividades**,
você recebe um conjunto de intervalos `[início, fim)` e quer o maior
subconjunto deles sem sobreposição (CORMEN et al., 2024, cap. 15). O mesmo
problema aparece com salas de reunião, com uma máquina que roda uma tarefa
por vez e com a grade de um canal de TV.

Testar todos os subconjuntos (0125) resolve, mas custa O(2ⁿ): são 512 casos
para nove pedidos e mais de um bilhão para trinta. Um guloso (0133) ordena
os pedidos uma vez e decide cada um numa passada. A dúvida é o critério.
Aceitar primeiro quem começa mais cedo parece justo. Aceitar primeiro o
pedido mais curto parece econômico. Aceitar primeiro quem termina mais cedo
parece estranho, e é o único que funciona sempre.

O motivo é simples de ver. O pedido que termina primeiro **devolve a quadra
mais cedo** e deixa o maior pedaço do dia livre para os outros (CORMEN et
al., 2024, cap. 15). Quem começa cedo pode ocupar a quadra o dia inteiro. Um
pedido curto pode cair bem no meio de dois outros que cabiam juntos.

A prova é uma troca, como no troco (0133). Pegue uma escolha ótima qualquer
e olhe o primeiro pedido dela. Troque-o pelo pedido que termina mais cedo
de todos. Esse termina antes ou junto, então não choca com nenhum dos
seguintes, e a escolha continua com o mesmo tamanho. Logo existe uma
solução ótima que começa pela escolha gulosa. Kleinberg e Tardos chamam esse
raciocínio de "ficar à frente": a cada passo, o guloso termina no máximo na
mesma hora que qualquer outra solução (KLEINBERG; TARDOS, 2006, cap. 4).

O algoritmo, que o Cormen chama de `GREEDY-ACTIVITY-SELECTOR`, tem três
partes. Primeiro, ordene os pedidos pela hora de fim. Depois, guarde numa
variável `livre_em` a hora em que a quadra fica livre, começando em 0. Por
fim, percorra os pedidos em ordem: se o pedido começa em `livre_em` ou
depois, aceite e mova `livre_em` para o fim dele; senão, recuse (CORMEN et
al., 2024, cap. 15).

O custo é dominado pela ordenação, O(n log n). A passada que decide é O(n),
porque olha cada pedido uma vez. Comparado com O(2ⁿ) de testar todos os
subconjuntos, a diferença é enorme já para poucas dezenas de pedidos
(CORMEN et al., 2024, cap. 15).

Um detalhe na comparação. Os intervalos são **semiabertos**: `[8, 10)`
inclui as 8h e não inclui as 10h. Quem sai às 10h libera a quadra às 10h, e
quem entra às 10h pode usá-la. Por isso o teste é `ini >= livre_em`, com o
igual (CORMEN et al., 2024, cap. 15). Com `>`, a reserva das 10h às 11h
seria recusada sem motivo.

> [!WARNING]
> Os outros critérios falham sem erro, só com resposta pior. "Começa primeiro"
> pega um pedido longo que bloqueia o dia; "mais curto primeiro" pode pegar um
> que choca com dois outros que cabiam juntos.

{{exemplo}}

Nove pedidos de reserva da quadra do condomínio no sábado. No desenho, verdes
foram aceitos e cinzas chocaram com alguém aceito. O pedido da Iara (7h às 17h)
seria o primeiro pelo critério "começa antes":

{{ideia}}

Os pedidos são structs, ordenados com `qsort` (0096) pelo fim. A comparação
usa `(x > y) - (x < y)`, que não estoura como a subtração:

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

"Começa primeiro" aceitaria a Iara e depois só o Hugo: 1 pedido em vez de 5.
Depois da ordenação, o laço tem uma pergunta só; o caminho marcado mostra a
Ana aceita e o Bruno recusado:

{{fluxograma}}

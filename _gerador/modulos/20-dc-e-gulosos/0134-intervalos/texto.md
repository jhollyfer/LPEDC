## 0134 · Seleção de intervalos

- **Seleção de atividades**: dado um conjunto de intervalos `[início, fim)`,
  achar o maior subconjunto sem sobreposição (CORMEN et al., 2024, cap. 15).
- **Critério guloso**: aceitar primeiro quem **termina** mais cedo. Ele
  devolve o recurso mais cedo e deixa mais espaço para os outros
  (CORMEN et al., 2024, cap. 15).
- **Prova por troca**: numa escolha ótima, troque o primeiro intervalo pelo
  que termina primeiro; ele não choca com os outros e o tamanho se mantém. É o
  argumento de "ficar à frente" (KLEINBERG; TARDOS, 2006, cap. 4).
- **`GREEDY-ACTIVITY-SELECTOR`**: ordene pelo fim; guarde `livre_em` (começa
  em 0); aceite quem começa em `livre_em` ou depois e mova `livre_em` para o
  fim dele (CORMEN et al., 2024, cap. 15).
- **Custo**: a ordenação, O(n log n), mais uma passada O(n). Testar todos os
  subconjuntos seria O(2ⁿ) (CORMEN et al., 2024, cap. 15).
- **Intervalo semiaberto**: quem sai às 10h libera às 10h, por isso o teste é
  `ini >= livre_em`, com o igual (CORMEN et al., 2024, cap. 15).

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

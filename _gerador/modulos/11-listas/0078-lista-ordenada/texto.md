## 0078 · Lista ordenada

Na clínica, as ligações chegam fora de ordem, mas a agenda tem de estar
sempre em ordem de horário. Em vez de reordenar tudo, cada marcação entra no
lugar certo.

Uma **lista ordenada** mantém os nós em ordem a cada inserção. A **inserção
ordenada** anda com o par `ant`/`p` (assunto 0077) enquanto os valores forem
menores que o novo. Ao parar, `p` é o primeiro nó maior ou igual ao novo (ou
`NULL`) e `ant` vem antes dele. O novo entra **entre** os dois, religando duas
setas, nesta ordem:

1. `novo->prox = p`;
2. `ant->prox = novo`.

Se `ant` for `NULL`, o novo é o menor e vira o início. O fim não é caso
especial: com `p == NULL`, o passo 1 grava `NULL` em `novo->prox`.

```c
No *lista_insere_ordenado(No *inicio, int valor) {
    No *novo = cria_no(valor);
    No *ant = NULL;
    No *p = inicio;
    while (p != NULL && p->valor < valor) { // anda enquanto os de lá são menores
        ant = p;
        p = p->prox;
    }
    novo->prox = p;         // o novo aponta para o primeiro maior (ou NULL)
    if (ant == NULL) {
        return novo;        // é o menor de todos: vira o início
    }
    ant->prox = novo;       // o anterior passa a apontar para o novo
    return inicio;
}
```

A ordem também ajuda na **busca**: dá para desistir ao passar do valor.
Procurando 11:00, a busca para no 14:30.

A agenda do exemplo tem 09:00, 14:30 e 16:00 quando chega a ligação das
10:15. O laço passa pelo 09:00 e para no 14:30 (`14:30 < 10:15` é falso). O
novo nó aponta para o 14:30 e o 09:00 aponta para ele:

{{ideia}}

O horário é um `int` hhmm (1430 é 14:30):

```c
#include <stdio.h>
#include "lista.h"

// cada horário é um int hhmm: 1430 quer dizer 14:30
static void mostra_agenda(const No *inicio) {
    for (const No *p = inicio; p != NULL; p = p->prox) {
        printf("%02d:%02d -> ", p->valor / 100, p->valor % 100);
    }
    printf("fim do dia\n");
}

int main(void) {
    No *agenda = NULL;
    int marcacoes[] = {1430, 900, 1600, 1015}; // na ordem em que ligaram

    for (int i = 0; i < 4; i++) {
        agenda = lista_insere_ordenado(agenda, marcacoes[i]);
        mostra_agenda(agenda);
    }

    // 11:00 está livre? A busca para no 14:30, sem olhar o resto
    if (lista_busca_ordenada(agenda, 1100) == NULL) printf("11:00 livre\n");

    lista_libera(agenda);
    return 0;
}
// Saída:
// 14:30 -> fim do dia
// 09:00 -> 14:30 -> fim do dia
// 09:00 -> 14:30 -> 16:00 -> fim do dia
// 09:00 -> 10:15 -> 14:30 -> 16:00 -> fim do dia
// 11:00 livre
```

No fluxograma, o laço roda uma vez e sai pelo Não no 14:30. Como `ant` é o
09:00, o caminho termina em `ant->prox = novo`. Na ligação das 9:00, `ant ==
NULL` e o novo virou o início:

{{fluxograma}}

O critério está na comparação do `while`: com `strcmp(p->nome, nome) < 0`, a
mesma inserção ordena por nome (exemplo A156).

> [!WARNING]
> O caso mais esquecido é o **novo menor que todos**: `ant` fica `NULL` e
> `ant->prox = novo` sem o `if` derruba o programa. Teste início, meio e fim.
> Com `<`, um valor repetido entra **antes** dos iguais; com `<=`, **depois**.

> [!TIP]
> **Por dentro do C:** a inserção ordenada é O(n) no pior caso; montar n itens
> custa O(n²). A busca continua O(n): chegar ao meio exige andar n/2 nós, sem
> busca binária. No vetor ordenado é o inverso: busca O(log n), inserção O(n).

> [!NOTE]
> **Pergunta para você:** inserindo 50, 40, 30, 20 e 10, nesta ordem, quantas
> vezes o corpo do `while` roda no total? E inserindo 10, 20, 30, 40 e 50?

{{pratique}}

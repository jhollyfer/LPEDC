## 0078 · Lista ordenada

Na clínica, as ligações chegam fora de ordem: primeiro alguém marca 14:30,
depois 09:00, depois 16:00. Mas a recepcionista precisa da agenda sempre em
ordem de horário, a qualquer momento do dia. Juntar tudo e ordenar no fim
não serve, porque a agenda é consultada o tempo todo. O jeito é cada marcação
entrar já no lugar certo.

É o que você faz com cartas na mão durante um jogo: cada carta nova vai
direto para a posição dela, entre a menor e a maior que ela, e a mão continua
arrumada. Uma **lista ordenada** mantém os nós em ordem a cada inserção, em
vez de reordenar tudo depois (CELES; RANGEL, 2002). Numa lista encadeada,
isso é barato na hora de encaixar: nenhum nó se move, só duas setas mudam.

A **inserção ordenada** reaproveita o par `ant`/`p` do assunto 0077. Os dois
andam pela lista enquanto os valores encontrados forem menores que o novo.
Quando o laço para, `p` é o primeiro nó com valor maior ou igual ao novo, ou
`NULL` se a lista acabou, e `ant` é o nó logo antes dele (FEOFILOFF, 2009,
cap. 4). O novo nó entra **entre** `ant` e `p`. Na agenda com 09:00, 14:30 e
16:00, a ligação das 10:15 faz o laço passar pelo 09:00 e parar no 14:30,
porque `14:30 < 10:15` é falso: `ant` fica no 09:00, `p` no 14:30.

Para encaixar o novo, religue duas setas, nesta ordem: primeiro
`novo->prox = p`, depois `ant->prox = novo` (CELES; RANGEL, 2002). A ordem
importa. O novo nó aponta para o seguinte enquanto o anterior ainda segura a
lista inteira; só então o anterior passa a apontar para o novo.

```c
while (p != NULL && p->valor < valor) { // anda enquanto os de lá são menores
    ant = p;
    p = p->prox;
}
novo->prox = p;          // o novo aponta para o primeiro maior (ou NULL)
if (ant == NULL) {
    return novo;         // é o menor de todos: vira o início
}
ant->prox = novo;        // o anterior passa a apontar para o novo
return inicio;
```

Dois extremos merecem atenção. Se o novo é menor que todos, o laço nem anda e
`ant` continua `NULL`: não há anterior, e o novo vira o início. O fim, ao
contrário, não é caso especial. Se o novo é maior que todos, `p` chega a
`NULL`, e `novo->prox = p` grava `NULL` no novo, que vira o último do jeito
certo (CELES; RANGEL, 2002).

A ordem também ajuda a **busca**. Numa lista sem ordem, para concluir que um
valor não está lá, você olha todos os nós. Numa lista ordenada, dá para
desistir assim que passar do valor procurado (FEOFILOFF, 2009, cap. 4).
Procurando 11:00, a busca para no 14:30: dali em diante, só há horários
maiores.

O critério da ordem mora todo na comparação do `while`. Trocando
`p->valor < valor` por `strcmp(p->nome, nome) < 0`, a mesma inserção ordena
por nome em ordem alfabética. A comparação também decide o que acontece com
valores repetidos: com `<`, o repetido entra **antes** dos iguais; com `<=`,
**depois** deles.

Quanto ao custo, cada inserção anda até o lugar certo, O(n) no pior caso, e
montar uma lista com n itens custa O(n²). A busca, mesmo com parada
antecipada, continua O(n): sem acesso direto ao meio, não dá para fazer busca
binária (ZIVIANI, 2010, cap. 3). O vetor ordenado tem o perfil oposto, e a
tabela compara os dois:

| Estrutura ordenada | Busca | Inserção |
| --- | --- | --- |
| lista encadeada | O(n) | O(n) para achar, O(1) para religar |
| vetor | O(log n) | O(n): desloca os seguintes |

> [!WARNING]
> O caso mais esquecido é o **novo menor que todos**: `ant` fica `NULL` e
> `ant->prox = novo` sem o `if` derruba o programa. Teste início, meio e fim.
> Com `<`, um repetido entra **antes** dos iguais; com `<=`, **depois**.

{{exemplo}}

A agenda de uma clínica tem 09:00, 14:30 e 16:00 quando chega a ligação das
10:15. O laço passa pelo 09:00 e para no 14:30; o novo aponta para o 14:30 e
o 09:00 aponta para ele:

{{ideia}}

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

Para as 10:15, o laço roda uma vez, `ant` é o 09:00 e o caminho termina em
`ant->prox = novo`; para as 9:00, `ant == NULL` e o novo vira o início:

{{fluxograma}}

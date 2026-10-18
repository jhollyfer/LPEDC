## 0083 · Lista ordenada

A recepcionista da clínica atende o telefone o dia todo. Um paciente marca
às 14:30, outro às 9:00, outro às 16:00, outro às 10:15. As ligações chegam
fora de ordem, mas a agenda na tela tem que estar sempre em ordem de horário.
Ordenar tudo de novo a cada ligação seria desperdício. Melhor: cada marcação
nova já entra no lugar certo.

Uma **lista ordenada** mantém os nós em ordem a cada inserção. A
**inserção ordenada** anda pela lista com o par `ant`/`p` do assunto anterior,
enquanto os valores de lá forem menores que o novo. Quando o laço para, `p` é
o primeiro nó maior ou igual ao novo (ou `NULL`, se o novo é o maior), e
`ant` é o nó que vem antes. O novo entra **entre** os dois.

Encaixar é religar duas setas, nesta ordem:

1. `novo->prox = p`: o novo aponta para quem vem depois dele;
2. `ant->prox = novo`: quem vinha antes passa a apontar para o novo.

Se `ant` for `NULL`, o novo é o menor de todos e vira o início. Não existe
caso especial para o fim: com `p == NULL`, o passo 1 grava `NULL` no
`novo->prox`, e é exatamente isso que o último precisa.

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

A ordem também ajuda na **busca**: procurando um valor numa lista crescente,
dá para desistir assim que passar dele. Procurando 11:00, a busca para no
14:30, porque dali para frente só tem horário mais tarde.

Vamos ver na prática. A agenda já tem 09:00, 14:30 e 16:00. Chega a ligação
das 10:15. O laço passa pelo 09:00 (menor) e para no 14:30, porque `14:30 <
10:15` é falso. O novo nó primeiro aponta para o 14:30 e depois o 09:00 passa
a apontar para ele:

{{ideia}}

O horário vira um `int` no formato hhmm (1430 é 14:30), e uma função do
próprio exemplo mostra bonito na tela:

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

Repara no fluxograma: o laço roda uma vez (passa pelo 09:00) e sai pelo Não no
14:30. Como `ant` aponta para o 09:00, o caminho termina em `ant->prox =
novo`. A ligação das 9:00, lá atrás, tinha ido pelo outro lado: `ant == NULL`,
e o novo virou o início:

{{fluxograma}}

O critério de ordem é só a comparação do `while`. Troque `p->valor < valor`
por `strcmp(p->nome, nome) < 0` e a mesma inserção monta uma lista em ordem
alfabética (exemplo A166).

> [!WARNING]
> O caso que todo mundo esquece é o **novo menor que todos**. O laço nem
> roda, `ant` fica `NULL`, e um `ant->prox = novo` sem o `if` derruba o
> programa. Teste sempre três inserções: no começo, no meio e no fim. E
> atenção ao `<` contra `<=`: com `<`, um valor repetido entra **antes** dos
> iguais; com `<=`, entra **depois**, e os iguais ficam na ordem de chegada.

> [!TIP]
> **Por dentro do C:** cada inserção ordenada custa O(n) no pior caso (o novo
> é o maior e o laço anda a lista toda). Montar uma lista de n itens assim
> custa O(n²). E a busca, mesmo parando cedo, continua O(n): não dá para
> fazer busca binária numa lista, porque chegar no meio exige andar n/2 nós.
> No vetor ordenado é o contrário: a busca binária é O(log n), mas inserir
> desloca até n itens. Cada estrutura cobra num lugar diferente.

> [!NOTE]
> **Pergunta para você:** inserindo 50, 40, 30, 20 e 10, nesta ordem, quantas
> vezes o corpo do `while` roda no total? E inserindo 10, 20, 30, 40 e 50?

{{pratique}}

## 0078 · Lista ordenada

- **Lista ordenada**: mantém os nós em ordem a cada inserção, em vez de
  reordenar tudo depois (CELES; RANGEL, 2002).
- **Inserção ordenada**: anda com o par `ant`/`p` (0077) enquanto os valores
  forem menores que o novo. Ao parar, `p` é o primeiro maior ou igual (ou
  `NULL`) e `ant` vem antes dele (FEOFILOFF, 2009, cap. 4).
- **Religar duas setas**, nesta ordem: `novo->prox = p` e depois
  `ant->prox = novo`. Se `ant` for `NULL`, o novo é o menor e vira o início;
  o fim não é caso especial (CELES; RANGEL, 2002).
- **Busca com parada**: dá para desistir ao passar do valor procurado
  (FEOFILOFF, 2009, cap. 4).
- **Critério**: está na comparação do `while`. Com
  `strcmp(p->nome, nome) < 0`, a mesma inserção ordena por nome.
- **Custo**: cada inserção é O(n) no pior caso, então montar n itens custa
  O(n²). A busca continua O(n): sem acesso direto não há busca binária
  (ZIVIANI, 2010, cap. 3).

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

## 0154 · Bellman-Ford: pesos negativos

Fim de turno. O motoboy de aplicativo está na Base e quer chegar em Casa
gastando o mínimo. Cada trecho custa gasolina, mas alguns trechos coincidem
com uma corrida aceita no caminho, e a corrida paga mais do que a gasolina.
Do Shopping até o Centro, por exemplo, ele gasta R$ 2 e recebe R$ 6: o
**custo líquido** do trecho é **R$ -4**.

O grafo é dirigido (a corrida só paga num sentido) e tem **pesos
negativos**. É aqui que o Dijkstra do assunto 0112 quebra. Ele fixa o Centro
com R$ 4 (indo direto da Base) antes de olhar o Shopping, e nunca mais volta
atrás. Mas Base, Shopping, Centro custa 6 - 4 = **R$ 2**. A promessa do
Dijkstra ("somar pesos só aumenta") deixou de valer, e ele termina dizendo
que Casa custa R$ 12, quando custa R$ 10.

O algoritmo de **Bellman-Ford** não confia em ninguém. Ele **relaxa todas
as arestas**, uma rodada inteira de cada vez, sem escolher o menor:

- `dist[origem] = 0` e INFINITO no resto;
- repita V - 1 vezes: para cada aresta `u -> v` com custo `c`, se
  `dist[u] + c < dist[v]`, atualize `dist[v]` e `anterior[v]`.

Por que V - 1 rodadas bastam? Um caminho mínimo não repete vértice, então
tem no máximo V - 1 arestas. A rodada 1 garante a primeira aresta do caminho
certa; a rodada 2, a segunda; e assim por diante. Se uma rodada inteira
passa sem mudar nada, as próximas também não mudariam, e dá para parar
antes.

E se existir um **ciclo negativo**, um circuito cuja soma é menor que zero?
Aí não existe caminho mínimo: dar mais uma volta sempre diminui o custo, e a
`dist` cairia para sempre. Bellman-Ford **detecta** isso com uma rodada
extra: se depois das V - 1 rodadas alguma aresta ainda melhora, há ciclo
negativo alcançável.

O preço da desconfiança é o tempo: V - 1 rodadas de E arestas, **O(V · E)**,
contra O((V + E) log V) do Dijkstra com heap. Use Bellman-Ford quando houver
peso negativo; sem eles, Dijkstra.

Vamos ver na prática. Os números nas setas são o custo líquido; em cima de
cada lugar, a `dist` final; verde, a rota até Casa. Embaixo, o vetor `dist`
rodada a rodada:

{{ideia}}

O código guarda as arestas numa lista (é só percorrer todas, então não
precisa de matriz). A ordem da lista foi escolhida de propósito para mostrar
as rodadas: começa pelas arestas que chegam em Casa.

```c
#include <stdbool.h>
#include <stdio.h>

#define V 6
#define E 9
#define INFINITO 1000000000 // folgado: INFINITO + peso ainda cabe num int

typedef struct {
    int de, para, custo; // custo líquido em R$: gasolina menos o que a corrida paga
} Trecho;

const char *lugares[V] = {"Base", "Shopping", "Centro", "Faculdade", "Hospital", "Casa"};

int main(void) {
    Trecho t[E] = {{4, 5, 3}, {3, 5, 6}, {3, 4, -2}, {2, 3, 9}, {2, 4, 5},
                   {1, 3, 7}, {1, 2, -4}, {0, 2, 4}, {0, 1, 6}};
    int dist[V], anterior[V];
    for (int v = 0; v < V; v++) {
        dist[v] = INFINITO;
        anterior[v] = -1;
    }
    dist[0] = 0;

    for (int rodada = 1; rodada <= V - 1; rodada++) { // no máximo V - 1 rodadas
        bool mudou = false;
        for (int k = 0; k < E; k++) { // relaxa TODAS as arestas, em qualquer ordem
            int u = t[k].de, v = t[k].para;
            if (dist[u] != INFINITO && dist[u] + t[k].custo < dist[v]) {
                dist[v] = dist[u] + t[k].custo;
                anterior[v] = u;
                mudou = true;
            }
        }
        printf("rodada %d:", rodada);
        for (int v = 0; v < V; v++) {
            if (dist[v] == INFINITO) printf(" ∞");
            else printf(" %d", dist[v]);
        }
        printf("\n");
        if (!mudou) break; // nada mudou: as próximas rodadas também não mudariam
    }

    for (int k = 0; k < E; k++) // rodada extra: se ainda melhora, há ciclo negativo
        if (dist[t[k].de] != INFINITO && dist[t[k].de] + t[k].custo < dist[t[k].para]) {
            printf("Ciclo negativo: dá para lucrar sem fim\n");
            return 0;
        }

    int rota[V], n = 0;
    for (int v = 5; v != -1; v = anterior[v]) rota[n++] = v;
    printf("Até Casa (R$ %d):", dist[5]);
    for (int i = n - 1; i >= 0; i--) printf(" %s%s", lugares[rota[i]], i > 0 ? " ->" : "");
    printf("\n");
    return 0;
}
// Saída:
// rodada 1: 0 6 4 ∞ ∞ ∞
// rodada 2: 0 6 2 13 9 ∞
// rodada 3: 0 6 2 11 7 12
// rodada 4: 0 6 2 11 7 10
// rodada 5: 0 6 2 11 7 10
// Até Casa (R$ 10): Base -> Shopping -> Centro -> Hospital -> Casa
```

Repara no fluxograma: não existe "escolher o menor". São dois laços
cegos, rodadas por fora e arestas por dentro, e duas saídas: uma rodada sem
mudança ou as V - 1 rodadas completas. Depois vem a rodada extra, só para
perguntar:

{{fluxograma}}

### Passo a passo

Cada rodada passa pela lista inteira, na ordem dela. Repare na Casa, que
aparece com 12 na rodada 3 (o mesmo valor errado do Dijkstra) e cai para 10
na rodada 4, quando a melhora do Centro chega até ela:

| Rodada | O que muda | Base | Shopping | Centro | Faculdade | Hospital | Casa |
| --- | --- | --- | --- | --- | --- | --- | --- |
| início | | 0 | ∞ | ∞ | ∞ | ∞ | ∞ |
| 1 | só as arestas que saem da Base | 0 | 6 | 4 | ∞ | ∞ | ∞ |
| 2 | Centro cai para 6 - 4 = 2 | 0 | 6 | 2 | 13 | 9 | ∞ |
| 3 | o 2 do Centro chega em Faculdade e Hospital | 0 | 6 | 2 | 11 | 7 | 12 |
| 4 | Casa via Hospital: 7 + 3 | 0 | 6 | 2 | 11 | 7 | 10 |
| 5 | nada muda: para | 0 | 6 | 2 | 11 | 7 | 10 |

Com a lista na ordem "natural" (as arestas da Base primeiro), uma rodada só
já chegaria ao resultado. O A308 mede isso. O A307 caça um ciclo negativo de
verdade, numa tabela de câmbio entre moedas, e mostra o ciclo.

> [!WARNING]
> Com `INT_MAX` como INFINITO e peso negativo, o teste `dist[u] != INFINITO`
> é obrigatório por outro motivo além do estouro: `INT_MAX + (-4)` **não**
> estoura, dá `INT_MAX - 4`, que é menor que `INT_MAX`. Sem o teste, um
> vértice inalcançável "melhora" outro vértice inalcançável, e o programa
> mostra uma distância gigante e falsa no lugar de "sem caminho". E cuidado:
> em grafo **não dirigido**, uma aresta negativa já é um ciclo negativo (ir e
> voltar por ela).

> [!TIP]
> **Por dentro do C:** a lista de arestas é um vetor de `Trecho` contíguo, 12
> bytes por aresta, e cada rodada o percorre em sequência, do primeiro ao
> último byte. Isso é o melhor caso para o cache do processador, e é um dos
> motivos de o Bellman-Ford ser usado de verdade em roteadores (o protocolo
> RIP espalha distâncias assim, vizinho a vizinho). O `INFINITO` de um bilhão
> deixa folga: `1000000000 + 1000000000` ainda cabe num `int` de 32 bits
> (até 2147483647), então nem a soma de dois "infinitos" estoura.

> [!NOTE]
> **Pergunta para você:** se a corrida da Faculdade para o Hospital passar a
> pagar mais (custo -6 em vez de -2), qual a nova rota até Casa e quanto ela
> custa? E se, além disso, existir um trecho Hospital -> Faculdade de custo
> 3, o que o programa mostra?

{{pratique}}

## 0155 · Floyd-Warshall: todos os pares

Um aplicativo de corrida precisa do tempo de cada bairro a cada outro, para
estimar o preço. São cinco bairros com ruas de **mão única**: Centro, Porto,
Vila, Alto e Feira. A pergunta é "**de todo mundo para todo mundo**".

Dá para rodar o Dijkstra a partir de cada bairro. O **Floyd-Warshall** monta
a tabela inteira com uma matriz e três laços aninhados. A ideia é da
programação dinâmica (módulo 21): pense nos bairros que um caminho pode usar
**como passagem**, não em caminhos inteiros.

Comece com `d[i][j]` = tempo da rua direta de `i` para `j` (INFINITO se não
existe, 0 na diagonal). Libere o Centro como passagem: vale ir de `i` ao
Centro e do Centro a `j`? Depois libere o Porto, a Vila, e assim por diante:

```text
para cada k:            (o bairro que passa a valer como passagem)
    para cada i, j:
        d[i][j] = mínimo(d[i][j], d[i][k] + d[k][j])
```

Depois da rodada `k`, `d[i][j]` é o melhor tempo de `i` a `j` usando como
passagem só os bairros de 0 a `k`. O `k` **tem** que ser o laço de fora: ele
é a rodada.

O custo é **O(V³)**, com memória O(V²): 125 passos para 5 bairros, 64
milhões para 400. Para 100 mil esquinas, use Dijkstra com heap. O
Floyd-Warshall aceita pesos negativos (sem ciclo negativo); com ciclo, aparece
`d[i][i] < 0` no fim.

No desenho, as setas são as ruas com os minutos, e o melhor caminho de
Centro até Alto, em verde, passa por três bairros. Embaixo, a tabela final,
com a linha do Centro destacada:

{{ideia}}

```c
#include <stdio.h>

#define V 5
#define INFINITO 1000000000

int main(void) {
    const char *bairros[V] = {"Centro", "Porto", "Vila", "Alto", "Feira"};
    int d[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = (i == j) ? 0 : INFINITO; // sem rua: infinito

    int ruas[][3] = {{0, 2, 2}, {2, 1, 3}, {0, 1, 6}, {1, 3, 4},
                     {3, 0, 5}, {2, 4, 7}, {4, 3, 1}, {1, 4, 2}};
    for (int r = 0; r < 8; r++) d[ruas[r][0]][ruas[r][1]] = ruas[r][2]; // mão única

    for (int k = 0; k < V; k++)         // k: o bairro que pode servir de passagem
        for (int i = 0; i < V; i++)     // de i
            for (int j = 0; j < V; j++) // para j
                if (d[i][k] != INFINITO && d[k][j] != INFINITO && d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j]; // passar por k é mais rápido

    printf("%-8s", "de\\para");
    for (int j = 0; j < V; j++) printf("%7s", bairros[j]);
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%-8s", bairros[i]);
        for (int j = 0; j < V; j++) printf("%7d", d[i][j]);
        printf("\n");
    }
    return 0;
}
// Saída:
// de\para  Centro  Porto   Vila   Alto  Feira
// Centro        0      5      2      8      7
// Porto         8      0     10      3      2
// Vila         11      3      0      6      5
// Alto          5     10      7      0     12
// Feira         6     11      8      1      0
```

O fluxograma tem três contadores e uma comparação no miolo, repetida V³
vezes:

{{fluxograma}}

### Passo a passo

A casa `d[Centro][Alto]`, rodada a rodada:

| Rodada (passagem liberada) | `d[Centro][Alto]` | Caminho por trás do número |
| --- | --- | --- |
| início | ∞ | (nenhuma rua direta) |
| k = Centro | ∞ | ninguém chega ao Alto pelo Centro ainda |
| k = Porto | 10 | Centro → Porto → Alto: 6 + 4 |
| k = Vila | 9 | Centro → Vila → Porto → Alto: 2 + 3 + 4 |
| k = Alto | 9 | passar pelo próprio destino não ajuda |
| k = Feira | 8 | Centro → Vila → Porto → Feira → Alto: 2 + 3 + 2 + 1 |

Na rodada da Vila, o programa soma `d[Centro][Vila]` (2) com
`d[Vila][Alto]` (7, da rodada do Porto): cada rodada aproveita as anteriores.

O A309 guarda o próximo passo de cada rota e imprime o caminho entre dois
bairros. O A310 troca `+` e `min` por `&&` e `||` e responde "existe
caminho?", o **fecho transitivo**.

> [!WARNING]
> Pôr o `k` no laço de **dentro** compila, roda e dá resposta errada sem
> aviso: `d[i][k]` e `d[k][j]` ainda não estão prontos. A soma
> `d[i][k] + d[k][j]` também precisa do teste de INFINITO (ou de um INFINITO
> folgado como o daqui): com `INT_MAX`, ela estoura.

> [!NOTE]
> **Pergunta para você:** se a prefeitura abrir uma rua Alto → Porto de 2
> minutos, que casas da tabela mudam? Calcule a nova linha do Alto e a nova
> coluna do Porto antes de acrescentar `{3, 1, 2}` (e trocar o 8 por 9).

{{pratique}}

## 0155 · Floyd-Warshall: todos os pares

Todo guia rodoviário antigo tinha, na última página, uma tabela triangular:
a distância de cada cidade para cada outra. Um aplicativo de corrida
precisa da mesma tabela, em minutos, para estimar o preço antes de chamar o
motorista. São cinco bairros com ruas de **mão única**: Centro, Porto, Vila,
Alto e Feira. A pergunta deixou de ser "de A até os outros" e passou a ser
"**de todo mundo para todo mundo**".

Dá para rodar o Dijkstra uma vez a partir de cada bairro. O
**Floyd-Warshall** faz a tabela inteira de outro jeito, com uma matriz e
três laços aninhados. A ideia é de programação dinâmica (módulo 21): em vez
de pensar em caminhos inteiros, pense nos bairros que um caminho pode usar
**como passagem**.

Comece com `d[i][j]` = tempo da rua direta de `i` para `j` (INFINITO se não
existe, 0 na diagonal). Agora libere o Centro como passagem: para cada par
`i`, `j`, vale a pena ir de `i` ao Centro e do Centro a `j`? Depois libere
também o Porto, depois a Vila, e assim por diante:

```text
para cada k:            (o bairro que passa a valer como passagem)
    para cada i, j:
        d[i][j] = mínimo(d[i][j], d[i][k] + d[k][j])
```

Depois da rodada `k`, `d[i][j]` é o melhor tempo de `i` a `j` usando como
passagem só os bairros de 0 a `k`. Depois da última, todos valem, e a tabela
está pronta. O `k` **tem** que ser o laço de fora: ele é a "rodada"; `i` e
`j` só percorrem a matriz.

São V³ passos: **O(V³)**, com memória O(V²). Para 5 bairros, 125 passos.
Para 400, 64 milhões, coisa de décimos de segundo. Para 100 mil esquinas,
esqueça: aí é Dijkstra com heap, de cada origem que interessar. E o
Floyd-Warshall aceita pesos negativos (sem ciclo negativo); se houver um,
ele aparece como `d[i][i] < 0` no fim.

Vamos ver na prática. As setas são as ruas com os minutos; em verde, o
melhor caminho de Centro até Alto, que passa por três bairros. Embaixo, a
tabela final, com a mesma linha do Centro destacada:

{{ideia}}

O código monta a matriz, roda os três laços e imprime a tabela:

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

Repara no fluxograma: não há fila, heap nem "escolher o menor". São três
contadores e uma comparação no miolo, repetida V³ vezes:

{{fluxograma}}

### Passo a passo

Siga uma casa só, `d[Centro][Alto]`, rodada a rodada. Não existe rua direta,
então ela começa em ∞:

| Rodada (passagem liberada) | `d[Centro][Alto]` | Caminho por trás do número |
| --- | --- | --- |
| início | ∞ | (nenhuma rua direta) |
| k = Centro | ∞ | ninguém chega ao Alto pelo Centro ainda |
| k = Porto | 10 | Centro → Porto → Alto: 6 + 4 |
| k = Vila | 9 | Centro → Vila → Porto → Alto: 2 + 3 + 4 |
| k = Alto | 9 | passar pelo próprio destino não ajuda |
| k = Feira | 8 | Centro → Vila → Porto → Feira → Alto: 2 + 3 + 2 + 1 |

Na rodada da Vila, o programa não "sabe" o caminho inteiro: ele só soma
`d[Centro][Vila]` (2) com `d[Vila][Alto]` (7, que a rodada do Porto já tinha
calculado). Cada rodada aproveita o trabalho das anteriores. É a tabela da
programação dinâmica, preenchida no lugar.

O A309 guarda, junto com a distância, o próximo passo de cada rota, e
imprime o caminho entre quaisquer dois bairros. O A310 troca `+` e `min` por
`&&` e `||` e responde só "existe caminho?", o **fecho transitivo**.

> [!WARNING]
> Pôr o `k` no laço de **dentro** (`for i, for j, for k`) compila, roda e dá
> resposta errada sem aviso: quando o par `i`, `j` é calculado, os pedaços
> `d[i][k]` e `d[k][j]` ainda não estão prontos. E a soma
> `d[i][k] + d[k][j]` precisa do teste de INFINITO (ou de um INFINITO
> folgado como o daqui): com `INT_MAX`, ela estoura.

> [!TIP]
> **Por dentro do C:** `int d[5][5]` são 25 `int` seguidos na memória, linha
> por linha: `d[i][j]` mora em `d + (i * 5 + j)`. No miolo, `j` é o laço
> mais rápido, então `d[i][j]` e `d[k][j]` andam de 4 em 4 bytes, em
> sequência, e o cache aproveita cada linha que busca. Trocar a ordem para
> `j` por fora e `i` por dentro daria o mesmo resultado (a rodada continua
> sendo o `k`), só que pulando 20 bytes a cada passo. Numa matriz de 2000 ×
> 2000, essa diferença vale um programa várias vezes mais lento.

> [!NOTE]
> **Pergunta para você:** se a prefeitura abrir uma rua Alto → Porto de 2
> minutos, que casas da tabela mudam? Calcule a nova linha do Alto e a nova
> coluna do Porto antes de acrescentar `{3, 1, 2}` (e trocar o 8 por 9).

{{pratique}}

## 0155 · Floyd-Warshall: todos os pares

Um aplicativo de corrida precisa do tempo de viagem de cada bairro para
cada outro, para estimar o preço antes de chamar o motorista. A cidade tem
cinco bairros ligados por ruas de **mão única**: Centro, Porto, Vila, Alto e
Feira. A pergunta não é mais "da origem para todo mundo", como no Dijkstra
(0112). É "**de todo mundo para todo mundo**".

Esse é o problema dos **caminhos mínimos entre todos os pares**: achar a
menor distância de cada vértice a cada outro e guardar tudo numa matriz
`d`, em que `d[i][j]` é a distância de `i` até `j` (CORMEN et al., 2024, cap.
23). Dá para rodar o Dijkstra uma vez a partir de cada bairro. O
**algoritmo de Floyd-Warshall** faz diferente: monta a matriz inteira com
três laços aninhados e quase nenhum código (FLOYD, 1962).

A ideia vem da programação dinâmica (módulo 21), e o truque está em qual
subproblema escolher. Em vez de pensar em caminhos inteiros, pense nos
bairros que um caminho tem permissão de usar **como passagem**, isto é, por
onde ele pode passar no meio, sem ser origem nem destino. No começo, nenhum
bairro pode ser passagem, e `d[i][j]` é só o tempo da rua direta de `i` para
`j`: INFINITO se a rua não existe e 0 na diagonal, porque ir de um bairro a
ele mesmo não custa nada (FLOYD, 1962).

Agora libere o Centro como passagem. Para cada par `i`, `j`, pergunte: ir
de `i` ao Centro e do Centro a `j` sai mais barato que o melhor que eu
conhecia? Se sim, atualize. Depois libere o Porto, fazendo a mesma pergunta
com o Porto no meio, e depois a Vila, o Alto e a Feira. Cada bairro liberado
é uma rodada:

```text
para cada k:            (o bairro que passa a valer como passagem)
    para cada i, j:
        d[i][j] = mínimo(d[i][j], d[i][k] + d[k][j])
```

O que garante que isso funciona é a afirmação que vale depois de cada
rodada: terminada a rodada `k`, `d[i][j]` é o melhor tempo de `i` a `j` que
usa como passagem só os bairros de 0 a `k`. Na rodada seguinte, o melhor
caminho com o bairro `k + 1` liberado ou não passa por ele, e já está em
`d[i][j]`, ou passa uma vez, e é a soma do trecho até ele com o trecho a
partir dele, dois valores já prontos. Por isso o `k` **tem** de ser o laço
de fora: ele é a rodada, e os laços de `i` e `j` só fazem sentido com a
rodada anterior completa.

Veja a casa `d[Centro][Alto]` evoluir. Não há rua direta, então ela começa
em INFINITO. Com o Porto liberado, vira 10 (Centro, Porto, Alto). Com a Vila,
cai para 9, porque Centro, Vila, Porto custa menos que Centro, Porto. Com a
Feira, cai para 8. Cada rodada aproveita o que as anteriores já acharam.

O custo é fácil de contar: três laços de V voltas, **O(V³)** de tempo, e a
matriz de V × V, O(V²) de memória. São 125 passos para 5 bairros e 64
milhões para 400. Para grafos grandes e esparsos, como um mapa com 100 mil
esquinas e poucas ruas por esquina, o Dijkstra com heap a partir de cada
origem sai muito mais barato (CORMEN et al., 2024, cap. 23).

O Floyd-Warshall aceita pesos negativos, desde que não haja ciclo negativo.
Se houver, ele avisa sozinho: no fim, algum `d[i][i]` fica menor que zero,
porque sair de `i` e voltar a `i` pelo ciclo "custa" menos que ficar
parado.

A mesma estrutura de três laços responde outra pergunta. Troque os números
por verdadeiro ou falso, o `+` por `&&` e o `mínimo` por `||`. Agora
`d[i][j]` diz se **existe caminho** de `i` a `j`. Essa matriz é o **fecho
transitivo** do grafo, e essa versão é o algoritmo de Warshall (TENENBAUM;
LANGSAM; AUGENSTEIN, 1995, cap. 8).

> [!WARNING]
> Pôr o `k` no laço de **dentro** compila, roda e erra sem aviso: `d[i][k]` e
> `d[k][j]` ainda não estão prontos. E `d[i][k] + d[k][j]` precisa do teste de
> INFINITO: com `INT_MAX`, estoura.

{{exemplo}}

Um aplicativo de corrida quer o tempo de cada bairro a cada outro, com ruas de
**mão única**. As setas são as ruas em minutos, e o melhor caminho de Centro
até Alto, em verde, passa por três bairros. Embaixo, a tabela final:

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

Cada rodada aproveita as anteriores: na da Vila, `d[Vila][Alto]` já vale 7,
calculado na rodada do Porto.

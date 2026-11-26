## 0188 · Aproximação

O 0186 deixou uma notícia ruim: para os problemas NP-difíceis, ninguém
conhece algoritmo que ache a resposta ótima em tempo polinomial. Só que o
problema continua lá, todo dia. O dono do barco de Manaus a Parintins precisa
decidir hoje como distribuir as cargas pelas viagens, e não pode esperar a
força bruta testar todas as combinações. Ele aceita uma resposta um pouco
pior que a melhor, desde que saia rápido e venha com uma **garantia** de
quanto pior ela pode ser.

Essa é a ideia do **algoritmo de aproximação**: um algoritmo de tempo
polinomial que, num problema de minimização, devolve uma solução de custo no
máximo **ρ vezes o ótimo**, em **qualquer** entrada. O número ρ é o **fator
de aproximação**. Um algoritmo 2-aproximado nunca gasta mais que o dobro do
ótimo, por pior que seja a entrada (CORMEN et al., 2024, cap. 35). Repare no
truque da prova: o algoritmo não conhece o ótimo, então a análise compara a
solução dele com um **limite inferior** do ótimo, um valor que nenhuma solução
consegue ficar abaixo.

O problema do barco é o **bin packing** (empacotamento em caixas): guardar
itens de tamanhos dados no menor número de caixas de capacidade C. É
NP-difícil. O limite inferior sai de uma conta simples: a soma dos tamanhos
dividida por C, arredondada para cima. Se as cargas somam 45 toneladas e o
barco leva 10, nenhuma solução faz menos que 5 viagens (KLEINBERG; TARDOS,
2006, cap. 11).

O guloso mais simples é o **first fit** (FF, primeira que cabe): cada item,
na ordem em que chega, vai para a primeira caixa aberta em que ele cabe; se
não cabe em nenhuma, abre uma caixa nova. A garantia vem de uma observação:
no fim, nunca sobram duas caixas ocupadas até a metade ou menos, porque o
conteúdo da segunda teria cabido na primeira. Então quase todas as caixas
estão mais que meio cheias, e o FF usa no máximo o dobro do ótimo. Uma
análise mais fina baixa esse fator para cerca de 1,7 (KLEINBERG; TARDOS, 2006,
cap. 11).

O **first fit decrescente** (FFD) ordena os itens do maior para o menor antes
de aplicar o mesmo guloso. Os itens grandes, que são os difíceis de encaixar,
entram primeiro, e os pequenos preenchem as sobras. A garantia melhora para
cerca de 11/9 do ótimo, mais uma constante pequena.

A **cobertura de vértices** do 0187 tem um 2-aproximado curto: enquanto houver
uma aresta `u-v` sem nenhuma ponta na cobertura, ponha **as duas pontas**
nela. O porquê do fator 2: as arestas que o algoritmo escolhe não têm ponta em
comum, já que, depois de escolher `u-v`, toda aresta que toca `u` ou `v` fica
coberta. Qualquer cobertura, inclusive a ótima, precisa de pelo menos uma
ponta de cada uma dessas arestas. O algoritmo pega duas por aresta, então
usa no máximo o dobro (CORMEN et al., 2024, cap. 35).

O **caixeiro viajante** pede o ciclo mais curto que passa por todas as
cidades. Na versão **métrica**, as distâncias obedecem à **desigualdade
triangular**: ir direto de A a C nunca é mais longo que passar por B. Com
essa hipótese existe um 2-aproximado: monte a árvore geradora mínima (Prim,
0153), percorra-a em pré-ordem e volte ao começo. A árvore custa menos que o
ciclo ótimo, porque tirar uma aresta do ciclo deixa uma árvore. Contornar a
árvore passa duas vezes por cada aresta, o dobro do custo dela, e pular as
cidades repetidas só encurta, pela desigualdade triangular. Sem essa
desigualdade, nenhum fator constante é possível, a menos que P = NP (CORMEN
et al., 2024, cap. 35).

> [!WARNING]
> "Aproximado" não é "chute": o fator vale para **toda** entrada e vem com
> prova. E o guloso "pega o vértice de maior grau" para cobertura **não** tem
> fator constante; o 2-aproximado é o "pega as duas pontas".

{{exemplo}}

Um barco de Manaus a Parintins leva 10 toneladas por viagem e recebe oito
cargas: 4, 4, 6, 9, 2, 6, 7 e 7. Em cima, o first fit na ordem de chegada;
embaixo, o decrescente, que bate o limite inferior de 5 viagens:

{{ideia}}

```c
#include <stdio.h>
#include <stdlib.h>

#define N 8
#define CAPACIDADE 10 // toneladas por viagem do barco

int compara_desc(const void *a, const void *b) {
    return *(const int *)b - *(const int *)a;
}

// first fit: cada carga vai para a PRIMEIRA viagem em que ainda cabe
int first_fit(const int carga[], int n, int viagem[][N], int qtd[]) {
    int livre[N], viagens = 0;
    for (int i = 0; i < n; i++) {
        int v = 0;
        while (v < viagens && livre[v] < carga[i]) v++;
        if (v == viagens) livre[viagens++] = CAPACIDADE, qtd[v] = 0; // abre outra viagem
        livre[v] -= carga[i];
        viagem[v][qtd[v]++] = carga[i];
    }
    return viagens;
}

void mostra(const char *nome, int viagens, int viagem[][N], const int qtd[]) {
    printf("%s: %d viagens\n", nome, viagens);
    for (int v = 0; v < viagens; v++) {
        int soma = 0;
        printf("  viagem %d:", v + 1);
        for (int i = 0; i < qtd[v]; i++) printf(" %d", viagem[v][i]), soma += viagem[v][i];
        printf("  (%d t)\n", soma);
    }
}

int main(void) {
    int carga[N] = {4, 4, 6, 9, 2, 6, 7, 7}; // na ordem em que chegam ao porto
    int viagem[N][N], qtd[N];

    int total = 0;
    for (int i = 0; i < N; i++) total += carga[i];
    printf("Total: %d t; limite inferior: %d viagens\n", total, (total + CAPACIDADE - 1) / CAPACIDADE);

    int ff = first_fit(carga, N, viagem, qtd);
    mostra("First fit", ff, viagem, qtd);

    qsort(carga, N, sizeof carga[0], compara_desc); // maiores primeiro
    int ffd = first_fit(carga, N, viagem, qtd);
    mostra("First fit decrescente", ffd, viagem, qtd);
    return 0;
}
// Saída:
// Total: 45 t; limite inferior: 5 viagens
// First fit: 6 viagens
//   viagem 1: 4 4 2  (10 t)
//   viagem 2: 6  (6 t)
//   viagem 3: 9  (9 t)
//   viagem 4: 6  (6 t)
//   viagem 5: 7  (7 t)
//   viagem 6: 7  (7 t)
// First fit decrescente: 5 viagens
//   viagem 1: 9  (9 t)
//   viagem 2: 7 2  (9 t)
//   viagem 3: 7  (7 t)
//   viagem 4: 6 4  (10 t)
//   viagem 5: 6 4  (10 t)
```

O first fit para uma carga procura a primeira viagem com espaço ou abre uma
nova. Custa O(n²) no pior caso:

{{fluxograma}}

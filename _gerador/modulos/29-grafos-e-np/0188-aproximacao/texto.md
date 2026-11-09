## 0188 · Aproximação

O barco de carga sai de Manaus para Parintins e leva no máximo 10 toneladas
por viagem. No porto chegam oito cargas: 4, 4, 6, 9, 2, 6, 7 e 7 toneladas.
Cada viagem custa caro, então o dono quer o menor número de viagens. Esse é
o **bin packing** (empacotamento em caixas), e ele é NP-difícil: ninguém
conhece um jeito rápido de achar sempre o mínimo.

O dono do barco não pode esperar a força bruta. Ele aceita uma resposta
**um pouco pior**, desde que venha rápido e com **garantia** de não ser
muito pior.

**Algoritmo de aproximação.** É um algoritmo polinomial que devolve uma
solução viável com custo no máximo **ρ vezes o ótimo** (num problema de
minimização). O ρ é o **fator de aproximação**: um algoritmo
2-aproximado nunca gasta mais que o dobro do ótimo, em **qualquer**
entrada. O truque é provar isso sem conhecer o ótimo, comparando com um
**limite inferior** dele.

**Bin packing.** Com capacidade C, nenhuma solução usa menos que
`soma / C` caixas, arredondado para cima: é o limite inferior. Dois gulosos:

- **first fit** (FF): cada item vai para a **primeira** caixa em que cabe;
  se não cabe em nenhuma, abre outra. Nunca sobram duas caixas com metade
  ou menos (o conteúdo da segunda caberia na primeira), e isso já garante
  no máximo 2 × ótimo; a análise fina dá cerca de 1,7 × ótimo;
- **first fit decrescente** (FFD): ordena os itens do maior para o menor e
  faz o mesmo. Os itens grandes abrem as caixas e os pequenos tapam os
  buracos. A garantia sobe para cerca de 11/9 × ótimo (mais uma constante).

**Cobertura de vértices 2-aproximada** (0187). Enquanto houver aresta
descoberta u-v, ponha **as duas pontas** na cobertura. As arestas escolhidas
não têm ponta em comum, e o ótimo precisa de pelo menos uma ponta de cada:
a resposta tem no máximo o dobro. O A375 roda isso contra a força bruta.

**Caixeiro viajante métrico 2-aproximado.** Quando as distâncias respeitam a
**desigualdade triangular** (ir direto nunca é mais longo que dar a volta),
monte a árvore geradora mínima (Prim, 0153), percorra-a em **pré-ordem** e
volte ao começo. A árvore custa menos que o ciclo ótimo (tire uma aresta do
ciclo e sobra uma árvore), a volta completa pela árvore custa o dobro dela, e
os atalhos da pré-ordem só encurtam. Total: no máximo 2 × ótimo. É o A376.
Sem a desigualdade triangular, nenhum fator constante é possível, a menos
que P = NP.

No desenho, em cima, está o first fit na ordem de chegada: os dois 4 e
o 2 lotam a primeira viagem, e cada carga grande acaba sozinha. Embaixo, o
first fit decrescente bate o limite inferior, 45 / 10 → 5 viagens: ótimo.

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

O fluxograma mostra o first fit para uma carga. Ele procura a primeira
viagem com espaço; se chegar ao fim da lista, abre uma nova. Com n cargas,
custa O(n²) no pior caso, nada perto do exponencial:

{{fluxograma}}

> [!WARNING]
> "Aproximado" não é "chute": o fator vale para **toda** entrada e vem com
> prova. E o fator é do pior caso; na prática o resultado costuma ser bem
> melhor. A pegadinha inversa também cai em prova: o guloso "pega o vértice
> de maior grau" para cobertura parece bom, mas **não** tem fator
> constante; pode ficar log n vezes pior que o ótimo. O 2-aproximado
> correto é o "pega as duas pontas".

> [!TIP]
> **Por dentro do C:** `livre[]` guarda quanto cabe em cada viagem aberta, e
> `viagem[N][N]` é uma matriz de 8 × 8 `int` na pilha (256 bytes): no pior
> caso cada carga vai sozinha, por isso N viagens de até N cargas. O
> `qsort` recebe `compara_desc`, que devolve `b - a` para inverter a ordem;
> com valores pequenos a subtração não estoura, mas para valores grandes
> use `(x < y) - (x > y)`. Ordenar custa O(n log n), menos que o próprio
> first fit.

> [!NOTE]
> **Pergunta para você:** se chegar uma nona carga de 5 toneladas no fim
> da fila, quantas viagens o first fit usa? E o decrescente? O limite
> inferior muda?


{{pratique}}

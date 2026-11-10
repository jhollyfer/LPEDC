## 0188 · Aproximação

O barco de Manaus a Parintins leva no máximo 10 toneladas por viagem. Chegam
oito cargas: 4, 4, 6, 9, 2, 6, 7 e 7, e o dono quer o menor número de viagens.
É o **bin packing** (empacotamento em caixas), NP-difícil. Ele aceita uma
resposta **um pouco pior**, se for rápida e com **garantia**.

**Algoritmo de aproximação** é um algoritmo polinomial com custo no máximo
**ρ vezes o ótimo** (minimização). O ρ é o **fator de aproximação**: um
2-aproximado nunca gasta mais que o dobro do ótimo, em **qualquer** entrada. A
prova compara com um **limite inferior** do ótimo.

**Bin packing.** Com capacidade C, nenhuma solução usa menos que `soma / C`
caixas, arredondado para cima: o limite inferior. Dois gulosos:

- **first fit** (FF): cada item vai para a **primeira** caixa em que cabe, ou
  abre outra. Nunca sobram duas caixas com metade ou menos (a segunda caberia
  na primeira): no máximo 2 × ótimo, e cerca de 1,7 × na análise fina;
- **first fit decrescente** (FFD): ordena do maior para o menor e faz o mesmo.
  A garantia é de cerca de 11/9 × ótimo (mais uma constante).

**Cobertura de vértices 2-aproximada** (0187): enquanto houver aresta
descoberta u-v, ponha **as duas pontas**. As arestas escolhidas não têm ponta
em comum, e o ótimo precisa de uma de cada: no máximo o dobro (A375).

**Caixeiro viajante métrico 2-aproximado.** Com a **desigualdade triangular**
(ir direto nunca é mais longo que dar a volta), monte a árvore geradora mínima
(Prim, 0153), percorra-a em **pré-ordem** e volte ao começo. A árvore custa
menos que o ciclo ótimo, a volta pela árvore custa o dobro dela, e os atalhos
só encurtam: no máximo 2 × ótimo (A376). Sem a desigualdade triangular, nenhum
fator constante é possível, a menos que P = NP.

No desenho, em cima, o first fit na ordem de chegada; embaixo, o decrescente,
que bate o limite inferior, 45 / 10 → 5 viagens: ótimo.

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

O fluxograma é o first fit para uma carga: procura a primeira viagem com
espaço ou abre uma nova. Custa O(n²) no pior caso:

{{fluxograma}}

> [!WARNING]
> "Aproximado" não é "chute": o fator vale para **toda** entrada e vem com
> prova, mas é do pior caso. A pegadinha inversa: o guloso "pega o vértice de
> maior grau" para cobertura **não** tem fator constante e pode ficar log n
> vezes pior que o ótimo. O 2-aproximado correto é o "pega as duas pontas".

> [!NOTE]
> **Pergunta para você:** se chegar uma nona carga de 5 toneladas no fim da
> fila, quantas viagens o first fit usa? E o decrescente? O limite inferior
> muda?

{{pratique}}

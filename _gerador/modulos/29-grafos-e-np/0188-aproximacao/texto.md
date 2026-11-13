## 0188 · Aproximação

- **Algoritmo de aproximação**: polinomial, com custo no máximo **ρ vezes o
  ótimo** (minimização) em **qualquer** entrada. O ρ é o **fator de
  aproximação**; a prova compara com um limite inferior do ótimo
  (CORMEN et al., 2024, cap. 35).
- **Bin packing**: guardar itens no menor número de caixas de capacidade C.
  NP-difícil; o limite inferior é `soma / C` arredondado para cima
  (KLEINBERG; TARDOS, 2006, cap. 11).
- **First fit** (FF): cada item vai para a primeira caixa em que cabe, ou abre
  outra. Nunca sobram duas caixas com metade ou menos: no máximo 2 × ótimo
  (cerca de 1,7 × na análise fina) (KLEINBERG; TARDOS, 2006, cap. 11).
- **First fit decrescente** (FFD): ordena do maior para o menor e faz o mesmo;
  garantia de cerca de 11/9 × ótimo, mais uma constante.
- **Cobertura de vértices 2-aproximada**: enquanto houver aresta descoberta
  u-v, ponha **as duas pontas**. As arestas escolhidas não têm ponta em comum
  e o ótimo precisa de uma de cada (CORMEN et al., 2024, cap. 35).
- **Caixeiro viajante métrico**: com a **desigualdade triangular**, monte a
  árvore geradora mínima (Prim, 0153), percorra em pré-ordem e volte ao
  começo: no máximo 2 × ótimo. Sem a desigualdade, nenhum fator constante é
  possível, salvo se P = NP (CORMEN et al., 2024, cap. 35).

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

## 0183 · Hamiltoniano

- **Ciclo hamiltoniano**: ciclo que passa por **todos os vértices**, cada um
  uma vez. **Caminho hamiltoniano** é o mesmo sem voltar ao começo
  (CORMEN et al., 2024, cap. 34).
- **Sem teste simples**: não se conhece condição necessária e suficiente nem
  algoritmo polinomial; o problema é NP-completo (KARP, 1972).
- **Condição de Dirac** (só suficiente): com V ≥ 3 e todo grau ≥ V/2, o ciclo
  existe. Um ciclo puro de 100 vértices tem grau 2 e é hamiltoniano mesmo
  assim (SZWARCFITER, 2018).
- **Backtracking**: monta a rota por posição; põe em `pos` um vizinho ainda
  não usado do último vértice, desce para `pos + 1` e, se travar, **desfaz** a
  escolha (ZIVIANI, 2010).
- **Economias**: fixe `rota[0] = 0` (divide o trabalho por V) e use `usada[]`
  para cortar repetição. No pior caso sobram (V - 1)! ordens: com 15
  vértices, 87 bilhões.

| | Euler (0182) | Hamilton |
| --- | --- | --- |
| passa uma vez por cada | aresta | vértice |
| teste | graus pares + conexo | nenhum teste rápido conhecido |
| custo para achar | O(V + E) | exponencial no pior caso |
| classe (0186) | P | NP-completo |

> [!WARNING]
> Esquecer o `usada[v] = false` depois da chamada recursiva deixa "queimado"
> todo vértice de uma tentativa que falhou, e o programa diz "não existe" para
> grafos que têm ciclo.

{{exemplo}}

Um carro-forte abastece cinco agências e volta à base, parando uma vez em
cada. A primeira tentativa trava no Shopping, sem via para a Base; o
backtracking volta ao Mercado, troca Porto por Shopping e fecha pelo Porto:

{{ideia}}

O código conta as chamadas da recursão:

```c
#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *agencias[V] = {"Base", "Centro", "Orla", "Mercado", "Porto", "Shopping"};
int via[V][V];
int rota[V];   // rota[i] = i-ésima agência visitada
bool usada[V];
long chamadas = 0;

// tenta pôr uma agência na posição pos da rota
bool hamilton(int pos) {
    chamadas++;
    if (pos == V) return via[rota[V - 1]][rota[0]]; // fecha o ciclo na Base?
    for (int v = 1; v < V; v++) {
        if (!via[rota[pos - 1]][v] || usada[v]) continue;
        rota[pos] = v;
        usada[v] = true;
        if (hamilton(pos + 1)) return true;
        usada[v] = false; // desfaz: volta atrás e tenta outra
    }
    return false;
}

int main(void) {
    int vias[][2] = {{0, 1}, {0, 2}, {0, 4}, {1, 2}, {1, 3}, {2, 3}, {3, 4}, {3, 5}, {4, 5}};
    for (int k = 0; k < 9; k++) via[vias[k][0]][vias[k][1]] = via[vias[k][1]][vias[k][0]] = 1;

    rota[0] = 0;
    usada[0] = true;
    if (hamilton(1)) {
        printf("Ciclo hamiltoniano:");
        for (int i = 0; i < V; i++) printf(" %s", agencias[rota[i]]);
        printf(" %s\n", agencias[rota[0]]);
    } else {
        printf("Não existe ciclo hamiltoniano\n");
    }
    printf("Chamadas da recursão: %ld\n", chamadas);
    return 0;
}
// Saída:
// Ciclo hamiltoniano: Base Centro Orla Mercado Shopping Porto Base
// Chamadas da recursão: 8
```

Este grafo não tem circuito euleriano (quatro agências de grau ímpar) e tem
ciclo hamiltoniano. O fluxograma mostra uma chamada de `hamilton(pos)`: o
trabalho está no laço que escolhe o vizinho e na linha que desfaz a escolha:

{{fluxograma}}

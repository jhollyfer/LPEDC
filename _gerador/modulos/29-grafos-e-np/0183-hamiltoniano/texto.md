## 0183 · Hamiltoniano

O carro-forte abastece cinco agências e volta à base. Repetir rua não importa;
parar duas vezes na mesma agência, sim, porque cada parada custa tempo e
escolta. Existe uma rota que passa por cada agência exatamente uma vez e
volta? A pergunta parece a do caminhão de lixo do 0182, só que com "vértice"
no lugar de "aresta". A troca de uma palavra muda tudo: para arestas existe
um teste rápido, e para vértices ninguém conhece um.

Um **ciclo hamiltoniano** é um ciclo que passa por todos os vértices do
grafo, cada um uma única vez, e volta ao primeiro. No vocabulário do Cormen,
é um ciclo simples que contém todos os vértices. Um **caminho hamiltoniano**
é a mesma coisa sem a volta ao começo: visita todos os vértices uma vez e
termina em outro lugar (CORMEN et al., 2024, cap. 34).

Para Euler bastava olhar os graus. Para Hamilton, não se conhece nenhuma
condição simples que seja ao mesmo tempo necessária e suficiente, e também
não se conhece algoritmo polinomial, isto é, com custo limitado por uma
potência de V. O problema de decidir se um grafo tem ciclo hamiltoniano está
na lista clássica de problemas NP-completos (KARP, 1972), uma classe que o
0186 apresenta com calma.

O que existe são condições **suficientes**: se valem, o ciclo existe; se não
valem, nada se conclui. A mais conhecida é a de **Dirac**: se o grafo tem V ≥
3 vértices e todo vértice tem grau ≥ V/2, então ele tem ciclo hamiltoniano
(SZWARCFITER, 2018). A intuição é que, com tantos vizinhos, sempre sobra uma
saída. A recíproca é falsa: um ciclo puro de 100 vértices tem grau 2 em todos,
muito abaixo de 50, e é hamiltoniano, porque ele mesmo é o ciclo.

A tabela compara os dois problemas, para que você não troque um pelo outro na
prova:

| | Euler (0182) | Hamilton |
| --- | --- | --- |
| passa uma vez por cada | aresta | vértice |
| teste | graus pares + conexo | nenhum teste rápido conhecido |
| custo para achar | O(V + E) | exponencial no pior caso |
| classe (0186) | P | NP-completo |

Sem teste rápido, sobra testar as possibilidades, e o jeito organizado de
fazer isso é o **backtracking** do módulo 19. A rota é montada por posição,
num vetor `rota[]`. Na posição `pos`, o algoritmo escolhe um vizinho do
vértice da posição `pos - 1` que ainda não esteja na rota, põe nessa posição
e desce para `pos + 1`. Se lá embaixo nenhuma escolha der certo, ele volta,
**desfaz** a escolha feita em `pos` e tenta o próximo vizinho. Quando as V
posições estão preenchidas, só falta conferir se o último vértice liga ao
primeiro (ZIVIANI, 2010).

Duas economias saem de graça. A primeira: todo ciclo pode começar em
qualquer um dos seus vértices, então fixar `rota[0] = 0` não perde nenhuma
resposta e divide o trabalho por V. A segunda: um vetor `usada[]` de
booleanos marca quem já está na rota, e a pergunta "esse vértice já entrou?"
custa O(1) em vez de uma varredura. Mesmo assim, no pior caso sobram (V - 1)!
ordens a testar. Com 15 vértices, são 14! ≈ 87 bilhões.

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

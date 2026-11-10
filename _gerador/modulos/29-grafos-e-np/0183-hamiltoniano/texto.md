## 0183 · Hamiltoniano

O carro-forte abastece cinco agências e volta à base. Repetir rua não importa;
parar duas vezes na mesma agência, sim. Existe uma rota que passa por **cada
agência exatamente uma vez** e volta? É o caminhão de lixo (0182) com
"vértice" no lugar de "aresta", mas a dificuldade é outra.

**Ciclo hamiltoniano** é um ciclo (simples, no Cormen) que passa por **todos
os vértices**, cada um uma vez. **Caminho hamiltoniano** é o mesmo sem voltar
ao começo.

Para Hamilton **não se conhece condição simples** necessária e suficiente, nem
algoritmo polinomial. Há condições suficientes, como a de **Dirac**: se V ≥ 3
e todo vértice tem grau ≥ V/2, o ciclo existe. Mas um ciclo puro de 100
vértices tem grau 2 em todos e é hamiltoniano mesmo assim.

| | Euler (0182) | Hamilton |
| --- | --- | --- |
| passa uma vez por cada | aresta | vértice |
| teste | graus pares + conexo | nenhum teste rápido conhecido |
| custo para achar | O(V + E) | exponencial no pior caso |
| classe (0186) | P | NP-completo |

Sobra testar. O **backtracking** do módulo 19 monta a rota por posição: põe em
`pos` um vizinho ainda não usado do último vértice, desce para `pos + 1` e, se
travar, **desfaz** a escolha e tenta a próxima. Com os V vértices na rota, só
falta o último ligar ao primeiro.

Duas economias não custam nada: fixe `rota[0] = 0` (todo ciclo pode começar
em qualquer vértice, o que divide o trabalho por V) e use `usada[]` para
cortar rota que repete agência. No pior caso sobram (V - 1)! ordens: com 15
agências, 87 bilhões.

A primeira tentativa, Base Centro Orla Mercado Porto Shopping, trava: não há
via do Shopping para a Base. O backtracking volta ao Mercado, troca Porto por
Shopping e fecha o ciclo pelo Porto:

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

O fluxograma mostra uma chamada de `hamilton(pos)`. "Rota completa?" só
confere a volta; o trabalho está no laço que escolhe o vizinho e na linha que
desfaz a escolha quando a descida falha:

{{fluxograma}}

Este grafo não tem circuito euleriano (quatro agências têm grau ímpar) e tem
ciclo hamiltoniano. O A365 mostra o contrário, e o backtracking só descobre
depois de tentar tudo. O A366 mede o crescimento das chamadas quando a
resposta é "não".

> [!WARNING]
> Esquecer o `usada[v] = false` depois da chamada recursiva é o erro clássico:
> cada agência de uma tentativa que falhou fica "queimada", e o programa
> responde "não existe" para grafos que têm ciclo.

> [!NOTE]
> **Pergunta para você:** se a via Porto-Base for fechada (apague `{0, 4}`),
> ainda existe ciclo hamiltoniano? A Base fica com grau 2: por quais agências
> o ciclo teria de entrar e sair dela?

{{pratique}}

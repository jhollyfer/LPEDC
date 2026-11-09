## 0183 · Hamiltoniano

O carro-forte sai da base, abastece os caixas eletrônicos de cinco agências e
volta. Aqui a pergunta mudou: ninguém se importa em repetir rua, mas parar
duas vezes na mesma agência é perder tempo com escolta e papelada. Existe uma
rota que passa por **cada agência exatamente uma vez** e volta para a base?

Parece o problema do caminhão de lixo (0182), trocando "aresta" por
"vértice", mas a dificuldade é outra.

**Ciclo hamiltoniano** é um ciclo (simples, no Cormen) que passa por **todos
os vértices**, cada um uma vez. **Caminho hamiltoniano** é o mesmo sem a
obrigação de voltar ao começo. O nome é do matemático William Hamilton, que
vendia um quebra-cabeça com um dodecaedro: achar um ciclo pelos 20 vértices.

Para Euler bastava contar graus. Para Hamilton **não se conhece nenhuma
condição simples** que seja necessária e suficiente, nem algoritmo
polinomial. Existem condições suficientes, como a de **Dirac**: se V ≥ 3 e
todo vértice tem grau ≥ V/2, o ciclo existe. Mas um ciclo puro de 100
vértices tem grau 2 em todos e é hamiltoniano mesmo assim.

| | Euler (0182) | Hamilton |
| --- | --- | --- |
| passa uma vez por cada | aresta | vértice |
| teste | graus pares + conexo | nenhum teste rápido conhecido |
| custo para achar | O(V + E) | exponencial no pior caso |
| classe (0186) | P | NP-completo |

Sem atalho, sobra testar. O **backtracking** do módulo 19 monta a rota uma
posição por vez: põe na posição `pos` um vizinho ainda não usado do último
vértice, desce para `pos + 1` e, se lá na frente travar, **desfaz** a escolha
e tenta a próxima. Quando a rota tem os V vértices, só falta conferir se o
último liga de volta ao primeiro.

Há duas economias que não custam nada. Todo ciclo pode começar em qualquer vértice, então
fixe o primeiro (`rota[0] = 0`): isso divide o trabalho por V. E o vetor
`usada[]` corta na hora qualquer rota que repete agência. Mesmo assim, no
pior caso sobram (V - 1)! ordens: com 15 agências, 87 bilhões.

A primeira tentativa, Base Centro Orla Mercado Porto
Shopping, trava: não há via do Shopping para a Base. O backtracking volta ao
Mercado, troca Porto por Shopping e fecha o ciclo pelo Porto:

{{ideia}}

O código conta as chamadas da recursão, para você ver quanto ele tentou:

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

O fluxograma mostra uma chamada de `hamilton(pos)`. A pergunta "rota
completa?" só confere a volta; o trabalho todo está no laço que escolhe o
vizinho, e na linha que desfaz a escolha quando a descida não deu certo:

{{fluxograma}}

Oito chamadas parece pouco porque a primeira tentativa quase deu certo. Mas
este grafo não tem circuito euleriano (quatro agências têm grau ímpar), e
mesmo assim tem ciclo hamiltoniano. O A365 mostra o contrário: um grafo com
circuito euleriano e **sem** ciclo hamiltoniano, em que o backtracking só
descobre isso depois de tentar tudo. O A366 mede o crescimento das chamadas
quando a resposta é "não".

> [!WARNING]
> Esquecer o `usada[v] = false` depois da chamada recursiva é o erro clássico.
> O programa continua compilando e rodando, mas cada agência visitada numa
> tentativa que falhou fica "queimada" para as tentativas seguintes, e ele
> responde "não existe" para grafos que têm ciclo. O E1097 traz esse bug. E lembre: euleriano é sobre **arestas**; hamiltoniano, sobre
> **vértices**.

> [!TIP]
> **Por dentro do C:** a recursão desce no máximo V níveis, então a pilha de
> chamadas nunca passa de V frames de `hamilton`, cada um com `pos`, `v` e o
> endereço de retorno. O que explode não é a memória, é o **tempo**: o número
> de chamadas pode chegar a (V - 1)!. `rota` e `usada` são globais e
> compartilhados por todas as chamadas, e por isso cada uma precisa desfazer
> o que fez antes de voltar.
 O `long` em `chamadas` está ali porque
> 13! já não cabe num `int` de 32 bits.

> [!NOTE]
> **Pergunta para você:** se a via Porto-Base for fechada (apague `{0, 4}`),
> ainda existe ciclo hamiltoniano? A Base fica com grau 2: por quais agências
> o ciclo teria de entrar e sair dela? Responda antes de rodar.

{{pratique}}

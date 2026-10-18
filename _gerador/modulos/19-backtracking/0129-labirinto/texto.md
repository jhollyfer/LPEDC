## 0129 · Labirinto

Festa junina na fazenda, e a atração é o labirinto de milho. Você entra pelo
canto de cima e quer achar a saída, lá no canto de baixo. A estratégia de quem
não tem mapa é a de sempre: anda, e quando dá num beco, volta até a última
bifurcação e tenta outro corredor. Para não andar em círculos, vai deixando
pedrinhas pelo caminho.

Isso é backtracking numa **matriz**. O mapa é um `char lab[L][C + 1]`: `'#'`
é parede, `'.'` é corredor, `'S'` é a entrada e `'F'` é a saída. A função
`anda(l, c)` responde "dá para chegar à saída a partir da casa (l, c)?". Ela
recusa na hora as casas impossíveis: fora do mapa, parede, ou casa que já
está no caminho. Se a casa é a saída, responde que sim. Senão, **marca** a
casa com `'*'`, tenta os quatro vizinhos e, se nenhum deu certo, **desfaz** a
marca.

Aqui está a diferença para os assuntos anteriores: o desfazer não volta a casa
para `'.'`, e sim para `'x'`. Uma casa da qual não se chega à saída continua
sem saída na próxima vez que a busca passar por ali, então não vale a pena
entrar de novo. Com o `'x'`, cada casa é visitada no máximo uma vez, e a
busca custa **O(L · C)**: é a busca em profundidade (DFS) do assunto 0111,
com a matriz fazendo o papel do grafo e os quatro vizinhos fazendo o papel
das arestas.

Repara também no `||` encadeado do código. Pelo curto-circuito (assunto
0013), assim que um vizinho devolve `true`, os seguintes nem são chamados. A
ordem das direções no `if` (direita, baixo, esquerda, cima) decide qual
caminho a busca acha primeiro.

Vamos ver na prática. Os números mostram a ordem dos passos do caminho
encontrado. A busca entrou primeiro no bolsão da direita, achou só becos
(vermelho) e voltou. Depois desceu pela coluna 1 até o corredor de baixo:

{{ideia}}

No fim, as casas com `*` são o caminho, e as com `x` são os becos que a
busca visitou e abandonou:

```c
#include <stdbool.h>
#include <stdio.h>

#define L 6
#define C 7

char lab[L][C + 1] = {   // + 1 para o '\0' de cada linha
    "S.....#",
    "#..#..#",
    "..#.##.",
    "...##.#",
    ".#.#.##",
    "......F",
};
int chamadas = 0;

// tenta chegar à saída a partir da casa (l, c)
bool anda(int l, int c) {
    chamadas++;
    if (l < 0 || l >= L || c < 0 || c >= C) {
        return false;                   // fora do mapa
    }
    if (lab[l][c] == 'F') {
        return true;                    // achou a saída
    }
    if (lab[l][c] != '.' && lab[l][c] != 'S') {
        return false;                   // parede, caminho atual ou beco
    }
    lab[l][c] = '*';                    // escolhe: estou passando por aqui
    if (anda(l, c + 1) || anda(l + 1, c) || anda(l, c - 1) || anda(l - 1, c)) {
        return true;                    // direita, baixo, esquerda, cima
    }
    lab[l][c] = 'x';                    // desfaz: beco sem saída
    return false;
}

int main(void) {
    if (anda(0, 0)) {
        int passos = 0;
        for (int l = 0; l < L; l++) {
            for (int c = 0; c < C; c++) {
                printf(c == 0 ? "%c" : " %c", lab[l][c]);
                passos += lab[l][c] == '*';
            }
            printf("\n");
        }
        printf("%d passos até a saída, %d chamadas\n", passos, chamadas);
    } else {
        printf("sem saída\n");
    }
    return 0;
}
// Saída:
// * * * x x x #
// # * * # x x #
// . * # . # # .
// . * * # # . #
// . # * # . # #
// . . * * * * F
// 13 passos até a saída, 41 chamadas
```

O caminho tem 13 passos, mas existe um de 11: descer direto pela coluna 1,
sem o desvio por (0, 2) e (1, 2). O backtracking acha **um** caminho, não o
**menor**. Para o menor, a ferramenta é a BFS (assunto 0110), ou um
backtracking que testa todos os caminhos (exemplo A258).

A mesma recursão, sem a saída e sem o desfazer, vira o **flood fill**
(preenchimento por inundação): a partir de uma casa, pinta todas as casas
alcançáveis. É o balde de tinta do editor de imagens, e é o assunto do
exemplo A257.

Repara no fluxograma: três perguntas mandam embora as casas impossíveis antes
de qualquer marcação, e só uma casa nova chega ao `'*'`:

{{fluxograma}}

> [!WARNING]
> Sem a marca de visitada, a busca anda em círculos. Da casa (0, 0) ela vai
> para (0, 1), que tenta a direita e o resto e, em algum momento, tenta a
> esquerda: volta para (0, 0), que tenta (0, 1) de novo, e assim para
> sempre. Não há laço infinito no código, mas a recursão não tem fim: a
> pilha estoura (*stack overflow*) e o programa morre. Marque a casa **antes**
> de chamar os vizinhos, não depois.

> [!TIP]
> **Por dentro do C:** a matriz `lab` é contínua na memória (assunto 0039):
> `lab[l][c]` fica no byte `l * (C + 1) + c` a partir do começo, e o `+ 1`
> existe porque cada linha foi escrita como uma string, com o `'\0'` no fim.
> A profundidade da recursão é o tamanho do caminho atual, que pode chegar a
> `L · C` casas. Um mapa 1000 × 1000 pede até um milhão de frames, bem mais
> que os 8 MB de pilha que o Linux costuma dar. Para mapas grandes, troque a
> recursão por uma pilha explícita de coordenadas (assunto 0082): é o mesmo
> algoritmo, com a pilha no heap.

> [!NOTE]
> **Pergunta para você:** troque a ordem das direções para baixo, direita,
> esquerda, cima. Quantos passos tem o caminho encontrado agora? Ainda
> aparece algum `x`?

{{pratique}}

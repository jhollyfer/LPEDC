## 0129 · Labirinto

Num labirinto de milho, você volta até a última bifurcação a cada beco e tenta
outro corredor, deixando pedrinhas para não andar em círculos.

Isso é backtracking numa **matriz**: `char lab[L][C + 1]`, com `'#'` de parede,
`'.'` de corredor, `'S'` de entrada e `'F'` de saída. `anda(l, c)` responde "dá
para chegar à saída a partir daqui?". Ela recusa fora do mapa, parede e casa
que já está no caminho; se a casa é a saída, responde sim; senão **marca** a
casa com `'*'`, tenta os quatro vizinhos e, se nenhum serviu, **desfaz** a
marca.

O desfazer volta a casa para `'x'`, não para `'.'`: quem não leva à saída
continua sem levar, então não vale entrar de novo. Assim cada casa é visitada
no máximo uma vez, e o custo é **O(L · C)**. É a busca em profundidade (DFS)
do assunto 0111, com a matriz no papel do grafo e os quatro vizinhos no das
arestas.

Pelo curto-circuito do `||` (assunto 0013), quando um vizinho devolve `true`,
os seguintes não são chamados. A ordem das direções (direita, baixo, esquerda,
cima) decide qual caminho sai primeiro.

No desenho, os números mostram a ordem dos passos: a busca tentou o bolsão da
direita, achou só becos (vermelho), voltou e desceu pela coluna 1:

{{ideia}}

No fim, `*` marca o caminho e `x` os becos abandonados:

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

O caminho tem 13 passos, mas existe um de 11 (descer direto pela coluna 1). O
backtracking acha **um** caminho, não o **menor**: para o menor, use a BFS
(assunto 0110) ou um backtracking que testa todos os caminhos (exemplo A258).

Sem a saída e sem o desfazer, a mesma recursão vira o **flood fill**
(preenchimento por inundação): o balde de tinta do editor de imagens (exemplo
A257). Três perguntas descartam as casas impossíveis, e só uma casa nova chega
ao `'*'`:

{{fluxograma}}

> [!WARNING]
> Sem a marca de visitada, a busca anda em círculos: (0, 0) chama (0, 1), que
> volta para (0, 0), e a recursão não tem fim até a pilha estourar (*stack
> overflow*). Marque a casa **antes** de chamar os vizinhos.

> [!TIP]
> **Por dentro do C:** a profundidade da recursão é o tamanho do caminho
> atual, até `L · C` casas. Um mapa 1000 × 1000 pede até um milhão de frames,
> mais que os 8 MB de pilha que o Linux costuma dar. Para mapas grandes, use
> uma pilha explícita de coordenadas (assunto 0082).

> [!NOTE]
> **Pergunta para você:** com as direções em ordem baixo, direita, esquerda,
> cima, quantos passos tem o caminho? Ainda aparece algum `x`?

{{pratique}}

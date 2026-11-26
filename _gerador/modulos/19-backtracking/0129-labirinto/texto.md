## 0129 · Labirinto

Num labirinto de milho, quem sai sem mapa usa uma estratégia que todo mundo
conhece. Segue por um corredor; num beco, volta até a última bifurcação e
tenta outro corredor; e deixa pedrinhas pelo caminho para não andar em
círculos. Isso é backtracking, e o labirinto é o lugar mais concreto para
vê-lo funcionar.

No C, o labirinto vira uma **matriz** de caracteres, `char lab[L][C + 1]`, em
que cada linha é uma string (daí o `+ 1`, para o `'\0'`). O caractere `'#'` é
parede, `'.'` é corredor livre, `'S'` é a entrada e `'F'` é a saída
(TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 3). Cada casa é um par
`(l, c)`, e os vizinhos dela são as quatro casas à direita, abaixo, à
esquerda e acima.

A função recursiva `anda(l, c)` responde uma pergunta só: "dá para chegar à
saída a partir desta casa?". Ela recusa logo três casos: casa fora do mapa,
parede e casa que já está marcada. Se a casa é a saída, responde sim. Senão,
**marca** a casa com `'*'`, como uma pedrinha, e tenta os quatro vizinhos. Se
algum responder sim, ela também responde sim, e as casas com `'*'` formam o
caminho. Se nenhum servir, ela **desfaz** a marca e responde não (DEITEL;
DEITEL, 2011).

O desfazer tem um detalhe. A casa não volta a ser `'.'`: ela vira `'x'`, uma
marca de beco. Uma casa de onde não se chega à saída continua sem levar à
saída na próxima vez que a busca passar por ela, então não adianta entrar de
novo. Com essa marca, cada casa é visitada no máximo uma vez, e o custo fica
em **O(L · C)**, proporcional ao tamanho do mapa (ROVAI, 2018).

Se você olhar com atenção, já viu esse algoritmo. É a busca em profundidade,
a DFS do assunto 0111: a matriz faz o papel do grafo, cada casa livre é um
vértice e os quatro vizinhos são as arestas. A marca `'*'` ou `'x'` é o
`visitado[]` (CORMEN et al., 2024, cap. 20).

Os quatro vizinhos são tentados numa expressão só, ligados por `||`. O
operador `||` do assunto 0013 tem **curto-circuito**: avalia da esquerda para
a direita e, assim que um termo dá verdadeiro, para, sem avaliar os seguintes.
Quando um vizinho devolve `true`, os outros nem são chamados (KERNIGHAN;
RITCHIE, 1989). Por isso a ordem das direções no código, direita, baixo,
esquerda, cima, decide qual caminho sai.

Como é uma DFS, o caminho achado é **um** caminho, não necessariamente o mais
curto. Ele depende da ordem das direções e pode dar voltas enormes. Para o
menor caminho, use a busca em largura, a BFS do assunto 0110, que explora a
matriz em ondas (CORMEN et al., 2024, cap. 20).

A profundidade da recursão é o tamanho do caminho atual, que pode chegar a
`L · C` casas. Um mapa de 1000 × 1000 pede até um milhão de frames, mais que
os 8 MB de pilha que o Linux costuma dar. Para mapas grandes, troque a
recursão por uma pilha explícita de coordenadas, como no assunto 0082.

A mesma recursão tem outro uso famoso. Tire a saída e tire o desfazer: a
função marca a casa e se espalha para os quatro vizinhos, até preencher toda a
região conectada. Isso é o **flood fill**, ou preenchimento por inundação, a
ferramenta do balde de tinta dos editores de imagem (CASTILHO; SILVA;
WEINGAERTNER, 2020).

> [!WARNING]
> Sem a marca de visitada, a busca anda em círculos: (0, 0) chama (0, 1), que
> volta para (0, 0), até a pilha estourar (*stack overflow*). Marque a casa
> **antes** de chamar os vizinhos.

{{exemplo}}

Num labirinto de milho 6 × 7, os números do desenho mostram a ordem dos
passos: a busca tentou o bolsão da direita, achou só becos (vermelho), voltou e
desceu pela coluna 1:

{{ideia}}

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

O caminho tem 13 passos, mas existe um de 11 (descer direto pela coluna 1).
Três perguntas descartam as casas impossíveis, e só uma casa nova chega ao
`'*'`:

{{fluxograma}}

## 0129 · Labirinto

- **Labirinto em matriz**: `char lab[L][C + 1]`, com `'#'` de parede, `'.'` de
  corredor, `'S'` de entrada e `'F'` de saída
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 3).
- **`anda(l, c)`**: responde "dá para chegar à saída daqui?". Recusa fora do
  mapa, parede e casa já marcada; senão **marca** com `'*'`, tenta os quatro
  vizinhos e, se nenhum serve, **desfaz** a marca (DEITEL; DEITEL, 2011).
- **Marca de beco**: o desfazer põe `'x'`, não `'.'`. Assim cada casa é
  visitada no máximo uma vez, e o custo é **O(L · C)** (ROVAI, 2018).
- **Busca em profundidade** (DFS): é o mesmo algoritmo do assunto 0111, com a
  matriz no papel do grafo e os quatro vizinhos no das arestas
  (CORMEN et al., 2024, cap. 20).
- **Curto-circuito**: no `||`, quando um vizinho devolve `true`, os seguintes
  não são chamados; a ordem das direções decide o caminho (KERNIGHAN; RITCHIE, 1989).
- **Um caminho, não o menor**: para o menor, use a busca em largura (BFS,
  assunto 0110) (CORMEN et al., 2024, cap. 20).
- **Flood fill** (preenchimento por inundação): a mesma recursão sem a saída e
  sem desfazer; é o balde de tinta do editor de imagens
  (CASTILHO; SILVA; WEINGAERTNER, 2020).

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

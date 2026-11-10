// 0152 · Kruskal: árvore geradora mínima
// Exercício E910 · ★★☆
//
// Oito sítios querem dividir o custo de puxar cabo de energia, mas um rio
// sem ponte separa quatro de um lado (Ipê, Jatobá, Aroeira, Cedro) e
// quatro do outro (Buriti, Pequi, Babaçu, Juçara). Sem travessia, não
// existe árvore que ligue todos: o resultado é uma FLORESTA, uma árvore
// mínima por margem. Escreva o Kruskal que funciona nesse caso e mostre
// cada rede (os sítios em ordem de índice e o total de km dela), listando
// as redes pela ordem do primeiro sítio de cada uma.
//
//   Saída esperada:
//   Rede 1 (Ipê Jatobá Aroeira Cedro): 9 km
//   Rede 2 (Buriti Pequi Babaçu Juçara): 7 km
//   Sem travessia: 2 redes separadas, 6 cabos, 16 km
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define V 8
#define E 10

typedef struct {
    int a, b, km;
} Aresta;

const char *sitios[V] = {"Ipê", "Buriti", "Jatobá", "Pequi", "Aroeira", "Babaçu", "Cedro", "Juçara"};

int main(void) {
    Aresta cabos[E] = {{0, 2, 3}, {2, 4, 4}, {0, 4, 6}, {4, 6, 2}, {2, 6, 5},
                       {1, 3, 7}, {3, 5, 1}, {5, 7, 3}, {1, 7, 4}, {3, 7, 2}};
    (void)cabos; // apague esta linha

    return 0;
}

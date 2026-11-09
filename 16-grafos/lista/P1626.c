// Lista · Módulo 16 · Grafos
// Exercício P1626 · ★★★ · O teorema dos parênteses no aeroporto
//
// Os corredores do aeroporto de Manaus são de mão única (grafo DIRIGIDO,
// vértices A a H no esqueleto). Rode a DFS do Cormen (laço principal e
// vizinhos em ordem de índice) e escreva "(X" quando X é descoberto e "X)"
// quando termina. O resultado é uma expressão de parênteses bem formada: é o
// TEOREMA DOS PARÊNTESES. Para dois vértices u e v, os intervalos [d, f] ou
// são disjuntos, ou um está inteiro dentro do outro, e v é descendente de u
// na floresta da DFS exatamente quando d[u] < d[v] < f[v] < f[u].
//
// Mostre:
//
// - a expressão de parênteses;
// - d/f de cada vértice;
// - quantos pares {u, v} têm intervalos aninhados, quantos disjuntos e
//   quantos se cruzam "pela metade" (tem de dar 0);
// - os descendentes de B pelo teste dos intervalos e, para conferir, subindo
//   por pi[] de cada vértice até achar (ou não) o B.
//
//   Saída esperada:
//   (A (B (C (D (E E) D) C) B) A) (F F) (G (H H) G)
//   A  1/10
//   B  2/ 9
//   C  3/ 8
//   D  4/ 7
//   E  5/ 6
//   F 11/12
//   G 13/16
//   H 14/15
//   Pares: 11 aninhados, 17 disjuntos, 0 cruzados
//   Descendentes de B (intervalos): C D E
//   Descendentes de B (pi):         C D E
//
// Dicas:
// 1. Ponha os printf de "(X" e "X)" nos mesmos lugares em que d[u] e f[u]
//    recebem ++relogio.
// 2. Para cada par i < j: aninhado se um intervalo contém o outro; disjunto
//    se f[i] < d[j] ou f[j] < d[i]; senão, cruzado.
// 3. v é descendente de u pelo pi[] se, subindo v, pi[v], pi[pi[v]], ...,
//    aparece u antes de -1.
// 4. Com 8 vértices há 28 pares. Os que estão na mesma linha de ancestrais
//    são aninhados (os 10 pares da cadeia A-B-C-D-E e o par G-H); o resto é
//    disjunto.
// 5. Resposta esperada: três árvores, (A ... A) (F F) (G (H H) G); 11 pares
//    aninhados, 17 disjuntos, 0 cruzados; descendentes de B: C D E.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 8

const char *nomes[V] = {"A", "B", "C", "D", "E", "F", "G", "H"};
// A check-in, B raio-x, C embarque, D free shop, E portão 1,
// F portão 2, G desembarque, H esteira
int adj[V][V];

int main(void) {
    int corredores[][2] = {{0, 1}, {1, 2}, {2, 3}, {2, 4}, {3, 4}, {4, 1}, {6, 7}, {7, 0}, {5, 4}};
    for (int k = 0; k < 9; k++) adj[corredores[k][0]][corredores[k][1]] = 1;

    return 0;
}

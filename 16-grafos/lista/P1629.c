// Lista · Módulo 16 · Grafos
// Exercício P1629 · ★★★ · Três representações do mesmo bairro em grade
//
// Um bairro planejado tem ruas em grade: 30 × 30 esquinas, cada esquina
// ligada às vizinhas de cima, baixo, esquerda e direita (não dirigido). A
// esquina (l, c) é o vértice l * 30 + c.
//
// Escreva um programa que:
//
// 1. gere a LISTA DE ARESTAS da grade (cada rua uma vez, como par u-v);
// 2. converta a lista de arestas em MATRIZ de adjacência e em LISTA de
//    adjacência (malloc);
// 3. rode a BFS a partir da esquina 0 nas duas representações, contando as
//    consultas (posições da matriz olhadas / nós de lista visitados), e
//    confira que o d[] de todos os 900 vértices bate;
// 4. mostre a memória de cada representação, calculada com sizeof, e quanto
//    a matriz ocuparia numa grade de 1000 × 1000.
//
//   Saída esperada:
//   V = 900, E = 1740
//   BFS: d máximo 58 | d igual nas duas: sim
//   Consultas: matriz 810000, lista 3480
//   Memória: arestas 13920 bytes, lista 62880 bytes, matriz 3240000 bytes
//   Grade 1000 x 1000: matriz de 4000000000000 bytes
//
// Dicas:
// 1. Arestas da grade: para cada esquina, a da direita (se c + 1 < 30) e a
//    de baixo (se l + 1 < 30). São 2 · 30 · 29 = 1740 ruas.
// 2. A matriz de 900 × 900 int tem 3,24 MB: deixe-a global (ou static), não
//    na pilha.
// 3. Memória: matriz V² · sizeof(int); lista V · sizeof(No *) + 2E ·
//    sizeof(No); arestas E · 2 · sizeof(int). Num sistema de 64 bits,
//    sizeof(No) é 16 (int + ponteiro, com 4 bytes de alinhamento).
// 4. Resposta esperada: d máximo 58 (o canto oposto), 810000 consultas na
//    matriz contra 3480 na lista, e a grade de um milhão de esquinas pediria
//    4 TB de matriz.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define N 30
#define V (N * N)

typedef struct No {
    int v;
    struct No *prox;
} No;

int main(void) {

    return 0;
}

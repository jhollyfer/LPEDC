// 0156 · Juntando tudo: o assistente do calouro
// Exercício E932 · ★☆☆
//
// A grade do texto: reprovar numa disciplina atrasa todas as que dependem
// dela, direta ou indiretamente. Complete a função alcance(u, visto): uma
// DFS que devolve quantas disciplinas ela alcança a partir de u (sem contar
// o próprio u), marcando em visto[] para não contar ninguém duas vezes. O
// main já mostra quantas cada uma "trava" e a mais perigosa.
//
//   Saída esperada:
//   Lógica trava 5
//   Cálculo trava 2
//   C trava 4
//   Estruturas trava 2
//   Arquivos trava 1
//   Grafos trava 1
//   Projeto trava 0
//   Não reprove em Lógica
//
// Dicas:
// 1. Para cada v com antes[u][v] e ainda não visto: marque visto[v] e some
//    1 (o próprio v) mais o que alcance(v, visto) devolver.
// 2. Sem o visto[], o Projeto seria contado duas vezes a partir de C (por
//    Arquivos e por Estruturas, Grafos).
// 3. Resposta esperada: a saída acima. Lógica trava C, Estruturas,
//    Arquivos, Grafos e Projeto.
//
// Escreva sua resposta abaixo (complete alcance):

#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *disc[V] = {"Lógica", "Cálculo", "C", "Estruturas", "Arquivos", "Grafos", "Projeto"};
int antes[V][V];

// quantas disciplinas a DFS alcança a partir de u (sem contar u)
int alcance(int u, bool visto[]) {
    (void)u; // apague estas duas linhas
    (void)visto;
    return 0;
}

int main(void) {
    int regras[][2] = {{0, 2}, {2, 3}, {2, 4}, {1, 5}, {3, 5}, {4, 6}, {5, 6}};
    for (int k = 0; k < 7; k++) antes[regras[k][0]][regras[k][1]] = 1;

    int melhor = 0, maior = -1;
    for (int u = 0; u < V; u++) {
        bool visto[V] = {false};
        visto[u] = true;
        int n = alcance(u, visto);
        printf("%s trava %d\n", disc[u], n);
        if (n > maior) {
            maior = n;
            melhor = u;
        }
    }
    printf("Não reprove em %s\n", disc[melhor]);
    return 0;
}

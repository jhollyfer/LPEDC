// 0109 · Grafos
// Exercício E652 · ★★☆
//
// Este programa tem DOIS erros de propósito. Ele monta o grafo NÃO dirigido
// do grupo de estudos (quem estuda com quem) e mostra o grau de cada pessoa.
// Rode com o rodar: o sanitizer acusa um dos erros. O outro é silencioso e só
// aparece nos números. Ache os dois, conserte e rode de novo até a saída
// bater com a esperada.
//
//   Saída esperada depois do conserto:
//   Ana estuda com 2 pessoa(s)
//   Beto estuda com 3 pessoa(s)
//   Cris estuda com 2 pessoa(s)
//   Davi estuda com 1 pessoa(s)
//   Soma dos graus: 8
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define V 4

int main(void) {
    const char *nomes[V] = {"Ana", "Beto", "Cris", "Davi"};
    int adj[V][V] = {0};
    int duplas[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}};

    for (int k = 0; k < 4; k++) {
        int a = duplas[k][0];
        int b = duplas[k][1];
        adj[a][b] = 1;
    }

    int soma = 0;
    for (int i = 0; i < V; i++) {
        int grau = 0;
        for (int j = 0; j <= V; j++) grau += adj[i][j];
        printf("%s estuda com %d pessoa(s)\n", nomes[i], grau);
        soma += grau;
    }
    printf("Soma dos graus: %d\n", soma);
    return 0;
}

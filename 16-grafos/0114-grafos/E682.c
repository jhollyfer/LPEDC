// 0114 · Grafos
// Exercício E682 · ★★☆
//
// Este programa tem DOIS erros de propósito. Ele monta o grafo NÃO dirigido
// do grupo de estudos (quem estuda com quem) e mostra o grau de cada pessoa.
// Rode com o rodar: o sanitizer acusa um dos erros. O outro é silencioso e só
// aparece nos números. Ache os dois e conserte.
//
//   Saída esperada depois do conserto:
//   Ana estuda com 2 pessoa(s)
//   Beto estuda com 3 pessoa(s)
//   Cris estuda com 2 pessoa(s)
//   Davi estuda com 1 pessoa(s)
//   Soma dos graus: 8
//
// Dicas:
// 1. Leia a mensagem do sanitizer: ela diz o índice e o tamanho do vetor.
// 2. Com 4 duplas de estudo, a soma dos graus deveria ser 2 x 4 = 8. Um
//    resultado ímpar é sinal de aresta guardada num sentido só.
// 3. Resposta esperada: o laço interno usa j <= V (lê adj[i][4], fora da
//    linha; o certo é j < V) e a aresta só é marcada em adj[a][b] (falta
//    adj[b][a] = 1). Consertado, mostra a saída acima.
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

// 0151 · Ordenação topológica
// Exercício E903 · ★★☆
//
// A equipe de suporte tem sete chamados, #101 a #107 (índices 0 a 6), e
// alguns só podem ser resolvidos depois de outros:
//
//   #105 -> #101   #105 -> #102   #106 -> #102   #102 -> #103
//   #107 -> #104   #101 -> #104
//
// O Kahn com fila atende na ordem em que os chamados ficam livres. A chefe
// quer outra regra: entre os livres, sempre o de MENOR número. Escreva as
// duas funções: kahn_fila (o Kahn do texto) e kahn_menor (a cada passo,
// procura o menor índice ainda não feito com grau 0).
//
//   Saída esperada:
//   Fila:   #105 #106 #107 #101 #102 #104 #103
//   Menor:  #105 #101 #106 #102 #103 #107 #104
//
// Dicas:
// 1. kahn_menor não precisa de fila: um vetor feito[] e, a cada um dos V
//    passos, um laço que pega o primeiro v com !feito[v] e grau[v] == 0.
// 2. Feito o u, desconte grau[v] de todo v com antes[u][v]. Se num passo
//    nenhum vértice estiver livre, há ciclo.
// 3. Resposta esperada: a saída acima. As duas são ordenações válidas. A
//    "menor" custa O(V²) com essa busca; com um heap de mínimo (assunto
//    0102) no lugar da fila, cairia para O((V + E) log V).
//
// Escreva sua resposta abaixo (escreva kahn_fila e kahn_menor):

#include <stdbool.h>
#include <stdio.h>

#define V 7

int antes[V][V]; // antes[a][b] = 1: o chamado a precisa ser resolvido antes do b

void conta_graus(int grau[]) {
    for (int b = 0; b < V; b++) grau[b] = 0;
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) grau[b] += antes[a][b];
}

void kahn_fila(void) {
    printf("Fila:  ");
    // ... para cada chamado u, na ordem: printf(" #%d", 101 + u);
    printf("\n");
}

void kahn_menor(void) {
    printf("Menor: ");

    printf("\n");
}

int main(void) {
    int regras[][2] = {{4, 0}, {4, 1}, {5, 1}, {1, 2}, {6, 3}, {0, 3}};
    for (int k = 0; k < 6; k++) antes[regras[k][0]][regras[k][1]] = 1;
    kahn_fila();
    kahn_menor();
    return 0;
}

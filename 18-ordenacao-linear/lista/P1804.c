// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1804 · ★☆☆ · Bucket sort da ocupação dos voos
//
// A companhia aérea guarda a taxa de ocupação de cada voo do dia como um
// número em [0, 1): 0.87 é 87% dos assentos. Ordene as 10 taxas do esqueleto
// com o bucket sort do Cormen: n = 10 baldes, o valor x vai para o balde
// ⌊10 x⌋, cada balde é uma lista encadeada (malloc) mantida em ordem por
// inserção, e no fim os baldes são concatenados em ordem.
//
// Mostre o conteúdo de cada balde não vazio e o vetor ordenado. Libere todos
// os nós.
//
//   Saída esperada:
//   balde 0: 0.05
//   balde 1: 0.12
//   balde 3: 0.31 0.36
//   balde 5: 0.52
//   balde 7: 0.79
//   balde 8: 0.84 0.87 0.88
//   balde 9: 0.99
//   ordenado: 0.05 0.12 0.31 0.36 0.52 0.79 0.84 0.87 0.88 0.99
//
// Dicas:
// 1. Balde de x: (int)(x * n). Como x < 1, o índice fica entre 0 e n - 1.
// 2. Inserir em ordem numa lista: ande com um ponteiro para ponteiro
//    (No **p = &balde[b]) enquanto (*p)->x < x, e encaixe o novo ali.
// 3. Com dados espalhados por igual, cada balde recebe O(1) itens em média e
//    o total é Θ(n). Aqui o balde 8 recebe três voos.
// 4. Resposta esperada: baldes 0, 1, 3, 5, 7, 8 e 9 ocupados; o vetor
//    ordenado começa em 0.05 e termina em 0.99.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct No {
    double x;
    struct No *prox;
} No;

int main(void) {
    double ocup[N] = {0.87, 0.31, 0.79, 0.05, 0.84, 0.52, 0.99, 0.12, 0.88, 0.36};

    for (int i = 0; i < N; i++) printf("%.2f ", ocup[i]);
    printf("\n");
    return 0;
}

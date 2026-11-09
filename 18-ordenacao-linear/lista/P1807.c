// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1807 · ★☆☆ · Quantas corridas entre R$ 10 e R$ 20? Em O(1)
//
// O app de transporte registrou o valor (em reais inteiros, de 0 a 50) das
// 20 corridas da manhã. O gerente vai fazer várias perguntas do tipo
// "quantas corridas custaram entre a e b reais?".
//
// O vetor acumulado do counting sort responde cada pergunta em O(1): depois
// de um pré-processamento Θ(n + k), C[x] = quantas corridas custaram <= x, e
// a resposta para [a, b] é C[b] - C[a - 1] (com C[-1] = 0). Escreva o
// pré-processamento e a função int entre(const int c[], int a, int b), e
// responda às perguntas do esqueleto.
//
//   Saída esperada:
//   Entre R$ 10 e R$ 20:  9 corridas
//   Entre R$  0 e R$ 50: 20 corridas
//   Entre R$  0 e R$  9:  4 corridas
//   Entre R$ 15 e R$ 15:  2 corridas
//   Entre R$ 30 e R$ 50:  4 corridas
//
// Dicas:
// 1. Mesmo começo do counting sort: conte cada valor e faça as somas
//    acumuladas. Não precisa ordenar nada.
// 2. Cuidado com a = 0: não existe C[-1]; trate como 0.
// 3. Para conferir, a pergunta [0, 50] tem de dar 20, e [x, x] dá quantas
//    corridas custaram exatamente x.
// 4. Resposta esperada: 9 corridas entre R$ 10 e R$ 20, 20 no total, 4 até
//    R$ 9 e 2 de exatamente R$ 15.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 20
#define K 51 // valores de 0 a 50

int main(void) {
    int corrida[N] = {12, 8, 25, 15, 33, 9, 18, 20, 41, 15,
                      7, 22, 10, 50, 13, 27, 19, 0, 36, 11};
    int perguntas[][2] = {{10, 20}, {0, 50}, {0, 9}, {15, 15}, {30, 50}};

    (void)corrida; // apague estas linhas
    (void)perguntas;
    return 0;
}

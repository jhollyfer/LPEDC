// Lista · Módulo 11 · Listas
// Exercício P1110 · ★☆☆ · A playlist de trás para frente, no lugar
//
// A playlist do treino é uma lista sequencial (vetor + tamanho). Escreva
//
//   int seq_inverte(ListaSeq *l)
//
// que inverte a ordem DENTRO do próprio vetor, trocando o primeiro com o
// último, o segundo com o penúltimo e assim por diante, e devolve quantas
// trocas fez.
// Teste com a playlist de 7 músicas 11, 22, 33, 44, 55, 66, 77 e com uma
// de 4 músicas 1, 2, 3, 4.
//
//   Saída esperada:
//   [77 66 55 44 33 22 11] em 3 trocas
//   [4 3 2 1] em 2 trocas
//
// Dicas:
// 1. Dois índices: i = 0 e j = n - 1. Troque v[i] com v[j] enquanto i < j,
//    andando i para a frente e j para trás.
// 2. São n / 2 trocas (divisão inteira): com n ímpar, o do meio fica onde
//    está. O custo é O(n) e a memória extra é O(1).
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define CAP 10

typedef struct {
    int v[CAP];
    int n;
} ListaSeq;

int main(void) {

    return 0;
}

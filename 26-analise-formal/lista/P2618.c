// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2618 · ★★☆ · Potência sem pilha
//
// A potência abaixo é recursiva e linear: para 3^e, empilha e + 1 frames e
// faz e multiplicações. Reescreva potencia com um laço só, sem recursão,
// pelo método das potências de 2 (quadrados sucessivos): enquanto e > 0,
// se e é ímpar multiplique o resultado pela base; eleve a base ao quadrado;
// divida e por 2. Faça as contas módulo 1000000007 e conte as
// multiplicações. Mostre o resultado e as multiplicações para e = 10, 1000
// e 1000000000:
//
//   Saída esperada:
//   3^10 mod p = 59049, 6 multiplicações
//   3^1000 mod p = 56888193, 16 multiplicações
//   3^1000000000 mod p = 235939645, 43 multiplicações
//
// Dicas:
// 1. São 2 multiplicações no máximo por volta, e floor(log2 e) + 1 voltas.
// 2. Espaço extra Θ(1) (três variáveis) e tempo Θ(log e). A versão do
//    esqueleto é Θ(e) nos dois.
// 3. Os resultados batem com o exercício E1005.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (reescreva a função):

#include <stdio.h>

#define MOD 1000000007L

long multiplicacoes = 0;

// 3^e mod p, uma chamada por expoente: Θ(e) de tempo e de pilha
long potencia(long base, long e) {
    if (e == 0) {
        return 1;
    }
    multiplicacoes++;
    return base * potencia(base, e - 1) % MOD;
}

int main(void) {
    long r = potencia(3, 10);
    printf("3^10 mod p = %ld, %ld multiplicações\n", r, multiplicacoes);
    return 0;
}

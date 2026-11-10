// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1020 · ★★☆ · As duplas da gincana em O(n)
//
// Na gincana da escola, uma dupla ganha bônus se a soma das idades dos dois
// for par. As idades dos 8 inscritos são 3, 8, 5, 12, 7, 10, 1 e 4 (é a
// gincana da família). Quantas duplas ganham bônus? Escreva:
//
//   long duplas_lento(const int v[], int n, long *passos)
//     testa todo par i < j e conta 1 passo por par testado;
//   long duplas_rapido(const int v[], int n, long *passos)
//     percorre o vetor UMA vez contando pares e ímpares (1 passo por item) e
//     depois calcula a resposta com uma conta.
//
//   Saída esperada:
//   Lento: 12 duplas em 28 passos
//   Rápido: 12 duplas em 8 passos
//
// Dicas:
// 1. Soma par só acontece com par + par ou ímpar + ímpar.
// 2. Com p pares e q ímpares: p (p - 1) / 2 + q (q - 1) / 2 duplas.
// 3. O lento é Θ(n²) (n (n - 1) / 2 pares); o rápido é Θ(n). Pensar no
//    problema, e não só no código, foi o que trocou a classe.
// 4. Resposta esperada: a saída acima (4 pares e 4 ímpares: 6 + 6 = 12).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

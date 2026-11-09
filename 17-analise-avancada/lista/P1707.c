// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1707 · ★☆☆ · Insertion sort recursivo e a recorrência T(n-1) + n
//
// Escreva do zero um insertion sort RECURSIVO para as senhas de atendimento
// de uma agência: ordena(v, n) ordena v[0..n-2] com uma chamada recursiva e
// depois insere v[n-1] na posição certa, deslocando os maiores. Conte as
// comparações entre elementos num contador global.
//
// A recorrência do pior caso é T(1) = 0 e T(n) = T(n - 1) + (n - 1), que
// soma 1 + 2 + ... + (n - 1) = n(n - 1)/2. No melhor caso, cada inserção faz
// uma comparação só: n - 1. Mostre as comparações para os três vetores de 10
// senhas do esqueleto, junto com n - 1 e n(n - 1)/2.
//
//   Saída esperada:
//   crescente     9 comparações: 101 102 103 104 105 106 107 108 109 110
//   decrescente  45 comparações: 101 102 103 104 105 106 107 108 109 110
//   misturado    26 comparações: 101 102 103 104 105 106 107 108 109 110
//   Melhor caso n - 1 = 9 | pior caso n(n - 1)/2 = 45
//
// Dicas:
// 1. Caso base: n <= 1, nada a fazer. Depois da chamada, x = v[n - 1];
//    j = n - 2; enquanto j >= 0 e (conte 1) v[j] > x, desloque v[j] para
//    v[j + 1].
// 2. Conte a comparação ANTES de testar: se o laço para porque j < 0, não
//    houve comparação.
// 3. O vetor crescente é o melhor caso (Θ(n)), o decrescente o pior
//    (Θ(n²)). O misturado fica no meio.
// 4. Resposta esperada: 9 comparações no crescente, 45 no decrescente e 26
//    no misturado.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 10

int main(void) {
    int crescente[N] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    int decrescente[N] = {110, 109, 108, 107, 106, 105, 104, 103, 102, 101};
    int misturado[N] = {105, 101, 108, 103, 110, 102, 107, 104, 109, 106};

    (void)crescente; // apague estas linhas
    (void)decrescente;
    (void)misturado;
    return 0;
}

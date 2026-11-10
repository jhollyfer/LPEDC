// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2907 · ★☆☆ · Clique ou independente?
//
// Numa turma de oito alunos (0 a 7), as amizades são:
//
//   0-1, 0-2, 0-3, 1-2, 1-3, 2-3, 3-4, 4-5, 5-6, 6-7, 4-6
//
// Escreva int tipo(const int s[], int k), que devolve 2 se o grupo é uma
// clique (todos amigos entre si), 1 se é independente (nenhum par amigo) e
// 0 se não é nenhum dos dois, e mostre o resultado para os grupos
// {0, 1, 2, 3}, {0, 4, 7}, {4, 5, 6}, {2, 5, 7} e {3, 4, 5}.
//
//   Saída esperada:
//   {0, 1, 2, 3}: clique
//   {0, 4, 7}: independente
//   {4, 5, 6}: clique
//   {2, 5, 7}: independente
//   {3, 4, 5}: nenhum dos dois
//
// Dicas:
// 1. Conte quantos dos k(k-1)/2 pares são amigos.
// 2. Todos os pares: clique. Nenhum: independente. Alguns: nenhum dos dois.
// 3. Resposta esperada: a saída acima. Os dois verificadores custam O(k²).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}

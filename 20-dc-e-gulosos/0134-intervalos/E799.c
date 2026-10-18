// 0134 · Seleção de intervalos
// Exercício E799 · ★☆☆
//
// A sala de reunião do escritório recebeu 8 pedidos para amanhã, já
// ORDENADOS pela hora de fim (o início está em ini[i], o fim em fim[i]):
//
//   8-9  8-10  9-11  10-12  11-12  12-14  13-15  14-16
//
// Escreva o laço guloso que escolhe o maior número de reuniões sem choque:
// guarde a hora em que a sala fica livre (começa em 0) e aceite cada pedido
// que começa nessa hora ou depois. Os intervalos são [ini, fim): quem
// termina às 9h libera a sala às 9h.
//
//   Saída esperada:
//   Escolhidas: 8-9 9-11 11-12 12-14 14-16
//   Total: 5
//
// Dicas:
// 1. Uma variável livre_em = 0 e um for de 0 a n - 1.
// 2. Se ini[i] >= livre_em: mostre o pedido, conte e faça livre_em = fim[i].
// 3. Resposta esperada: a saída acima. Como os pedidos já vieram ordenados,
//    o custo é O(n).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    // reuniões já ordenadas pela hora de fim
    int ini[] = {8, 8, 9, 10, 11, 12, 13, 14};
    int fim[] = {9, 10, 11, 12, 12, 14, 15, 16};
    int n = 8;
    (void)ini;
    (void)fim;
    (void)n;

    return 0;
}

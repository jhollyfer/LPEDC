// Lista · Módulo 12 · Pilhas e filas
// Exercício P1224 · ★★★ · A Torre de Hanói sem recursão
//
// Cada pino da Torre de Hanói é uma PILHA de discos: só se mexe no disco de
// cima, e nunca um disco maior sobre um menor. Há um jeito iterativo de
// resolver, sem recursão nenhuma: com n ímpar, repita em ciclo os pares de
// pinos (A, C), (A, B), (B, C); com n par, (A, B), (A, C), (B, C). Em cada
// par, faça o ÚNICO movimento permitido entre os dois pinos (o disco menor
// vai para cima do maior, ou para o pino vazio). Pare quando os n discos
// estiverem em C. Escreva o programa com três pilhas de int sobre vetor,
// para n = 3, numerando os movimentos.
//
//   Saída esperada:
//   1. disco 1: A -> C
//   2. disco 2: A -> B
//   3. disco 1: C -> B
//   4. disco 3: A -> C
//   5. disco 1: B -> A
//   6. disco 2: B -> C
//   7. disco 1: A -> C
//   Pino C (de baixo para cima): 3 2 1
//
// Dicas:
// 1. Comece com A = 3 2 1 (o 3 embaixo). topo(p) devolve o disco de cima,
//    ou um número grande (como 99) se o pino está vazio: assim "mover o
//    menor para cima do maior" vira uma comparação só.
// 2. Em cada par (x, y): se topo(x) < topo(y), mova de x para y; senão, de
//    y para x.
// 3. São sempre 2ⁿ - 1 movimentos: 7 para n = 3. O laço pode ir até o pino
//    C ter n discos.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    int v[10];
    int n;
    char nome;
} Pino;

int main(void) {

    return 0;
}

// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2024 · ★★★ · O máximo de entregas no prazo
//
// A lavanderia recebeu 7 pedidos para hoje. Cada um leva um tempo (em
// horas de máquina) e tem um prazo (a hora em que o cliente vem buscar).
// A máquina lava um pedido por vez. Pedido atrasado é cliente perdido,
// então o dono quer o MAIOR NÚMERO de pedidos prontos no prazo:
//
//   pedido   A  B  C  D  E  F  G
//   tempo    2  4  3  1  5  2  3
//   prazo    3  5  6  7  9 10 11
//
// O algoritmo de Moore-Hodgson é guloso: percorra os pedidos por prazo
// crescente, sempre aceitando o pedido; se a soma dos tempos aceitos passa
// do prazo do pedido atual, DESCARTE o aceito de MAIOR tempo (é o que mais
// libera a máquina). Escreva do zero, mostrando cada descarte e, no fim,
// os pedidos aceitos e a hora em que cada um fica pronto.
//
//   Saída esperada:
//   Descarta B (tempo 4)
//   Descarta E (tempo 5)
//   A pronto às 2 (prazo 3)
//   C pronto às 5 (prazo 6)
//   D pronto às 6 (prazo 7)
//   F pronto às 8 (prazo 10)
//   G pronto às 11 (prazo 11)
//   Pedidos no prazo: 5
//
// Dicas:
// 1. Os pedidos já estão em ordem de prazo. Guarde os aceitos num vetor
//    (com 7 pedidos, procurar o de maior tempo com um laço basta; com
//    milhares, use um heap de máximo).
// 2. Descartar o maior pode descartar o próprio pedido que acabou de
//    entrar: tudo bem.
// 3. Resposta esperada: descarta B e E e entrega 5 pedidos: A, C, D, F e G.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

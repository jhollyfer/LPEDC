// Lista · Módulo 21 · Programação dinâmica
// Exercício P2128 · ★★★ · As reservas que dão mais dinheiro
//
// O salão de festas recebeu 8 pedidos de reserva para sábado, cada um
// [ini, fim) em horas e com o valor que o cliente paga:
//
//   pedido   A       B       C       D        E        F        G        H
//   horas  [8,11)  [9,13)  [10,12) [11,15)  [12,16)  [14,18)  [15,20)  [17,22)
//   R$      400     700     300     600      500     1500      900      450
//
// Como no módulo 20, só cabe uma festa por vez. Mas agora o objetivo é o
// MAIOR FATURAMENTO, e o guloso "termina primeiro" não serve mais. A PD da
// SELEÇÃO DE INTERVALOS COM PESOS: ordene por fim; p[j] é o último pedido
// (na ordem) que termina até o início do j; melhor[j] = max(melhor[j - 1],
// valor[j] + melhor[p[j]]). Escreva do zero, ache p[j] por busca binária e
// reconstrua os pedidos aceitos.
//
//   Saída esperada:
//   Faturamento máximo: R$ 2200
//   Pedidos: B F
//
// Dicas:
// 1. Indexe de 1 a 8 depois de ordenar, com melhor[0] = 0 e p[j] = 0
//    quando nenhum termina antes.
// 2. Reconstrução: j = 8; se valor[j] + melhor[p[j]] >= melhor[j - 1], o
//    pedido j entrou (j = p[j]); senão, j--.
// 3. Resposta esperada: R$ 2200 com B e F. O guloso "termina primeiro"
//    pega A, D e G: mais festas (3), mas só R$ 1900.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}

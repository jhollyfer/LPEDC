// 0105 · A ideia e a função hash
// Exercício E625 · ★☆☆
//
// A lanchonete guarda os pedidos do dia numa prateleira com 11 nichos. O
// nicho de cada pedido é o resto da divisão do número do pedido por 11.
// Escreva a função "int nicho(int pedido)" e mostre o nicho dos pedidos
// 1043, 2210, 3876, 5521 e 7019, um por linha, no formato abaixo. Quando o
// nicho já estiver ocupado por um pedido anterior, acrescente na linha
// "(colide com NNNN)".
//
//   Saída esperada:
//   pedido 1043 -> nicho 9
//   pedido 2210 -> nicho 10
//   ...
//
// Dicas:
// 1. A função hash de inteiros é só "return pedido % 11;".
// 2. Guarde os 5 números num vetor e percorra com um for. Um vetor
//    "int dono[11] = {0};" lembra qual pedido ocupou cada nicho (0 = vazio).
// 3. Resposta esperada: 1043 -> 9, 2210 -> 10, 3876 -> 4,
//    5521 -> 10 (colide com 2210) e 7019 -> 1.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

// 0151 · Ordenação topológica
// Exercício E904 · ★★☆
//
// Uma obra tem oito serviços (índices 0 a 7, com a duração em dias): Elétrica
// 5, Fundação 10, Hidráulica 6, Paredes 15, Piso 4, Pintura 6, Reboco 8 e
// Telhado 7. As regras "a antes de b" são:
//
//   Fundação -> Paredes    Paredes -> Telhado     Paredes -> Elétrica
//   Paredes -> Hidráulica  Telhado -> Reboco      Elétrica -> Reboco
//   Hidráulica -> Reboco   Hidráulica -> Piso     Reboco -> Pintura
//   Piso -> Pintura
//
// Com equipes em paralelo, um serviço começa no dia em que o ÚLTIMO dos que ele
// espera termina. Escreva o Kahn com fila (vizinhos em ordem de índice) e
// mostre, na ordem em que os serviços saem da fila, o dia de início e o de fim
// de cada um, o prazo total e o caminho crítico (a corrente de serviços que, se
// atrasar um dia, atrasa a obra).
//
//   Saída esperada:
//   Fundação: dia 0 ao 10
//   Paredes: dia 10 ao 25
//   Elétrica: dia 25 ao 30
//   Hidráulica: dia 25 ao 31
//   Telhado: dia 25 ao 32
//   Piso: dia 31 ao 35
//   Reboco: dia 32 ao 40
//   Pintura: dia 40 ao 46
//   Obra pronta em 46 dias
//   Caminho crítico: Fundação -> Paredes -> Telhado -> Reboco -> Pintura
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

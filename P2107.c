// Lista · Módulo 21 · Programação dinâmica
// Exercício P2107 · ★☆☆ · Plantões sem dois seguidos
//
// Uma enfermeira pode pegar plantões extras nos próximos 9 dias, mas a
// regra do hospital proíbe dois plantões em dias seguidos. Cada dia paga
// um valor diferente (fim de semana e feriado pagam mais):
//
//   dia:   1    2    3    4    5    6    7    8    9
//   R$:   180  250  160  300  120  220  400  150  210
//
// Quanto ela ganha, no máximo? Escreva do zero a PD: ganho[i] é o melhor
// valor usando os dias 1 a i. No dia i, ou ela não trabalha (fica
// ganho[i - 1]) ou trabalha (valor[i] + ganho[i - 2]). Depois, reconstrua
// os dias escolhidos andando de trás para a frente.
//
//   Saída esperada:
//   Ganho máximo: R$ 1160
//   Dias: 2 4 7 9
//
// Dicas:
// 1. ganho[0] = 0 e ganho[1] = valor[1]. Use índices de 1 a 9 para o
//    i - 2 não sair do vetor.
// 2. Reconstrução: i = 9; se ganho[i] == ganho[i - 1], o dia i ficou de
//    fora (i--); senão, ele entrou (mostre e i -= 2).
// 3. Resposta esperada: R$ 1160, nos dias 2, 4, 7 e 9.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

// 0133 · Algoritmos gulosos
// Exercício E798 · ★★★
//
// Depois do churrasco, a conta foi dividida igualmente entre 6 amigos, mas
// cada um pagou uma parte diferente no mercado:
//
//   Ana R$ 180, Bruno R$ 0, Carla R$ 60, Davi R$ 120, Eva R$ 0, Fábio R$ 90
//
// Monte os Pix para acertar as contas com este guloso: enquanto alguém deve,
// quem MAIS deve paga para quem MAIS tem a receber o menor dos dois valores
// (a dívida de um ou o crédito do outro). Em caso de empate, vale o que vem
// primeiro na lista. Trabalhe em centavos, num int.
//
//   Saída esperada:
//   Total R$ 450.00, cada um R$ 75.00
//   Bruno -> Ana: R$ 75.00
//   Eva -> Davi: R$ 45.00
//   Eva -> Ana: R$ 30.00
//   Carla -> Fábio: R$ 15.00
//   4 Pix
//
// Dicas:
// 1. saldo[i] = pagou[i] - parte. Positivo: tem a receber; negativo: deve.
// 2. A cada volta, ache o índice do menor saldo (quem mais deve) e o do
//    maior (quem mais tem a receber). Se o menor saldo é 0, acabou.
// 3. Resposta esperada: a saída acima. Cada Pix zera pelo menos uma pessoa,
//    então são no máximo n - 1 Pix. (Achar o MÍNIMO absoluto de Pix é um
//    problema bem mais difícil; o guloso dá uma boa resposta, rápida.)
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 6

int main(void) {
    const char *nome[N] = {"Ana", "Bruno", "Carla", "Davi", "Eva", "Fábio"};
    int pagou[N] = {18000, 0, 6000, 12000, 0, 9000}; // centavos
    (void)nome;
    (void)pagou;

    return 0;
}

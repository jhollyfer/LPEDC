// 0023 · switch, case, break e fall-through
// Exercício E138 · ★★★
//
// Fall-through de propósito. O lava-rápido tem três pacotes, e cada um
// inclui os de baixo: o 1 é só lavagem (R$ 30); o 2 é aspiração (R$ 15) +
// lavagem; o 3 é cera (R$ 25) + aspiração + lavagem. Leia o pacote, liste os
// serviços e mostre o total, usando UM switch em que o case 3 cai no 2 e o 2
// cai no 1.
//
//   Pacote (1 a 3): 3
//   Cera: R$ 25.00
//   Aspiração: R$ 15.00
//   Lavagem: R$ 30.00
//   Total: R$ 70.00
//
// Dicas:
// 1. Comece com total = 0. Cada case mostra o seu serviço e soma o preço.
// 2. Ponha os case na ordem 3, 2, 1; só o 1 tem break. Escreva o comentário
//    "// fall through" no lugar de cada break que falta: o gcc entende e
//    não avisa.
// 3. Resposta esperada: 3 → R$ 70.00; 2 → aspiração e lavagem, R$ 45.00;
//    1 → só lavagem, R$ 30.00; 4 → "Pacote inválido.".
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

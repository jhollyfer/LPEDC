// 0003 · Tipos e limites
// Exercício E018 · ★★★
//
// Complemento de dois na prática. O painel de um freezer recebe a
// temperatura num byte. Para cada temperatura (-1, -128, 127 e 0), guarde o
// valor num int8_t, copie para um uint8_t e mostre: o valor com sinal, o
// valor sem sinal e o byte em hexa. Reaproveite as mesmas duas variáveis
// (declare uma vez e troque os valores). Por fim, mostre a faixa do int8_t
// com as constantes do stdint.h.
//
//   Saída esperada:
//   -1 -> 255 (0xFF)
//   -128 -> 128 (0x80)
//   127 -> 127 (0x7F)
//   0 -> 0 (0x0)
//   int8_t: -128 a 127
//
// Dicas:
// 1. int8_t com_sinal = -1; uint8_t sem_sinal = com_sinal; e depois
//    com_sinal = -128; sem_sinal = com_sinal; e assim por diante.
// 2. printf("%d -> %d (0x%X)\n", com_sinal, sem_sinal, sem_sinal);
// 3. Os bits não mudam na cópia: o tipo só decide se o bit de cima vale
//    -128 ou +128. Para os negativos, sem sinal = com sinal + 256.
// 4. Resposta esperada: as cinco linhas acima. A faixa é assimétrica
//    porque o zero ocupa uma das combinações sem o bit de cima, e não
//    existe -0.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdint.h>

int main(void) {

    return 0;
}

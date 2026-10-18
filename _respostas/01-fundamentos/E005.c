// 0001 · O primeiro programa
// Exercício E005 · ★★★
//
// Resposta: a) com return 0, echo $? mostra 0; com return 3, mostra 3; com
// return 256, mostra 0. b) Com return 3, "pode seguir" não aparece: o && do
// terminal só roda o segundo comando quando o primeiro devolve 0 (sucesso).
// c) O sistema guarda só o byte de baixo do código de saída: 256 em binário
// é 1 0000 0000, e os 8 bits de baixo são todos zero.

#include <stdio.h>

int main(void) {
    printf("Backup concluído\n");
    return 0; // troque por 3 e depois por 256 para testar
}

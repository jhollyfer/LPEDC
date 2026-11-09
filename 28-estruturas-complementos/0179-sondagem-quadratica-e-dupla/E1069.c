// 0179 · Sondagem quadrática e dupla
// Exercício E1069 · ★☆☆
//
// Com m = 13 (sondagem.h), mostre as 6 primeiras posições da sequência de
// sondagem das chaves 44 e 57 nos três modos (SD_LINEAR, SD_QUADRATICA e
// SD_DUPLA), usando sd_posicao(t, chave, i) para i de 0 a 5. As duas chaves
// começam na posição 5: repare em qual modo as sequências se separam.
//
//   Saída esperada:
//   chave 44
//     linear:      5  6  7  8  9 10
//     quadrática:  5  6  9  1  8  4
//     dupla:       5  1 10  6  2 11
//   chave 57
//     linear:      5  6  7  8  9 10
//     quadrática:  5  6  9  1  8  4
//     dupla:       5  2 12  9  6  3
//
// Dicas:
// 1. Crie uma tabela por modo com sd_cria(13, (ModoSondagem)modo), para
//    modo de 0 a 2, e libere depois.
// 2. Na dupla, o passo da 44 é 1 + 44 % 12 = 9 e o da 57 é 1 + 57 % 12 = 10.
// 3. Resposta esperada: a saída acima. Linear e quadrática repetem a mesma
//    sequência para chaves com o mesmo começo (agrupamento secundário).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "sondagem.h"

int main(void) {

    return 0;
}

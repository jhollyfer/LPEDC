// 0179 · Sondagem quadrática e dupla
// Exercício E1072 · ★★☆
//
// A sondagem quadrática h(k, i) = (k % m + i²) % m não visita todas as
// posições: com m primo, só (m + 1) / 2 delas são diferentes. Com uma
// tabela de m = 7 (sondagem.h, SD_QUADRATICA), mostre a sequência da chave
// 0 para i de 0 a 6 e as posições que ela nunca visita. Depois insira 0, 7,
// 14, 21 e 28 (todas começam no 0), mostrando a posição de cada uma (-1 é
// falha), a tabela e a carga. A 28 não entra, com três posições livres.
//
//   Saída esperada:
//   sequência da chave 0: 0 1 4 2 2 4 1
//   nunca visitadas: 3 5 6
//   insere  0: posição 0
//   insere  7: posição 1
//   insere 14: posição 4
//   insere 21: posição 2
//   insere 28: posição -1
//   tabela:   0   7  21   .  14   .   .
//   carga 0.57 e a chave 28 ficou de fora
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include "sondagem.h"

int main(void) {

    return 0;
}

// 0090 · Fila
// Exercício E539 · ★★★
//
// Batata quente: 7 pessoas numeradas de 1 a 7 estão em roda. A batata passa
// de mão em mão, e quem estiver com ela na 3ª passada sai. A contagem
// recomeça de quem estava ao lado, até sobrar uma pessoa. (É o famoso
// problema de Josephus.)
//
// Resolva com o fila.h: a roda é a fila. "Passar a batata" é tirar do
// início e pôr de novo no fim. Na 3ª pessoa, tire e não devolva. Mostre a
// ordem de saída e quem sobrou.
//
//   Saída esperada:
//   Saíram: 3 6 2 7 5 1
//   Sobrou: 4
//
// Dicas:
// 1. Insira 1 a 7. Enquanto fila_tamanho > 1: faça 2 vezes "retira e
//    insere de novo"; na 3ª, retire e mostre.
// 2. A capacidade do fila.c é 8, então 7 pessoas cabem.
// 3. Cada eliminação custa m operações de fila: no total, O(n · m).
// 4. Resposta esperada: Saíram: 3 6 2 7 5 1 e Sobrou: 4.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "fila.h"

int main(void) {

    return 0;
}

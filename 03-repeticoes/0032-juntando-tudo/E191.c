// 0032 · Juntando tudo
// Exercício E191 · ★★★
//
// O jogo dos 21 palitos: na mesa há 21 palitos. Você e o computador se
// revezam, cada um tirando 1, 2 ou 3. Quem tirar o ÚLTIMO palito perde. Você
// começa. Escreva o jogo:
//
// - sua jogada é lida com do-while e só vale de 1 a 3 e no máximo o que
//   sobrou na mesa;
// - o computador joga com a estratégia vencedora: tira
//   (palitos - 1) % 4; se isso der 0, tira 1;
// - a cada jogada, mostre quantos palitos sobraram; no fim, quem perdeu.
//
//   Você tira: 3
//   Sobram 18. O computador tira 1. Sobram 17.
//   Você tira: 3
//   Sobram 14. O computador tira 1. Sobram 13.
//   ...
//   Você tira: 1
//   Sobram 0. Você tirou o último palito. Perdeu!
//
// Dicas:
// 1. Um laço principal enquanto houver palitos. Dentro: sua vez; se zerou,
//    você perdeu (break); senão, a vez do computador; se zerou, ele perdeu.
// 2. A estratégia deixa sempre 1, 5, 9, 13, 17 na mesa para você. Faça o
//    teste de mesa: de 17, tire o que quiser, o computador volta para 13.
// 3. Resposta esperada: começando com 21 e você jogando primeiro, o
//    computador sempre vence. Com as jogadas 3, 3, 3, 3, 3 e 1, a mesa fica
//    18/17, 14/13, 10/9, 6/5, 2/1 e 0, e você perde.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

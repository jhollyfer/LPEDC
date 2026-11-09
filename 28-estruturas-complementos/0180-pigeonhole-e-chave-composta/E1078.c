// 0180 · Pigeonhole e chave composta
// Exercício E1078 · ★★☆
//
// A previsão do frio na serra: ordene as leituras da MAIS QUENTE para a
// MAIS FRIA com um pigeonhole sort estável escrito por você. As
// temperaturas vão de -5 a 8 graus (14 casas; a casa de t é t - (-5)). Cada
// casa é uma fila de índices, como no pombal.c, e as casas são esvaziadas
// da mais quente para a mais fria. Leituras: Urubici -3, Gramado 4,
// Curitiba 8, Sao Joaquim -5, Lages 4, Bom Jardim -3, Canela 4, Caxias 6.
//
//   Saída esperada:
//     8 Curitiba
//     6 Caxias
//     4 Gramado
//     4 Lages
//     4 Canela
//    -3 Urubici
//    -3 Bom Jardim
//    -5 Sao Joaquim
//
// Dicas:
// 1. Vetores primeiro[14] e ultimo[14] e um prox[n] (malloc): o aluno i
//    entra no fim da fila da sua casa.
// 2. Para a ordem decrescente, só o laço de esvaziar muda: de c = 13 até 0.
//    A estabilidade continua (Gramado, Lages, Canela na ordem de chegada).
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}

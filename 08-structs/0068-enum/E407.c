// 0068 · Enum
// Exercício E407 · ★★★
//
// A catraca do metrô é uma máquina de estados. Ela está TRAVADA ou LIBERADA,
// e recebe dois eventos: BILHETE e EMPURRAO. As regras:
//
//   TRAVADA  + BILHETE  -> LIBERADA
//   TRAVADA  + EMPURRAO -> TRAVADA   (alguém tentou passar sem pagar)
//   LIBERADA + EMPURRAO -> TRAVADA   (uma pessoa passou)
//   LIBERADA + BILHETE  -> LIBERADA  (bilhete desperdiçado)
//
// Use dois enums (Estado e Evento) e uma função
// Estado transicao(Estado e, Evento ev). Começando TRAVADA, processe a
// sequência BILHETE, EMPURRAO, EMPURRAO, BILHETE, BILHETE, EMPURRAO, EMPURRAO
// e conte quantos passaram, quantas tentativas foram barradas e quantos
// bilhetes foram desperdiçados.
//
//   Saída esperada:
//   travada + bilhete -> liberada
//   liberada + empurrão -> travada
//   travada + empurrão -> travada
//   travada + bilhete -> liberada
//   liberada + bilhete -> liberada
//   liberada + empurrão -> travada
//   travada + empurrão -> travada
//   Passaram: 2 | Barrados: 2 | Bilhetes desperdiçados: 1
//
// Dicas:
// 1. Guarde os eventos num vetor: Evento seq[] = {BILHETE, EMPURRAO, ...};
// 2. Conte olhando o par (estado atual, evento) antes de trocar de estado.
// 3. Um switch dentro de outro (estado por fora, evento por dentro) deixa as
//    4 regras bem visíveis.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

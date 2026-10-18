// 0009 · Atribuição, ++ e --
// Exercício E054 · ★★★
//
// O placar está invertido de novo: casa = 2 e visitante = 5, e o certo é o
// contrário. Desta vez, troque os valores SEM usar uma terceira variável,
// só com += e -= (e, se precisar, um = simples).
//
//   Saída esperada:
//   Casa 5 x 2 Visitante
//
// Dicas:
// 1. Guarde a soma dos dois numa das variáveis: casa += visitante (casa = 7).
// 2. Da soma, dá para recuperar cada um tirando o outro.
// 3. Cuidado na vida real: com valores perto de INT_MAX, a soma estoura o
//    int (comportamento indefinido). A versão com variável auxiliar é mais
//    segura e mais clara; este truque é só para treinar os compostos.
// 4. Resposta esperada: casa += visitante; visitante = casa - visitante;
//    casa -= visitante; e a saída "Casa 5 x 2 Visitante".
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int casa = 2;
    int visitante = 5;

    printf("Casa %d x %d Visitante\n", casa, visitante);
    return 0;
}

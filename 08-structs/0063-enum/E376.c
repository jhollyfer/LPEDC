// 0063 · Enum
// Exercício E376 · ★★☆
//
// Este programa compila sem nenhum aviso, mas uma das cartas sai como "???".
// Rode, ache o problema e conserte. O gcc avisa quando um switch de enum
// esquece um caso, mas desta vez ficou quieto: mude o código para que ele
// avise. Para testar, acrescente um quinto naipe CORINGA no fim do enum e
// rode: tem que aparecer o aviso. Depois tire o CORINGA e rode de novo.
//
//   Saída esperada (depois de consertado):
//   7 de ouros
//   7 de espadas
//   7 de copas
//   7 de paus
//
// Dicas:
// 1. Conte os case e conte os nomes do enum.
// 2. O aviso -Wswitch só aparece quando o switch não tem default.
// 3. Resposta esperada: faltava o case COPAS; o default escondia o esquecimento
//    (com default, o gcc entende que você tratou "o resto"). Acrescente o
//    case COPAS, tire o default e devolva "???" depois do switch.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

typedef enum { OUROS, ESPADAS, COPAS, PAUS } Naipe;

const char *nome_naipe(Naipe n) {
    switch (n) {
    case OUROS:
        return "ouros";
    case ESPADAS:
        return "espadas";
    case PAUS:
        return "paus";
    default:
        return "???";
    }
}

int main(void) {
    for (Naipe n = OUROS; n <= PAUS; n++) {
        printf("7 de %s\n", nome_naipe(n));
    }
    return 0;
}

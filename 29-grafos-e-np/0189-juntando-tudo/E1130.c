// 0189 · Juntando tudo
// Exercício E1130 · ★☆☆
//
// O entregador da farmácia do texto usa a regra "vou sempre para o cliente
// mais perto que ainda não visitei" (o VIZINHO MAIS PRÓXIMO, um guloso).
// Escreva o programa com os mesmos oito pontos e distâncias do texto,
// mostre a rota e o custo da volta completa.
//
//   Saída esperada:
//   Farmácia Ana Bruno Clara Edna Gil Dênis Fábio Farmácia
//   Vizinho mais próximo: 40 quarteirões
//
// Dicas:
// 1. Um vetor visitado[] e um laço de N - 1 passos; em cada passo, procure
//    o v não visitado com menor d[atual][v] (empate: menor índice).
// 2. Não esqueça a volta: some d[atual][0] no fim.
// 3. Resposta esperada: a saída acima. Pior que a árvore (36) e que o
//    ótimo (28): perto do fim, os clientes que sobraram estão longe uns dos
//    outros (Dênis -> Fábio custa 11). O vizinho mais próximo não tem
//    fator de aproximação constante, nem com distâncias métricas.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}

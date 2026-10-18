// 0113 · Juntando tudo: a central de entregas
// Exercício E676 · ★★☆
//
// No futebol da firma, algumas duplas não podem jogar no mesmo time (são
// rivais). Você precisa dividir as seis pessoas em DOIS times sem nenhuma
// dupla de rivais junta. Pessoas: Ana 0, Bruno 1, Carla 2, Diego 3, Elisa 4,
// Fábio 5. Rivalidades (não dirigido):
//
//   Ana-Bruno, Ana-Diego, Carla-Bruno, Carla-Fábio, Elisa-Diego
//
// Use BFS para "pintar" cada pessoa com o time 0 ou 1: a origem fica no
// time 0 e cada rival descoberto vai para o time contrário de quem o
// descobriu. Se um rival já pintado estiver no MESMO time, a divisão é
// impossível. Depois, acrescente a rivalidade Ana-Carla e tente de novo.
//
//   Saída esperada:
//   Time 1: Ana Carla Elisa
//   Time 2: Bruno Diego Fábio
//   Impossível: Bruno e Carla ficariam no mesmo time
//
// Dicas:
// 1. Vetor time[] com -1 (sem time), 0 ou 1. O time do rival é 1 - time[u].
// 2. Faça o laço externo das componentes (assunto 0110, E658): pode haver
//    gente sem rival nenhum ou grupos soltos.
// 3. Um grafo que dá para dividir assim se chama BIPARTIDO. Ele deixa de
//    ser bipartido quando aparece um ciclo de tamanho ímpar: Ana, Bruno,
//    Carla, Ana.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}

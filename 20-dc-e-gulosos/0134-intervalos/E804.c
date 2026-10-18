// 0134 · Seleção de intervalos
// Exercício E804 · ★★★
//
// O clube tem DUAS quadras iguais e recebeu 10 pedidos de jogos, [ini, fim):
//
//   Leões 8-10, Tubarões 8-11, Águias 9-12, Lobos 10-12, Falcões 11-13,
//   Panteras 12-14, Touros 10-15, Corujas 13-16, Raposas 14-16, Ursos 15-17
//
// Aceite o maior número de jogos. O guloso do texto se estende assim:
// ordene pela hora de fim (em caso de empate, quem começa antes vem antes);
// para cada jogo, entre as quadras já livres na hora em que ele começa,
// escolha a que ficou livre MAIS TARDE; se nenhuma está livre, recuse.
//
//   Saída esperada:
//    8h-10h quadra 1  Leões
//    8h-11h quadra 2  Tubarões
//    9h-12h recusado  Águias
//   10h-12h quadra 1  Lobos
//   11h-13h quadra 2  Falcões
//   12h-14h quadra 1  Panteras
//   10h-15h recusado  Touros
//   13h-16h quadra 2  Corujas
//   14h-16h quadra 1  Raposas
//   15h-17h recusado  Ursos
//   Jogos aceitos: 7 de 10
//
// Dicas:
// 1. Guarde int livre_em[2] = {0, 0}. Para cada jogo, procure o índice q
//    com livre_em[q] <= ini e livre_em[q] o maior possível (q = -1 se não
//    houver).
// 2. Por que a que ficou livre mais tarde? Porque a outra, livre há mais
//    tempo, pode receber um jogo que começa cedo e que esta não receberia.
//    Usar a quadra "mais folgada" desperdiça folga.
// 3. Resposta esperada: a saída acima. (Com printf("%2dh-%2dh ...") os
//    horários ficam alinhados.)
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *time;
    int ini, fim; // [ini, fim), em horas
} Jogo;

int main(void) {
    Jogo j[] = {
        {"Leões", 8, 10},   {"Tubarões", 8, 11}, {"Águias", 9, 12},
        {"Lobos", 10, 12},  {"Falcões", 11, 13}, {"Panteras", 12, 14},
        {"Touros", 10, 15}, {"Corujas", 13, 16}, {"Raposas", 14, 16},
        {"Ursos", 15, 17},
    };
    int n = 10;
    (void)j;
    (void)n;

    return 0;
}

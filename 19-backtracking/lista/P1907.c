// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1907 · ★☆☆ · A playlist de 30 minutos
//
// O motorista do ônibus de turismo quer uma playlist que dure exatamente 30
// minutos até a próxima parada. As músicas duram 7, 12, 5, 9, 11 e 4
// minutos. Escreva a função acha(i, soma), que devolve 1 assim que achar UM
// subconjunto que soma 30 (e 0 se não houver), marcando em leva[] as
// músicas escolhidas. Corte o ramo quando a soma passar de 30. O main já
// mostra o resultado.
//
//   Saída esperada:
//   Playlist: 7 12 11 = 30 minutos
//
// Dicas:
// 1. Caso base: soma == ALVO devolve 1; soma > ALVO ou i == N devolve 0.
// 2. Tente primeiro levar a música i: leva[i] = 1; if (acha(i + 1, soma +
//    dur[i])) return 1; leva[i] = 0; depois tente sem ela.
// 3. Resposta esperada: 7 + 12 + 11 = 30. É a primeira que a ordem "leva
//    antes de não levar" encontra.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

#define N 6
#define ALVO 30

const int dur[N] = {7, 12, 5, 9, 11, 4};
int leva[N];

int acha(int i, int soma) {
    (void)i;
    (void)soma;
    // COMPLETE AQUI
    return 0;
}

int main(void) {
    if (acha(0, 0)) {
        printf("Playlist:");
        int total = 0;
        for (int i = 0; i < N; i++) {
            if (leva[i]) {
                printf(" %d", dur[i]);
                total += dur[i];
            }
        }
        printf(" = %d minutos\n", total);
    } else {
        printf("Não dá para fechar %d minutos\n", ALVO);
    }
    return 0;
}

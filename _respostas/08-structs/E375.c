// 0063 · Enum
// Exercício E375 · ★★☆

#include <stdio.h>

typedef enum { PEDRA, PAPEL, TESOURA } Jogada;
typedef enum { EMPATE, VITORIA, DERROTA } Resultado;

typedef struct {
    Jogada voce;
    Jogada outro;
} Partida;

Resultado jogar(Jogada voce, Jogada outro) {
    return (Resultado)((voce - outro + 3) % 3);
}

int main(void) {
    const char *jogadas[] = {"pedra", "papel", "tesoura"};
    const char *resultados[] = {"empate", "vitória", "derrota"};
    Partida partidas[] = {
        {PEDRA, TESOURA},
        {PAPEL, TESOURA},
        {TESOURA, TESOURA},
        {PAPEL, PEDRA},
        {PEDRA, PAPEL},
    };
    int n = sizeof partidas / sizeof partidas[0];
    int placar[3] = {0};

    for (int i = 0; i < n; i++) {
        Resultado r = jogar(partidas[i].voce, partidas[i].outro);
        placar[r]++;
        printf("%s x %s: %s\n", jogadas[partidas[i].voce], jogadas[partidas[i].outro], resultados[r]);
    }
    printf("Placar: %d vitórias, %d empate, %d derrotas\n", placar[VITORIA], placar[EMPATE], placar[DERROTA]);
    return 0;
}

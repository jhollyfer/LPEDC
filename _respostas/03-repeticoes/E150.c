// 0025 · Padrões de laço
// Exercício E150 · ★★★

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int atual, anterior = 0;
    bool crescente = true;
    int sequencia = 0, recorde = 0;

    for (int i = 1; i <= 6; i++) {
        printf("Treino %d: ", i);
        if (scanf("%d", &atual) != 1) {
            return 1;
        }
        if (i > 1 && atual > anterior) {
            sequencia++;
        } else {
            if (i > 1) {
                crescente = false; // desceu ou empatou: a flag cai de vez
            }
            sequencia = 1;         // a sequência recomeça neste treino
        }
        if (sequencia > recorde) {
            recorde = sequencia;
        }
        anterior = atual;
    }
    printf("Em ordem crescente? %s\n", crescente ? "sim" : "não");
    printf("Maior sequência em alta: %d treinos\n", recorde);
    return 0;
}

// 0048 · Juntando tudo
// Exercício E284 · ★☆☆

#include <stdio.h>

#define JOGADORES 4
#define TAM 12

void mostrar_tabela(char nomes[][TAM], const int gols[], int n) {
    int total = 0;
    printf("%-10s%6s\n", "Nome", "Gols");
    for (int i = 0; i < n; i++) {
        printf("%-10s%6d\n", nomes[i], gols[i]);
        total += gols[i];
    }
    printf("%-10s%6d\n", "Total:", total);
}

int indice_artilheiro(const int gols[], int n) {
    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (gols[i] > gols[pos]) {
            pos = i;
        }
    }
    return pos;
}

int main(void) {
    char nomes[JOGADORES][TAM] = {"Tiago", "Duda", "Kauã", "Lia"};
    int gols[JOGADORES] = {7, 12, 5, 9};

    mostrar_tabela(nomes, gols, JOGADORES);
    printf("Artilheiro: %s\n", nomes[indice_artilheiro(gols, JOGADORES)]);
    return 0;
}

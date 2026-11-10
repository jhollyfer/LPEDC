// 0043 · Juntando tudo
// Exercício E254 · ★☆☆
//
// Complete as funções para mostrar a tabela de artilheiros do campeonato do
// bairro, com o nome alinhado à esquerda em 10 colunas e o total no fim. O
// main já está pronto.
//
//   Saída esperada:
//   Nome        Gols
//   Tiago          7
//   Duda          12
//   Kauã          5
//   Lia            9
//   Total:        33
//   Artilheiro: Duda
//
// Escreva sua resposta abaixo (complete as funções):

#include <stdio.h>

#define JOGADORES 4
#define TAM 12

void mostrar_tabela(char nomes[][TAM], const int gols[], int n) {
    (void) nomes, (void) gols, (void) n; // apague esta linha quando escrever

}

int indice_artilheiro(const int gols[], int n) {
    (void) gols, (void) n; // apague esta linha quando escrever
    return 0;
}

int main(void) {
    char nomes[JOGADORES][TAM] = {"Tiago", "Duda", "Kauã", "Lia"};
    int gols[JOGADORES] = {7, 12, 5, 9};

    mostrar_tabela(nomes, gols, JOGADORES);
    printf("Artilheiro: %s\n", nomes[indice_artilheiro(gols, JOGADORES)]);
    return 0;
}

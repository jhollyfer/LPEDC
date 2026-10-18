// 0048 · Juntando tudo
// Exercício E284 · ★☆☆
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
// Dicas:
// 1. printf("%-10s%6d\n", nomes[i], gols[i]) alinha o nome à esquerda em 10
//    colunas e o número à direita em 6.
// 2. indice_artilheiro é o padrão "posição do maior" do assunto 0043.
// 3. Repare que "Kauã" tem um acento: em UTF-8 são 5 bytes, e o printf conta
//    bytes. Por isso o número dele aparece uma coluna à esquerda dos
//    outros. Tudo bem aqui; só saiba por quê.
// 4. Resposta esperada: a saída acima.
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

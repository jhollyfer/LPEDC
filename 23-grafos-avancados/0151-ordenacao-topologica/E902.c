// 0151 · Ordenação topológica
// Exercício E902 · ★☆☆
//
// Três técnicos mandaram a ordem em que montariam um computador. Complete a
// função valida(ordem): ela confere se toda regra "a antes de b" é
// respeitada. Se for, mostra "válida"; se não, mostra a primeira regra
// quebrada (procurando a de 0 a 7 e b de 0 a 7, nessa ordem) e devolve false.
// As regras, já montadas no main, são:
//
//   processador -> cooler          processador -> placa no gabinete
//   cooler -> placa no gabinete    memória -> placa no gabinete
//   placa no gabinete -> cabos     placa no gabinete -> placa de vídeo
//   fonte -> cabos                 placa de vídeo -> cabos
//   cabos -> ligar
//
//   Saída esperada:
//   João: válida
//   Lia: válida
//   Rui: inválida (placa no gabinete veio antes de cooler)
//
// Dicas:
// 1. Monte um vetor pos[V] com a posição de cada etapa na ordem:
//    pos[ordem[i]] = i.
// 2. A regra a -> b está quebrada quando antes[a][b] e pos[a] > pos[b].
//    Aí b apareceu antes de a.
// 3. Resposta esperada: a saída acima. João e Lia mandaram ordens
//    diferentes, e as duas valem: a ordenação topológica não é única.
//
// Escreva sua resposta abaixo (complete valida):

#include <stdbool.h>
#include <stdio.h>

#define V 8

const char *etapas[V] = {"processador", "cooler", "memória", "placa no gabinete",
                         "fonte", "placa de vídeo", "cabos", "ligar"};
int antes[V][V];

bool valida(const int ordem[]) {
    (void)ordem; // apague esta linha

    return true;
}

int main(void) {
    int regras[][2] = {{0, 1}, {0, 3}, {1, 3}, {2, 3}, {3, 5}, {4, 6}, {5, 6}, {3, 6}, {6, 7}};
    for (int k = 0; k < 9; k++) antes[regras[k][0]][regras[k][1]] = 1;

    int joao[V] = {0, 1, 2, 3, 4, 5, 6, 7};
    int lia[V] = {4, 2, 0, 1, 3, 5, 6, 7};
    int rui[V] = {0, 2, 3, 1, 4, 5, 6, 7};
    printf("João: ");
    valida(joao);
    printf("Lia: ");
    valida(lia);
    printf("Rui: ");
    valida(rui);
    return 0;
}

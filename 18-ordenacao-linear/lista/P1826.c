// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1826 · ★★★ · Os números mais sorteados: frequência, depois valor
//
// Uma lotérica anotou as 40 dezenas (de 1 a 60) que saíram nos últimos
// sorteios. Ela quer a lista reordenada pela FREQUÊNCIA, da dezena que mais
// saiu para a que menos saiu, com as repetições juntas, e, no empate de
// frequência, a dezena MENOR primeiro. Exemplo: se 7 saiu 3 vezes e 2 saiu
// 3 vezes, a lista começa 2 2 2 7 7 7.
//
// Tudo em tempo linear, sem comparar elementos:
//
// 1. conte a frequência de cada dezena (counting, k = 61);
// 2. monte a lista das dezenas que apareceram em ordem crescente (é só
// percorrer o vetor de contagem);
// 3. ordene essa lista com um counting sort ESTÁVEL pela chave
// (maior_freq - freq), que põe as mais frequentes primeiro e preserva a
// ordem crescente nos empates;
// 4. escreva cada dezena freq vezes.
//
// Mostre as dezenas distintas com a frequência, na ordem final, e a lista
// completa (10 por linha).
//
//   Saída esperada:
//   Dezenas (frequência):
//     6(3) 24(3) 36(3) 1(2) 25(2) 29(2) 50(2) 2(1) 3(1) 4(1)
//     5(1) 8(1) 9(1) 17(1) 18(1) 23(1) 26(1) 28(1) 37(1) 38(1)
//     44(1) 45(1) 47(1) 48(1) 49(1) 51(1) 52(1) 55(1) 56(1) 60(1)
//   Lista:
//      6  6  6 24 24 24 36 36 36  1
//      1 25 25 29 29 50 50  2  3  4
//      5  8  9 17 18 23 26 28 37 38
//     44 45 47 48 49 51 52 55 56 60
//   Total: 40 números
//
// Dicas:
// 1. Os dados do esqueleto vêm de um gerador fixo: a saída é sempre a mesma.
// 2. A chave do passo 3 vai de 0 (as mais frequentes) a maior_freq - 1: o
//    vetor C tem maior_freq posições.
// 3. Por que o passo 2 dispensa ordenação? O vetor de contagem já está
//    indexado pela dezena: percorrê-lo de 1 a 60 dá as dezenas em ordem.
// 4. Resposta esperada: 6, 24 e 36 saíram 3 vezes e abrem a lista (6 6 6 24
//    24 24 36 36 36); depois vêm 1, 25, 29 e 50, com 2; a lista tem 40
//    números.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 40
#define K 61 // dezenas de 1 a 60

unsigned semente = 1996;

int sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente >> 16) % 60) + 1;
}

int main(void) {
    int dez[N];
    for (int i = 0; i < N; i++) dez[i] = sorteia();

    for (int i = 0; i < N; i++) printf("%d ", dez[i]);
    printf("\n");
    return 0;
}

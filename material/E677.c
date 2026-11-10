// 0113 · Juntando tudo: a central de entregas
// Exercício E677 · ★★★
//
// Escada de palavras: transformar uma palavra em outra trocando UMA letra por
// vez, e cada passo tem de ser uma palavra da lista (GATO, GATA, MATA...). Ache
// a escada mais curta. A lista já está no esqueleto. Ninguém monta a matriz:
// duas palavras são vizinhas quando têm o mesmo tamanho e diferem em
// exatamente uma posição. Rode uma BFS e reconstrua a escada com pai[]. Teste
// GATO -> BOLA, CASA -> ROSA, MOTO -> CAMA e GATO -> PEIXE.
//
//   Saída esperada:
//   GATO -> BOLA em 5 passo(s): GATO GATA MATA MALA MOLA BOLA
//   CASA -> ROSA em 10 passo(s): CASA CAMA LAMA LATA MATA MALA MOLA BOLA BOTA ROTA ROSA
//   MOTO -> CAMA em 5 passo(s): MOTO MATO MATA LATA LAMA CAMA
//   GATO -> PEIXE: impossível
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define N 20

const char *palavras[N] = {"GATO", "GATA", "RATO", "MATO", "MOTO", "BOTA", "ROTA", "ROSA", "BOLA", "COLA",
                           "PEIXE", "MOLA", "MALA", "SALA", "SOLA", "LATA", "LAMA", "CAMA", "CASA", "MATA"};

int main(void) {

    return 0;
}

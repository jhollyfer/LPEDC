// 0113 · Juntando tudo: a central de entregas
// Exercício E677 · ★★★
//
// Escada de palavras: transformar uma palavra em outra trocando UMA letra
// por vez, e cada passo tem de ser uma palavra da lista. Ex.: GATO, GATA,
// MATA... Ache a escada mais curta. A lista já está no esqueleto.
//
// Ninguém monta a matriz: duas palavras são vizinhas quando têm o mesmo
// tamanho e diferem em exatamente uma posição. A aresta sai de uma conta,
// como as casas do galpão do A220. Rode uma BFS e reconstrua a escada com
// pai[]. Teste com GATO -> BOLA, CASA -> ROSA, MOTO -> CAMA e GATO -> PEIXE.
//
//   Saída esperada:
//   GATO -> BOLA em 5 passo(s): GATO GATA MATA MALA MOLA BOLA
//   CASA -> ROSA em 10 passo(s): CASA CAMA LAMA LATA MATA MALA MOLA BOLA BOTA ROTA ROSA
//   MOTO -> CAMA em 5 passo(s): MOTO MATO MATA LATA LAMA CAMA
//   GATO -> PEIXE: impossível
//
// Dicas:
// 1. bool vizinhas(const char *a, const char *b): strlen igual e um só
//    a[i] != b[i]. int indice(const char *p) acha a posição com strcmp.
// 2. A BFS é a do A219, trocando "adj[u][v]" por "vizinhas(palavras[u],
//    palavras[v])".
// 3. Empates: GATO -> MATO -> MATA também leva a BOLA em 5 passos; a BFS
//    fica com GATA porque ela vem antes na lista.
// 4. Resposta esperada: a saída acima.
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

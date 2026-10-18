// 0142 · Distância de edição
// Exercício E847 · ★☆☆
//
// Escreva a função
//
//   int distancia(const char *a, const char *b)
//
// que devolve a distância de Levenshtein entre duas palavras (inserir,
// remover e trocar custam 1), e teste com os pares abaixo, mostrando cada
// um entre aspas.
//
//   Saída esperada:
//   "LIVRO" -> "LIBRA": 2
//   "" -> "SOL": 3
//   "CASA" -> "CASA": 0
//   "ABACAXI" -> "ABACATE": 2
//   "FUTEBOL" -> "BASQUETE": 8
//
// Dicas:
// 1. Tabela int d[31][31]. Borda: d[i][0] = i e d[0][j] = j.
// 2. Letras iguais: d[i][j] = d[i - 1][j - 1]. Diferentes: 1 + o menor
//    entre diagonal, cima e esquerda. Uma função menor3 ajuda.
// 3. A distância nunca passa do tamanho da maior palavra (troque tudo e
//    insira o que faltar): FUTEBOL x BASQUETE bate nesse teto.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}

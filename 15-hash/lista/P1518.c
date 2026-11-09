// Lista · Módulo 15 · Tabelas hash
// Exercício P1518 · ★★☆ · O produto mais vendido do dia
//
// O caixa do mercadinho registrou estes códigos de produto, um por item
// vendido:
//
//   78912 55301 78912 10450 55301 78912 33017 10450
//   55301 55301 90008 78912 55301 33017
//
// Conte as vendas de cada código com uma tabela hash: endereçamento aberto,
// m = 23, sondagem linear, dois vetores globais int codigo[23] (VAZIO = -1)
// e int vendas[23]. Depois, percorra a TABELA (na ordem das posições),
// mostrando cada código e as vendas, e diga quantos produtos distintos houve
// e qual foi o mais vendido.
//
//   Saída esperada:
//   10450: vendas 2
//   55301: vendas 5
//   90008: vendas 1
//   33017: vendas 2
//   78912: vendas 4
//   5 produtos distintos; mais vendido: 55301 (5 vendas)
//
// Dicas:
// 1. registra(k): sonde enquanto a posição está ocupada por OUTRO código;
//    ao parar, grave o código (se era vazio) e some 1 nas vendas.
// 2. A ordem da listagem é a das posições na tabela (k % 23 com as
//    colisões), não a ordem de chegada: hash não guarda ordem.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define M 23
#define VAZIO -1

int codigo[M], vendas[M];

int main(void) {

    return 0;
}

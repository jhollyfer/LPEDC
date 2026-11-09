// Lista · Módulo 15 · Tabelas hash
// Exercício P1515 · ★★☆ · Três sondagens, as mesmas chaves
//
// Compare as três sondagens numa tabela de m = 13 posições, com as mesmas
// chaves 13, 26, 39, 52, 1, 14 (as quatro primeiras com h = 0, as duas
// últimas com h = 1). As funções recebem a chave k e a tentativa i:
//
//   linear:      (k % 13 + i) % 13
//   quadrática:  (k % 13 + i * i) % 13
//   dupla:       (k % 13 + i * (1 + k % 11)) % 13
//
// Escreva testa(nome, sonda, chaves, n), que recebe a sondagem como ponteiro
// para função, monta a tabela do zero, conta o TOTAL de posições olhadas e
// mostra a tabela final com printf("%-10s sondagens %2d:", ...).
//
//   Saída esperada:
//   linear     sondagens 19: 13 26 39 52 1 14 _ _ _ _ _ _ _
//   quadrática sondagens 15: 13 26 1 _ 39 14 _ _ _ 52 _ _ _
//   dupla      sondagens 13: 13 1 _ _ 14 26 _ 39 _ 52 _ _ _
//
// Dicas:
// 1. A assinatura do parâmetro é int (*sonda)(int k, int i).
// 2. Na linear, o 1 e o 14 pagam pelo bloco que o 13, o 26, o 39 e o 52
//    formaram (agrupamento primário). Na quadrática, quem tem o mesmo h
//    ainda segue a mesma trilha (agrupamento secundário). Na dupla, cada
//    chave tem um passo próprio.
// 3. Com 6 chaves o ganho é pequeno; com a tabela mais cheia, a diferença
//    explode (veja o P1528).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define M 13
#define VAZIO -1

int main(void) {

    return 0;
}

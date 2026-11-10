// 0116 · Análise amortizada
// Exercício E693 · ★★☆
//
// Muitas bibliotecas crescem o vetor por 1,5, e não por 2, para sobrar menos
// memória. Continua O(1) amortizado? Escreva o vetor dinâmico de int (struct
// Vetor com dados, n, cap, "long copias" e "int mudancas", capacidade inicial
// 1) com insere(v, valor, num, den): a nova capacidade é cap * num / den. Escreva
// testa(nome, num, den, n), que insere n números e mostra mudanças, cópias,
// cópias por inserção e a sobra (cap - n). Rode com n = 1000000 para 3/2 e 2/1.
// Atenção: com cap = 1, a conta 1 * 3 / 2 dá 1; a nova capacidade tem de ser
// sempre maior que a antiga.
//
//   Saída esperada:
//   fator  mudanças    cópias  cópias/n     sobra
//   x 1,5        34    2099753     2.10     49869
//   x 2          20    1048575     1.05     48576
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}

// 0053 · Ponteiros e strings
// Exercício E318 · ★★★
//
// Escreva sua versão do strstr:
//
//   const char *acha(const char *texto, const char *trecho)
//
// que devolve o endereço da primeira ocorrência de trecho dentro de texto,
// ou NULL se não houver. No main, mostre a posição (com subtração de
// ponteiros) e o resto do texto a partir dali.
//
//   texto: "o pix caiu na conta"
//
//   Saída esperada:
//   "caiu" na posição 6: caiu na conta
//   "boleto" não aparece
//   "" na posição 0: o pix caiu na conta
//
// Dicas:
// 1. Para cada posição t do texto, compare t[k] com trecho[k] enquanto o
//    trecho não acabar e os dois forem iguais.
// 2. Se chegou ao '\0' do trecho, achou: devolva t. Trecho vazio aparece
//    na posição 0.
// 3. Resposta esperada: posição 6 ("caiu na conta"); "boleto" não aparece;
//    o trecho vazio dá posição 0.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

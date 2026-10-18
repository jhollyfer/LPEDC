// 0094 · Busca sequencial
// Exercício E561 · ★★☆
//
// A tabela de preços de uma loja está em ordem crescente:
// 12, 19, 25, 31, 38, 44, 52, 60, 73, 89. Escreva duas funções que devolvem o
// índice (ou -1) e contam quantos elementos olharam:
//
//   busca: a busca sequencial comum;
//   busca_ordenada: aproveita a ordem e desiste assim que encontra um preço
//   MAIOR que o procurado.
//
// Teste as duas com R$ 47 (não existe) e R$ 60.
//
//   Saída esperada:
//   R$ 47: comum -1 (10 olhados), ordenada -1 (7 olhados)
//   R$ 60: comum 7 (8 olhados), ordenada 7 (8 olhados)
//
// Dicas:
// 1. Num vetor crescente, se v[i] > x, todos depois de i também são maiores.
// 2. Na busca_ordenada, cada volta faz dois testes: v[i] == x e v[i] > x.
//    Conte só um "olhado" por volta.
// 3. A melhora só aparece quando a chave NÃO está no vetor. Continua O(n).
// 4. Resposta esperada: a saída acima (47 para no 52, que é o 7º elemento).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

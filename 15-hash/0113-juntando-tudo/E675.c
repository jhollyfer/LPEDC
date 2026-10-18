// 0113 · Juntando tudo: o contador de palavras
// Exercício E675 · ★★☆
//
// Às vezes você não quer contar tudo, só saber se algo já apareceu. Use uma
// tabela hash como CONJUNTO (só chaves, sem contagem) para achar a primeira
// palavra que aparece pela segunda vez na frase
//
//   Quem parte e reparte fica com a maior parte
//
// e em que posição ela se repete. Ignore maiúsculas. Use 13 baldes,
// encadeamento e o hash polinomial.
//
//   Saída esperada:
//   primeira repetida: parte (palavra 9)
//
// Dicas:
// 1. Escreva "bool viu_antes(No *baldes[], const char *w)": procura a
//    palavra no seu balde; se achar, devolve true; senão guarda uma cópia e
//    devolve false.
// 2. "reparte" não é "parte": a tabela compara a palavra inteira com
//    strcmp. Não esqueça de liberar os nós antes de sair.
// 3. Resposta esperada: a saída acima. Custo: O(n) em média, contra O(n²)
//    de comparar cada palavra com todas as anteriores.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(void) {

    return 0;
}

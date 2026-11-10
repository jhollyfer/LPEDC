// 0151 · Ordenação topológica
// Exercício E903 · ★★☆
//
// A equipe de suporte tem sete chamados, #101 a #107 (índices 0 a 6), e alguns
// só podem ser resolvidos depois de outros:
//
//   #105 -> #101   #105 -> #102   #106 -> #102   #102 -> #103
//   #107 -> #104   #101 -> #104
//
// O Kahn com fila atende na ordem em que os chamados ficam livres. A chefe quer
// outra regra: entre os livres, sempre o de MENOR número. Escreva kahn_fila()
// (o Kahn com fila) e kahn_menor() (a cada passo, procura o menor índice ainda
// não feito com grau de entrada 0). Mostre as duas ordens.
//
//   Saída esperada:
//   Fila:   #105 #106 #107 #101 #102 #104 #103
//   Menor:  #105 #101 #106 #102 #103 #107 #104
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}

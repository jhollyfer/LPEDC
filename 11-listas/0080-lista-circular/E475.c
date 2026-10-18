// 0080 · Lista circular
// Exercício E475 · ★☆☆
//
// Numa roda de chimarrão com 5 pessoas (numeradas de 1 a 5), a cuia começa
// com a pessoa 1 e passa para a seguinte 12 vezes. Com quem ela fica? Monte
// a roda com lista_insere_fim e descubra ANDANDO na lista circular. Depois
// confira com uma conta usando %.
//
//   Saída esperada:
//   1 -> 2 -> 3 -> 4 -> 5 -> (volta ao 1)
//   depois de 12 passadas, a cuia está com a pessoa 3
//   conferindo com %: pessoa 3
//
// Dicas:
// 1. A pessoa 1 é roda->prox (a roda guarda o último).
// 2. Cada passada é p = p->prox. Numa lista circular o laço nunca encontra
//    NULL: não precisa testar nada.
// 3. A conta: a pessoa 1 está na posição 0; depois de k passadas, a posição
//    é k % 5, e a pessoa é a posição + 1.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "lista.h"

int main(void) {

    return 0;
}

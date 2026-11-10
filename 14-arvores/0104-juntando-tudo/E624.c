// 0104 · Juntando tudo
// Exercício E624 · ★★★
//
// Lista de espera do posto de saúde. Cada linha da entrada traz um nome e
// uma prioridade (maior = mais urgente). Um nome que já está na lista é
// recusado. No fim da entrada, o programa chama todos, do mais urgente ao
// menos urgente. Escreva do zero, usando:
// - uma BST de nomes (compare com strcmp) para saber se o nome já entrou;
// - um heap de máximo de structs {prioridade, nome} para a ordem de chamada.
//
// Teste com:
//   printf 'Ana 3\nBeto 5\nCaio 1\nAna 4\nDani 4\nEdu 2\n' | ~/LPEDC/rodar 14-arvores/0104-juntando-tudo/E624.c
//
//   Saída esperada:
//   Ana já está na lista
//   Chamando: Beto (5)
//   Chamando: Dani (4)
//   Chamando: Ana (3)
//   Chamando: Edu (2)
//   Chamando: Caio (1)
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}

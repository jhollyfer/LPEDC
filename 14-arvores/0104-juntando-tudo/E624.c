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
// Dicas:
// 1. Leia com while (scanf("%19s %d", nome, &prio) == 2). Os nós da BST e
//    os elementos do heap guardam uma CÓPIA do nome (char nome[20] e
//    strcpy), porque o buffer de leitura é reaproveitado a cada linha.
// 2. Um heap de até 32 pacientes num vetor fixo basta. Para cada linha: se o
//    nome está na BST, avise; senão, insira na BST e no heap.
// 3. Resposta esperada: a saída acima. O segundo "Ana" (prioridade 4) é
//    recusado e a Ana fica com a prioridade 3. Libere a BST no fim.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}

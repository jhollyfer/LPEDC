// 0032 · Recursão
// Exercício E189 · ★★☆
//
// Resposta: ida 3 / ida 2 / ida 1 / fundo / volta 1 / volta 2 / volta 3.
// Os "ida" saem enquanto a pilha cresce; os "volta" saem enquanto ela
// diminui, do topo para a base, cada quadro com o seu n.

#include <stdio.h>

void eco(int n) {
    if (n == 0) {
        printf("fundo\n");
        return;
    }
    printf("ida %d\n", n);
    eco(n - 1);
    printf("volta %d\n", n);
}

int main(void) {
    eco(3);
    return 0;
}

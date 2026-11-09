// Lista · Módulo 04 · Funções e modularização
// Exercício P0421 · ★★★ · Hanói com 4 discos e a conta de cada disco

#include <stdio.h>

int movimentos = 0;
int conta1 = 0, conta2 = 0, conta3 = 0, conta4 = 0;

void mover(int disco, char de, char para) {
    movimentos++;
    printf("%2d: disco %d de %c para %c\n", movimentos, disco, de, para);
    switch (disco) {
        case 1: conta1++; break;
        case 2: conta2++; break;
        case 3: conta3++; break;
        default: conta4++; break;
    }
}

void hanoi(int n, char origem, char destino, char apoio) {
    if (n == 0) {
        return;
    }
    hanoi(n - 1, origem, apoio, destino);  // tira os de cima do caminho
    mover(n, origem, destino);              // move o maior
    hanoi(n - 1, apoio, destino, origem);  // põe os de cima de volta sobre ele
}

int main(void) {
    hanoi(4, 'A', 'C', 'B');
    printf("Total: %d movimentos\n", movimentos);
    printf("Disco 1: %d, disco 2: %d, disco 3: %d, disco 4: %d\n", conta1, conta2, conta3, conta4);
    return 0;
}

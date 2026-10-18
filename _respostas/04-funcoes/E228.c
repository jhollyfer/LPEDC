// 0038 · Recursão na prática: Fibonacci, Hanói e Euclides
// Exercício E228 · ★★★
//
// Resposta: a primeira chamada recursiva repetia a ordem das estacas
// (origem, destino, auxiliar) e mandava os n - 1 discos para o destino, onde o
// maior vai cair. Já no movimento 2 o disco 2 caía sobre o disco 1 (ilegal), e
// no 3 o programa tirava um disco de B, que estava vazia. Os n - 1 discos têm
// que ir para a AUXILIAR: hanoi(n - 1, origem, auxiliar, destino).

#include <stdio.h>

int movimentos = 0;

void hanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 0) {
        return;
    }
    hanoi(n - 1, origem, auxiliar, destino);
    movimentos++;
    printf("%d. disco %d: %c -> %c\n", movimentos, n, origem, destino);
    hanoi(n - 1, auxiliar, destino, origem);
}

int main(void) {
    hanoi(3, 'A', 'C', 'B');
    printf("Total: %d movimentos\n", movimentos);
    return 0;
}

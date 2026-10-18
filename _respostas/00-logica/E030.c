// 0005 · Do .c ao executável
// Exercício E030 · ★★★
//
// Resposta: a) a linha do printf dentro do for, quando i vale 3; b) o C não confere limites de vetor: o erro só existe quando o programa roda; c) de execução. A correção é "i < 3" no lugar de "i <= 3".

#include <stdio.h>

int main(void) {
    int notas[3] = {7, 9, 6};
    for (int i = 0; i < 3; i++) {
        printf("Nota %d: %d\n", i + 1, notas[i]);
    }
    return 0;
}

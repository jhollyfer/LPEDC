// 0005 · Do .c ao executável
// Exercício E030 · ★★★
//
// Este programa compila sem nenhum aviso. Mesmo assim, está errado. Rode com
// o rodar e leia o relatório do AddressSanitizer. Responda:
//
// a) Em que linha está o erro?
// b) Por que o compilador não reclamou?
// c) Que tipo de erro é: de compilação, de ligação ou de execução?
//
// Depois conserte para mostrar as 3 notas.
//
// Dicas:
// 1. Procure "stack-buffer-overflow" e o número da linha no relatório.
// 2. Um vetor de 3 posições tem os índices 0, 1 e 2.
// 3. Resposta esperada: a) a linha do printf dentro do for, quando i vale 3;
//    b) o C não confere limites de vetor: o erro só existe quando o programa
//    roda; c) de execução. A correção é "i < 3" no lugar de "i <= 3".
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int notas[3] = {7, 9, 6};
    for (int i = 0; i <= 3; i++) {
        printf("Nota %d: %d\n", i + 1, notas[i]);
    }
    return 0;
}

// 0012 · Relacionais e a verdade em C
// Exercício E071 · ★★★
//
// O sistema da gincana confere se a nota digitada vale (de 0 a 10) e se os
// três jurados deram a mesma nota. Quem escreveu copiou a matemática:
// 0 <= nota <= 10 e j1 == j2 == j3. Compila, com avisos (de propósito), e
// erra. Rode com as entradas abaixo, leia os avisos e conserte as duas
// linhas SEM usar && (ele só chega no 0013): use o fato de que cada
// comparação vale 0 ou 1.
//
//   Nota: 15
//   Jurados: 7 7 7
//   Nota válida? 0
//   Unanimidade? 1
//
// Dicas:
// 1. O C avalia da esquerda para a direita: 0 <= nota <= 10 é
//    (0 <= nota) <= 10, e o 0 ou 1 da esquerda é sempre <= 10.
// 2. "As duas coisas são verdade" é o mesmo que "o produto das duas vale
//    1": (0 <= nota) * (nota <= 10).
// 3. Resposta esperada: valida = (nota >= 0) * (nota <= 10);
//    unanime = (j1 == j2) * (j2 == j3). Testes: 15 e 7 7 7 → 0 e 1;
//    8 e 7 7 9 → 1 e 0; 10 e 2 2 2 → 1 e 1. Sem o conserto, 15 e 7 7 7
//    mostram 1 e 0.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int nota = 0, j1 = 0, j2 = 0, j3 = 0;
    printf("Nota: ");
    scanf("%d", &nota);
    printf("Jurados: ");
    scanf("%d %d %d", &j1, &j2, &j3);

    bool valida = 0 <= nota <= 10;
    bool unanime = j1 == j2 == j3;

    printf("Nota válida? %d\n", valida);
    printf("Unanimidade? %d\n", unanime);
    return 0;
}

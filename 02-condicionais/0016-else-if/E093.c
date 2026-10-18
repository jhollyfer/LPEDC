// 0016 · else if, if aninhado e o else pendurado
// Exercício E093 · ★★☆
//
// O recuo deste trecho mente. Preveja a saída para os três pares de valores
// e só depois rode:
//
//   if (a > 0)
//       if (b > 0)
//           printf("A\n");
//   else
//       printf("B\n");
//   printf("C\n");
//
//   a) a = -1, b = 5      b) a = 2, b = -1      c) a = 2, b = 3
//
// Por fim, coloque chaves para que o else fique de fato com o if (a > 0).
//
// Dicas:
// 1. O else pertence ao if mais próximo que ainda não tem else.
// 2. Com a = -1, o if de fora é falso, e o else não é dele.
// 3. Resposta esperada: a) só "C"; b) "B" e "C"; c) "A" e "C". Com as
//    chaves em volta do if (b > 0), o caso a) passa a mostrar "B" e "C", e o
//    caso b) mostra só "C".
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

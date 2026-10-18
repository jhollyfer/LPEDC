// 0076 · Eficiência: contar passos
// Exercício E454 · ★★☆
//
// Dois jeitos de saber se n é primo, contando as divisões (n % d) como passo:
//
//   ingênuo: testa todo d de 2 até n - 1;
//   esperto: testa d de 2 enquanto d * d <= n. Se n tivesse um divisor maior
//            que a raiz, teria também um menor, que já teria aparecido.
//
// Escreva as duas funções (devolvem bool) com contadores e mostre a tabela
// para os primos 97, 997 e 9973.
//
//   Saída esperada:
//       n  ingênuo  esperto
//      97       95        8
//     997      995       30
//    9973     9971       98
//
// Dicas:
// 1. Primo é o pior caso dos dois: nenhuma divisão dá resto 0, então o laço
//    vai até o fim.
// 2. Use dois contadores globais e zere os dois antes de cada n.
// 3. Repare: n cresceu 100 vezes; o ingênuo cresceu 100 vezes, o esperto
//    só uns 12. A raiz de 100 é 10.
// 4. Resposta esperada: a tabela acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}

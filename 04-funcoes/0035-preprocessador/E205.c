// 0035 · Pré-processador: macros e #ifdef
// Exercício E205 · ★☆☆
//
// Rode o programa abaixo: a segunda linha mostra 16, mas 3 vezes o dobro de
// 4 é 24. Conserte a macro DOBRO, sem mexer no main. Depois escreva a macro
// TRIPLO(x), já à prova de precedência, e tire as barras da última linha.
//
//   Saída esperada:
//   DOBRO(4) = 8
//   3 * DOBRO(4) = 24
//   METADE(10 + 4) = 7
//   100 + TAXA * 2 = 120
//   TRIPLO(2 + 1) = 9
//
// Dicas:
// 1. Escreva a troca de texto à mão: 3 * DOBRO(4) vira 3 * 4 + 4. A
//    multiplicação vem antes da soma.
// 2. Parênteses em cada parâmetro e em volta de tudo, como em METADE.
// 3. Resposta esperada: a saída acima, com #define DOBRO(x) ((x) + (x)) e
//    #define TRIPLO(x) ((x) * 3). Sem os parênteses no x, TRIPLO(2 + 1)
//    viraria 2 + 1 * 3 = 5.
//
// Escreva sua resposta abaixo (conserte e complete o código):

#include <stdio.h>

#define DOBRO(x) x + x
#define METADE(x) ((x) / 2)
#define TAXA 10

int main(void) {
    printf("DOBRO(4) = %d\n", DOBRO(4));
    printf("3 * DOBRO(4) = %d\n", 3 * DOBRO(4));
    printf("METADE(10 + 4) = %d\n", METADE(10 + 4));
    printf("100 + TAXA * 2 = %d\n", 100 + TAXA * 2);
    // printf("TRIPLO(2 + 1) = %d\n", TRIPLO(2 + 1));
    return 0;
}

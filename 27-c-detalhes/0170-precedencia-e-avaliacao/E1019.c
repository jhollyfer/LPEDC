// 0170 · Precedência e ordem de avaliação
// Exercício E1019 · ★★★
//
// As três macros abaixo têm defeito. #define só troca texto: DOBRO(n) vira
// "n + n" colado no meio da expressão, e MAIOR(fila++, limite) copia o
// fila++ duas vezes. Conserte:
//
//   - DOBRO e AREA: ponha parênteses em volta de cada parâmetro e do
//     resultado inteiro;
//   - MAIOR: troque a macro por uma função int maior(int a, int b), que
//     avalia cada argumento uma vez só.
//
//   Saída esperada:
//   100 / DOBRO(5) = 10
//   AREA(2 + 1, 4) = 12
//   maior = 3, fila = 4
//
// Dicas:
// 1. Rode antes: sai 25, 6 e "maior = 4, fila = 5". Escreva no papel o
//    texto que cada macro gera.
// 2. #define DOBRO(x) ((x) + (x))
// 3. Com a função, a chamada fica maior(fila++, limite).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define DOBRO(x) x + x
#define AREA(l, c) l * c
#define MAIOR(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
    int n = 5;
    printf("100 / DOBRO(5) = %d\n", 100 / DOBRO(n));
    printf("AREA(2 + 1, 4) = %d\n", AREA(2 + 1, 4));

    int fila = 3, limite = 2;
    int m = MAIOR(fila++, limite);
    printf("maior = %d, fila = %d\n", m, fila);
    return 0;
}

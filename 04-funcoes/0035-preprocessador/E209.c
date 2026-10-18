// 0035 · Pré-processador: macros e #ifdef
// Exercício E209 · ★★★
//
// A macro avalia o argumento cada vez que ele aparece. Rode o programa: nas
// linhas da macro, x anda duas vezes e pontos é chamada a mais.
//
// Conserte sem apagar a macro MAIOR:
//   1. nas duas linhas marcadas "macro:", guarde cada argumento numa variável
//      ANTES de usar a macro, para elas mostrarem o mesmo que as da função;
//   2. escreva "int maior3(int a, int b, int c)" usando a função maior e
//      acrescente a última linha da saída. A linha "macro aninhada" fica como
//      está, para comparar.
//
//   Saída esperada:
//   macro:  m = 5, x = 6
//   função: m = 5, x = 6
//   macro:  m = 40, chamadas = 2
//   função: m = 40, chamadas = 2
//   macro aninhada: m = 19, chamadas = 7
//   maior3: m = 19, chamadas = 3
//
// Dicas:
// 1. Expanda MAIOR(x++, y) à mão: ((x++) > (y) ? (x++) : (y)). Com a
//    comparação verdadeira, x++ roda duas vezes. Com int a = x++; antes,
//    a macro recebe só o nome a.
// 2. Na função, cada argumento é avaliado uma vez, antes da chamada.
//    maior3 cabe numa linha: return maior(maior(a, b), c);
// 3. Resposta esperada: a saída acima. Na macro aninhada, o MAIOR de dentro
//    é colado duas vezes no de fora: 3 + 1 + 3 = 7 chamadas de pontos.
//
// Escreva sua resposta abaixo (conserte e complete o código):

#include <stdio.h>

#define MAIOR(a, b) ((a) > (b) ? (a) : (b))

int chamadas = 0;

int pontos(int p) {
    chamadas++;
    return p;
}

int maior(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int x = 5;
    int y = 3;
    int m = MAIOR(x++, y);
    printf("macro:  m = %d, x = %d\n", m, x);

    x = 5;
    m = maior(x++, y);
    printf("função: m = %d, x = %d\n", m, x);

    chamadas = 0;
    m = MAIOR(pontos(40), pontos(25));
    printf("macro:  m = %d, chamadas = %d\n", m, chamadas);

    chamadas = 0;
    m = maior(pontos(40), pontos(25));
    printf("função: m = %d, chamadas = %d\n", m, chamadas);

    chamadas = 0;
    m = MAIOR(MAIOR(pontos(7), pontos(19)), pontos(12));
    printf("macro aninhada: m = %d, chamadas = %d\n", m, chamadas);
    return 0;
}

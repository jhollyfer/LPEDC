// 0004 · Constantes
// Exercício E021 · ★★☆
//
// Resposta: (1) o ; do #define MENSALIDADE ia parar dentro do printf
// ("expected ')' before ';' token", na linha do printf); (2) o = do
// #define DESCONTO virava "%.2f\n", = 10.00 ("expected expression before
// '=' token"); (3) const precisa do valor na declaração: atribuir depois dá
// "assignment of read-only variable 'dia'".

#include <stdio.h>

#define MENSALIDADE 89.90
#define DESCONTO 10.00

int main(void) {
    const int dia = 10;

    printf("Mensalidade: R$ %.2f\n", MENSALIDADE);
    printf("Desconto: R$ %.2f\n", DESCONTO);
    printf("Vencimento: dia %d\n", dia);
    return 0;
}

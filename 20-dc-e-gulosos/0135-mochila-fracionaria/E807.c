// 0135 · Mochila fracionária
// Exercício E807 · ★★☆
//
// Ache o bug. O feirante tem 15 kg de espaço e três caixas de fruta de
// 10 kg: uva (R$ 42, ou R$ 4,20/kg), caqui (R$ 20) e ameixa (R$ 48, ou
// R$ 4,80/kg). O certo é levar a ameixa inteira e metade da uva, mas o
// programa faz outra coisa, sem nenhum aviso:
//
//   Saída que aparece:
//   10 kg de uva
//   5 kg de ameixa
//   Total: R$ 66.00
//
//   Saída esperada:
//   10 kg de ameixa
//   5 kg de uva
//   Total: R$ 69.00
//
// O erro está na função de comparação. Acrescente um printf nela que mostre
// rx, ry e o valor devolvido, rode, ache o problema e conserte.
//
// Dicas:
// 1. Quanto vale (int)(4.8 - 4.2)? E (int)(2.0 - 4.2)?
// 2. Quando a comparação devolve 0, o qsort entende que tanto faz a ordem
//    dos dois, e eles podem ficar como estavam: a uva antes da ameixa.
// 3. Resposta esperada: troque o "return (int)(ry - rx);" por
//    "return (rx < ry) - (rx > ry);", que devolve -1, 0 ou 1 sem cortar
//    nada. Consertado, mostra a saída acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *fruta;
    double kg, valor;
} Caixa;

int por_razao(const void *a, const void *b) {
    const Caixa *x = a;
    const Caixa *y = b;
    double rx = x->valor / x->kg;
    double ry = y->valor / y->kg;
    return (int)(ry - rx);
}

int main(void) {
    Caixa c[] = {{"uva", 10, 42}, {"caqui", 10, 20}, {"ameixa", 10, 48}};
    int n = 3;
    double livre = 15, total = 0;

    qsort(c, n, sizeof c[0], por_razao);
    for (int i = 0; i < n && livre > 0; i++) {
        double leva = c[i].kg <= livre ? c[i].kg : livre;
        total += c[i].valor * leva / c[i].kg;
        printf("%.0f kg de %s\n", leva, c[i].fruta);
        livre -= leva;
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}

// 0135 · Mochila fracionária
// Exercício E806 · ★☆☆
//
// Uma loja de temperos a granel vai a uma feira com uma mala de 12 kg. O
// programa está pronto, menos a função de comparação do qsort, que precisa
// pôr primeiro o tempero de MAIOR valor por quilo. Complete no lugar
// marcado com "COMPLETE AQUI".
//
//   canela 4 kg R$ 120, pimenta 6 kg R$ 240, orégano 5 kg R$ 100,
//   cominho 3 kg R$ 75
//
//   Saída esperada:
//   6 de 6 kg: pimenta
//   4 de 4 kg: canela
//   2 de 3 kg: cominho
//   Total: R$ 410.00
//
// Dicas:
// 1. Calcule as duas razões em double: rx = x->valor / x->peso, e o mesmo
//    para y.
// 2. Para a ordem DECRESCENTE, devolva negativo quando rx > ry:
//    (rx < ry) - (rx > ry).
// 3. Resposta esperada: a saída acima. As razões são pimenta 40, canela 30,
//    cominho 25 e orégano 20 (R$/kg).
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *nome;
    double peso, valor;
} Tempero;

int por_razao(const void *a, const void *b) {
    // COMPLETE AQUI
    (void)a;
    (void)b;
    return 0;
}

int main(void) {
    Tempero t[] = {{"canela", 4, 120}, {"pimenta", 6, 240}, {"orégano", 5, 100}, {"cominho", 3, 75}};
    int n = 4;
    double livre = 12, total = 0;

    qsort(t, n, sizeof t[0], por_razao);
    for (int i = 0; i < n && livre > 0; i++) {
        double leva = t[i].peso <= livre ? t[i].peso : livre;
        total += t[i].valor * leva / t[i].peso;
        printf("%.0f de %.0f kg: %s\n", leva, t[i].peso, t[i].nome);
        livre -= leva;
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}

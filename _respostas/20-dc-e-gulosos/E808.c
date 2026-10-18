// 0135 · Mochila fracionária
// Exercício E808 · ★★☆

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome;
    int litros;  // oferta máxima
    int centavos; // preço por litro, em centavos
} Oferta;

int mais_barata(const void *a, const void *b) {
    const Oferta *x = a, *y = b;
    return (x->centavos > y->centavos) - (x->centavos < y->centavos);
}

int main(void) {
    Oferta o[] = {{'A', 12000, 510}, {'B', 8000, 495}, {'C', 15000, 525}, {'D', 6000, 489}};
    int n = 4;
    int falta = 30000;      // litros que o posto precisa
    long long custo = 0;    // centavos

    qsort(o, n, sizeof o[0], mais_barata);
    for (int i = 0; i < n && falta > 0; i++) {
        int compra = o[i].litros <= falta ? o[i].litros : falta;
        long long parcial = (long long)compra * o[i].centavos;
        printf("%c: %5d L a R$ %d.%02d = R$ %lld.%02lld\n", o[i].nome, compra,
               o[i].centavos / 100, o[i].centavos % 100, parcial / 100, parcial % 100);
        custo += parcial;
        falta -= compra;
    }
    printf("Total: R$ %lld.%02lld\n", custo / 100, custo % 100);
    return 0;
}

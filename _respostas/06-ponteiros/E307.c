// 0052 · Juntando tudo: o ranking da feira
// Exercício E307 · ★☆☆

#include <stdio.h>
#include <math.h>

void separa(double valor, int *reais, int *centavos) {
    long total = lround(valor * 100); // 19.99 * 100 = 1998.999... vira 1999
    *reais = (int)(total / 100);
    *centavos = (int)(total % 100);
}

int main(void) {
    double valores[3] = {37.85, 0.99, 19.99};
    int r, c;

    for (int i = 0; i < 3; i++) {
        separa(valores[i], &r, &c);
        printf("R$ %.2f = %d reais e %d centavos\n", valores[i], r, c);
    }
    return 0;
}

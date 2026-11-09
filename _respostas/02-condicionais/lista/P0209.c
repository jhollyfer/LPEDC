// Lista · Módulo 02 · Decisões
// Exercício P0209 · ★☆☆ · O troco que não bate

#include <math.h>
#include <stdio.h>

int main(void) {
    double soma = 0.10 + 0.20;
    double esperado = 0.30;

    printf("Soma: %.17f\n", soma);
    if (fabs(soma - esperado) < 0.000001) { // perto o bastante conta como igual
        printf("Troco certo.\n");
    } else {
        printf("Troco errado!\n");
    }
    return 0;
}

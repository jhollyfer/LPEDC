// Lista · Módulo 03 · Laços
// Exercício P0318 · ★★☆ · A soma que demora a crescer

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    double soma = 0.0;
    int n = 0;
    bool passou_3 = false;

    while (soma <= 5) {
        n++;
        soma += 1.0 / n;
        if (!passou_3 && soma > 3) {
            printf("Passa de 3 com %d termos (soma %.4f)\n", n, soma);
            passou_3 = true;
        }
    }
    printf("Passa de 5 com %d termos (soma %.4f)\n", n, soma);
    return 0;
}

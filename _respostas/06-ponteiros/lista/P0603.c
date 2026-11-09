// Lista · Módulo 06 · Ponteiros
// Exercício P0603 · ★☆☆ · Rachando a conta do bar

#include <stdio.h>
#include <stdbool.h>

bool rachar(double total, int pessoas, double *por_pessoa, double *gorjeta) {
    if (pessoas < 1) {
        return false;
    }
    *gorjeta = total * 0.10;
    *por_pessoa = (total + *gorjeta) / pessoas;
    return true;
}

int main(void) {
    double totais[3] = {186.00, 95.50, 50.00};
    int pessoas[3] = {4, 3, 0};

    for (int i = 0; i < 3; i++) {
        double cada, gorjeta;
        if (rachar(totais[i], pessoas[i], &cada, &gorjeta)) {
            printf("R$ %.2f / %d: gorjeta R$ %.2f, cada um paga R$ %.2f\n",
                   totais[i], pessoas[i], gorjeta, cada);
        } else {
            printf("R$ %.2f / %d: ninguém para pagar\n", totais[i], pessoas[i]);
        }
    }
    return 0;
}

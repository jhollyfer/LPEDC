// Lista · Módulo 08 · Tipos compostos
// Exercício P0808 · ★☆☆ · Conserte o cadastro do sócio

#include <stdio.h>

typedef struct {
    char nome[20];
    int anos;
    double mensalidade;
} Socio;

void aplicar_desconto(Socio *s) { // o endereço: mexe no original
    if (s->anos > 10) {
        s->mensalidade *= 0.80;
    }
}

int main(void) {
    Socio socios[3] = {{"Seu Lourival", 23, 150.0}, {"Kelly", 4, 150.0},
                       {"Dona Ivete", 11, 120.0}};

    for (int i = 0; i < 3; i++) {
        aplicar_desconto(&socios[i]);
        printf("%-13s %2d anos: R$ %.2f\n", socios[i].nome, socios[i].anos,
               socios[i].mensalidade); // double pede %f
    }
    return 0;
}

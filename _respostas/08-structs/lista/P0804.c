// Lista · Módulo 08 · Tipos compostos
// Exercício P0804 · ★☆☆ · O carro e o tanque

#include <stdio.h>

typedef struct {
    char modelo[16];
    double tanque, capacidade, km_por_litro, odometro;
} Carro;

double abastecer(Carro *c, double litros) {
    double cabe = c->capacidade - c->tanque;
    double entra = litros < cabe ? litros : cabe;
    c->tanque += entra;
    return entra;
}

double rodar(Carro *c, double km) {
    double maximo = c->tanque * c->km_por_litro;
    double feito = km < maximo ? km : maximo;
    c->tanque -= feito / c->km_por_litro;
    c->odometro += feito;
    return feito;
}

void painel(const Carro *c) {
    printf("  %s: tanque %.2f L, odômetro %.1f km\n", c->modelo, c->tanque, c->odometro);
}

int main(void) {
    Carro mobi = {"Mobi", 5, 47, 13.5, 10230};

    printf("Abasteceu %.2f L\n", abastecer(&mobi, 50));
    painel(&mobi);
    printf("Rodou %.1f km\n", rodar(&mobi, 300));
    painel(&mobi);
    printf("Rodou %.1f km\n", rodar(&mobi, 400));
    painel(&mobi);
    printf("Abasteceu %.2f L\n", abastecer(&mobi, 20));
    painel(&mobi);
    return 0;
}

// Lista · Módulo 02 · Decisões
// Exercício P0205 · ★☆☆ · Pode doar sangue?

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int idade_ana = 17;
    double peso_ana = 52.0;
    int idade_rui = 72;
    double peso_rui = 80.0;

    bool ana_pode = idade_ana >= 16 && idade_ana <= 69 && peso_ana >= 50;
    bool rui_pode = idade_rui >= 16 && idade_rui <= 69 && peso_rui >= 50;

    printf("Ana pode doar? %s\n", ana_pode ? "sim" : "não");
    printf("Rui pode doar? %s\n", rui_pode ? "sim" : "não");
    return 0;
}

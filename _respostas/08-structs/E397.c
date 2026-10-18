// 0067 · Ponteiro para struct
// Exercício E397 · ★☆☆

#include <stdio.h>

typedef struct {
    char nome[20];
    double salario;
} Funcionario;

void reajustar(Funcionario *f, double pct) {
    f->salario *= 1 + pct / 100.0;
}

void mostrar(const Funcionario *f) {
    printf("%s: R$ %.2f\n", f->nome, f->salario);
}

int main(void) {
    Funcionario ana = {"Ana", 3200.00};
    Funcionario beto = {"Beto", 4100.00};

    mostrar(&ana);
    mostrar(&beto);
    reajustar(&ana, 8);
    reajustar(&beto, 8);
    printf("Depois do reajuste:\n");
    mostrar(&ana);
    mostrar(&beto);
    return 0;
}

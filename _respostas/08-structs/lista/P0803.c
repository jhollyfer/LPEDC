// Lista · Módulo 08 · Tipos compostos
// Exercício P0803 · ★☆☆ · O estoque baixo da farmácia

#include <stdio.h>

typedef struct {
    int codigo;
    char nome[24];
    int estoque;
    int minimo;
} Remedio;

int buscar(const Remedio *v, int n, int codigo) {
    for (int i = 0; i < n; i++) {
        if (v[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    Remedio v[6] = {
        {101, "Dipirona", 40, 20},  {102, "Amoxicilina", 8, 15},
        {103, "Losartana", 22, 25}, {104, "Omeprazol", 60, 30},
        {105, "Insulina", 3, 10},   {106, "Paracetamol", 35, 20},
    };

    printf("Comprar:\n");
    for (int i = 0; i < 6; i++) {
        if (v[i].estoque < v[i].minimo) {
            printf("  %-12s faltam %d\n", v[i].nome, v[i].minimo - v[i].estoque);
        }
    }
    int codigos[2] = {105, 110};
    for (int k = 0; k < 2; k++) {
        int i = buscar(v, 6, codigos[k]);
        if (i >= 0) {
            printf("Código %d: %s, estoque %d\n", codigos[k], v[i].nome, v[i].estoque);
        } else {
            printf("Código %d: não cadastrado\n", codigos[k]);
        }
    }
    return 0;
}

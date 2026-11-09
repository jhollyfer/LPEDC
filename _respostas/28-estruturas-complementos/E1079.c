// 0180 · Pigeonhole e chave composta
// Exercício E1079 · ★★★

#include <stdio.h>

typedef struct {
    char nome[8];
    int cidade, nota;
} Inscrito;

void ordena_por_cidade(Inscrito *v, int n) {
    for (int i = 1; i < n; i++) {
        Inscrito x = v[i];
        int j = i - 1;
        while (j >= 0 && v[j].cidade > x.cidade) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

void ordena_por_nota(Inscrito *v, int n) {
    for (int i = 1; i < n; i++) {
        Inscrito x = v[i];
        int j = i - 1;
        while (j >= 0 && v[j].nota > x.nota) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

int main(void) {
    Inscrito v[] = {
        {"Ana", 1, 62}, {"Teo", 2, 70}, {"Nina", 3, 91}, {"Rui", 1, 80}, {"Bia", 2, 48},
        {"Lia", 1, 62}, {"Caio", 3, 55}, {"Ivo", 2, 70}, {"Joao", 1, 55},
    };
    int n = 9;
    ordena_por_nota(v, n);   // 1º a chave secundária
    ordena_por_cidade(v, n); // por último a principal
    for (int i = 0; i < n; i++) {
        printf("%s%d:%s(%d)", i > 0 && v[i].cidade == v[i - 1].cidade ? " " : (i > 0 ? "\n" : ""),
               v[i].cidade, v[i].nome, v[i].nota);
    }
    printf("\n");
    return 0;
}

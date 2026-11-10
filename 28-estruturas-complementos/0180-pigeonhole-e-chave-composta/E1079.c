// 0180 · Pigeonhole e chave composta
// Exercício E1079 · ★★★
//
// Ache o bug. A secretaria quer a lista dos inscritos do vestibular por
// CIDADE (código 1, 2 ou 3) e, dentro de cada cidade, por NOTA, da menor
// para a maior. O programa faz duas passadas com a inserção, que é estável,
// mas a lista sai agrupada por nota, com as cidades misturadas. A ordem das
// passadas está trocada. Conserte o main e rode de novo.
//
//   Saída esperada:
//   1:Joao(55) 1:Ana(62) 1:Lia(62) 1:Rui(80)
//   2:Bia(48) 2:Teo(70) 2:Ivo(70)
//   3:Caio(55) 3:Nina(91)
//
// Escreva sua resposta abaixo (conserte o código):

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
    ordena_por_cidade(v, n);
    ordena_por_nota(v, n);
    for (int i = 0; i < n; i++) {
        printf("%s%d:%s(%d)", i > 0 && v[i].cidade == v[i - 1].cidade ? " " : (i > 0 ? "\n" : ""),
               v[i].cidade, v[i].nome, v[i].nota);
    }
    printf("\n");
    return 0;
}

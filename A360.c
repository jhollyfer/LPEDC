// A360 · Duas passadas estáveis viram uma chave composta

#include <stdio.h>
#include "0180-pombal.h"

// inserção pela turma (estável), para a segunda passada
void insercao_por_turma(Aluno *v, int n) {
    for (int i = 1; i < n; i++) {
        Aluno x = v[i];
        int j = i - 1;
        while (j >= 0 && v[j].turma > x.turma) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

// seleção pela turma (não estável), para comparar
void selecao_por_turma(Aluno *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j].turma < v[m].turma) {
                m = j;
            }
        }
        Aluno t = v[i];
        v[i] = v[m];
        v[m] = t;
    }
}

void mostra(const Aluno *v, int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d:%s(%d)", v[i].turma, v[i].nome, v[i].nota);
    }
    printf("\n");
}

int main(void) {
    Aluno chamada[] = {
        {"Ana", 7, 1},   {"Bruno", 5, 2}, {"Carla", 9, 1}, {"Diego", 5, 1},
        {"Elisa", 7, 2}, {"Fabio", 3, 2}, {"Gabi", 9, 2},  {"Hugo", 5, 1},
    };
    int n = 8;
    Aluno a[8], b[8];
    for (int i = 0; i < n; i++) {
        a[i] = chamada[i];
    }
    // objetivo: por turma e, dentro da turma, por nota
    if (pb_pigeonhole(a, n, 0, 10) != 0) { // 1ª passada: a chave secundária
        return 1;
    }
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
    printf("1ª passada (nota): ");
    mostra(a, n);
    insercao_por_turma(a, n); // 2ª passada: a principal, com método estável
    printf("2ª estável (turma):");
    mostra(a, n);
    selecao_por_turma(b, n); // a mesma 2ª passada com a seleção
    printf("2ª com seleção:    ");
    mostra(b, n);
    return 0;
}
// Saída:
// 1ª passada (nota):  2:Fabio(3) 2:Bruno(5) 1:Diego(5) 1:Hugo(5) 1:Ana(7) 2:Elisa(7) 1:Carla(9) 2:Gabi(9)
// 2ª estável (turma): 1:Diego(5) 1:Hugo(5) 1:Ana(7) 1:Carla(9) 2:Fabio(3) 2:Bruno(5) 2:Elisa(7) 2:Gabi(9)
// 2ª com seleção:     1:Diego(5) 1:Hugo(5) 1:Ana(7) 1:Carla(9) 2:Fabio(3) 2:Elisa(7) 2:Bruno(5) 2:Gabi(9)

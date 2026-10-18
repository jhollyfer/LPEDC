// A122 · A classificação ordenada

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    int vitorias;
    int empates;
} Time;

int pontos(Time t) {
    return 3 * t.vitorias + t.empates;
}

// qsort entrega ponteiros genéricos para dois elementos do vetor
int comparar(const void *a, const void *b) {
    Time x = *(const Time *)a; // copia o time apontado
    Time y = *(const Time *)b;
    if (pontos(x) != pontos(y)) {
        return pontos(y) - pontos(x); // mais pontos primeiro
    }
    return y.vitorias - x.vitorias; // desempate: mais vitórias
}

int main(void) {
    Time tabela[] = {
        {"Bahia", 8, 5},
        {"Flamengo", 9, 6},
        {"Palmeiras", 10, 4},
        {"Fortaleza", 10, 3},
        {"Vasco", 7, 7},
    };
    int n = sizeof tabela / sizeof tabela[0];

    // qsort troca structs inteiras de lugar (28 bytes por vez)
    qsort(tabela, n, sizeof tabela[0], comparar);

    for (int i = 0; i < n; i++) {
        printf("%dº %-10s %2d pts, %2d vitórias\n", i + 1, tabela[i].nome,
               pontos(tabela[i]), tabela[i].vitorias);
    }
    return 0;
}
// Saída:
// 1º Palmeiras  34 pts, 10 vitórias
// 2º Fortaleza  33 pts, 10 vitórias
// 3º Flamengo   33 pts,  9 vitórias
// 4º Bahia      29 pts,  8 vitórias
// 5º Vasco      28 pts,  7 vitórias

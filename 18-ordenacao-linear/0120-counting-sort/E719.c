// 0120 · Counting sort
// Exercício E719 · ★★★
//
// Ache o bug. A central de suporte ordena os chamados por prioridade (0 é
// urgente, 3 pode esperar) e, dentro da mesma prioridade, quer atender
// primeiro quem abriu antes (número menor). O programa compila e roda, mas
// a ordem dentro de cada prioridade sai errada. Faça duas coisas:
//
// a) escreva a função estavel, que confere a fila pronta: entre chamados de
// mesma prioridade, os números têm que vir crescentes. Rode: com o bug,
// tem que aparecer "estável? não";
//
// b) ache e conserte o erro do counting sort e rode de novo.
//
//   Saída esperada depois de (a):
//   p0: 110 106 102
//   p1: 108 105
//   p2: 107 104 101
//   p3: 109 103
//   estável? não
//
//   Saída esperada depois de (b):
//   p0: 102 106 110
//   p1: 105 108
//   p2: 101 104 107
//   p3: 103 109
//   estável? sim
//
// Dicas:
// 1. Na função estavel, compare cada fila[i] com fila[i - 1]: mesma
//    prioridade e número menor quer dizer que a ordem se perdeu.
// 2. O erro está em um dos três laços de ordena. Qual deles decide quem
//    fica com a ÚLTIMA vaga de cada bloco?
// 3. Resposta esperada: o terceiro laço anda da frente para trás. Com
//    c[x]--, o primeiro chamado de cada prioridade fica com a última vaga
//    do bloco, e os empates saem invertidos. O certo é
//    for (int i = n - 1; i >= 0; i--).
//
// Escreva sua resposta abaixo (complete estavel e conserte o código):

#include <stdio.h>
#include <stdbool.h>

#define K 4 // prioridade de 0 (urgente) a 3 (pode esperar)

typedef struct {
    int chamado;    // número do chamado, na ordem de abertura
    int prioridade;
} Chamado;

void ordena(const Chamado v[], Chamado saida[], int n) {
    int c[K] = {0};
    for (int i = 0; i < n; i++) {
        c[v[i].prioridade]++;
    }
    for (int x = 1; x < K; x++) {
        c[x] += c[x - 1];
    }
    for (int i = 0; i < n; i++) {
        int x = v[i].prioridade;
        c[x]--;
        saida[c[x]] = v[i];
    }
}

// estável: entre prioridades iguais, os chamados seguem crescentes
bool estavel(const Chamado v[], int n) {
    (void) v; // apague estas duas linhas
    (void) n;
    return true;
}

int main(void) {
    Chamado abertos[] = {{101, 2}, {102, 0}, {103, 3}, {104, 2}, {105, 1},
                         {106, 0}, {107, 2}, {108, 1}, {109, 3}, {110, 0}};
    Chamado fila[10];
    int n = 10;

    ordena(abertos, fila, n);
    for (int i = 0; i < n; i++) {
        if (i == 0 || fila[i].prioridade != fila[i - 1].prioridade) {
            printf("%sp%d:", i == 0 ? "" : "\n", fila[i].prioridade);
        }
        printf(" %d", fila[i].chamado);
    }
    printf("\nestável? %s\n", estavel(fila, n) ? "sim" : "não");
    return 0;
}

// A234 · O adversário que esconde a ordem

#include <stdbool.h>
#include <stdio.h>

#define N 4
#define ORDENS 24 // 4!

int pos[ORDENS][N]; // pos[o][x] = lugar da encomenda x na ordem o (0 = mais leve)
bool viva[ORDENS];  // a ordem o ainda combina com tudo que a balança disse?
int perguntas = 0;

// gera as 24 ordens com quatro laços (cada encomenda num lugar diferente)
void gera_ordens(void) {
    int o = 0;
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            for (int c = 0; c < N; c++) {
                for (int d = 0; d < N; d++) {
                    if (a != b && a != c && a != d && b != c && b != d && c != d) {
                        pos[o][0] = a;
                        pos[o][1] = b;
                        pos[o][2] = c;
                        pos[o][3] = d;
                        viva[o++] = true;
                    }
                }
            }
        }
    }
}

int vivas(void) {
    int k = 0;
    for (int o = 0; o < ORDENS; o++) {
        k += viva[o];
    }
    return k;
}

// a balança desonesta: "x é mais leve que y?" Ela não tem pesos de verdade:
// responde o que mantém MAIS ordens possíveis, e descarta as outras
bool mais_leve(int x, int y) {
    int sim = 0, nao = 0;
    for (int o = 0; o < ORDENS; o++) {
        if (viva[o]) {
            if (pos[o][x] < pos[o][y]) {
                sim++;
            } else {
                nao++;
            }
        }
    }
    bool resposta = sim >= nao;
    for (int o = 0; o < ORDENS; o++) {
        if (viva[o] && (pos[o][x] < pos[o][y]) != resposta) {
            viva[o] = false;                 // contradiz a resposta: descarta
        }
    }
    perguntas++;
    printf("  %c mais leve que %c? %s (ordens possíveis: %d)\n", 'A' + x, 'A' + y, resposta ? "sim" : "não", vivas());
    return resposta;
}

void insertion(int e[]) {
    for (int i = 1; i < N; i++) {
        int x = e[i], j = i - 1;
        while (j >= 0 && mais_leve(x, e[j])) {
            e[j + 1] = e[j];
            j--;
        }
        e[j + 1] = x;
    }
}

// merge sort de 4: ordena os pares (A,B) e (C,D) e intercala
void merge4(int e[]) {
    int esq[2] = {e[0], e[1]}, dir[2] = {e[2], e[3]};
    if (mais_leve(esq[1], esq[0])) {
        int t = esq[0];
        esq[0] = esq[1];
        esq[1] = t;
    }
    if (mais_leve(dir[1], dir[0])) {
        int t = dir[0];
        dir[0] = dir[1];
        dir[1] = t;
    }
    int i = 0, j = 0, k = 0;
    while (i < 2 && j < 2) {
        e[k++] = mais_leve(dir[j], esq[i]) ? dir[j++] : esq[i++];
    }
    while (i < 2) e[k++] = esq[i++];
    while (j < 2) e[k++] = dir[j++];
}

void joga(const char *nome, void (*ordena)(int[])) {
    int e[N] = {0, 1, 2, 3};
    gera_ordens();
    perguntas = 0;
    printf("%s contra o adversário:\n", nome);
    ordena(e);
    printf("  ordem final: %c %c %c %c, depois de %d perguntas\n\n", 'A' + e[0], 'A' + e[1], 'A' + e[2], 'A' + e[3], perguntas);
}

int main(void) {
    joga("insertion sort", insertion);
    joga("merge sort", merge4);
    printf("cada resposta deixa pelo menos metade: 24, 12, 6, 3, 2, 1 -> 5 perguntas no mínimo\n");
    return 0;
}
// Saída:
// insertion sort contra o adversário:
//   B mais leve que A? sim (ordens possíveis: 12)
//   C mais leve que A? sim (ordens possíveis: 8)
//   C mais leve que B? sim (ordens possíveis: 4)
//   D mais leve que A? sim (ordens possíveis: 3)
//   D mais leve que B? sim (ordens possíveis: 2)
//   D mais leve que C? sim (ordens possíveis: 1)
//   ordem final: D C B A, depois de 6 perguntas
//
// merge sort contra o adversário:
//   B mais leve que A? sim (ordens possíveis: 12)
//   D mais leve que C? sim (ordens possíveis: 6)
//   D mais leve que B? sim (ordens possíveis: 3)
//   C mais leve que B? não (ordens possíveis: 2)
//   C mais leve que A? sim (ordens possíveis: 1)
//   ordem final: D B C A, depois de 5 perguntas
//
// cada resposta deixa pelo menos metade: 24, 12, 6, 3, 2, 1 -> 5 perguntas no mínimo

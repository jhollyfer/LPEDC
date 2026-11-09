// 0181 · Juntando tudo
// Exercício E1086 · ★★★

#include <stdio.h>

#define M 31 // primo

typedef struct {
    int cpf;      // 0: posição livre
    int consultas;
    int ordem;    // em que ordem o paciente apareceu pela primeira vez
} Registro;

// dispersão dupla: devolve a posição do cpf (achada ou livre para ele)
int posicao(const Registro *t, int cpf) {
    int h1 = cpf % M, h2 = 1 + cpf % (M - 1);
    for (int i = 0; i < M; i++) {
        int j = (h1 + i * h2) % M;
        if (t[j].cpf == 0 || t[j].cpf == cpf) {
            return j;
        }
    }
    return -1;
}

int main(void) {
    int consultas[] = {711, 305, 711, 902, 118, 305, 711, 640, 902, 305,
                       118, 711, 555, 640, 305, 902, 711, 118, 999, 640};
    int n = 20;
    Registro t[M] = {{0, 0, 0}};
    int distintos = 0;
    for (int i = 0; i < n; i++) {
        int j = posicao(t, consultas[i]);
        if (t[j].cpf == 0) {
            t[j].cpf = consultas[i];
            t[j].ordem = distintos++;
        }
        t[j].consultas++;
    }
    // junta os registros na ordem de chegada (pela ordem)
    Registro lista[M];
    for (int j = 0; j < M; j++) {
        if (t[j].cpf != 0) {
            lista[t[j].ordem] = t[j];
        }
    }
    // pigeonhole pela quantidade, da maior para a menor, estável: casas 1..n
    int primeiro[21], prox[M], ultimo[21];
    for (int c = 0; c <= n; c++) {
        primeiro[c] = -1;
    }
    for (int i = 0; i < distintos; i++) {
        int c = lista[i].consultas;
        prox[i] = -1;
        if (primeiro[c] == -1) {
            primeiro[c] = i;
        } else {
            prox[ultimo[c]] = i;
        }
        ultimo[c] = i;
    }
    printf("%d pacientes diferentes em %d consultas\n", distintos, n);
    for (int c = n; c >= 1; c--) {
        for (int i = primeiro[c]; i != -1; i = prox[i]) {
            printf("cpf %3d: %d consultas\n", lista[i].cpf, c);
        }
    }
    return 0;
}

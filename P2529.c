// Lista · Módulo 25 · Estruturas especiais
// Exercício P2529 · ★★★ · A agenda do consultório
//
// Os horários marcados do consultório (em minutos desde 0h) ficam numa
// skip list. A recepção precisa de quatro operações, todas em O(log n)
// esperado. O programa já tem desce(h, antes), que desce os andares
// parando no último nó com chave < h (e guarda esse nó de cada andar em
// antes[], se antes não for NULL), e marca(h). Escreva:
// - desmarca(h): remove o horário, se existir, de todos os andares;
// - proximo(h): o menor horário >= h, ou -1;
// - anterior(h): o maior horário < h, ou -1.
//
//   Saída esperada:
//   marca 10:15 de novo: já ocupado
//   desmarca 11:00: ok
//   desmarca 12:00: não havia
//   07:00 -> anterior nenhum, próximo 08:00
//   10:15 -> anterior 09:00, próximo 10:15
//   10:16 -> anterior 10:15, próximo 13:00
//   12:00 -> anterior 10:15, próximo 13:00
//   17:00 -> anterior 16:00, próximo nenhum
//   Agenda: 08:00 09:00 10:15 13:00 14:30 16:00
//
// Dicas:
// 1. Depois de desce(h, ...), o nó devolvido é o maior com chave < h: é a
//    resposta de anterior (se for a cabeça, não há). O seguinte dele no
//    andar 0 é a resposta de proximo.
// 2. Em desmarca, o alvo é desce(h, antes)->prox[0]; desligue-o de
//    antes[k] para k menor que os andares dele e só então libere.
// 3. Resposta esperada: 10:16 tem anterior 10:15 e próximo 13:00 (o 11:00
//    foi desmarcado); a agenda final é 08:00 09:00 10:15 13:00 14:30 16:00.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 6

typedef struct No {
    int chave; // minutos desde 0h
    int andares;
    struct No *prox[MAX];
} No;

No cabeca;
unsigned semente = 11;

int moeda(void) {
    semente = semente * 1103515245u + 12345u;
    return (semente >> 16) & 1;
}

No *desce(int h, No *antes[]) {
    No *x = &cabeca;
    for (int k = MAX - 1; k >= 0; k--) {
        while (x->prox[k] != NULL && x->prox[k]->chave < h) x = x->prox[k];
        if (antes != NULL) antes[k] = x;
    }
    return x;
}

bool marca(int h) {
    No *antes[MAX];
    No *x = desce(h, antes);
    if (x->prox[0] != NULL && x->prox[0]->chave == h) return false;
    int andares = 1;
    while (andares < MAX && moeda() == 1) andares++;
    No *novo = malloc(sizeof(No));
    if (novo == NULL) exit(1);
    novo->chave = h;
    novo->andares = andares;
    for (int k = 0; k < MAX; k++) {
        novo->prox[k] = NULL;
        if (k < andares) {
            novo->prox[k] = antes[k]->prox[k];
            antes[k]->prox[k] = novo;
        }
    }
    return true;
}

bool desmarca(int h) {
    (void)h; // apague esta linha e escreva a remoção
    return false;
}

int proximo(int h) {
    (void)h; // apague esta linha
    return -1;
}

int anterior(int h) {
    (void)h; // apague esta linha
    return -1;
}

void hora(int m) {
    if (m < 0) printf("nenhum");
    else printf("%02d:%02d", m / 60, m % 60);
}

int main(void) {
    int horarios[] = {9 * 60, 14 * 60 + 30, 8 * 60, 10 * 60 + 15, 16 * 60, 11 * 60, 13 * 60};
    for (int k = 0; k < 7; k++) marca(horarios[k]);
    printf("marca 10:15 de novo: %s\n", marca(10 * 60 + 15) ? "marcado" : "já ocupado");
    printf("desmarca 11:00: %s\n", desmarca(11 * 60) ? "ok" : "não havia");
    printf("desmarca 12:00: %s\n", desmarca(12 * 60) ? "ok" : "não havia");

    int perguntas[] = {7 * 60, 10 * 60 + 15, 10 * 60 + 16, 12 * 60, 17 * 60};
    for (int k = 0; k < 5; k++) {
        hora(perguntas[k]);
        printf(" -> anterior ");
        hora(anterior(perguntas[k]));
        printf(", próximo ");
        hora(proximo(perguntas[k]));
        printf("\n");
    }
    printf("Agenda:");
    for (No *x = cabeca.prox[0]; x != NULL; x = x->prox[0]) {
        printf(" ");
        hora(x->chave);
    }
    printf("\n");
    No *x = cabeca.prox[0];
    while (x != NULL) {
        No *seguinte = x->prox[0];
        free(x);
        x = seguinte;
    }
    return 0;
}

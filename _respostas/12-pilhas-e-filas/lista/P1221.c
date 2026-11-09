// Lista · Módulo 12 · Pilhas e filas
// Exercício P1221 · ★★★ · O banco em que o cliente desiste

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[12];
    int chegada, atendimento, tolerancia;
} Cliente;

typedef struct no {
    Cliente c;
    struct no *prox;
} No;

typedef struct {
    No *inicio, *fim;
} Fila;

void entra(Fila *f, Cliente c) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->c = c;
    novo->prox = NULL;
    if (f->fim == NULL) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
}

bool sai(Fila *f, Cliente *c) {
    if (f->inicio == NULL) {
        return false;
    }
    No *velho = f->inicio;
    *c = velho->c;
    f->inicio = velho->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(velho);
    return true;
}

int main(void) {
    Cliente chegam[6] = {
        {"Ana", 0, 5, 10}, {"Beto", 1, 3, 2}, {"Caio", 2, 4, 10},
        {"Duda", 3, 2, 1}, {"Edu", 8, 3, 5}, {"Fabi", 9, 1, 0},
    };
    int total = 6, proximo = 0;
    Fila fila = {NULL, NULL};
    int livre_em = 0, atendidos = 0, desistencias = 0, soma_espera = 0;

    for (int minuto = 0; proximo < total || fila.inicio != NULL; minuto++) {
        while (proximo < total && chegam[proximo].chegada == minuto) {
            entra(&fila, chegam[proximo++]);
        }
        Cliente c;
        while (livre_em <= minuto && sai(&fila, &c)) {
            int espera = minuto - c.chegada;
            if (espera > c.tolerancia) {
                printf("min %d: %s tinha desistido\n", minuto, c.nome);
                desistencias++;
                continue; // chama o próximo no mesmo minuto
            }
            printf("min %d: atende %s (esperou %d)\n", minuto, c.nome, espera);
            atendidos++;
            soma_espera += espera;
            livre_em = minuto + c.atendimento;
        }
    }
    printf("Atendidos: %d, desistências: %d\n", atendidos, desistencias);
    if (atendidos > 0) {
        printf("Espera média dos atendidos: %.2f min\n", (double) soma_espera / atendidos);
    }
    return 0;
}

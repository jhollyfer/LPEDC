// 0034 · Módulos: .h, .c e compilação separada
// Exercício E203 · ★★★

#include <stdio.h>

// placar.h
#ifndef PLACAR_H
#define PLACAR_H

void marcar_gol(int time);
void encerrar_partida(void);
int pontos(int time);
int gols(int time);

#endif

// main.c
int main(void) {
    marcar_gol(1);
    marcar_gol(2);
    marcar_gol(1);
    encerrar_partida(); // 2 x 1

    encerrar_partida(); // 0 x 0

    marcar_gol(2);
    marcar_gol(1);
    marcar_gol(2);
    marcar_gol(2);
    encerrar_partida(); // 1 x 3

    printf("Casa: %d pontos, %d gols\n", pontos(1), gols(1));
    printf("Visitante: %d pontos, %d gols\n", pontos(2), gols(2));
    return 0;
}

// placar.c
static int partida = 0;
static int agora_casa = 0;
static int agora_visitante = 0;
static int pontos_casa = 0;
static int pontos_visitante = 0;
static int gols_casa = 0;
static int gols_visitante = 0;

static void anotar(int time) {
    if (time == 1) {
        agora_casa++;
    } else {
        agora_visitante++;
    }
}

void marcar_gol(int time) {
    anotar(time);
}

void encerrar_partida(void) {
    partida++;
    printf("Partida %d: %d x %d\n", partida, agora_casa, agora_visitante);
    if (agora_casa > agora_visitante) {
        pontos_casa += 3;
    } else if (agora_visitante > agora_casa) {
        pontos_visitante += 3;
    } else {
        pontos_casa++;
        pontos_visitante++;
    }
    gols_casa += agora_casa;
    gols_visitante += agora_visitante;
    agora_casa = 0;
    agora_visitante = 0;
}

int pontos(int time) {
    return time == 1 ? pontos_casa : pontos_visitante;
}

int gols(int time) {
    return time == 1 ? gols_casa : gols_visitante;
}

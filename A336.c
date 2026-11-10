// A336 · Trocar tempo por espaço: a tabela de idades

#include <stdio.h>

#define SOCIOS 10000
#define CONSULTAS 1000
#define IDADE_MAX 120

unsigned semente = 2024;

// gerador simples e previsível: a mesma sequência em toda execução
int sorteia(int limite) {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente / 65536u) % (unsigned)limite);
}

int main(void) {
    static int idade[SOCIOS];
    for (int i = 0; i < SOCIOS; i++) {
        idade[i] = 16 + sorteia(65);     // sócios da academia: 16 a 80 anos
    }
    int pergunta[CONSULTAS];
    for (int q = 0; q < CONSULTAS; q++) {
        pergunta[q] = 16 + sorteia(65);  // "quantos sócios têm x anos?"
    }

    // jeito 1: sem memória extra, percorre todos os sócios a cada consulta
    long passos1 = 0, soma1 = 0;
    for (int q = 0; q < CONSULTAS; q++) {
        for (int i = 0; i < SOCIOS; i++) {
            passos1++;
            soma1 += (idade[i] == pergunta[q]);
        }
    }

    // jeito 2: monta uma vez a tabela de contagem e responde olhando nela
    long passos2 = 0, soma2 = 0;
    int quantos[IDADE_MAX + 1] = {0};
    for (int i = 0; i < SOCIOS; i++) {
        passos2++;
        quantos[idade[i]]++;
    }
    for (int q = 0; q < CONSULTAS; q++) {
        passos2++;
        soma2 += quantos[pergunta[q]];
    }

    printf("sem tabela: %8ld passos, %3d bytes extras, respostas somam %ld\n",
           passos1, 0, soma1);
    printf("com tabela: %8ld passos, %3zu bytes extras, respostas somam %ld\n",
           passos2, sizeof quantos, soma2);
    // Θ(n·q) de tempo e Θ(1) de espaço contra Θ(n + q) de tempo e Θ(k) de
    // espaço, com k = 121 idades possíveis.
    return 0;
}
// Saída:
// sem tabela: 10000000 passos,   0 bytes extras, respostas somam 154767
// com tabela:    11000 passos, 484 bytes extras, respostas somam 154767

// A073 · O hidrômetro e a gaveta vizinha

#include <stdio.h>

#define LEITURAS 8

int main(void) {
    // o relógio d'água só acumula: cada leitura é o total desde a instalação
    int leitura[LEITURAS] = {1520, 1690, 1830, 2075, 2210, 2300, 2510, 2640};

    int maior = 0; // aqui 0 serve: consumo nunca é negativo
    int dia_maior = 0;

    // 8 leituras dão 7 dias de consumo: i vai até LEITURAS - 2,
    // porque o laço lê a gaveta vizinha, leitura[i + 1]
    for (int i = 0; i < LEITURAS - 1; i++) {
        int consumo = leitura[i + 1] - leitura[i];
        printf("Dia %d: %d litros\n", i + 1, consumo);
        if (consumo > maior) {
            maior = consumo;
            dia_maior = i + 1;
        }
    }

    // a primeira e a última gaveta dão o total, sem somar nada
    printf("Na semana: %d litros\n", leitura[LEITURAS - 1] - leitura[0]);
    printf("Pico: dia %d, com %d litros\n", dia_maior, maior);
    return 0;
}
// Saída:
// Dia 1: 170 litros
// Dia 2: 140 litros
// Dia 3: 245 litros
// Dia 4: 135 litros
// Dia 5: 90 litros
// Dia 6: 210 litros
// Dia 7: 130 litros
// Na semana: 1120 litros
// Pico: dia 3, com 245 litros

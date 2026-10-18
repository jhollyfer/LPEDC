// A015 · O cast que corta de propósito

#include <stdio.h>

int main(void) {
    // quantos pacotes cheios de 2.5 kg saem de 18 kg de café?
    double estoque = 18.0, pacote = 2.5;
    int cheios = (int) (estoque / pacote);   // 7.2 vira 7: aqui cortar é o certo
    double sobra = estoque - cheios * pacote; // int * double: a conta é real
    printf("Pacotes cheios: %d\n", cheios);
    printf("Sobram %.1f kg\n", sobra);

    // horas decimais do ponto eletrônico para horas e minutos
    double trabalhadas = 2.75;
    int horas = (int) trabalhadas;                    // 2
    int minutos = (int) ((trabalhadas - horas) * 60); // 0.75 * 60 = 45
    printf("%.2f h = %d h %d min\n", trabalhadas, horas, minutos);

    // o cast pega só o valor logo à direita dele
    printf("(int) 2.75 * 60 = %d\n", (int) 2.75 * 60);     // 2 * 60
    printf("(int) (2.75 * 60) = %d\n", (int) (2.75 * 60)); // 165.0 vira 165
    return 0;
}
// Saída:
// Pacotes cheios: 7
// Sobram 0.5 kg
// 2.75 h = 2 h 45 min
// (int) 2.75 * 60 = 120
// (int) (2.75 * 60) = 165

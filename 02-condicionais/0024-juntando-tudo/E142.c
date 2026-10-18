// 0024 · Juntando tudo: a conta de luz
// Exercício E142 · ★★☆
//
// Complete o programa do pedágio. Moto (1) paga R$ 6.00; carro (2) paga
// R$ 12.00; caminhão (3) paga R$ 12.00 por eixo. No horário de pico (das 17h
// às 19h59), a tarifa sobe 20%. Siga os TODO.
//
//   Categoria (1 moto, 2 carro, 3 caminhão): 2
//   Hora (0 a 23): 18
//   Horário de pico? sim
//   Tarifa: R$ 14.40
//
// Dicas:
// 1. No case 3, leia o número de eixos antes de calcular (declare
//    int eixos lá no começo do main, junto com categoria).
// 2. pico = hora >= 17 && hora < 20; e depois
//    tarifa = pico ? tarifa * 1.2 : tarifa;
// 3. Resposta esperada: carro às 18h → 14.40; caminhão com 4 eixos às 10h
//    → 48.00; moto às 19h → 7.20; categoria 5 → "Categoria inválida.".
//
// Escreva sua resposta abaixo (complete o código):

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int categoria, hora;
    double tarifa = 0;

    printf("Categoria (1 moto, 2 carro, 3 caminhão): ");
    if (scanf("%d", &categoria) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    switch (categoria) {
    case 1:
        tarifa = 6.00;
        break;
    // TODO: case 2 (carro, R$ 12.00)
    // TODO: case 3 (caminhão): leia os eixos e cobre R$ 12.00 por eixo
    default:
        printf("Categoria inválida.\n");
        return 1;
    }

    printf("Hora (0 a 23): ");
    if (scanf("%d", &hora) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    bool pico = false; // TODO: das 17h às 19h59
    // TODO: no pico, a tarifa sobe 20% (use um ternário)

    printf("Horário de pico? %s\n", pico ? "sim" : "não");
    printf("Tarifa: R$ %.2f\n", tarifa);
    return 0;
}

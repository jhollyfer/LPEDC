// A029 · O estacionamento e a constante à esquerda

#include <stdio.h>

int main(void) {
    int horas = 5;
    int vagas_livres = 0;
    double valor;

    // os dois caminhos guardam o resultado na mesma variável
    if (horas <= 3) {
        valor = 12.0;                      // preço fechado até 3 horas
    } else {
        valor = 12.0 + (horas - 3) * 4.0;  // R$ 4 por hora a mais
    }
    printf("%d horas: R$ %.2f\n", horas, valor); // roda depois de qualquer lado

    // constante à esquerda: se esquecer um =, "0 = vagas_livres" nem compila
    if (0 == vagas_livres) {
        printf("Placa na entrada: LOTADO\n");
    } else {
        printf("Placa na entrada: %d vagas\n", vagas_livres);
    }
    return 0;
}
// Saída:
// 5 horas: R$ 20.00
// Placa na entrada: LOTADO

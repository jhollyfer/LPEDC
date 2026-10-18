// A049 · Inverno na serra: maior e menor com INT_MIN e INT_MAX

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    const int FIM = 999;      // sentinela
    int temp;
    int dias = 0;             // contador
    int soma = 0;             // acumulador
    int geada = 0;            // contador com condição: dias com máxima <= 0
    int maior = INT_MIN;      // qualquer temperatura ganha do menor int
    int menor = INT_MAX;      // qualquer temperatura perde do maior int
    bool esquentou = false;   // flag: algum dia passou de 0 °C?

    // ler e testar a sentinela na própria pergunta do while
    printf("Máxima do dia (999 encerra): ");
    while (scanf("%d", &temp) == 1 && temp != FIM) {
        dias++;
        soma += temp;
        if (temp > maior) {
            maior = temp;     // sem o "dias == 1 ||": INT_MIN cuida disso
        }
        if (temp < menor) {
            menor = temp;
        }
        if (temp <= 0) {
            geada++;
        } else {
            esquentou = true;
        }
        printf("Máxima do dia (999 encerra): ");
    }

    if (dias == 0) {
        printf("Nenhum dia lido.\n");
        return 0;
    }
    printf("Dias: %d | Com máxima até 0 °C: %d\n", dias, geada);
    printf("Média: %.1f °C\n", (double) soma / dias);
    printf("Maior: %d °C | Menor: %d °C\n", maior, menor);
    printf("Algum dia acima de 0 °C? %s\n", esquentou ? "sim" : "não");
    return 0;
}
// Máxima do dia (999 encerra): -3
// Máxima do dia (999 encerra): -1
// Máxima do dia (999 encerra): -4
// Máxima do dia (999 encerra): 999
// Dias: 3 | Com máxima até 0 °C: 3
// Média: -2.7 °C
// Maior: -1 °C | Menor: -4 °C
// Algum dia acima de 0 °C? não

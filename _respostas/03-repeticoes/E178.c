// 0030 · Padrões de laço
// Exercício E178 · ★★☆
//
// Resposta: (1) dias++ vinha antes do teste da sentinela e contava o 9999;
// (2) maior = 0 vencia todos os negativos: agora começa com o primeiro dia;
// (3) soma / dias era divisão inteira: agora é (double) soma / dias com %.2f.

#include <stdio.h>

int main(void) {
    const int FIM = 9999;
    int valor;
    int dias = 0;
    int soma = 0;
    int maior = 0;

    while (1) {
        if (scanf("%d", &valor) != 1) {
            break;
        }
        if (valor == FIM) {
            break;
        }
        dias++;
        soma += valor;
        if (dias == 1 || valor > maior) {
            maior = valor;
        }
    }
    if (dias > 0) {
        printf("Dias: %d\n", dias);
        printf("Média: %.2f\n", (double) soma / dias);
        printf("Melhor dia: %d\n", maior);
    }
    return 0;
}

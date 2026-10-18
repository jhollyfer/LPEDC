// 0025 · Padrões de laço
// Exercício E148 · ★★☆
//
// A lanchonete anota o resultado de cada dia em reais (negativo é prejuízo) e
// digita 9999 para encerrar. Numa semana ruim, com -30, -10, -45 e 9999, o
// programa abaixo mostra:
//
//   Dias: 4
//   Média: -21
//   Melhor dia: 0
//
// mas o certo é 3 dias, média -28.33 e melhor dia -10. O código, com TRÊS
// erros, está logo abaixo. Teste com
//
//   printf -- '-30\n-10\n-45\n9999\n' | ~/LPEDC/rodar 03-repeticoes/0025-padroes-de-laco/E148.c
//
// ache os três e conserte.
//
// Dicas:
// 1. O contador conta antes ou depois de saber se é a sentinela?
// 2. Se todos os dias foram negativos, quem ganha de um "maior" que começa
//    em 0? E int dividido por int dá...
// 3. Resposta esperada: (1) dias++ vem antes do teste da sentinela e conta o
//    9999; (2) maior = 0 vence todos os negativos: comece com o primeiro dia;
//    (3) soma / dias é divisão inteira: use (double) soma / dias e %.2f.
//    Corrigido: "Dias: 3", "Média: -28.33", "Melhor dia: -10".
//
// Escreva sua resposta abaixo (conserte o código):

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
        dias++;
        if (valor == FIM) {
            break;
        }
        soma += valor;
        if (valor > maior) {
            maior = valor;
        }
    }
    if (dias > 0) {
        printf("Dias: %d\n", dias);
        printf("Média: %d\n", soma / dias);
        printf("Melhor dia: %d\n", maior);
    }
    return 0;
}

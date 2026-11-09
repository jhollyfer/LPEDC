// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0906 · ★☆☆ · O recibo da conta de luz, letra por letra
//
// Grave em /tmp/p0906_recibo.txt as três linhas do recibo:
//
//   Consumo: 230 kWh
//   Tarifa: R$ 0.85
//   Total: R$ 195.50
//
// (use fprintf e calcule o total no programa: 230 * 0.85). Depois reabra o
// arquivo e leia-o UM CARACTERE POR VEZ com fgetc: mostre cada caractere
// na tela com putchar e conte quantos caracteres e quantas linhas ('\n')
// o arquivo tem. Apague o arquivo no fim.
//
//   Saída esperada:
//   Consumo: 230 kWh
//   Tarifa: R$ 0.85
//   Total: R$ 195.50
//   3 linhas, 50 caracteres
//
// Dicas:
// 1. fgetc devolve um int, não um char: guarde em int c e compare com EOF.
//    Um char não consegue distinguir o EOF de um byte de verdade.
// 2. O laço é while ((c = fgetc(arq)) != EOF) { ... }.
// 3. Resposta esperada: 3 linhas e 50 caracteres (17 + 16 + 17, contando o
//    '\n' de cada linha).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

// 0053 · Pilha e heap
// Exercício E316 · ★★☆
//
// Um sensor de vibração de uma ponte grava 5.000.000 de leituras por dia.
// Simule as leituras com leitura[i] = i % 7 e mostre a soma de todas.
//
// Faça em dois passos:
// 1) declare o vetor int leituras[5000000]; como LOCAL de main e rode com o
//    rodar. Leia o que acontece.
// 2) mude o vetor para os DADOS (global ou static) e rode de novo.
//
//   Saída esperada (no passo 2):
//   Soma das leituras: 14999995
//
// Responda: quantos bytes o vetor ocupa? Por que o passo 1 quebra?
//
// Dicas:
// 1. 5.000.000 * 4 bytes = 20.000.000 bytes, uns 19 MiB.
// 2. Basta escrever static na frente da declaração, dentro de main.
// 3. Resposta esperada: 14999995. O vetor tem 20 MB e a pilha só tem 8 MiB:
//    no passo 1 o AddressSanitizer acusa stack-overflow (sem ele, o programa
//    morre com Segmentation fault). Nos dados, o espaço é reservado quando o
//    programa carrega e não depende do tamanho da pilha. No assunto 0054 você
//    vai fazer o mesmo com malloc, escolhendo o tamanho na hora de rodar.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

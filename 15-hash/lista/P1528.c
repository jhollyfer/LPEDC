// Lista · Módulo 15 · Tabelas hash
// Exercício P1528 · ★★★ · A teoria do fator de carga, medida
//
// O Cormen e o Knuth dizem quanto custa, em média, uma busca SEM sucesso no
// endereçamento aberto com fator de carga α:
//
//   sondagem linear:                  (1 + 1/(1 - α)²) / 2
//   hashing uniforme (≈ dispersão dupla):  1 / (1 - α)
//
// Confira na prática. Tabela de M = 1009 posições, sondagem linear
// (k % M + i) % M e dupla (k % M + i · (1 + k % (M - 1))) % M. Para cada α
// em 0,5, 0,75 e 0,9: reinicie a semente, encha a tabela com n = α · M
// chaves sorteadas e meça a média de posições olhadas em 2000 buscas de
// chaves que NÃO estão lá (1000000 + sorteio), até achar um VAZIO.
//
// Use este gerador, para o resultado ser igual em qualquer máquina:
//
//   unsigned long long semente = 2026;
//   int sorteia(void) {
//       semente = (semente * 1103515245ULL + 12345ULL) % 2147483648ULL;
//       return (int)(semente % 1000000);
//   }
//
//   Saída esperada:
//   alfa  linear (teoria)   dupla (teoria)
//   0.50   2.57 ( 2.50)      2.02 ( 2.00)
//   0.75   9.14 ( 8.50)      3.88 ( 4.00)
//   0.90  49.35 (50.50)      9.73 (10.00)
//
// Dicas:
// 1. Escreva double mede(int (*sonda)(int, int), double alfa) e chame com
//    linear e com dupla. Ponha semente = 2026 no começo de mede.
// 2. Use printf("%.2f  %5.2f (%5.2f)     %5.2f (%5.2f)\n", ...).
// 3. Com α = 0,9, a linear custa 5 vezes a dupla: o agrupamento primário é o
//    que separa as duas. Por isso tabelas abertas costumam fazer rehash
//    antes de α chegar perto de 1.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define M 1009
#define VAZIO -1

unsigned long long semente = 2026;

int sorteia(void) {
    semente = (semente * 1103515245ULL + 12345ULL) % 2147483648ULL;
    return (int)(semente % 1000000);
}

int main(void) {

    return 0;
}

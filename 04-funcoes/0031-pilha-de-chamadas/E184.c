// 0031 · A pilha de chamadas
// Exercício E184 · ★★☆
//
// Cada quadro tem as suas variáveis, mesmo com nomes iguais: aqui são três
// "n" e três "r". Estenda o programa abaixo com printfs que mostrem n e r em
// cada quadro: na entrada e na saída de dobro_mais_um e na saída de processa
// (o valor que ela devolve). Não mude nenhuma conta.
//
//   Saída esperada:
//   dobro_mais_um entra: n = 5
//   dobro_mais_um sai: n = 11, r = 10
//   processa: n = 5, r = 11
//   processa devolve 16
//   main: n = 5, r = 16
//
// Dicas:
// 1. Em dobro_mais_um, o printf de entrada vem antes de "int r"; o de saída,
//    logo antes do return.
// 2. Em processa, guarde r + n numa local antes do return para poder
//    mostrar o valor.
// 3. Resposta esperada: a saída acima. O n de dobro_mais_um vira 11, mas é o
//    n do quadro dela: o de processa continua 5, e o do main também.
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdio.h>

int dobro_mais_um(int n) {
    int r = n * 2;
    n = r + 1;
    return n;
}

int processa(int n) {
    int r = dobro_mais_um(n);
    printf("processa: n = %d, r = %d\n", n, r);
    return r + n;
}

int main(void) {
    int n = 5;
    int r = processa(n);
    printf("main: n = %d, r = %d\n", n, r);
    return 0;
}

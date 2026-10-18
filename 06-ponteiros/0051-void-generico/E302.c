// 0051 · void * e cast
// Exercício E302 · ★☆☆
//
// O programa abaixo tem quatro linhas, de L1 a L4, e cada comentário diz o
// que a linha QUERIA fazer. A L2 está certa e já roda. As outras três
// estão comentadas porque têm erro: descomente UMA de cada vez, rode com o
// rodar, leia a mensagem e conserte a linha para que ela faça o que
// promete. No fim, as quatro devem ficar descomentadas e rodando limpo.
//
//   Saída esperada:
//   L1: 300
//   L2: 450
//   L3: 450
//   L4: 450.0
//   pontos[0] = 300
//
// Dicas:
// 1. void * não diz quantos bytes ler nem quantos bytes andar: antes de
//    usar * ou +, converta para o tipo certo. Em C, void * vira int * sem
//    cast.
// 2. L1 não compila ("invalid use of void expression"). L3 só passa com
//    aviso do -pedantic: aritmética com void * é extensão do gcc, que anda
//    1 byte. L4 lê 8 bytes onde há um int de 4 (o sanitizer reclama).
// 3. Resposta esperada: a saída acima, com L1: *(int *)p; L2 igual;
//    L3: p = (int *)p + 1; L4: (double)*(int *)p com %.1f.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int pontos[2] = {300, 450}; // pontos do cartão em dois meses
    void *p = pontos;

    // L1 (mostra o primeiro mês): printf("L1: %d\n", *p);
    // L2 (mostra o segundo mês):
    int *q = p;
    printf("L2: %d\n", q[1]);
    // L3 (anda para o segundo mês): p = p + 1; printf("L3: %d\n", *(int *)p);
    // L4 (mostra com uma casa): printf("L4: %.1f\n", *(double *)p);

    printf("pontos[0] = %d\n", pontos[0]);
    return 0;
}

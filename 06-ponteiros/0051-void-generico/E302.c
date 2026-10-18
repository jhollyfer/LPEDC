// 0051 · void * e cast
// Exercício E302 · ★☆☆
//
// O programa abaixo tem quatro linhas comentadas, marcadas de L1 a L4.
// ANTES de testar, diga para cada uma: compila? Se compila, funciona? Depois
// descomente UMA linha de cada vez, rode com o rodar e leia a mensagem.
//
// Dicas:
// 1. void * não diz quantos bytes ler nem quantos bytes andar.
// 2. Em C, void * vira int * sem cast.
// 3. Resposta esperada: L1 não compila (desreferenciar void *: "invalid use
//    of void expression"); L2 compila e mostra 300; L3 compila só com
//    aviso do -pedantic ("pointer of type 'void *' used in arithmetic"),
//    porque aritmética com void * é extensão do gcc; o gcc anda 1 byte, e
//    o printf final passa a ler um int fora do lugar ("load of misaligned
//    address"); L4 compila, mas lê 8 bytes onde só há um int de 4: lixo e
//    erro do AddressSanitizer (stack-buffer-overflow).
//
// Escreva sua resposta abaixo (em comentário):

#include <stdio.h>

int main(void) {
    int pontos = 300;
    void *p = &pontos;

    // L1: printf("%d\n", *p);
    // L2: int *q = p; printf("%d\n", *q);
    // L3: p = p + 1;
    // L4: printf("%f\n", *(double *)p);

    printf("pontos = %d\n", *(int *)p);
    return 0;
}

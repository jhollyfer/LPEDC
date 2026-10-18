// 0044 · Memória e endereços
// Exercício E262 · ★★☆
//
// Este programa da pizzaria tenta mostrar o endereço da variável pedidos de
// três jeitos, e os três estão errados DE PROPÓSITO. Rode com o rodar e leia
// os avisos do compilador. Conserte as três linhas para mostrarem o
// endereço do jeito certo, rode de novo e confira que o rodar não reclama
// mais e que as três linhas mostram o mesmo endereço.
//
//   Saída esperada depois do conserto (o endereço muda a cada execução):
//   Endereço: 0x7f...
//   Endereço: 0x7f...
//   Endereço: 0x7f...
//
// Dicas:
// 1. Leia o aviso inteiro: ele diz o tipo que o formato espera e o tipo que
//    recebeu.
// 2. Um endereço tem 8 bytes; %d e %x leem um int de 4.
// 3. Resposta esperada: compila sem nenhum aviso e as três linhas mostram
//    o mesmo endereço em hexa. %d e %x leem só 4 bytes (número cortado);
//    %p sem cast funciona na prática, mas o padrão pede void *. As três
//    viram printf("Endereço: %p\n", (void *)&pedidos);
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int pedidos = 15;

    printf("Endereço: %d\n", &pedidos);
    printf("Endereço: %x\n", &pedidos);
    printf("Endereço: %p\n", &pedidos);
    return 0;
}

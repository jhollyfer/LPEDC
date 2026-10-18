// 0053 · Pilha e heap
// Exercício E317 · ★★★
//
// O programa abaixo mistura uma global, uma static e uma local numa função
// recursiva. Estenda o programa (sem mudar as contas) para ele mostrar o que
// acontece em cada frame:
//
// - logo depois de contador--, um printf com n, chamadas, local e contador;
// - logo antes do return, um printf com n e o valor que o frame devolve.
//
// Use os formatos da saída esperada. Rode e confira cada número com o lugar
// onde mora cada variável.
//
//   Saída esperada:
//   entra n=3: chamadas=1 local=1 contador=99
//   entra n=2: chamadas=2 local=1 contador=98
//   entra n=1: chamadas=3 local=1 contador=97
//   entra n=0: chamadas=4 local=1 contador=96
//   sai n=0: devolve 41
//   sai n=1: devolve 41
//   sai n=2: devolve 41
//   sai n=3: devolve 41
//   41
//   entra n=0: chamadas=5 local=1 contador=95
//   sai n=0: devolve 51
//   51
//   95
//
// Dicas:
// 1. Para o segundo printf, guarde a conta numa variável antes do return:
//    int resultado = chamadas * 10 + local;
// 2. passo(3) gera 4 frames (n = 3, 2, 1 e 0) e cada um tem a sua local.
//    chamadas e contador são um só para todos os frames.
// 3. Resposta esperada: a saída acima. local vale sempre 1 porque nasce de
//    novo em cada frame (pilha); chamadas só cresce porque mora nos dados.
//    Quando o primeiro frame chega ao return, as chamadas de dentro já
//    terminaram: por isso todos os frames de passo(3) devolvem 41.
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdio.h>

int contador = 100;

int passo(int n) {
    static int chamadas = 0;
    int local = 0;
    chamadas++;
    local++;
    contador--;
    if (n > 0) {
        passo(n - 1);
    }
    return chamadas * 10 + local;
}

int main(void) {
    printf("%d\n", passo(3));
    printf("%d\n", passo(0));
    printf("%d\n", contador);
    return 0;
}

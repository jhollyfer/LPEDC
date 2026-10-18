// 0045 · Ponteiros
// Exercício E269 · ★★★
//
// Transforme o trecho abaixo num teste de mesa que o próprio programa
// imprime. Cole o código no main e, depois da declaração e depois de CADA
// uma das cinco linhas, acrescente um printf que mostre a linha executada
// e os valores de a, b, *p e *q naquele momento.
//
//   int a = 3, b = 8;
//   int *p = &a, *q = &b;
//
//   *p = *q + 1;
//   p = q;
//   *p = *p * 2;
//   q = &a;
//   *q -= 4;
//
//   Saída esperada:
//   início        a = 3, b = 8, *p = 3, *q = 8
//   *p = *q + 1   a = 9, b = 8, *p = 9, *q = 8
//   p = q         a = 9, b = 8, *p = 8, *q = 8
//   ...
//   *q -= 4       a = 5, b = 16, *p = 16, *q = 5
//
// Dicas:
// 1. Quem muda com *p = ... é a variável apontada; p = q e q = &a só trocam
//    o alvo do ponteiro, sem mexer em a nem em b.
// 2. Use o mesmo printf seis vezes, mudando só o texto da linha; alinhe
//    com espaços para a tabela ficar fácil de ler.
// 3. Resposta esperada: as seis linhas terminam em a = 5, b = 16, *p = 16,
//    *q = 5; no meio aparecem "*p = *p * 2  a = 9, b = 16, *p = 16, *q = 16"
//    e "q = &a  a = 9, b = 16, *p = 16, *q = 9".
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

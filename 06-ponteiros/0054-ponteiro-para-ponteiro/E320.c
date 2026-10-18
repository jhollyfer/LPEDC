// 0054 · Ponteiro para ponteiro
// Exercício E320 · ★☆☆
//
// Olhe o gaveteiro (endereços fictícios) e preencha a tabela sem rodar:
//
//   endereço   conteúdo   variável
//   0x4000     5          x   (int)
//   0x4010     0x4000     p   (int *)
//   0x4020     0x4010     pp  (int **)
//
//   expressão   valor
//   x           ?
//   p           ?
//   *p          ?
//   pp          ?
//   *pp         ?
//   **pp        ?
//   &pp         ?
//   &*pp        ?
//
// Dicas:
// 1. Cada * dá um salto: vai até o endereço e pega o que tem lá.
// 2. & e * se anulam: &*pp é o mesmo que pp.
// 3. Resposta esperada: x = 5; p = 0x4000; *p = 5; pp = 0x4010;
//    *pp = 0x4000; **pp = 5; &pp = 0x4020; &*pp = 0x4010.
//
// Escreva sua resposta abaixo (em comentário; se quiser, confira montando
// as variáveis e mostrando com printf):

#include <stdio.h>

int main(void) {

    return 0;
}

// 0050 · Ponteiros
// Exercício E296 · ★☆☆
//
// Depois de executar
//
//   int vagas = 7;
//   int *p = &vagas;
//
// imagine que vagas mora no endereço 0x3000 e p no 0x3008. Preencha a
// tabela sem rodar:
//
//   expressão   valor
//   vagas       ?
//   &vagas      ?
//   p           ?
//   *p          ?
//   &p          ?
//   *&vagas     ?
//
// Depois escreva o programa e mostre cada expressão com printf (use %d
// para as que são int e %p com (void *) para as que são endereço). Os
// endereços reais vão ser outros; confira só quais são iguais entre si.
//
// Dicas:
// 1. & dá o endereço; * vai até o endereço e pega o que tem lá.
// 2. *&vagas: primeiro pega o endereço de vagas, depois vai até ele.
// 3. Resposta esperada: vagas = 7; &vagas = 0x3000; p = 0x3000; *p = 7;
//    &p = 0x3008; *&vagas = 7. No programa, &vagas e p saem iguais.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

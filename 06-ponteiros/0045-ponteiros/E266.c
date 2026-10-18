// 0045 · Ponteiros
// Exercício E266 · ★☆☆
//
// O painel do estacionamento guarda as vagas livres:
//
//   int vagas = 7;
//   int *p = &vagas;
//
// Escreva o programa e mostre cada expressão abaixo com printf (use %d
// para as que são int e %p com (void *) para as que são endereço):
// vagas, &vagas, p, *p, &p e *&vagas. Depois mostre, com %d, o resultado
// de três comparações: p == &vagas, *p == vagas e (void *)&p == (void *)&vagas.
//
//   Saída esperada (endereços mudam a cada execução):
//   vagas   = 7
//   &vagas  = 0x7f...30
//   p       = 0x7f...30
//   *p      = 7
//   &p      = 0x7f...40
//   *&vagas = 7
//   p == &vagas: 1
//   *p == vagas: 1
//   &p == &vagas: 0
//
// Dicas:
// 1. & dá o endereço; * vai até o endereço e pega o que tem lá.
// 2. *&vagas: primeiro pega o endereço de vagas, depois vai até ele.
// 3. Resposta esperada: &vagas e p saem iguais, &p sai diferente (o
//    ponteiro mora na sua própria gaveta); *p e *&vagas valem 7; as
//    comparações dão 1, 1 e 0.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

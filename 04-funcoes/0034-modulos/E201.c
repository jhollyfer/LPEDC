// 0034 · Módulos: .h, .c e compilação separada
// Exercício E201 · ★★☆
//
// O módulo conversao (conversao.h e conversao.c, nesta pasta) converte km em
// milhas, mas não faz o contrário. Sem mexer no módulo, escreva NESTE arquivo
// "double milhas_para_km(double milhas)" (1 milha = 1.609344 km) e use as
// duas funções juntas:
//
//   1. a maratona de 26.2 milhas em km;
//   2. a volta completa: km_para_milhas(milhas_para_km(26.2)) tem que dar
//      26.2 de novo;
//   3. a meia maratona de 13.1 milhas em km;
//   4. quantas conversões o módulo contou.
//
// Antes de terminar, tente escrever "contador++;" dentro da sua função, rode,
// leia o erro e apague a linha.
//
//   Saída esperada:
//   Maratona: 26.2 milhas = 42.2 km
//   Volta completa: 26.2 milhas
//   Meia: 13.1 milhas = 21.1 km
//   Conversões do módulo: 1
//
// Dicas:
// 1. O include do módulo já está aí embaixo; o rodar compila o conversao.c
//    junto, sozinho.
// 2. O contador é static dentro do conversao.c: o seu arquivo não enxerga
//    esse nome ('contador' undeclared). Só as funções do módulo contam.
// 3. Resposta esperada: a saída acima. O módulo contou 1: só a chamada de
//    km_para_milhas passa pelo contador; a sua função é de fora.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#include "conversao.h"

int main(void) {

    return 0;
}

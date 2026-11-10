// 0034 · Módulos: .h, .c e compilação separada
// Exercício E201 · ★★☆
//
// O módulo conversao (conversao.h e conversao.c, nesta pasta) converte km em
// milhas, mas não faz o contrário. Sem mexer no módulo, escreva NESTE arquivo
// "double milhas_para_km(double milhas)" (1 milha = 1.609344 km) e use as
// duas funções juntas: a maratona de 26.2 milhas em km; a volta completa
// km_para_milhas(milhas_para_km(26.2)); a meia maratona de 13.1 milhas em km;
// e quantas conversões o módulo contou (conversoes_feitas).
//
//   Saída esperada:
//   Maratona: 26.2 milhas = 42.2 km
//   Volta completa: 26.2 milhas
//   Meia: 13.1 milhas = 21.1 km
//   Conversões do módulo: 1
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#include "0034-conversao.h"

double milhas_para_km(double milhas);

int main(void) {

    return 0;
}

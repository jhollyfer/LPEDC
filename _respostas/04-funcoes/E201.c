// 0034 · Módulos: .h, .c e compilação separada
// Exercício E201 · ★★☆
//
// Na pasta do assunto, o programa usa #include "conversao.h" e o rodar
// compila o conversao.c junto. Para esta resolução rodar sozinha aqui, o
// necessário do módulo está copiado logo abaixo.

#include <stdio.h>

// --- cópia do necessário de conversao.h + conversao.c ---
static int contador = 0;

double km_para_milhas(double km) {
    contador++;
    return km / 1.609344;
}

int conversoes_feitas(void) {
    return contador;
}
// --- fim da cópia ---

double milhas_para_km(double milhas) {
    return milhas * 1.609344;
}

int main(void) {
    printf("Maratona: 26.2 milhas = %.1f km\n", milhas_para_km(26.2));
    printf("Volta completa: %.1f milhas\n", km_para_milhas(milhas_para_km(26.2)));
    printf("Meia: 13.1 milhas = %.1f km\n", milhas_para_km(13.1));
    printf("Conversões do módulo: %d\n", conversoes_feitas());
    return 0;
}

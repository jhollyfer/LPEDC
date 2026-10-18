// conversao.c · a implementação do módulo: COMO ele faz
#include "conversao.h"

static int contador = 0; // static fora de função: só este arquivo enxerga

// static: função auxiliar, invisível para quem inclui o .h
static double contar(double valor) {
    contador++;
    return valor;
}

double celsius_para_fahrenheit(double celsius) {
    return contar(celsius * 9 / 5 + 32);
}

double km_para_milhas(double km) {
    return contar(km / 1.609344);
}

double reais_para_dolares(double reais, double cotacao) {
    return contar(reais / cotacao);
}

int conversoes_feitas(void) {
    return contador;
}

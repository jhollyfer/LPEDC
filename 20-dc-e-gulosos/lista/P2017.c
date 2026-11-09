// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2017 · ★★☆ · Os postos da BR-319
//
// Um carro sai de Manaus pela BR-319 rumo a Porto Velho, 880 km, e o
// tanque cheio dá 250 km. Os postos ficam nos quilômetros 90, 180, 240,
// 330, 420, 470, 560, 650, 700 e 790. O motorista quer parar o MENOR
// número de vezes. O guloso: só pare quando o próximo posto ficar fora do
// alcance, e pare no posto mais distante que ainda dá para alcançar.
// Escreva do zero e mostre as paradas e o total; se algum trecho entre
// postos for maior que 250 km, avise que é impossível.
//
//   Saída esperada:
//   Parada 1: km 240
//   Parada 2: km 470
//   Parada 3: km 700
//   Chegou a Porto Velho com 3 paradas
//
// Dicas:
// 1. Ponha o destino como último "posto" (km 880). Guarde ultima, o km do
//    último abastecimento (começa em 0).
// 2. Enquanto o destino não está ao alcance (880 - ultima > 250): ande pelos
//    postos enquanto posto[i + 1] - ultima <= 250; pare em posto[i].
// 3. Resposta esperada: 4 paradas, nos km 240, 470, 700 e... confira na
//    saída de cima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

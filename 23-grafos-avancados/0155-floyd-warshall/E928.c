// 0155 · Floyd-Warshall: todos os pares
// Exercício E928 · ★★☆
//
// Uma casa de câmbio cobra uma taxa fixa (em centavos) por conversão entre
// Real, Dólar, Euro e Cripto (índices 0 a 3). As conversões de uma semana, de
// mão única, são:
//
//   Real -> Dólar 30     Dólar -> Euro 20      Euro -> Real 25
//   Real -> Cripto 50    Cripto -> Dólar -10   Dólar -> Real 35
//   Euro -> Cripto 15
//
// Na semana 2 de promoção, Cripto -> Dólar dá um bônus maior (-40 em vez de
// -10). Escreva analisa(semana, ...), que roda o Floyd-Warshall e, olhando a
// diagonal, diz se existe um ciclo negativo (trocar em roda e sair ganhando) e
// por quais moedas ele passa. Analise as duas semanas.
//
//   Saída esperada:
//   Semana 1: sem ciclo negativo
//   Semana 2: ciclo negativo passando por Dólar Euro Cripto
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define INFINITO 1000000000

int main(void) {

    return 0;
}

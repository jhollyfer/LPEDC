// 0009 · Atribuição, ++ e --
// Exercício E049 · ★☆☆
//
// Refatore: reescreva as cinco linhas marcadas usando os operadores
// compostos e o ++, sem mudar o que o programa mostra.
//
//   Saída esperada (igual antes e depois):
//   pontos 110, vidas 2, moedas 40, tempo 45, fase 4
//
// Dicas:
// 1. x = x + 10 vira x += 10. Somar 1 vira ++ e tirar 1 vira --.
// 2. Rode antes e depois: a saída tem de ser a mesma.
// 3. Resposta esperada: pontos += 10; vidas--; moedas *= 2; tempo /= 2;
//    fase++; e a mesma saída.
//
// Escreva sua resposta abaixo (refatore o código):

#include <stdio.h>

int main(void) {
    int pontos = 100, vidas = 3, moedas = 20, tempo = 90, fase = 3;

    pontos = pontos + 10;  // refatore
    vidas = vidas - 1;     // refatore
    moedas = moedas * 2;   // refatore
    tempo = tempo / 2;     // refatore
    fase = fase + 1;       // refatore

    printf("pontos %d, vidas %d, moedas %d, tempo %d, fase %d\n",
           pontos, vidas, moedas, tempo, fase);
    return 0;
}

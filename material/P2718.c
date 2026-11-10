// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2718 · ★★☆ · A catraca do ônibus
//
// A catraca tem dois estados, typedef enum { TRAVADA, LIBERADA } Estado;, e
// recebe dois eventos: 'M' (moeda) e 'P' (empurrar). Travada, a moeda
// libera e o empurrão é bloqueado; liberada, o empurrão deixa passar e trava
// de novo, e uma moeda a mais é desperdiçada. Processe a sequência "PMPMMPP"
// com um do/while sobre a string e um switch sobre o estado, contando
// passagens, moedas, moedas desperdiçadas e bloqueios.
//
//   Saída esperada:
//   passagens: 2
//   moedas: 3 (1 desperdiçada)
//   bloqueios: 2
//
// Dicas:
// 1. const char *p = eventos; do { ... p++; } while (*p != '\0'); serve
//    porque a string tem pelo menos um evento.
// 2. Dentro do switch (estado), um if sobre o evento decide o que fazer.
// 3. Comece em TRAVADA.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

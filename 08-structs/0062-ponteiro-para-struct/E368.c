// 0062 · Ponteiro para struct
// Exercício E368 · ★☆☆
//
// Complete o programa abaixo. Escreva as duas funções, uma que recebe o
// placar por valor e outra que recebe o endereço:
//
//   - void gol_copia(Placar p): soma 1 em p.gols;
//   - void gol(Placar *p): soma 1 em p->gols.
//
// No main, depois de cada chamada, mostre casa.gols. No fim, crie um
// ponteiro ptr para casa, some 10 por ele com a seta e mostre casa.gols e
// (*ptr).gols.
//
//   Saída esperada:
//   depois de gol_copia: 0
//   depois de gol: 1
//   depois de gol: 2
//   depois de gol_copia: 2
//   casa.gols = 12, (*ptr).gols = 12
//
// Dicas:
// 1. Quem recebe Placar (sem *) trabalha numa cópia que some no fim da
//    função.
// 2. Na chamada por endereço, passe &casa.
// 3. ptr->gols e (*ptr).gols são a mesma coisa, e ptr aponta para casa.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

typedef struct {
    int gols;
} Placar;

// escreva gol_copia e gol aqui

int main(void) {
    // crie Placar casa = {0}; chame gol_copia, gol, gol e gol_copia,
    // mostrando casa.gols depois de cada uma; depois use o ponteiro ptr

    return 0;
}

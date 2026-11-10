// 0164 · Listas autoajustáveis
// Exercício E979 · ★☆☆
//
// A playlist do carro tem 6 músicas e a busca é sequencial. Faça as 10
// buscas desta sequência nas duas listas (já montadas no main): a fixa com
// al_busca e a outra com al_busca_transpoe. Some o custo de cada uma e mostre
// os dois totais e a ordem final da lista que se ajusta.
//
//   sequência: Luar Asa Luar Luar Trem Luar Asa Luar Asa Luar
//
//   Saída esperada:
//   Fixa: 54 comparações
//   Transposição: 46 comparações
//   Ordem final: Luar Aquarela Trem Asa Garota Ciranda
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "0164-autolista.h"

int main(void) {
    const char *musicas[] = {"Aquarela", "Garota", "Trem", "Ciranda", "Asa", "Luar"};
    AutoLista *fixa = al_cria();
    AutoLista *ajusta = al_cria();
    for (int i = 0; i < 6; i++) {
        al_insere_fim(fixa, musicas[i]);
        al_insere_fim(ajusta, musicas[i]);
    }

    al_libera(fixa);
    al_libera(ajusta);
    return 0;
}

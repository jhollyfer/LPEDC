// 0164 · Listas autoajustáveis
// Exercício E979 · ★☆☆
//
// A playlist do carro tem 6 músicas e a busca é sequencial. Complete o main:
// faça as 10 buscas da sequência nas duas listas, a fixa com al_busca e a
// outra com al_busca_transpoe, some os custos de cada uma e mostre os dois
// totais e a ordem final da lista que se ajusta.
//
//   Saída esperada:
//   Fixa: 54 comparações
//   Transposição: 46 comparações
//   Ordem final: Luar Aquarela Trem Asa Garota Ciranda
//
// Dicas:
// 1. Um laço de 0 a 9; em cada volta, chame as duas buscas com &custo e
//    acumule em duas variáveis.
// 2. Para a ordem final, use al_mostra(ajusta) e depois um printf("\n").
// 3. Resposta esperada: a saída acima. O Luar, a mais tocada, começou em
//    último e só chegou à frente no décimo acesso: a transposição aprende
//    devagar (com mover para a frente, bastaria o primeiro).
//
// Escreva sua resposta abaixo (complete o main):

#include <stdio.h>
#include "autolista.h"

int main(void) {
    const char *musicas[] = {"Aquarela", "Garota", "Trem", "Ciranda", "Asa", "Luar"};
    const char *sequencia[] = {"Luar", "Asa", "Luar", "Luar", "Trem",
                               "Luar", "Asa", "Luar", "Asa", "Luar"};
    AutoLista *fixa = al_cria();
    AutoLista *ajusta = al_cria();
    for (int i = 0; i < 6; i++) {
        al_insere_fim(fixa, musicas[i]);
        al_insere_fim(ajusta, musicas[i]);
    }
    (void)sequencia; // apague esta linha

    al_libera(fixa);
    al_libera(ajusta);
    return 0;
}

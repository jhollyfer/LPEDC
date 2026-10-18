// 0164 · Listas autoajustáveis
// Exercício E979 · ★☆☆

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

    int total_fixa = 0, total_ajusta = 0;
    for (int i = 0; i < 10; i++) {
        int custo;
        al_busca(fixa, sequencia[i], &custo);
        total_fixa += custo;
        al_busca_transpoe(ajusta, sequencia[i], &custo);
        total_ajusta += custo;
    }
    printf("Fixa: %d comparações\n", total_fixa);
    printf("Transposição: %d comparações\n", total_ajusta);
    printf("Ordem final: ");
    al_mostra(ajusta);
    printf("\n");

    al_libera(fixa);
    al_libera(ajusta);
    return 0;
}

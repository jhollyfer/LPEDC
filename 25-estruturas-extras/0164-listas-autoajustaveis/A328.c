// A328 · Quando mover para a frente atrapalha

#include <stdio.h>
#include "autolista.h"

#define APPS 6

typedef bool (*Busca)(AutoLista *, const char *, int *);

// a busca sem ajuste tem outro tipo (recebe const): um embrulho resolve
bool fixa(AutoLista *l, const char *nome, int *custo) {
    return al_busca(l, nome, custo);
}

// monta a lista inicial, faz as buscas com a política e devolve o custo total
int roda(Busca busca, const char *seq[], int n) {
    const char *apps[APPS] = {"Banco", "Mapa", "Musica", "Fotos", "Email", "Agenda"};
    AutoLista *l = al_cria();
    for (int i = 0; i < APPS; i++) {
        al_insere_fim(l, apps[i]);
    }
    int total = 0;
    for (int i = 0; i < n; i++) {
        int custo;
        busca(l, seq[i], &custo);
        total += custo;
    }
    al_libera(l);
    return total;
}

int main(void) {
    // costume: quase sempre a Agenda e o Email, com uma Fotos perdida no meio
    const char *costume[] = {"Agenda", "Email", "Agenda", "Agenda", "Email", "Fotos",
                            "Agenda", "Email", "Agenda", "Email", "Agenda", "Agenda"};
    // revezando: cada app uma vez, na ordem da lista, três vezes seguidas
    const char *revezando[] = {"Banco", "Mapa", "Musica", "Fotos", "Email", "Agenda",
                             "Banco", "Mapa", "Musica", "Fotos", "Email", "Agenda",
                             "Banco", "Mapa", "Musica", "Fotos", "Email", "Agenda"};
    Busca politicas[] = {fixa, al_busca_mtf, al_busca_transpoe, al_busca_conta};

    printf("%-10s %6s %7s %7s %9s\n", "", "fixa", "frente", "transp", "contagem");
    printf("%-10s", "costume");
    for (int p = 0; p < 4; p++) {
        printf(" %*d", p == 0 ? 6 : p == 3 ? 9 : 7, roda(politicas[p], costume, 12));
    }
    printf("\n%-10s", "revezando");
    for (int p = 0; p < 4; p++) {
        printf(" %*d", p == 0 ? 6 : p == 3 ? 9 : 7, roda(politicas[p], revezando, 18));
    }
    printf("\n");
    return 0;
}
// Saída:
//              fixa  frente  transp  contagem
// costume        66      36      56        30
// revezando      63      93      66        63

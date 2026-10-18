// 0164 · Listas autoajustáveis
// Exercício E981 · ★★☆
//
// Uma política intermediária entre mover para a frente e transposição: o
// item achado sobe DUAS casas (ou vai para o início, se estava na posição
// 1 ou 2, contando do 0). Complete busca_sobe2, que faz isso numa
// AutoLista, devolve se achou e guarda o custo em *custo.
//
//   Saída esperada:
//   Edu  custo 5 -> Ana Bia Edu Caio Duda
//   Edu  custo 3 -> Edu Ana Bia Caio Duda
//   Duda custo 5 -> Edu Ana Duda Bia Caio
//   Edu  custo 1 -> Edu Ana Duda Bia Caio
//   Duda custo 3 -> Duda Edu Ana Bia Caio
//   Total: 17
//
// Dicas:
// 1. Ande com ant e p contando a posição i do nó achado (a do primeiro é 0).
//    Se i == 0, não há o que mudar.
// 2. Tire p da lista (ant->prox = p->prox). Depois volte ao começo e ache o
//    lugar novo, a posição i - 2 (ou 0, se i for 1): use
//    NoAuto **q = &l->inicio e avance até lá com q = &(*q)->prox. Aí faça
//    p->prox = *q e *q = p.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete busca_sobe2):

#include <stdio.h>
#include <string.h>
#include "autolista.h"

bool busca_sobe2(AutoLista *l, const char *nome, int *custo) {
    (void)l; // apague estas três linhas
    (void)nome;
    *custo = 0;
    return false;
}

int main(void) {
    const char *contatos[] = {"Ana", "Bia", "Caio", "Duda", "Edu"};
    const char *chamadas[] = {"Edu", "Edu", "Duda", "Edu", "Duda"};
    AutoLista *agenda = al_cria();
    for (int i = 0; i < 5; i++) {
        al_insere_fim(agenda, contatos[i]);
    }

    int total = 0;
    for (int i = 0; i < 5; i++) {
        int custo;
        busca_sobe2(agenda, chamadas[i], &custo);
        total += custo;
        printf("%-4s custo %d -> ", chamadas[i], custo);
        al_mostra(agenda);
        printf("\n");
    }
    printf("Total: %d\n", total);

    al_libera(agenda);
    return 0;
}

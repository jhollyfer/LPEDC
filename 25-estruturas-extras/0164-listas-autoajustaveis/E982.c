// 0164 · Listas autoajustáveis
// Exercício E982 · ★★☆
//
// Ache o bug. A função liga faz mover para a frente na agenda, mas o
// programa quebra na segunda ligação: o sanitizer acusa "member access
// within null pointer" e SEGV (acesso a um endereço inválido) dentro de
// liga. Conserte a função e rode de novo.
//
//   Saída esperada (sem nenhum erro do sanitizer):
//   Bia: Bia Ana Caio Duda
//   Bia: Bia Ana Caio Duda
//   Duda: Duda Bia Ana Caio
//   Ana: Ana Duda Bia Caio
//   Ana: Ana Duda Bia Caio
//
// Dicas:
// 1. Na segunda ligação, a Bia já é a primeira da lista. Quanto vale ant
//    quando o laço para no primeiro nó?
// 2. Se o nó achado já é o primeiro, não há nada para mover.
// 3. Resposta esperada: envolva as três atribuições do fim num
//    if (ant != NULL) { ... }.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>
#include "autolista.h"

void liga(AutoLista *l, const char *nome) {
    NoAuto *ant = NULL;
    NoAuto *p = l->inicio;
    while (p != NULL && strcmp(p->nome, nome) != 0) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) {
        return; // não está na agenda
    }
    ant->prox = p->prox;
    p->prox = l->inicio;
    l->inicio = p;
}

int main(void) {
    const char *contatos[] = {"Ana", "Bia", "Caio", "Duda"};
    const char *chamadas[] = {"Bia", "Bia", "Duda", "Ana", "Ana"};
    AutoLista *agenda = al_cria();
    for (int i = 0; i < 4; i++) {
        al_insere_fim(agenda, contatos[i]);
    }

    for (int i = 0; i < 5; i++) {
        liga(agenda, chamadas[i]);
        printf("%s: ", chamadas[i]);
        al_mostra(agenda);
        printf("\n");
    }

    al_libera(agenda);
    return 0;
}

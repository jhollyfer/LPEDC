// 0083 · Pilha encadeada
// Exercício E495 · ★★☆
//
// O botão Voltar do navegador é uma pilha de páginas. Com os tipos abaixo (pilha
// encadeada com um texto em cada nó), escreva bool visita(Historico *h, const
// char *url), que põe a página no topo, e bool voltar(Historico *h), que tira a
// página do topo, mas só se ela não for a única (da primeira página não se
// volta). No main, visite g1.globo.com, ge.globo.com e receitas.com, mostre a
// página atual, tente voltar, visite cifraclub.com.br, mostre a página atual,
// tente voltar três vezes e libere a memória.
//
//   Saída esperada:
//   Agora em: receitas.com
//   Voltar -> ge.globo.com
//   Agora em: cifraclub.com.br
//   Voltar -> ge.globo.com
//   Voltar -> g1.globo.com
//   Não dá para voltar de g1.globo.com
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pagina {
    char url[40];
    struct pagina *ant; // a página de onde você veio
} Pagina;

typedef struct {
    Pagina *topo; // a página aberta agora
} Historico;

int main(void) {

    return 0;
}

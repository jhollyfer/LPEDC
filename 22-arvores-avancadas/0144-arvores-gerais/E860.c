// 0144 · Árvores gerais
// Exercício E860 · ★☆☆
//
// A lista de material escolar está numa árvore geral (arvgen.h). Escreva
// mais_caro(r): devolve um ponteiro para a FOLHA de maior valor da subárvore
// de r. Depois use a mesma função em duas subárvores, achadas com ag_busca.
//
//   Saída esperada:
//   Mais caro da lista: mochila (R$ 120)
//   Mais caro em livros: gramatica (R$ 89)
//   Mais caro em papelaria: estojo (R$ 25)
//
// Dicas:
// 1. Se r não tem filho, a resposta é o próprio r.
// 2. Senão, comece com melhor = NULL e, para cada filho p, pegue
//    c = mais_caro(p); se melhor for NULL ou c->valor > melhor->valor, troque.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (escreva mais_caro e complete o main):

#include <stdio.h>
#include "arvgen.h"

int main(void) {
    NoG *lista = ag_cria("lista", 0);
    NoG *papelaria = ag_adiciona(lista, "papelaria", 0);
    ag_adiciona(papelaria, "caderno", 18);
    ag_adiciona(papelaria, "lapis", 3);
    ag_adiciona(papelaria, "estojo", 25);
    NoG *livros = ag_adiciona(lista, "livros", 0);
    ag_adiciona(livros, "gramatica", 89);
    ag_adiciona(livros, "atlas", 64);
    ag_adiciona(lista, "mochila", 120);

    // chame mais_caro para a lista, para "livros" e para "papelaria"
    (void)papelaria; // apague estas duas linhas
    (void)livros;

    ag_libera(lista);
    return 0;
}

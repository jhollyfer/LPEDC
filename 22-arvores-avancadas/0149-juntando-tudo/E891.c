// 0149 · Juntando tudo
// Exercício E891 · ★★☆
//
// Quando uma palavra está longe demais de tudo, as sugestões a uma edição
// de distância não acham nada. Outra pista é o começo da palavra. Escreva
// pelo_prefixo(d, palavra, max): desça na trie do dicionário enquanto as
// letras da palavra existirem, mostre o maior prefixo em comum e sugira até
// max palavras do dicionário que começam com ele, em ordem alfabética.
//
//   Saída esperada:
//   esquina: prefixo "es" | escola
//   cafezinho: prefixo "cafe" | cafe
//   mercadinho: prefixo "mercad" | mercado
//   portaria: prefixo "porta" | porta portao
//   xis: prefixo "" | nenhuma
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include "corretor.h"

int main(void) {
    NoC *dic = cor_cria();
    cor_carrega_basico(dic);
    const char *testes[] = {"esquina", "cafezinho", "mercadinho", "portaria", "xis"};
    (void)testes; // apague esta linha

    cor_libera(dic);
    return 0;
}

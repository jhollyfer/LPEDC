// 0149 · Juntando tudo
// Exercício E894 · ★★★
//
// Sugestões a até DUAS edições, com a distância de Levenshtein do assunto
// 0142, sem calcular a distância contra cada palavra do dicionário. A ideia:
// desça na trie com DFS levando a última linha da tabela da distância. Cada
// nó acrescenta uma linha (a letra dele contra a palavra procurada), e todas
// as palavras que passam por aquele prefixo aproveitam as linhas de cima. Se
// o menor valor da linha nova já passar de 2, nada embaixo daquele nó chega a
// 2: pode cortar o ramo inteiro. Escreva parecidas(d, alvo), que mostra, em
// ordem alfabética, as palavras do dicionário básico a distância 2 ou menos,
// com a distância entre parênteses.
//
//   Saída esperada:
//   carrro: bairro(2) caro(2) carro(1)
//   jnaela: janela(2)
//   bolsa: boa(2) bola(1) bolo(2)
//   mercadorias: nenhuma
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include "corretor.h"

int main(void) {
    NoC *dic = cor_cria();
    cor_carrega_basico(dic);
    const char *testes[] = {"carrro", "jnaela", "bolsa", "mercadorias"};
    (void)testes; // apague esta linha

    cor_libera(dic);
    return 0;
}

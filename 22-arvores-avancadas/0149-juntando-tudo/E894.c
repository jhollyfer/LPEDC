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
// Dicas:
// 1. A linha da raiz (prefixo vazio) é 0, 1, 2, ..., m (m = strlen(alvo)).
//    Para o filho com a letra c, a linha nova é lin[0] = ant[0] + 1 e, para
//    j de 1 a m, lin[j] = o menor entre ant[j - 1] + (alvo[j - 1] != c),
//    ant[j] + 1 e lin[j - 1] + 1.
// 2. Na função recursiva, receba a linha do pai (const int ant[]), monte a
//    sua num vetor local e passe para os filhos. Se o nó tem fim e lin[m] <= 2,
//    mostre a palavra do buffer. Se o menor valor de lin passar de 2, volte.
// 3. Resposta esperada: a saída acima. Repare em "jnaela": trocar duas letras
//    vizinhas de lugar custa 2 na distância de Levenshtein, mas é UMA edição no
//    cor_sugere (que testa a troca de vizinhas à parte).
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

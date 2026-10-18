// 0161 · Juntando tudo
// Exercício E962 · ★☆☆
//
// O caderno de receitas virou um vetor de linhas. Complete o laço para fazer
// um "grep -n" com o pb_horspool: mostre o número (contando de 1) e o texto de
// cada linha que tem "ovo" e, no fim, quantas linhas e quantas ocorrências:
//
//   Saída esperada:
//   1: bolo de cenoura: 3 ovos, 2 xícaras de farinha
//   2: pão de queijo: polvilho, queijo, ovo e leite
//   4: omelete: 2 ovos e queijo
//   5: pudim: leite, ovos e açúcar; ovo extra se quiser
//   6: farofa: farinha, manteiga e ovo cozido
//   5 linhas, 6 ocorrências
//
// Dicas:
// 1. O n de cada linha é (int) strlen(receitas[l]).
// 2. A função devolve quantas vezes o padrão aparece na linha: maior que 0
//    quer dizer que a linha entra.
// 3. Linhas e ocorrências são contadores diferentes: a linha 5 tem duas.
// 4. Resposta esperada: a saída acima. "ovos" contém "ovo" e conta.
//
// Escreva sua resposta abaixo (complete o laço):

#include <stdio.h>
#include <string.h>
#include "padroes.h"

int main(void) {
    const char *receitas[] = {
        "bolo de cenoura: 3 ovos, 2 xícaras de farinha",
        "pão de queijo: polvilho, queijo, ovo e leite",
        "brigadeiro: leite condensado e chocolate",
        "omelete: 2 ovos e queijo",
        "pudim: leite, ovos e açúcar; ovo extra se quiser",
        "farofa: farinha, manteiga e ovo cozido",
    };
    int linhas = sizeof receitas / sizeof receitas[0];
    const char *padrao = "ovo";
    int m = (int) strlen(padrao);
    int com = 0, ocorrencias = 0;
    long comp = 0;

    for (int l = 0; l < linhas; l++) {
        // chame pb_horspool na linha l e, se achou, mostre e conte
    }
    (void)m; // apague estas duas linhas quando usar m e comp
    (void)comp;
    printf("%d linhas, %d ocorrências\n", com, ocorrencias);
    return 0;
}

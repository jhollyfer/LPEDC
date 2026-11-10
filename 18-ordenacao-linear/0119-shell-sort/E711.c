// 0119 · Shell sort
// Exercício E711 · ★★☆
//
// A lista de convidados da festa precisa ir para a portaria em ordem
// alfabética. Escreva void shell_nomes(const char *v[], int n), um shell
// sort com os saltos de Knuth para um vetor de strings, que troca só os
// ponteiros (as letras não saem do lugar). Conte as comparações (cada strcmp
// conta uma) numa variável static.
//
//   Convidados: Rafael Bianca Tiago Larissa Diego Amanda Paulo Helena Caio
//               Sofia Murilo Elisa
//
//   Saída esperada:
//   Amanda, Bianca, Caio, Diego, Elisa, Helena, Larissa, Murilo, Paulo, Rafael, Sofia, Tiago
//   36 comparações
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *convidados[] = {"Rafael", "Bianca", "Tiago", "Larissa", "Diego", "Amanda",
                                "Paulo", "Helena", "Caio", "Sofia", "Murilo", "Elisa"};
    (void) convidados; // apague esta linha

    return 0;
}

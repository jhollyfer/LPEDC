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
// Dicas:
// 1. É o shell_sort do texto com int trocado por const char * e
//    v[j - h] > x trocado por strcmp(v[j - h], x) > 0.
// 2. Com n = 12, os saltos são 4 e 1.
// 3. Para contar cada strcmp, escreva o while só com j >= h e faça o teste
//    do strcmp dentro dele, com um break.
// 4. Resposta esperada: a saída acima.
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

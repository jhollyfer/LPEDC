// 0187 · Reduções
// Exercício E1118 · ★☆☆
//
// A prefeitura quer câmeras em esquinas de modo que toda rua tenha câmera
// em pelo menos uma ponta (uma cobertura de vértices). Esquinas A a G
// (0 a 6) e ruas:
//
//   A-B, B-C, C-D, D-E, E-F, F-G, B-F, C-E
//
// Escreva dois verificadores, bool cobre(const bool em[]) e
// bool independente(const bool em[]), e confira o teorema do texto nos
// dois planos abaixo: um conjunto é cobertura exatamente quando as
// esquinas que sobram formam um conjunto independente.
//
//   Plano 1: câmeras em B, D, E, F
//   Plano 2: câmeras em B, D, F
//
//   Saída esperada:
//   Plano 1: câmeras em B D E F
//     cobre todas as ruas? sim
//     sem câmera: A C G
//     independente? sim
//   Plano 2: câmeras em B D F
//     cobre todas as ruas? não
//     sem câmera: A C E G
//     independente? não
//
// Dicas:
// 1. Cobertura falha se existe rua a-b com nenhuma das pontas marcada.
//    Independente falha se existe rua a-b com as duas pontas marcadas.
// 2. O "resto" é o vetor com cada posição negada: resto[v] = !em[v].
// 3. Resposta esperada: a saída acima. No plano 2, a rua C-E fica sem
//    câmera, e é a mesma rua que liga C e E no resto.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}

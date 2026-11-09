// 0186 · P e NP
// Exercício E1112 · ★☆☆
//
// CLIQUE é NP-completo: "existe um grupo de k pessoas em que todo mundo é
// amigo de todo mundo?". Achar é difícil; conferir é fácil. Seis colegas
// (Ana, Bia, Cadu, Dani, Edu, Fê; 0 a 5) têm estas amizades:
//
//   Ana-Bia, Ana-Cadu, Bia-Cadu, Bia-Dani, Cadu-Dani, Ana-Dani,
//   Dani-Edu, Edu-Fê, Cadu-Edu
//
// Escreva o verificador bool eh_clique(const int grupo[], int k), que
// confere todos os pares do grupo e, ao achar um par que não é amigo,
// mostra o par e devolve false. Teste os três grupos da saída.
//
//   Saída esperada:
//   Grupo: Ana Bia Cadu Dani
//     é clique
//   Grupo: Bia Cadu Dani Edu
//     Bia e Edu não são amigos
//     não é clique
//   Grupo: Cadu Dani Edu
//     é clique
//
// Dicas:
// 1. Dois laços, j começando em i + 1: são k(k-1)/2 pares, O(k²). Isso é
//    polinomial no tamanho do certificado.
// 2. Mostre o nome do grupo antes de chamar o verificador, porque ele
//    imprime o par culpado.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}

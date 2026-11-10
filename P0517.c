// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0517 · ★★☆ · Arrumando os espaços do endereço
//
// O formulário do correio recebeu um endereço cheio de espaços sobrando:
//
//   char end[] = "   Av.   Eduardo    Ribeiro ,  620   ";
//
// Escreva void normalizar(char s[]), que arruma a string NO LUGAR: tira os
// espaços do começo e do fim, deixa um espaço só entre as palavras e tira o
// espaço que vem antes de vírgula. Mostre a string entre colchetes, antes e
// depois, e o strlen de cada uma:
//
//   Saída esperada:
//   Antes:  [   Av.   Eduardo    Ribeiro ,  620   ] (37)
//   Depois: [Av. Eduardo Ribeiro, 620] (24)
//
// Dicas:
// 1. Mesma ideia de compactar vetor: i lê, k escreve. A string só encolhe,
//    então escrever em s[k] nunca atropela o que i ainda vai ler.
// 2. Ao ver um espaço, não escreva na hora: lembre que "tem espaço pendente".
//    Ao ver um caractere que não é espaço, escreva o espaço pendente antes
//    (se k > 0 e o caractere não for vírgula) e depois o caractere.
// 3. Espaço pendente no fim é simplesmente descartado. Feche com s[k] = '\0'.
// 4. Resposta esperada: [Av. Eduardo Ribeiro, 620], com 24 caracteres.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    char end[] = "   Av.   Eduardo    Ribeiro ,  620   ";
    (void) end; // apague esta linha quando escrever

    return 0;
}

// 0157 · Força bruta
// Exercício E940 · ★★☆
//
// A tia quer as abreviações do grupo por extenso. Escreva a função
//
//   int substitui(const char *texto, const char *velho, const char *novo,
//                 char saida[], int cap)
//
// que copia texto para saida trocando cada ocorrência de velho por novo e
// devolve quantas trocas fez. Nunca escreva mais que cap posições em saida
// (contando o '\0'). Use a força bruta para saber se velho começa em cada
// posição i. Teste:
//
//   texto: "vc vem? se vc não vier, vc avisa"   velho: "vc"   novo: "você"
//
//   Saída esperada:
//   você vem? se você não vier, você avisa
//   3 trocas
//
// Dicas:
// 1. Uma função auxiliar casa_em(texto, i, velho, m) responde se as m letras
//    de velho estão em texto a partir de i (é o miolo da força bruta).
// 2. Ande com dois índices: i no texto e k na saída. Se casou, copie novo
//    letra a letra e faça i += m (não conta sobreposição: o pedaço sumiu).
//    Senão, copie uma letra só.
// 3. Só teste casa_em quando i <= n - m. E termine saida com '\0'.
// 4. "você" tem 5 bytes em UTF-8 (o 'ê' ocupa 2), e tudo bem: o código só
//    copia bytes. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}

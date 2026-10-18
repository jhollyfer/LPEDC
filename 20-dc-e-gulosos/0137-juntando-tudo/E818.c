// 0137 · Juntando tudo
// Exercício E818 · ★☆☆
//
// A primeira passada do compactador conta quantas vezes cada byte aparece.
// Faça só essa parte, sem o TAD: grave a estrofe abaixo num arquivo
// "poema.txt", reabra em modo binário, conte as frequências com fgetc num
// vetor long freq[256] e mostre o total de bytes e os 5 bytes mais
// frequentes (no empate, o de menor código). Apague o arquivo no fim.
//
//   Minha terra tem palmeiras,
//   Onde canta o Sabiá;
//   As aves, que aqui gorjeiam,
//   Não gorjeiam como lá.
//
//   Saída esperada:
//   100 bytes. Os 5 mais frequentes:
//     ' ' 13
//     'a' 11
//     'e' 8
//     'i' 6
//     'o' 6
//
// Dicas:
// 1. while ((c = fgetc(f)) != EOF) freq[c]++; (o c é int, e fgetc devolve
//    o byte como unsigned char, de 0 a 255, ou EOF).
// 2. Para os 5 maiores: 5 vezes, ache o índice do maior e, depois de
//    mostrar, ponha -1 nele para tirá-lo da disputa.
// 3. Resposta esperada: a saída acima. O "á" e o "ã" não aparecem como uma
//    letra só: em UTF-8 cada um vira dois bytes (0xC3 e mais um).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

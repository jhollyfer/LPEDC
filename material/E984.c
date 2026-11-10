// 0164 · Listas autoajustáveis
// Exercício E984 · ★★★
//
// Mover para a frente também é um truque de compressão (o bzip2 usa). Comece
// com o alfabeto em ordem, "abcdefghijklmnopqrstuvwxyz". Para cada letra do
// texto, escreva a POSIÇÃO atual dela nesse vetor (contando do 0) e leve a
// letra para a frente. Letras repetidas de perto viram números pequenos,
// principalmente zeros, que um compressor guarda em poucos bits.
//
// Escreva codifica(texto, codigos) e decodifica(codigos, n, saida). A
// decodificação começa do mesmo alfabeto: o número diz a posição; a letra
// que está lá é a próxima do texto, e ela também vai para a frente. Teste
// com "banana" e "aaabbbaaa":
//
//   Saída esperada:
//   banana: 1 1 13 1 1 1 -> banana
//   aaabbbaaa: 0 0 0 1 0 0 1 0 0 -> aaabbbaaa
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}

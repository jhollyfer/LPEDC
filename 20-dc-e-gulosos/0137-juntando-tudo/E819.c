// 0137 · Juntando tudo
// Exercício E819 · ★★☆
//
// O cabeçalho do .huf tem 1036 bytes fixos. A partir de que tamanho a
// compactação compensa? Grave num arquivo "padaria.txt" a linha abaixo 1,
// 10, 30, 60, 100 e 300 vezes (um arquivo novo a cada caso), compacte cada
// um com o TAD compactador.h e monte a tabela:
//
//   Pão francês ..... R$ 0,75 a unidade
//
//   Saída esperada:
//   linhas  original  compactado
//        1        38        1057  não compensa
//       10       380        1240  não compensa
//       30      1140        1648  não compensa
//       60      2280        2259  compensa
//      100      3800        3074  compensa
//      300     11400        7149  compensa
//
// Dicas:
// 1. Um vetor int vezes[] = {1, 10, 30, 60, 100, 300} e, para cada caso,
//    abra com "w" (que apaga o conteúdo anterior), grave e feche.
// 2. printf("%6d  %8ld  %10ld  %s\n", ...) monta as colunas.
// 3. Resposta esperada: a saída acima. Os bits sozinhos ocupam uns 54% do
//    original; o cabeçalho é que estraga os arquivos pequenos. Apague os
//    arquivos no fim.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "compactador.h"

int main(void) {

    return 0;
}

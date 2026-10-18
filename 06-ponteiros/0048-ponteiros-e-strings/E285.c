// 0048 · Ponteiros e strings
// Exercício E285 · ★★☆
//
// Escreva sua própria versão do strcpy com ponteiros:
//
//   void copia(char *destino, const char *origem)
//
// Copie caractere por caractere, INCLUINDO o '\0' do fim. Depois escreva
// uma segunda versão, copia_classica, com o laço clássico de corpo vazio:
//
//   while ((*destino++ = *origem++) != '\0') {
//   }
//
// Teste as duas copiando "Porto Alegre" para um vetor char destino[20] e
// mostrando o resultado e o strlen dele. Para provar que a clássica copia
// o '\0', antes de chamá-la encha destino com "XXXXXXXXXXXXXXXXXXX" (19 X)
// e confira que nenhum X sobra no fim.
//
//   Saída esperada:
//   copia:          Porto Alegre (12 letras)
//   copia_classica: Porto Alegre (12 letras)
//
// Dicas:
// 1. Versão simples: enquanto *origem != '\0', copie e avance os dois; no
//    fim, *destino = '\0'.
// 2. Na versão clássica, a atribuição copia, o valor dela é o caractere
//    copiado e o ++ avança os dois ponteiros depois. O laço para logo
//    depois de copiar o '\0', porque o valor copiado é 0.
// 3. Resposta esperada: as duas linhas acima, com 12 letras; se sobrasse
//    X, o '\0' não teria sido copiado.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}

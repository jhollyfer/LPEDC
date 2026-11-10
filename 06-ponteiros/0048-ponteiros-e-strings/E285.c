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
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}

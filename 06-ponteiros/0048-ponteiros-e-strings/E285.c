// 0048 · Ponteiros e strings
// Exercício E285 · ★★☆
//
// Escreva sua própria versão do strcpy com ponteiros:
//
//   void copia(char *destino, const char *origem)
//
// Copie caractere por caractere, INCLUINDO o '\0' do fim. Teste copiando
// "Porto Alegre" para um vetor char destino[20] e mostrando o resultado e
// o strlen dele.
//
//   Saída esperada:
//   Destino: Porto Alegre (12 letras)
//
// Desafio extra: a versão clássica tem o corpo do laço vazio:
//
//   while ((*destino++ = *origem++) != '\0') {
//   }
//
// Explique em comentário por que ela funciona.
//
// Dicas:
// 1. Versão simples: enquanto *origem != '\0', copie e avance os dois; no
//    fim, *destino = '\0'.
// 2. Na versão clássica, a atribuição copia, o valor dela é o caractere
//    copiado e o ++ avança os dois ponteiros depois.
// 3. Resposta esperada: "Porto Alegre", 12 letras. O laço clássico para
//    logo depois de copiar o '\0', porque o valor copiado é 0.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}

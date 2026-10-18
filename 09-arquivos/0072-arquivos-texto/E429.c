// 0072 · Arquivos texto
// Exercício E429 · ★★☆
//
// Faça um "wc" caseiro. Primeiro, grave em /tmp/recado.txt exatamente estas
// três linhas (cada uma termina com '\n'):
//
//   Feira no domingo
//   leve sacolas
//   e o dinheiro do pastel
//
// Depois, abra o arquivo para leitura e leia caractere por caractere com
// fgetc, contando linhas, palavras e caracteres (bytes). Mostre:
//
//   Linhas: 3
//   Palavras: 10
//   Caracteres: 53
//
// Dicas:
// 1. A variável que recebe o fgetc precisa ser int, não char: o EOF não é um
//    caractere, é um valor fora da faixa de 0 a 255.
// 2. Cada '\n' é uma linha. Uma palavra começa quando você estava fora de
//    palavra e chega num caractere que não é espaço nem '\n' (use isspace de
//    <ctype.h> e uma flag dentro_palavra).
// 3. Resposta esperada: Linhas: 3, Palavras: 10, Caracteres: 53 (16 + 12 + 22
//    letras e espaços, mais os 3 '\n'). Confira com: wc /tmp/recado.txt
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {

    return 0;
}

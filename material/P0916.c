// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0916 · ★★☆ · A linha mais comprida do poema
//
// Grave em /tmp/p0916_poema.txt estas quatro linhas:
//
//   Choveu em Manaus
//   o rio subiu devagar
//   e a balsa atrasou
//   fim
//
// Depois leia o arquivo com fgets e mostre qual é a linha mais comprida e
// qual é a mais curta (número da linha, tamanho sem o '\n' e o texto).
// Apague o arquivo no fim.
//
//   Saída esperada:
//   Mais comprida: linha 2 (19 caracteres): o rio subiu devagar
//   Mais curta: linha 4 (3 caracteres): fim
//
// Dicas:
// 1. Guarde o texto da maior e da menor em dois vetores de char com strcpy,
//    porque o vetor da leitura é sobrescrito a cada fgets.
// 2. Tire o '\n' com linha[strcspn(linha, "\n")] = '\0' antes de medir.
// 3. Resposta esperada: linha 2 com 19 caracteres e linha 4 com 3.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}

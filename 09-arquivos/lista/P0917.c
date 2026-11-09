// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0917 · ★★☆ · Virar o arquivo do avesso no lugar
//
// O medidor de pressão gravou 6 leituras em /tmp/p0917_pressao.bin, em
// binário: 120, 118, 125, 130, 122 e 119. Inverta a ordem DENTRO do próprio
// arquivo, sem carregar tudo num vetor: abra com "rb+" e, para cada i de 0
// até n/2 - 1, leia o registro i e o registro n-1-i e grave cada um no
// lugar do outro. Mostre o arquivo antes e depois.
//
//   Saída esperada:
//   Antes:  120 118 125 130 122 119
//   Depois: 119 122 130 125 118 120
//
// Dicas:
// 1. Escreva duas funções pequenas: int le(FILE *arq, int i) e
//    void grava(FILE *arq, int i, int valor), cada uma com um fseek para
//    i * sizeof(int) antes do fread ou fwrite.
// 2. Num arquivo aberto com "+", sempre faça um fseek entre uma leitura e
//    uma escrita: a regra do C exige isso para trocar de direção.
// 3. Resposta esperada: Depois: 119 122 130 125 118 120 (só 3 trocas para
//    6 registros).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

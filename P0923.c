// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0923 · ★★★ · O índice de linhas do cardápio
//
// Num arquivo texto, cada linha tem um tamanho, então não dá para calcular
// onde começa a linha k como num arquivo de registros. Mas dá para montar um
// ÍNDICE: leia o arquivo uma vez e anote, num vetor de long, a posição
// (ftell) do começo de cada linha. Depois, qualquer linha é um fseek e um
// fgets, sem reler o arquivo.
//
// Grave em /tmp/p0923_cardapio.txt estas 6 linhas:
//
//   Tacaca na esquina
//   Pirarucu de casaca
//   Tucupi no pato
//   Bolo de macaxeira
//   Cupuacu gelado
//   Pupunha com cafe
//
// Monte o índice (no máximo 100 linhas) e mostre as linhas 5, 2, 6 e 9,
// nesta ordem, com o byte onde cada uma começa. Apague o arquivo no fim.
//
//   Saída esperada:
//   6 linhas indexadas
//   Linha 5 (byte 70): Cupuacu gelado
//   Linha 2 (byte 18): Pirarucu de casaca
//   Linha 6 (byte 85): Pupunha com cafe
//   Linha 9: não existe
//
// Dicas:
// 1. Antes de cada fgets da primeira passada, pos[n] = ftell(arq).
// 2. Para mostrar a linha k: fseek(arq, pos[k - 1], SEEK_SET) e um fgets.
// 3. A linha 2 começa no byte 18 porque a linha 1 tem 17 letras mais o '\n'.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}

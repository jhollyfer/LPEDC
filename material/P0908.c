// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0908 · ★☆☆ · Pulando de dois em dois no arquivo
//
// Grave em /tmp/p0908_quadrados.bin, em binário, os quadrados de 1 a 10
// (1, 4, 9, ..., 100) como int. Depois leia SÓ os que estão nas posições
// ímpares da contagem humana (1º, 3º, 5º, 7º e 9º): leia um com fread e
// pule o seguinte com fseek a partir da posição atual. Mostre os lidos e
// quantos foram.
//
//   Saída esperada:
//   1 9 25 49 81
//   Lidos: 5
//
// Dicas:
// 1. Depois de cada fread de um int, o arquivo já andou 4 bytes. Para pular
//    o próximo, fseek(arq, sizeof(int), SEEK_CUR).
// 2. O laço pode ser while (fread(&x, sizeof x, 1, arq) == 1): quando o
//    fseek passa do fim, o fread seguinte devolve 0 e o laço para.
// 3. Resposta esperada: 1 9 25 49 81 e Lidos: 5.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

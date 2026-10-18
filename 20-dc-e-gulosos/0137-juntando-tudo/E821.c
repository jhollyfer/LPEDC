// 0137 · Juntando tudo
// Exercício E821 · ★★★
//
// O cabeçalho do .huf guarda as 256 frequências, 1024 bytes, mesmo quando
// o texto usa só 5 símbolos. Escreva um cabeçalho compacto e confira a ida
// e volta, com as frequências de "BANANA NA CABANA":
//
// - grave num arquivo "cab.bin" quantos símbolos aparecem (um uint16_t) e,
//   para cada um, o byte (1 byte) e a frequência (um uint32_t);
// - leia de volta num vetor uint32_t lida[256] zerado e compare com o
//   original usando memcmp;
// - mostre quantos símbolos, o tamanho do cabeçalho (ftell antes de
//   fechar) e se as frequências voltaram iguais. Apague o arquivo no fim.
//
//   Saída esperada:
//   Símbolos: 5
//   Cabeçalho compacto: 27 bytes (o completo tem 1024)
//   Frequências iguais
//
// Dicas:
// 1. fwrite(&k, sizeof k, 1, f) grava os 2 bytes do uint16_t; para o
//    símbolo, use um unsigned char e fwrite de 1 byte.
// 2. Na leitura, confira o retorno de cada fread (tem que ser 1).
// 3. Resposta esperada: a saída acima: 2 + 5 × (1 + 4) = 27 bytes. Com os
//    256 símbolos presentes, o compacto daria 2 + 256 × 5 = 1282 bytes, mais
//    que o completo: um formato bom escolhe o menor dos dois.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(void) {

    return 0;
}

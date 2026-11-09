// Lista · Módulo 08 · Tipos compostos
// Exercício P0828 · ★★★ · O cabeçalho do pacote em 32 bits
//
// Um protocolo de sensores sem fio manda, antes de cada pacote, um cabeçalho
// de 32 bits com quatro campos:
//
//   bits 31-28: versão (4 bits)    bits 27-24: tipo (4 bits)
//   bits 23-16: tamanho (8 bits)   bits 15-0:  id (16 bits)
//
// Crie typedef struct { unsigned versao, tipo, tamanho, id; } Cabecalho; e
// escreva:
//
//   bool empacotar(const Cabecalho *c, uint32_t *saida); // false: não cabe
//   Cabecalho desempacotar(uint32_t x);
//
// Empacote os três cabeçalhos abaixo, mostre em hexa, desempacote e confira
// que voltou igual. O terceiro tem tamanho 300, que não cabe em 8 bits:
// empacotar recusa. Por fim, compare com uma struct de CAMPOS DE BITS
// (unsigned versao : 4; ...), em que o compilador faz os deslocamentos, e
// mostre o sizeof das duas:
//
//   {2, 5, 64, 1027}   {15, 0, 255, 65535}   {1, 3, 300, 7}
//
//   Saída esperada:
//   {2, 5, 64, 1027} -> 0x25400403 -> {2, 5, 64, 1027} ok
//   {15, 0, 255, 65535} -> 0xF0FFFFFF -> {15, 0, 255, 65535} ok
//   {1, 3, 300, 7} -> recusado: campo grande demais
//   Campos de bits: {2, 5, 64, 1027}
//   sizeof(Cabecalho) = 16, sizeof(Compacto) = 4
//
// Dicas:
// 1. Empacotar: ((uint32_t) v << 28) | ((uint32_t) t << 24) | ((uint32_t)
//    tam << 16) | id. Antes, recuse se v > 0xF, t > 0xF, tam > 0xFF ou id >
//    0xFFFF.
// 2. Desempacotar: versao = (x >> 28) & 0xF; tipo = (x >> 24) & 0xF;
//    tamanho = (x >> 16) & 0xFF; id = x & 0xFFFF.
// 3. Campos de bits: typedef struct { unsigned id : 16; unsigned tamanho : 8;
//    unsigned tipo : 4; unsigned versao : 4; } Compacto; A ordem dos bits
//    dentro da palavra depende do compilador: para mandar pela rede, as
//    contas com << e >> são as que você controla.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(void) {

    return 0;
}

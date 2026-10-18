// 0137 · Juntando tudo
// Exercício E817 · ★☆☆
//
// O restaurante por quilo guarda o cardápio de cada semana num arquivo. Use
// o TAD compactador.h da pasta: grave o cardápio abaixo 30 vezes seguidas
// num arquivo "cardapio.txt", compacte para "cardapio.huf", descompacte
// para "cardapio2.txt" e mostre os três tamanhos. No fim, apague os três
// arquivos com remove.
//
//   PRATO DO DIA
//   Segunda: feijoada com couve e laranja
//   Terça: frango assado com farofa
//   Quarta: feijoada com couve e laranja
//   Quinta: peixe com pirão
//   Sexta: feijoada com couve e laranja
//
//   Saída esperada:
//   Original:      5460 bytes
//   Compactado:    4096 bytes (75.0%)
//   Descompactado: 5460 bytes
//
// Dicas:
// 1. Guarde o cardápio numa string só, com os "\n" no fim de cada linha, e
//    grave com fputs dentro de um for de 30 voltas.
// 2. arq_tamanho, huf_compacta e huf_descompacta devolvem tamanhos em
//    bytes (ou -1 se der erro).
// 3. Resposta esperada: a saída acima. Os acentos contam 2 bytes cada em
//    UTF-8; por isso cada cardápio tem 182 bytes, e não 180.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "compactador.h"

int main(void) {

    return 0;
}

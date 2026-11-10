// 0136 · Código de Huffman
// Exercício E813 · ★★☆
//
// Chegou uma mensagem compactada, junto com a TABELA de códigos (sem a
// árvore). Decodifique usando só a tabela:
//
//   E 00   S 01   T 100   O 101   U 1100   espaço 1101   B 1110   M 1111
//
//   Bits: 0001100101110011011110001111
//
// Como o código é livre de prefixo, dá para ler assim: vá juntando os bits
// num buffer, um por um; a cada bit, compare o buffer com todos os códigos
// (strcmp). Quando bater, escreva o símbolo e esvazie o buffer. No fim, se
// sobrar algo no buffer, avise.
//
//   Saída esperada:
//   Mensagem: ESTOU BEM
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    // a tabela de códigos que veio junto com a mensagem
    char simbolo[] = {'E', 'S', 'T', 'O', 'U', ' ', 'B', 'M'};
    const char *codigo[] = {"00", "01", "100", "101", "1100", "1101", "1110", "1111"};
    int k = 8;
    const char *bits = "0001100101110011011110001111";
    (void)simbolo;
    (void)codigo;
    (void)k;
    (void)bits;

    return 0;
}

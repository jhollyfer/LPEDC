// Lista · Módulo 06 · Ponteiros
// Exercício P0604 · ★☆☆ · A placa no padrão Mercosul
//
// O despachante digitou as placas em minúsculas. Escreva void maiusculas(char
// *s), que passa a string para maiúsculas andando com o próprio ponteiro s
// até o '\0' (sem índice), e bool padrao_mercosul(const char *p), que confere
// o formato LLLNLNN (3 letras, 1 dígito, 1 letra, 2 dígitos). Teste:
//
//   char placas[3][8] = {"rio2a18", "abc1234", "qxz9b07"};
//
//   Saída esperada:
//   RIO2A18: Mercosul
//   ABC1234: modelo antigo
//   QXZ9B07: Mercosul
//
// Dicas:
// 1. while (*s != '\0') { *s = toupper((unsigned char) *s); s++; } — dentro
//    da função, s é uma CÓPIA do endereço: andar com ela não estraga o
//    ponteiro do main.
// 2. No padrao_mercosul, confira cada posição com isalpha ou isdigit:
//    p[0], p[1], p[2] letras; p[3] dígito; p[4] letra; p[5], p[6] dígitos;
//    e p[7] tem que ser o '\0'.
// 3. Não dá para passar um literal ("abc1234") para maiusculas: literal é só
//    de leitura. Por isso as placas estão num vetor de char.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    char placas[3][8] = {"rio2a18", "abc1234", "qxz9b07"};
    (void) placas; // apague esta linha quando escrever

    return 0;
}

// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0520 · ★★☆ · O meu atoi
//
// O extrato do banco chegou como texto, e cada lançamento é uma string:
//
//   char lanc[5][8] = {"1200", "-350", "+80", "-1045", "75"};
//
// Escreva int texto_para_int(const char s[]), que converte a string em int
// SEM usar atoi nem sscanf: aceita um sinal opcional (+ ou -) no começo e
// para no primeiro caractere que não é dígito. Mostre cada valor convertido
// e o saldo final (a soma de todos):
//
//   Saída esperada:
//   "1200" -> 1200
//   "-350" -> -350
//   "+80" -> 80
//   "-1045" -> -1045
//   "75" -> 75
//   Saldo: -40
//
// Dicas:
// 1. Um char dígito vira número com s[i] - '0' (o '7' vale 55 na tabela
//    ASCII, o '0' vale 48: 55 - 48 = 7).
// 2. Para juntar os dígitos: valor = valor * 10 + (s[i] - '0'). "1200" passa
//    por 1, 12, 120, 1200.
// 3. Guarde o sinal numa variável (1 ou -1) e multiplique no fim.
// 4. Resposta esperada: a saída acima (saldo -40).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char lanc[5][8] = {"1200", "-350", "+80", "-1045", "75"};
    (void) lanc; // apague esta linha quando escrever

    return 0;
}

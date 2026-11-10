// Lista · Módulo 07 · Memória dinâmica
// Exercício P0724 · ★★★ · Multiplicar números que não cabem em nenhum tipo
//
// Escreva char *multiplicar(const char *a, const char *b), que recebe dois
// números naturais como strings de dígitos, de qualquer tamanho, e devolve o
// produto numa string nova no heap, sem zeros à esquerda. Faça como na conta
// à mão: o dígito i de a (contado da direita) vezes o dígito j de b vai para
// a casa i + j de um vetor de int alocado com calloc, e depois se acertam os
// "vai um". Teste:
//
//   "12" x "34"
//   "99999999999" x "99999999999"
//   "123456789012345678901234567890" x "987654321"
//   "2026" x "0"
//
//   Saída esperada:
//   12 x 34 =
//     408 (tamanho 3)
//   99999999999 x 99999999999 =
//     9999999999800000000001 (tamanho 22)
//   123456789012345678901234567890 x 987654321 =
//     121932631124828532112482853211126352690 (tamanho 39)
//   2026 x 0 =
//     0 (tamanho 1)
//
// Dicas:
// 1. O produto de um número de na dígitos por um de nb tem no máximo
//    na + nb dígitos: int *casas = calloc(na + nb, sizeof *casas);
// 2. Com os índices da direita: da = a[na - 1 - i] - '0', db = b[nb - 1 -
//    j] - '0', e casas[i + j] += da * db.
// 3. Depois, de 0 a na + nb - 2: casas[k + 1] += casas[k] / 10;
//    casas[k] %= 10.
// 4. Ache o dígito mais alto que não é zero (se todos forem zero, a resposta
//    é "0"), aloque a string e escreva do mais alto para o mais baixo.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}

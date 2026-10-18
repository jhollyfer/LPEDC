// 0160 · Rabin-Karp
// Exercício E955 · ★☆☆
//
// A data de hoje sem as barras é "18102026". Escreva
// int hash_digitos(const char *s, int m, int q), que devolve o número formado
// pelos m primeiros dígitos de s, mod q, sem nunca montar o número inteiro
// (regra de Horner, tirando o resto a cada passo). Mostre o hash, com q = 97,
// de cada janela de 4 dígitos, calculando cada uma do zero:
//
//   Saída esperada:
//   1810 -> 64
//   8102 -> 51
//   1020 -> 50
//   0202 ->  8
//   2026 -> 86
//
// Dicas:
// 1. Horner: h = (h * 10 + dígito) % q, para cada dígito, da esquerda para a
//    direita. O dígito é s[j] - '0'.
// 2. Tirar o resto a cada passo dá o mesmo que tirar só no fim, e o h nunca
//    passa de 10 * q. É o que deixa usar janelas enormes sem estourar o int.
// 3. Passe data + i para a função: o ponteiro já começa na janela.
// 4. Resposta esperada: a saída acima (1810 = 18 * 97 + 64).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}

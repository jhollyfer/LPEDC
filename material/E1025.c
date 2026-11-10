// 0171 · Com sinal e sem sinal
// Exercício E1025 · ★★★
//
// Um leitor de código de barras manda os bytes de um boleto e, no fim, um
// byte verificador: o número que, somado a todos os bytes, dá 0 módulo 256.
// Escreva:
//
//   - unsigned char verificador(const unsigned char *d, size_t n);
//   - bool confere(const unsigned char *d, size_t n, unsigned char v), que
//     soma os bytes e o v e diz se o byte da soma é 0.
//
// Teste com os bytes {0x12, 0xA0, 0xFF, 0x31} e depois troque o 0xA0 por
// 0xA1, como se um bit tivesse se perdido na transmissão.
//
//   Saída esperada:
//   verificador = 0x1E
//   original: confere
//   alterado: nao confere
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

int main(void) {

    return 0;
}

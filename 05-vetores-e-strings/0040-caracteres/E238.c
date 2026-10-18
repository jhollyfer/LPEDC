// 0040 · Caracteres
// Exercício E238 · ★★☆
//
// Um formulário pede o CEP. A pessoa pode digitar com ou sem o traço:
// "69050-010" e "69050010" valem. Leia a linha caractere por caractere com
// getchar, até o Enter (ou EOF), e:
//
//   - guarde os dígitos num vetor char cep[8];
//   - ignore o '-';
//   - qualquer outro caractere torna o CEP inválido;
//   - o CEP só é válido com exatamente 8 dígitos.
//
//   Exemplo de execução (válido):
//   CEP: 69050-010
//   CEP válido: 69050010
//
//   Exemplo de execução (inválido):
//   CEP: 6905-00100
//   CEP inválido.
//
// Dicas:
// 1. int c; while ((c = getchar()) != '\n' && c != EOF) { ... }
// 2. Conte os dígitos, mas só guarde no vetor enquanto couber (contador < 8).
//    Se você guardar sem olhar, um CEP de 12 dígitos escreve fora do vetor.
// 3. isdigit(c) responde se é dígito.
// 4. Resposta esperada: as duas execuções acima ("6905-00100" tem 9 dígitos).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {

    return 0;
}

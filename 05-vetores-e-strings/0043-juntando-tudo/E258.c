// 0043 · Juntando tudo
// Exercício E258 · ★★★
//
// Compressão RLE (run-length encoding): cada sequência de letras repetidas
// vira a letra seguida de quantas vezes ela aparece. "aaabccdddd" vira
// "a3b1c2d4". Para simplificar, a contagem é sempre um dígito só: uma
// sequência de mais de 9 vira pedaços de 9 ("zzzzzzzzzzzz", 12 z, vira
// "z9z3").
//
// Leia uma linha com fgets, tire o '\n', comprima numa string saida[] e
// mostre o resultado e os tamanhos. Se a versão comprimida não for menor,
// avise que não compensa.
//
//   Exemplo de execução 1:
//   Texto: aaabccdddd
//   a3b1c2d4 (10 -> 8)
//
//   Exemplo de execução 2:
//   Texto: abc
//   a1b1c1 (3 -> 6): não compensa
//
//   Exemplo de execução 3:
//   Texto: zzzzzzzzzzzz
//   z9z3 (12 -> 4)
//
// Dicas:
// 1. Escreva void comprimir(const char texto[], char saida[]). Use dois
//    índices: i anda no texto, j marca onde escrever na saída.
// 2. Para cada posição, conte quantas vezes texto[i] se repete a partir dali
//    (no máximo 9). Escreva a letra, depois o dígito: (char) ('0' + conta).
//    Avance i pela quantidade contada.
// 3. No pior caso a saída tem o dobro do tamanho do texto (abc vira a1b1c1):
//    dimensione saida com 2 * tamanho do texto + 1. E feche com '\0'.
// 4. Resposta esperada: as três execuções acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define TAM_TEXTO 100

int main(void) {

    return 0;
}

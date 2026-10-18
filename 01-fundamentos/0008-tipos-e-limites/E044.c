// 0008 · Tipos e limites
// Exercício E044 · ★☆☆
//
// Escolha o MENOR tipo inteiro que guarda cada dado com folga e declare uma
// variável para cada um, com o valor indicado. Mostre todas com printf.
//
//   a) idade de uma pessoa (34)
//   b) temperatura mínima em São Joaquim, SC, em graus (-8)
//   c) população do Brasil (203080756)
//   d) tamanho de um arquivo de vídeo de 5 GB, em bytes (5368709120)
//   e) ano de nascimento (1991)
//
//   Saída esperada:
//   idade: 34
//   temperatura: -8
//   população: 203080756
//   arquivo: 5368709120 bytes
//   ano: 1991
//
// Dicas:
// 1. Confira os limites na tabela do texto ou rodando o A016.
// 2. short vai até 32767; int até uns 2,1 bilhões; acima disso, long long.
// 3. Resposta esperada: a) signed char ou int8_t (até 127) serve; short
//    também; b) signed char/int8_t (aceita negativo); c) int (cabe com folga
//    até 2,1 bilhões); d) long long ou int64_t (passa de 4,2 bilhões, nem
//    unsigned int serve); e) short. Na prática, int é o padrão para
//    inteiros pequenos: economize só quando tiver milhões deles.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdint.h>

int main(void) {

    return 0;
}

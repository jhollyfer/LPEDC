// 0060 · calloc e realloc
// Exercício E358 · ★★☆
//
// Um sensor de umidade mandou 10 leituras, mas -1 significa "falha na
// leitura": 12, -1, 15, 14, -1, -1, 13, 16, -1, 11. Copie as leituras para
// um bloco do heap, remova as falhas puxando as válidas para a frente (no
// mesmo bloco) e depois ENCOLHA o bloco com realloc para o tamanho exato.
//
//   Saída esperada:
//   6 leituras válidas: 12 15 14 13 16 11
//   Bloco encolheu de 40 para 24 bytes
//
// Dicas:
// 1. Ande com dois índices: i lê todas as posições, j marca onde escrever a
//    próxima válida. No fim, j é a quantidade de válidas.
// 2. realloc também diminui: realloc(v, j * sizeof *v). Use temporário.
// 3. Resposta esperada: a saída acima. Encolher preserva as primeiras j
//    posições, exatamente as válidas.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}

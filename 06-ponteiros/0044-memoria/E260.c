// 0044 · Memória e endereços
// Exercício E260 · ★☆☆
//
// O placar eletrônico do estádio guarda três dados de um time: os gols
// (int, 3), a média de gols por jogo (double, 1.5) e o resultado da
// partida (char, 'V'). Escreva um programa que monte o "gaveteiro" dessas
// variáveis: uma linha por variável, com o nome, o valor, o endereço e
// quantos bytes ela ocupa. No fim, mostre quantos bytes as três ocupam
// juntas, somando os sizeof.
//
//   Saída esperada (os endereços mudam a cada execução):
//   gols   = 3   em 0x7f..., 4 bytes
//   media  = 1.5 em 0x7f..., 8 bytes
//   result = V   em 0x7f..., 1 bytes
//   total: 13 bytes
//
// Dicas:
// 1. O endereço sai com %p e (void *)&nome; o tamanho, com %zu e sizeof.
// 2. sizeof dá um size_t: guarde a soma numa variável size_t e mostre
//    com %zu.
// 3. Resposta esperada: os tamanhos 4, 8 e 1 e a linha "total: 13 bytes";
//    os endereços aparecem em hexadecimal e mudam a cada vez que você roda.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

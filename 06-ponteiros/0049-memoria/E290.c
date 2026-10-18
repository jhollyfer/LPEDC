// 0049 · Memória e endereços
// Exercício E290 · ★☆☆
//
// Olhe este gaveteiro (endereços fictícios) de um programa de futebol e
// responda sem rodar nada:
//
//   endereço   conteúdo   variável
//   0x2000     3          gols   (int)
//   0x2004     (livre)
//   0x2008     1.5        media  (double)
//   0x2010     'V'        result (char)
//
//   a) Quanto vale gols? E &gols?
//   b) Quanto vale &media?
//   c) media ocupa 8 bytes. Qual é o endereço do último byte dela?
//   d) Que bytes a variável gols ocupa?
//   e) Rodando o programa de novo, &gols continua 0x2000?
//
// Depois, escreva o programa com as três variáveis e mostre os endereços
// reais com %p.
//
// Dicas:
// 1. O endereço de uma variável é o da primeira gaveta dela.
// 2. Do 0x2008 andando 8 gavetas, a última é 0x2008 + 7.
// 3. Resposta esperada: a) 3 e 0x2000; b) 0x2008; c) 0x200F;
//    d) 0x2000, 0x2001, 0x2002 e 0x2003; e) não: o sistema sorteia os
//    endereços a cada execução (ASLR).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

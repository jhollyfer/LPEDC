// 0121 · Radix sort
// Exercício E722 · ★☆☆
//
// A transportadora separa as encomendas pelo começo do CEP (5 dígitos).
// Ordene os 7 prefixos com o radix sort LSD em base 10 e mostre o vetor
// depois de cada passada. Mostre os números com %05d: o prefixo 01310 é
// guardado como o int 1310, mas continua tendo 5 dígitos para o carteiro.
//
//   Saída esperada:
//   início:      69050 13083 69005 01310 40140 13010 88015
//   exp =     1: 69050 01310 40140 13010 13083 69005 88015
//   exp =    10: 69005 01310 13010 88015 40140 69050 13083
//   exp =   100: 69005 13010 88015 69050 13083 40140 01310
//   exp =  1000: 40140 01310 13010 13083 88015 69005 69050
//   exp = 10000: 01310 13010 13083 40140 69005 69050 88015
//
// Dicas:
// 1. A passada é a do texto. O vetor auxiliar pode ser um int aux[7]
//    comum, porque n é fixo.
// 2. O maior é 88015, então são 5 passadas. O 1310 tem só 4 dígitos "de
//    verdade", mas na quinta passada o dígito dele é 0, e ele vai para a
//    frente.
// 3. Formato das linhas: "exp = %5d:" seguido de " %05d" para cada número.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int ceps[] = {69050, 13083, 69005, 1310, 40140, 13010, 88015};
    int n = 7;
    (void) ceps; // apague estas duas linhas
    (void) n;

    return 0;
}

// 0006 · O primeiro programa
// Exercício E034 · ★★☆
//
// Escreva um programa que mostre só "Bom dia" (com \n). Depois, dentro
// desta pasta, rode cada estação separada e responda como comentário:
//
//   gcc -E E034.c | wc -l
//   gcc -S E034.c
//   gcc -c E034.c
//   gcc E034.o -o bomdia && ./bomdia
//
// a) Quantas linhas o arquivo tem depois do pré-processador? De onde veio
//    tanta linha? O que aconteceu com os comentários?
// b) Abra o E034.s. Que função aparece depois de "call": printf ou puts?
// c) Troque o texto por printf("Bom dia %d\n", 7); e gere o .s de novo.
//    Mudou? Por quê?
// d) Que arquivos novos apareceram na pasta, e qual deles roda?
//
// Dicas:
// 1. O wc -l conta linhas. Procure "printf" no resultado do gcc -E.
// 2. O texto fixo fica numa linha .string do .s, com uma etiqueta como .LC0.
// 3. Resposta esperada: a) algumas centenas (uns 700 a 900, depende do
//    sistema): é o stdio.h colado no lugar do #include; os comentários
//    somem; b) puts: o texto é fixo e termina em \n, então o compilador troca
//    por uma função mais simples; c) com o %d ele precisa formatar e volta a
//    chamar printf; d) E034.s (assembly, texto), E034.o (objeto, binário) e
//    bomdia (o executável, o único que roda).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

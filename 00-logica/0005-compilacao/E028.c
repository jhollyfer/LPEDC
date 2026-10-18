// 0005 · Do .c ao executável
// Exercício E028 · ★★☆
//
// Escreva um programa que mostre "Bom dia" (só isso, com \n). Gere o assembly
// com "gcc -S E028.c" e abra o arquivo E028.s. Responda:
//
// a) Em que linha aparece o texto "Bom dia"?
// b) Que função é chamada: printf ou puts? Por quê?
// c) Agora troque por printf("Bom dia %d\n", 7); gere de novo. Mudou?
//
// Dicas:
// 1. O texto fica numa seção de dados, com uma etiqueta como .LC0.
// 2. Procure a palavra "call".
// 3. Resposta esperada: a) numa linha .string "Bom dia" (sem o \n);
//    b) puts: o texto é fixo e termina em \n, então o compilador troca por
//    puts, que é mais simples; c) com o %d ele precisa formatar, então volta a
//    chamar printf.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

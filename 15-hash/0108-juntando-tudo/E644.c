// 0108 · Juntando tudo: o contador de palavras
// Exercício E644 · ★☆☆
//
// Um contador de palavras usa 4 baldes, encadeamento com inserção no início
// e a função hash "soma dos códigos % 4". Os códigos: 'o' = 111, 'v' = 118,
// 's' = 115, 'a' = 97, 'l' = 108, 'm' = 109, 'e' = 101. Sem rodar, diga o
// que ele mostra depois de contar, nesta ordem:
//
//   ovo  sal  mel  las  sal
//
// O programa mostra cada balde assim: [0] palavra:vezes palavra:vezes ...
//
// Dicas:
// 1. ovo = 340, sal = 320, mel = 318, las = 320. Agora tire o resto por 4.
// 2. O segundo "sal" não cria nó: acha o que existe e soma 1.
// 3. Resposta esperada: [0] las:1 sal:2 ovo:1; [1] vazio; [2] mel:1;
//    [3] vazio. "las" e "sal" são anagramas e a soma junta os dois no mesmo
//    balde; o strcmp é que separa as contagens.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

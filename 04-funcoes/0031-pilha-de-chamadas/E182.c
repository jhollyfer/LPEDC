// 0031 · A pilha de chamadas
// Exercício E182 · ★☆☆
//
// Escreva três funções void, a, b e c, que se chamam assim:
//
//   c mostra "c (vez N)", em que N conta quantas vezes c já rodou;
//   b mostra "b começa", chama c e mostra "b termina";
//   a mostra "a começa", chama b, chama c e mostra "a termina".
//
// O main chama a e depois c.
//
//   Saída esperada:
//   a começa
//   b começa
//   c (vez 1)
//   b termina
//   c (vez 2)
//   a termina
//   c (vez 3)
//
// Dicas:
// 1. Uma função só continua depois que a função que ela chamou retornou: por
//    isso "b termina" vem depois do c.
// 2. O contador de c é uma static int vezes = 0; dentro dela (assunto 0030).
// 3. Resposta esperada: a saída acima. O ponto mais fundo é main -> a -> b
//    -> c: quatro quadros na pilha ao mesmo tempo.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

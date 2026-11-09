// 0179 · Sondagem quadrática e dupla
// Exercício E1074 · ★★★
//
// Escreva, sem o TAD, uma tabela de dispersão dupla que cresce: um vetor de
// int (-1 livre), m primo, h1 = k % m e h2 = 1 + k % (m - 1). Antes de
// inserir, se (n + 1) / m passar de 0.5, ela cresce para o menor primo >=
// 2m, reinsere as chaves antigas (com o m novo, as posições mudam) e mostra
// "cresceu: m = ... -> ... (n = ...)". Comece com m = 7, insira as chaves
// 7919 * i % 100000, para i de 0 a 39, e no fim mostre n, m, a carga e a
// média de sondagens para achar cada uma das 40 chaves. Libere o vetor.
//
//   Saída esperada:
//   cresceu: m = 7 -> 17 (n = 3)
//   cresceu: m = 17 -> 37 (n = 8)
//   cresceu: m = 37 -> 79 (n = 18)
//   cresceu: m = 79 -> 163 (n = 39)
//   fim: n = 40, m = 163, carga 0.25, média de sondagens 1.38
//
// Dicas:
// 1. Separe coloca(t, k), que insere sem olhar a carga, de insere(t, k), que
//    cresce se precisar e chama coloca.
// 2. Para crescer: guarde o vetor velho, crie o novo cheio de -1, zere n,
//    coloque de volta cada chave >= 0 e libere o velho.
// 3. Resposta esperada: a saída acima. Na reconstrução as lápides (se
//    houvesse) ficariam para trás de graça.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}

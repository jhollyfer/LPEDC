// 0189 · Juntando tudo
// Exercício E1131 · ★★☆
//
// Confira o Held-Karp do texto pela força bruta das permutações (0126):
// escreva void permuta(int pos, int acum, bool poda), que monta todas as
// rotas a partir da farmácia (rota[0] = 0) para os mesmos oito pontos do
// texto, guarda o menor custo em melhor e conta as chamadas e as rotas
// completas. Com poda = true, a função volta logo no começo se acum já
// chegou a melhor (branch and bound, 0127). Rode as duas versões.
//
//   Saída esperada:
//   Sem poda: ótimo 28, 5040 rotas completas, 13700 chamadas
//   Com poda: ótimo 28, 110 rotas completas, 6977 chamadas
//
// Dicas:
// 1. Conte a chamada na primeira linha da função, antes do teste da poda.
//    Uma rota é completa quando pos == N; aí some a volta d[rota[N-1]][0].
// 2. Tente os vizinhos v = 1 a N - 1 em ordem, com usado[] e desfazendo
//    a marca na volta. Zere melhor (1 << 30) e os contadores entre as duas
//    rodadas.
// 3. Resposta esperada: a saída acima. Sem poda são (8 - 1)! = 5040 rotas;
//    a poda corta metade das chamadas, mas continua exponencial.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}

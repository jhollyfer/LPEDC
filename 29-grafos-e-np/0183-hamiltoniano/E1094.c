// 0183 · Hamiltoniano
// Exercício E1094 · ★☆☆
//
// A gravata do A365 (Mirante, Cachoeira, Gruta, Lagoa, Pedra; trilhas
// Mirante-Cachoeira, Cachoeira-Gruta, Gruta-Mirante, Mirante-Lagoa,
// Lagoa-Pedra, Pedra-Mirante) não tem ciclo hamiltoniano. Mas talvez tenha
// CAMINHO hamiltoniano: passar por todos os pontos uma vez, sem voltar.
// Escreva o backtracking caminho(pos) e tente cada ponto de partida, em
// ordem de índice, até achar um. Mostre as tentativas.
//
//   Saída esperada:
//   Começando em Mirante: não dá
//   Começando em Cachoeira: Cachoeira Gruta Mirante Lagoa Pedra
//
// Dicas:
// 1. Parta do hamilton do texto. Duas mudanças: quando pos == V, devolva
//    true direto (não há volta para conferir); e o laço dos vizinhos começa
//    no 0, porque o início não é mais fixo.
// 2. Para cada início, zere usado[], ponha rota[0] = inicio e marque-o.
// 3. Resposta esperada: a saída acima. O Mirante no meio do caminho é a
//    única saída: começando nele, você nunca volta ao outro triângulo.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}

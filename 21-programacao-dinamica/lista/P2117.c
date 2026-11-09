// Lista · Módulo 21 · Programação dinâmica
// Exercício P2117 · ★★☆ · Pagar com o mínimo de cédulas da carteira
//
// No troco mínimo do assunto 0139, cada moeda pode ser usada quantas vezes
// quiser. Na carteira não: há UMA cédula de cada. Você tem 50, 20, 20, 10,
// 5, 5, 2 e 2 reais e vai pagar R$ 64 exatos com o menor número de
// cédulas. Escreva do zero a PD 0/1: min[s] é o menor número de cédulas
// que soma s; para cada cédula, atualize min[s] de TRÁS PARA A FRENTE (como
// na mochila de uma linha), e guarde quem foi usada numa tabela usou[i][s]
// para reconstruir.
//
//   Saída esperada:
//   Mínimo: 4 cédulas
//   Cédulas: 2 2 10 50
//
// Dicas:
// 1. min[0] = 0 e o resto INF. Para a cédula i, de s = 64 até c[i]: se
//    min[s - c[i]] + 1 < min[s], atualize e marque usou[i][s] = 1.
// 2. Reconstrução: s = 64; para i de 7 até 0, se usou[i][s], a cédula i
//    entrou: s -= c[i]. (Isso funciona porque usou[i][s] guarda a decisão
//    tomada com as cédulas 0..i.)
// 3. Resposta esperada: 4 cédulas, 50 + 10 + 2 + 2.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

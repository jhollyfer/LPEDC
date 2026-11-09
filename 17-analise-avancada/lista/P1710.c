// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1710 · ★☆☆ · Adivinhe o preço: o limite da árvore de decisão
//
// No programa de auditório, o participante adivinha um preço inteiro de 1 a
// n reais, e o apresentador responde "é esse", "mais" ou "menos". Qualquer
// estratégia é uma árvore de decisão com n respostas possíveis; uma árvore
// binária de altura h tem no máximo 2^h - 1 nós de "é esse", então o pior
// caso precisa de pelo menos ⌈lg(n + 1)⌉ palpites.
//
// A busca binária atinge esse limite. Escreva:
//
//   int palpites(int n, int preco);   // palpites da busca binária até acertar
//   int teto_lg(int x);               // menor h com 2^h >= x, só com inteiros
//
// e mostre, para n = 7, 15, 100, 1000 e 1000000, o pior caso da busca
// binária (testando TODOS os preços de 1 a n) e o limite ⌈lg(n + 1)⌉.
//
//   Saída esperada:
//         n  pior caso  limite
//         7          3       3
//        15          4       4
//       100          7       7
//      1000         10      10
//   1000000         20      20
//
// Dicas:
// 1. palpites: ini = 1, fim = n; a cada volta, chute meio = (ini + fim) / 2
//    e conte 1; se acertou, pare; se o preço é maior, ini = meio + 1; senão,
//    fim = meio - 1.
// 2. teto_lg: h = 0, p = 1; enquanto p < x, p *= 2 e h++. Use long para p.
// 3. Com n = 1000000, testar todos os preços custa uns 20 milhões de passos:
//    roda em menos de um segundo.
// 4. Resposta esperada: as duas colunas são iguais; 3, 4, 7, 10 e 20.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2322 · ★★★ · Arbitragem na casa de câmbio
//
// A casa de câmbio publica quanto se recebe de cada moeda por 1 unidade de
// outra (Real, Dólar, Euro, Libra, Peso). ARBITRAGEM é uma volta de trocas
// que termina com mais dinheiro do que começou: o produto das taxas da
// volta passa de 1. O truque do Cormen: com peso -log(taxa), produto maior
// que 1 vira soma negativa, e arbitragem vira CICLO NEGATIVO.
//
// O main já tem as 20 taxas. Escreva analisa(rotulo, t, n) do zero:
// - Bellman-Ford com todas as distâncias começando em 0 (é como ter uma
//   origem imaginária ligada a todas as moedas) e um vetor ant[];
// - se a M-ésima rodada (a extra) ainda melhora alguém, guarde essa moeda
//   x, ande M passos por ant[] (assim você cai dentro do ciclo) e recolha
//   o ciclo seguindo ant[] até voltar em x;
// - mostre o ciclo na ordem das trocas e o fator (produto das taxas).
// Na terça a casa corrigiu Euro -> Real de 5.50 para 5.40.
//
//   Saída esperada:
//   Segunda-feira: arbitragem Dólar -> Euro -> Real -> Dólar
//     fator do ciclo: 1.0120 (lucro de 1.20%)
//   Terça-feira: sem arbitragem
//
// Dicas:
// 1. Compare com folga por causa do double: troque quando
//    dist[de] + w < dist[para] - 1e-12. Use log de <math.h>.
// 2. ant[] aponta para trás (de quem veio). Recolhendo x, ant[x],
//    ant[ant[x]]..., você tem o ciclo ao contrário: mostre de trás para
//    frente e, para cada par (de, para), multiplique a taxa da troca.
// 3. Resposta esperada: na segunda, Dólar -> Euro -> Real -> Dólar com
//    fator 1.0120 (0,92 × 5,50 × 0,20); na terça, sem arbitragem.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>

#define M 5
#define E 20

typedef struct {
    int de, para;
    double taxa;
} Troca;

const char *moedas[M] = {"Real", "Dólar", "Euro", "Libra", "Peso"};

int main(void) {
    Troca t[E] = {{0, 1, 0.20}, {1, 0, 4.95}, {0, 2, 0.18}, {2, 0, 5.50}, {0, 3, 0.155}, {3, 0, 6.30},
                  {1, 2, 0.92}, {2, 1, 1.07}, {1, 3, 0.78}, {3, 1, 1.26}, {2, 3, 0.85}, {3, 2, 1.16},
                  {0, 4, 210.0}, {4, 0, 0.0046}, {1, 4, 1000.0}, {4, 1, 0.00090}, {2, 4, 1080.0},
                  {4, 2, 0.00084}, {3, 4, 1260.0}, {4, 3, 0.00072}};
    printf("%s -> %s: %.2f\n", moedas[t[0].de], moedas[t[0].para], t[0].taxa);
    return 0;
}

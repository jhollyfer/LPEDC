// Lista · Módulo 16 · Grafos
// Exercício P1605 · ★☆☆ · O complemento: quem ainda precisa ser apresentado
//
// No coffee break de um congresso em Manaus, a organização quer apresentar
// quem ainda não se conhece. A matriz conhece[][] (não dirigida) diz quem já
// se conhece. O grafo das apresentações que faltam é o COMPLEMENTO: tem uma
// aresta i-j (com i != j) exatamente quando conhece[i][j] == 0.
//
// Escreva void complemento(int g[V][V], int c[V][V]) e um main que mostre,
// para cada pessoa, quem ela ainda precisa conhecer, o número de arestas dos
// dois grafos e a soma, que tem de dar o número de arestas do grafo completo.
//
//   Saída esperada:
//   Raimundo : Ubiratan Vania
//   Socorro  : Ubiratan Vania Wesley
//   Tiago    : Vania Wesley
//   Ubiratan : Raimundo Socorro Wesley
//   Vania    : Raimundo Socorro Tiago
//   Wesley   : Socorro Tiago Ubiratan
//   conhece: 7 | complemento: 8 | total: 15 = 6·5/2
//
// Dicas:
// 1. c[i][j] = (i != j && !g[i][j]). A diagonal fica 0: ninguém é
//    apresentado a si mesmo.
// 2. Toda aresta possível (são V(V - 1)/2) está em g ou em c, nunca nas duas.
// 3. Para mostrar "ninguém", use um contador por pessoa.
// 4. Resposta esperada: 7 arestas em conhece, 8 no complemento, 15 no total.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 6

const char *nomes[V] = {"Raimundo", "Socorro", "Tiago", "Ubiratan", "Vania", "Wesley"};
int conhece[V][V] = {
    {0, 1, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0},
    {1, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 0},
};

int main(void) {

    return 0;
}

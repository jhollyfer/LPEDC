// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2929 · ★★★ · Cobertura exata por ramificação
//
// A cobertura de vértices é NP-difícil, mas existe um truque quando a
// resposta k é pequena: pegue uma aresta descoberta u-v; alguma das pontas
// TEM de estar na cobertura. Então tente u (e resolva com k - 1) e, se não
// der, tente v. São no máximo 2^k ramos, não importa o tamanho do grafo.
// Num grafo de 12 vértices (0 a 11) com as arestas
//
//   0-1, 1-2, 2-3, 3-0, 4-5, 5-6, 6-4, 7-8, 8-9, 9-10, 10-11, 11-7, 0-4, 2-7
//
// escreva bool cobre(int k), que decide se existe cobertura de tamanho no
// máximo k, e ache o menor k testando k = 0, 1, 2, ... Conte as chamadas e
// compare com as 2^12 máscaras da força bruta. Mostre a cobertura achada.
//
//   Saída esperada:
//   Menor cobertura: 7 vértices: 0 2 4 5 7 8 10
//   Chamadas: 319 (força bruta: 4096 máscaras)
//
// Dicas:
// 1. Guarde em[] global. Em cobre(k): ache a primeira aresta (na ordem da
//    lista) sem ponta marcada; se não houver, devolva true. Se k == 0, false.
//    Senão marque u, chame cobre(k - 1), desmarque; depois o mesmo com v.
// 2. Ao achar a cobertura, não desmarque: devolva true direto, e em[] guarda a
//    resposta.
// 3. Resposta esperada: a saída acima. As chamadas somam todos os k testados,
//    e mesmo assim ficam bem abaixo de 4096.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}

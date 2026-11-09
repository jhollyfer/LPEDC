// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2328 · ★★★ · Três zonas de entrega
//
// Uma rede de farmácias vai dividir nove bairros em 3 zonas de entrega,
// com bairros parecidos juntos e zonas o mais separadas possível. As
// coordenadas (km) estão no main; a distância é a de quarteirão,
// |x1 - x2| + |y1 - y2|.
//
// O Kruskal resolve: ordene todos os pares pela distância e vá juntando
// grupos, mas PARE quando sobrarem 3. A próxima aresta que ligaria dois
// grupos diferentes é o ESPAÇAMENTO, a menor distância entre zonas, e
// esse corte é o que deixa o espaçamento máximo. Escreva do zero: monte as
// 36 arestas, ordene (empate: menor a, depois menor b), mostre as zonas
// (na ordem do primeiro bairro de cada uma) e o espaçamento.
//
//   Saída esperada:
//   Zona 1: Aleixo Flores Parque 10
//   Zona 2: Compensa Glória Santo Antônio
//   Zona 3: Japiim Coroado Distrito
//   Espaçamento: 4 km (Aleixo-Japiim)
//
// Dicas:
// 1. Use as coordenadas do esqueleto: x = {2, 3, 2, 10, 11, 9, 6, 7, 6} e
//    y = {9, 8, 7, 2, 3, 1, 9, 10, 11}, na ordem Aleixo, Flores, Parque 10,
//    Compensa, Glória, Santo Antônio, Japiim, Coroado, Distrito.
// 2. O desempate no comparador deixa a saída a mesma em qualquer máquina:
//    o qsort não garante a ordem de iguais.
// 3. Resposta esperada: Aleixo, Flores e Parque 10; Compensa, Glória e
//    Santo Antônio; Japiim, Coroado e Distrito; espaçamento 4 km
//    (Aleixo-Japiim).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define V 9

const char *bairros[V] = {"Aleixo", "Flores", "Parque 10", "Compensa", "Glória",
                          "Santo Antônio", "Japiim", "Coroado", "Distrito"};
int x[V] = {2, 3, 2, 10, 11, 9, 6, 7, 6};
int y[V] = {9, 8, 7, 2, 3, 1, 9, 10, 11};

int main(void) {
    printf("%s fica em (%d, %d)\n", bairros[0], x[0], y[0]);
    return 0;
}

// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2226 · ★★★ · Quantos metros acima?
//
// Uma equipe de topografia mede DIFERENÇAS de altitude entre marcos (0 a
// 6), nunca a altitude de um marco sozinho. Cada medição "a b d" quer dizer
// "b está d metros acima de a". Depois, perguntam a diferença entre dois
// marcos: se eles estão ligados por medições, dá para calcular; se não,
// "desconhecida". E se uma medição nova contradiz as anteriores, ela é
// rejeitada. Escreva do zero um UNION-FIND COM PESOS: além de pai[x],
// guarde dif[x] = altitude(x) - altitude(pai[x]). Na compressão de
// caminho, some as diferenças do caminho; na união, calcule a diferença
// entre as duas raízes.
//
//   Medições: 0 1 5   1 2 3   3 4 -2   2 3 4   0 4 10   5 6 7   0 2 9
//   Perguntas: 0 3   4 1   2 5   6 5
//
//   Saída esperada:
//   Medição 0 1 5: aceita
//   Medição 1 2 3: aceita
//   Medição 3 4 -2: aceita
//   Medição 2 3 4: aceita
//   Medição 0 4 10: aceita
//   Medição 5 6 7: aceita
//   Medição 0 2 9: rejeitada (contradiz)
//   0 -> 3: 12 m
//   4 -> 1: -5 m
//   2 -> 5: desconhecida
//   6 -> 5: -7 m
//
// Dicas:
// 1. acha(x): se pai[x] != x, r = acha(pai[x]); dif[x] += dif[pai[x]] (já
//    relativo à raiz); pai[x] = r. Assim dif[x] passa a ser altitude(x) -
//    altitude(raiz).
// 2. Medição "a b d" com raízes ra e rb diferentes: pendure rb em ra com
//    dif[rb] = dif[a] + d - dif[b]. Com raízes iguais, só confira se dif[b]
//    - dif[a] == d.
// 3. Resposta esperada: a medição 0 4 10 confere com as anteriores (5 + 3
//    + 4 - 2 = 10) e é aceita; a 0 2 9 contradiz (de 0 a 2 já dá 8 m) e é
//    rejeitada. Nas perguntas: 12 m, -5 m, desconhecida e -7 m.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

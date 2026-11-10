// Lista · Módulo 13 · Busca e ordenação
// Exercício P1322 · ★★★ · Três filiais, uma fila de pedidos
//
// Três filiais de uma pizzaria mandam os números dos pedidos já em ordem:
// Centro 3, 10, 21, 30; Norte 1, 12, 18; Sul 5, 7, 25, 40. A central quer uma
// fila só, em ordem. Faça de dois jeitos e conte as comparações entre
// elementos (variável global comparacoes):
//
// a) intercala3: olha as três frentes de uma vez e tira a menor. Use uma
//    função auxiliar menor(v, i, n, w, j, m) que devolve 1 se a fila v ainda
//    tem gente e (a fila w acabou ou v[i] <= w[j]); ela só conta comparação
//    quando as DUAS filas têm gente. A frente de a sai se for menor que a de
//    b E que a de c; senão sai a de b, se for menor que a de c; senão a de c.
// b) duas a duas: intercala Centro com Norte num vetor temporário e depois o
//    resultado com Sul, com a intercala2 de sempre.
//
//   Saída esperada:
//   de uma vez: 1 3 5 7 10 12 18 21 25 30 40
//   comparações: 19
//   duas a duas: 1 3 5 7 10 12 18 21 25 30 40
//   comparações: 15
//
// Dicas:
// 1. O while de intercala3 continua enquanto ALGUMA fila tem gente
//    (i < na || j < nb || k < nc).
// 2. O "de uma vez" gasta até 2 comparações por elemento; o "duas a duas",
//    no máximo 1 por elemento em cada intercalação. Com muitas listas, o
//    jeito certo de achar a menor frente é um heap (módulo 14).
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int comparacoes;

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
}

int main(void) {

    return 0;
}

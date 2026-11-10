// Lista · Módulo 13 · Busca e ordenação
// Exercício P1326 · ★★★ · Busca binária na escala que deu a volta
//
// O painel do pronto-atendimento guarda as senhas na ordem em que foram
// chamadas. A contagem vai até 99 e recomeça, então o vetor é crescente mas
// "girado":
//
//   61, 67, 72, 80, 94, 3, 9, 18, 26, 33, 40, 52
//
// Escreva uma busca O(log n) nesse vetor:
//
// a) int ponto_de_giro(const int v[], int n): a posição do menor elemento,
//    por busca binária. Enquanto ini < fim: se v[meio] > v[fim], o giro está
//    à direita (ini = meio + 1); senão, fim = meio (o meio pode ser o menor).
// b) int busca(const int v[], int ini, int fim, int x, int *voltas): a
//    binária normal num trecho, somando as voltas.
// c) int busca_girada(const int v[], int n, int x, int *voltas): zera as
//    voltas, acha o giro g e faz UMA busca binária no trecho certo: [0, g-1]
//    se g > 0 e x >= v[0]; senão, [g, n-1].
//
// Mostre o giro e procure 80, 3, 33, 61, 52 e 50.
//
//   Saída esperada:
//   giro na posição 5
//   80: posição 3 (voltas: 2)
//   3: posição 5 (voltas: 3)
//   33: posição 9 (voltas: 3)
//   61: posição 0 (voltas: 2)
//   52: posição 11 (voltas: 3)
//   50: posição -1 (voltas: 3)
//
// Dicas:
// 1. Compare com v[fim], não com v[ini]: assim o caso sem giro (vetor todo
//    crescente) também dá certo e devolve 0.
// 2. As duas partes, v[0..g-1] e v[g..n-1], são crescentes. Todo elemento da
//    primeira é maior que todo elemento da segunda.
// 3. As voltas contadas são só as da busca do item (c), não as do giro.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int escala[] = {61, 67, 72, 80, 94, 3, 9, 18, 26, 33, 40, 52};
    int n = 12;
    int consultas[] = {80, 3, 33, 61, 52, 50};

    (void)escala;
    (void)n;
    (void)consultas;
    return 0;
}

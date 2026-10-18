// 0120 · Counting sort
// Exercício E715 · ★☆☆
//
// As notas da prova de 20 alunos vão de 0 a 10. Ordene o vetor com a versão
// curta do counting sort (conte cada nota e reescreva cada uma c[x] vezes,
// sem vetor de saída) e mostre também a nota mais comum, usando os mesmos
// contadores.
//
//   Saída esperada:
//   ordenadas: 2 3 4 5 5 5 5 6 6 7 7 7 7 7 8 8 8 9 10 10
//   mais comum: 7 (5 alunos)
//
// Dicas:
// 1. int c[11] = {0}; tem um contador para cada nota, de 0 a 10.
// 2. Para reescrever, use um índice pos que só anda para a frente.
// 3. A nota mais comum é o x com o maior c[x]: dá para achar no mesmo laço
//    que reescreve o vetor.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int notas[] = {7, 5, 10, 3, 7, 8, 5, 7, 9, 6, 4, 7, 8, 2, 5, 10, 6, 7, 8, 5};
    int n = 20;
    (void) notas; // apague estas duas linhas
    (void) n;

    return 0;
}

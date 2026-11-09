// Lista · Módulo 13 · Busca e ordenação
// Exercício P1327 · ★★★ · O relatório dos três quadráticos
//
// Monte um relatório que compara bubble, selection e insertion no mesmo
// vetor. Cada um tem a assinatura void f(int v[], int n, int *comp, int *mov)
// e conta:
//
// - bubble (com parada antecipada): comp = comparações v[j] > v[j + 1],
//   mov = trocas;
// - selection: comp = comparações v[j] < v[menor], mov = trocas feitas (só
//   quando menor != i);
// - insertion: comp = cada vez que o while compara v[i] com x (inclusive a
//   comparação que faz o laço parar), mov = deslocamentos v[i + 1] = v[i].
//
// Escreva void relatorio(const char *nome, const int orig[], int n), que roda
// os três numa CÓPIA de orig e mostra uma linha por algoritmo com
// printf("  %-9s comparações %2d, movimentos %2d\n", ...). Rode com o
// vetor misturado 5 2 8 1 9 3 7 4, o crescente 1 2 3 4 5 7 8 9 e o
// decrescente 9 8 7 5 4 3 2 1.
//
//   Saída esperada:
//   misturado:
//     bubble    comparações 25, movimentos 13
//     selection comparações 28, movimentos  5
//     insertion comparações 18, movimentos 13
//   crescente:
//     bubble    comparações  7, movimentos  0
//     selection comparações 28, movimentos  0
//     insertion comparações  7, movimentos  0
//   decrescente:
//     bubble    comparações 28, movimentos 28
//     selection comparações 28, movimentos  4
//     insertion comparações 28, movimentos 28
//
// Dicas:
// 1. No insertion, escreva o while como while (i >= 0) { comp++; if (v[i] <=
//    x) break; ... } para contar também a comparação que para.
// 2. Um vetor de ponteiros para função deixa o relatório curto:
//    void (*alg[])(int[], int, int *, int *) = {bubble, selection, insertion};
// 3. O selection compara sempre 28 = 8 · 7 / 2, mas é o que menos
//    escreve. Bubble e insertion movem exatamente o número de inversões (13
//    no misturado).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

int main(void) {

    return 0;
}

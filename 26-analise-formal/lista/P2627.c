// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2627 · ★★★ · Selection contra insertion
//
// Compare o selection sort e o insertion sort em 1000 notas de alunos, nas
// três entradas clássicas: já ordenada, ao contrário e embaralhada (com o
// gerador do programa). Conte comparações entre elementos e movimentações
// (no selection, cada troca conta 1; no insertion, cada elemento deslocado
// conta 1 e a colocação do x conta 1):
//
//   Saída esperada:
//   entrada       selection: comps   movs | insertion: comps   movs
//   ordenada               499500      0 |              999    999
//   invertida              499500    500 |           499500 500499
//   embaralhada            499500    990 |           250293 250302
//
// Dicas:
// 1. O selection faz n(n-1)/2 = 499500 comparações em qualquer entrada:
//    melhor e pior caso coincidem, Θ(n²).
// 2. O insertion faz n - 1 = 999 comparações na entrada ordenada (Θ(n)) e
//    n(n-1)/2 na invertida.
// 3. Conte a troca do selection só quando o menor não está já na posição (min
//    != i). Use o mesmo vetor embaralhado nos dois.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

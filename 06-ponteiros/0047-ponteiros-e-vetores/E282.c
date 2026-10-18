// 0047 · Ponteiros e vetores
// Exercício E282 · ★★★
//
// O sensor de presença manda leituras repetidas em sequência. Escreva
//
//   int compacta(int *v, int n)
//
// que remove as repetições VIZINHAS no próprio vetor e devolve o novo
// tamanho. Use dois ponteiros: le (que visita cada elemento) e escreve
// (onde vai o próximo valor que fica). Sem vetor auxiliar.
//
//   int leituras[10] = {3, 3, 5, 5, 5, 2, 8, 8, 3, 3};
//
//   Saída esperada:
//   Novo tamanho: 5
//   3 5 2 8 3
//
// Dicas:
// 1. O primeiro sempre fica: escreve começa em v + 1, le também.
// 2. Para cada le, se *le for diferente de *(escreve - 1), copie:
//    *escreve = *le; escreve++.
// 3. O novo tamanho é escreve - v.
// 4. Resposta esperada: tamanho 5 e 3 5 2 8 3 (o último 3 fica: não é
//    vizinho do primeiro).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

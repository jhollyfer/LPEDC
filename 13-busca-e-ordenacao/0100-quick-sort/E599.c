// 0100 · Quick sort
// Exercício E599 · ★★★
//
// Os 11 corredores do grupo fizeram 5 km em 45, 22, 38, 31, 50, 27, 24, 41,
// 29, 35 e 33 minutos. Qual o tempo MEDIANO (o do meio, se a lista estivesse
// ordenada)? Não precisa ordenar tudo: depois de um separa, o pivô está na
// posição final j. Se j é a posição que você quer (k = n / 2), acabou. Se
// k < j, a resposta está só no lado esquerdo; se k > j, só no direito. Isso é
// o QUICKSELECT.
//
// Escreva int quickselect(int v[], int n, int k), sem recursão (um while que
// encolhe [p, r]), e compare as comparações com um quick sort completo numa
// cópia do vetor.
//
//   Saída esperada:
//   mediana: 33 min (quickselect: 10 comparações)
//   ordenando tudo: 33 min (23 comparações)
//
// Dicas:
// 1. Reaproveite o separa do A199, contando comparações num static int.
// 2. Diferente do quick sort, o quickselect só segue UM dos lados.
// 3. Se p == r, sobrou um elemento só: é ele.
// 4. Na média, o quickselect é O(n): n + n/2 + n/4 + ... < 2n.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

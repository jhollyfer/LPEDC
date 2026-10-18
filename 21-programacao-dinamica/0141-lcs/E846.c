// 0141 · Maior subsequência comum (LCS)
// Exercício E846 · ★★★
//
// O fechamento de uma ação em 13 pregões foi, em reais:
//
//   31 28 35 30 33 29 36 40 34 38 41 37 33
//
// Qual é a maior sequência de pregões (não precisam ser seguidos) em que o
// preço SEMPRE sobe? É a maior subsequência crescente, e existe um truque
// para resolvê-la com o que você já tem: ela é a LCS entre o vetor original
// e uma cópia dele ORDENADA e SEM REPETIDOS. (Pense: uma subsequência comum
// às duas está na ordem dos pregões e, ao mesmo tempo, em ordem crescente.)
//
// Escreva o programa: copie o vetor, ordene a cópia com qsort (assunto
// 0050), tire os repetidos, rode a LCS de vetores de int com recuperação e
// mostre o tamanho e os preços.
//
//   Saída esperada:
//   Maior sequência de altas: 6 dias
//   Preços: 28 30 33 36 40 41
//
// Dicas:
// 1. A compara do qsort: return (a > b) - (a < b); (sem a - b, que pode
//    estourar).
// 2. Para tirar repetidos de um vetor ordenado, copie ord[i] para ord[u++]
//    só quando ele for diferente do último copiado.
// 3. Sem tirar os repetidos, o 33 (que aparece duas vezes) poderia entrar
//    duas vezes, e "33 33" não é subir.
// 4. Use o desempate do texto (>= sobe). Há outras respostas com 6 preços,
//    como 28 30 33 34 38 41.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}

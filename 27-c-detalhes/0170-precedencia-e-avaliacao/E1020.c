// 0170 · Precedência e ordem de avaliação
// Exercício E1020 · ★★★
//
// Um colega escreveu a busca de um código no estoque assim:
//
//   while (v[i] != alvo && i < n) i++;
//
// Quando o código não existe, ele lê v[n], que fica fora do vetor (o
// AddressSanitizer acusa). Escreva a versão segura:
//
//   int procurar(const int *v, int n, int alvo, int *lidos)
//
// Ela devolve o índice do alvo, ou -1, e conta em *lidos quantas vezes leu
// uma casa do vetor. Teste com os códigos {12, 7, 30, 7, 55}, procurando 30
// e 99, e com um vetor vazio (n = 0).
//
//   Saída esperada:
//   procurar 30: indice 2, leituras 3
//   procurar 99: indice -1, leituras 5
//   vetor vazio: indice -1, leituras 0
//
// Dicas:
// 1. Troque a ordem: i < n tem que vir antes, porque o && só avalia o lado
//    direito se o esquerdo der verdadeiro.
// 2. Para contar só as leituras que acontecem, use o operador vírgula no
//    lado direito: (++*lidos, v[i] != alvo).
// 3. Comece *lidos em 0 dentro da função.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

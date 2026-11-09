// Lista · Módulo 21 · Programação dinâmica
// Exercício P2112 · ★★☆ · A mochila de uma linha só
//
// Este programa tem um erro de propósito. A mochila 0/1 não precisa da
// tabela n × W inteira: uma linha só, melhor[w], basta, desde que o laço
// de w ande de TRÁS PARA A FRENTE. A feirante tem uma caixa térmica de 10
// kg e quatro produtos, cada um levado inteiro ou não levado:
//
//   produto   queijo  manteiga  doce  requeijão
//   kg          4        3       5       2
//   R$         40       27      45      16
//
// O programa compila sem aviso e roda, mas responde R$ 96, mais do que é
// possível: ele está levando o mesmo produto mais de uma vez. Conserte.
//
//   Saída esperada:
//   Melhor valor em 10 kg: R$ 88
//
// Dicas:
// 1. Acrescente um printf de melhor[] depois de cada produto. Com o laço
//    de frente para trás, melhor[w - kg] já foi atualizado com o MESMO
//    produto quando você chega em melhor[w].
// 2. De trás para a frente, melhor[w - kg] ainda é o valor da linha
//    anterior (sem o produto atual).
// 3. Resposta esperada: for (int w = CAP; w >= kg[i]; w--). O ótimo é R$ 88:
//    manteiga + doce + requeijão, exatamente 10 kg.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define N 4
#define CAP 10

int main(void) {
    const int kg[N] = {4, 3, 5, 2};
    const int valor[N] = {40, 27, 45, 16};
    int melhor[CAP + 1] = {0};
    for (int i = 0; i < N; i++) {
        for (int w = kg[i]; w <= CAP; w++) {
            if (melhor[w - kg[i]] + valor[i] > melhor[w]) {
                melhor[w] = melhor[w - kg[i]] + valor[i];
            }
        }
    }
    printf("Melhor valor em %d kg: R$ %d\n", CAP, melhor[CAP]);
    return 0;
}

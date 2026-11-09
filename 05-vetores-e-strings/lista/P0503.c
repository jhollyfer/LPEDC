// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0503 · ★☆☆ · A fila ao contrário
//
// Na fila do posto de saúde, as senhas foram chamadas nesta ordem:
//
//   int senhas[] = {101, 102, 105, 108, 110, 113, 117};
//
// O auditor quer ver a fila de trás para a frente. Escreva
// void inverter(int v[], int n), que inverte o vetor NO LUGAR (sem criar
// outro vetor), e void mostrar(const int v[], int n). Mostre a fila antes e
// depois de inverter.
//
//   Saída esperada:
//   Antes:  101 102 105 108 110 113 117
//   Depois: 117 113 110 108 105 102 101
//
// Dicas:
// 1. Troque v[0] com v[n - 1], v[1] com v[n - 2], e assim por diante.
// 2. Pare no meio (i < n / 2). Se for até o fim, você destroca tudo e o vetor
//    volta a ser o que era.
// 3. A troca usa uma variável auxiliar: aux = v[i]; v[i] = v[j]; v[j] = aux;
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int senhas[] = {101, 102, 105, 108, 110, 113, 117};
    int n = sizeof senhas / sizeof senhas[0];
    (void) n; // apague esta linha quando escrever

    return 0;
}

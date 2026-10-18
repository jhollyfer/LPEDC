// 0076 · Eficiência: contar passos
// Exercício E452 · ★☆☆
//
// A função abaixo acha a maior temperatura de uma semana e meia (10 dias).
// Complete o código com dois contadores globais: "comparacoes" (quantas vezes
// a função compara t[i] com o maior até agora) e "trocas" (quantas vezes o
// maior até agora muda de valor). Mostre os dois no final.
//
//   Saída esperada:
//   Maior: 36
//   Comparações: 9
//   Trocas: 3
//
// Dicas:
// 1. O maior começa como t[0]. A primeira comparação é com t[1].
// 2. Some 1 em comparacoes antes do if; some 1 em trocas dentro dele.
// 3. Com n valores, achar o maior custa sempre n - 1 comparações, não importa
//    a ordem. Já o número de trocas depende da ordem dos dados.
// 4. Resposta esperada: Maior: 36, Comparações: 9, Trocas: 3 (o maior muda
//    para 31, depois 35, depois 36).
//
// Escreva sua resposta abaixo (complete os TODO):

#include <stdio.h>

int comparacoes = 0;
int trocas = 0;

int maior_temperatura(const int t[], int n) {
    int maior = t[0];
    for (int i = 1; i < n; i++) {
        // TODO: conte a comparação
        if (t[i] > maior) {
            maior = t[i];
            // TODO: conte a troca
        }
    }
    return maior;
}

int main(void) {
    int temps[10] = {28, 31, 27, 35, 33, 30, 29, 36, 34, 32};

    printf("Maior: %d\n", maior_temperatura(temps, 10));
    // TODO: mostre comparacoes e trocas
    return 0;
}

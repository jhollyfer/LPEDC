// 0096 · Comparando: estabilidade, custo e qsort
// Exercício E572 · ★☆☆
//
// O placar de um torneio de 12 jogadores é reordenado a cada ponto marcado,
// então ele está sempre QUASE em ordem. Qual algoritmo usar? Decida com
// números, não com palpite. O selection sort abaixo já devolve quantas
// comparações fez. Escreva int insertion(int v[], int n), que também devolve
// as comparações (uma por teste v[i] <= x feito), rode os dois em cópias do
// placar e mostre qual foi melhor.
//
//   Saída esperada:
//   selection: 66 comparações
//   insertion: 13 comparações
//   melhor para o placar: insertion
//
// Dicas:
// 1. Faça outra cópia, como o main já faz para o selection: cada algoritmo
//    precisa receber o placar original, não o já ordenado.
// 2. No insertion, conte dentro do while e saia com break quando
//    v[i] <= x: é aí que ele economiza.
// 3. O selection faz sempre 11 + 10 + ... + 1 = 66, esteja o vetor como
//    estiver.
// 4. Resposta esperada: a saída acima. Só o 58 está fora do lugar, então o
//    insertion faz pouco mais que n comparações.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>
#include <string.h>

int selection(int v[], int n) {
    int comparacoes = 0;
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        int aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
    return comparacoes;
}

// escreva aqui: int insertion(int v[], int n)

int main(void) {
    int placar[] = {10, 14, 19, 23, 27, 31, 36, 40, 45, 58, 49, 52};
    int n = 12;

    int a[12];
    memcpy(a, placar, sizeof placar);   // o selection ordena uma cópia
    printf("selection: %d comparações\n", selection(a, n));
    // complete: rode o insertion em outra cópia e diga qual foi melhor
    return 0;
}

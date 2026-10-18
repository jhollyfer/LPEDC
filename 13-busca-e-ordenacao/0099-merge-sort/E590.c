// 0099 · Merge sort
// Exercício E590 · ★☆☆
//
// O programa abaixo não ordena nada: ele só mostra QUAIS chamadas o merge sort
// faria para um vetor de 5 elementos, com um recuo de dois espaços por nível
// de recursão. SEM RODAR, escreva a saída exata. Depois rode e confira.
//
// Dicas:
// 1. Comece por ordena(0, 5): q = 0 + 5 / 2 = 2. As metades são [0, 2) e [2, 5).
// 2. A metade esquerda inteira (com todas as suas chamadas) é mostrada antes
//    da direita.
// 3. Pedaços com menos de 2 elementos aparecem, mas não chamam ninguém.
// 4. Resposta esperada: 9 linhas, nesta ordem: [0, 5), [0, 2), [0, 1),
//    [1, 2), [2, 5), [2, 3), [3, 5), [3, 4) e [4, 5). Recuo: nenhum na
//    primeira; 2 espaços em [0, 2) e [2, 5); 4 em [0, 1), [1, 2), [2, 3) e
//    [3, 5); 6 nas duas últimas.
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>

void ordena(int p, int r, int nivel) {
    for (int i = 0; i < nivel; i++) {
        printf("  ");
    }
    printf("[%d, %d)\n", p, r);
    if (r - p < 2) {
        return;
    }
    int q = p + (r - p) / 2;
    ordena(p, q, nivel + 1);
    ordena(q, r, nivel + 1);
}

int main(void) {
    ordena(0, 5, 0);
    return 0;
}

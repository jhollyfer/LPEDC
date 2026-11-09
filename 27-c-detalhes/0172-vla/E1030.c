// 0172 · Vetor de tamanho variável (VLA)
// Exercício E1030 · ★★☆
//
// O programa abaixo calcula o preço médio de n produtos guardados num VLA.
// Com n = 10 ele funciona. Mas o cliente tem 3 milhões de produtos: 24 MB,
// três vezes a pilha. Refatore:
//
//   - troque o VLA por double *precos = malloc(...), confira NULL e libere
//     com free no fim;
//   - mude n para 3000000.
//
//   Saída esperada:
//   n = 3000000, media = R$ 50.00
//
// Dicas:
// 1. Rode antes, com n = 10: sai media = R$ 5.00.
// 2. malloc(n * sizeof *precos). Se der NULL, mostre "sem memória" e
//    devolva 1.
// 3. O resto do código não muda: precos[i] funciona igual com o ponteiro.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (refatore o código):

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 10;
    double precos[n];
    for (int i = 0; i < n; i++) {
        precos[i] = i % 100 + 0.5;
    }

    double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += precos[i];
    }
    printf("n = %d, media = R$ %.2f\n", n, soma / n);
    return 0;
}

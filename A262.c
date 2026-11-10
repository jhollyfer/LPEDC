// A262 · Maior e menor de uma vez, dividindo ao meio

#include <stdio.h>

static int comparacoes = 0;

typedef struct {
    int menor;
    int maior;
} Extremos;

// menor e maior de v[ini..fim] (intervalo fechado)
Extremos extremos(const int v[], int ini, int fim) {
    Extremos e;
    if (ini == fim) {                   // 1 elemento: é o menor e o maior
        e.menor = e.maior = v[ini];
        return e;
    }
    if (fim == ini + 1) {               // 2 elementos: 1 comparação basta
        comparacoes++;
        if (v[ini] < v[fim]) {
            e.menor = v[ini];
            e.maior = v[fim];
        } else {
            e.menor = v[fim];
            e.maior = v[ini];
        }
        return e;
    }
    int meio = ini + (fim - ini) / 2;
    Extremos a = extremos(v, ini, meio);     // metade esquerda
    Extremos b = extremos(v, meio + 1, fim); // metade direita
    comparacoes += 2;                        // combina: 2 comparações
    e.menor = a.menor < b.menor ? a.menor : b.menor;
    e.maior = a.maior > b.maior ? a.maior : b.maior;
    return e;
}

int main(void) {
    // temperaturas mínimas de 16 dias em Curitiba, em graus
    int temp[] = {12, 9, 15, 7, 11, 14, 6, 10, 13, 8, 16, 5, 9, 12, 17, 10};
    int n = 16;

    // jeito simples: cada elemento compara com o menor E com o maior
    int menor = temp[0], maior = temp[0], simples = 0;
    for (int i = 1; i < n; i++) {
        simples += 2;
        if (temp[i] < menor) menor = temp[i];
        if (temp[i] > maior) maior = temp[i];
    }
    printf("Laço simples: menor %d, maior %d, %d comparações\n", menor, maior, simples);

    // dividindo: cada par custa 1 comparação (e não 2), e cada combinação
    // custa 2. Total: 3n/2 - 2 = 22, contra 2(n - 1) = 30. O Big-O é o mesmo,
    // O(n); a divisão e conquista ganhou na constante.
    Extremos e = extremos(temp, 0, n - 1);
    printf("Dividindo:    menor %d, maior %d, %d comparações\n", e.menor, e.maior, comparacoes);
    return 0;
}
// Saída:
// Laço simples: menor 5, maior 17, 30 comparações
// Dividindo:    menor 5, maior 17, 22 comparações

// 0169 · Juntando tudo: passos e bytes conferidos
// Exercício E1010 · ★☆☆

#include <stdio.h>

long passos_pares = 0;
long passos_uma = 0;

// maior diferença testando todos os pares: Θ(n²)
int diferenca_pares(const int v[], int n) {
    int maior = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            passos_pares++;
            int d = v[i] > v[j] ? v[i] - v[j] : v[j] - v[i];
            if (d > maior) {
                maior = d;
            }
        }
    }
    return maior;
}

// maior diferença = maior - menor, numa passada só: Θ(n)
int diferenca_uma(const int v[], int n) {
    int menor = v[0], maior = v[0];
    for (int i = 0; i < n; i++) {
        passos_uma++;
        if (v[i] < menor) menor = v[i];
        if (v[i] > maior) maior = v[i];
    }
    return maior - menor;
}

int main(void) {
    static int preco[1000];
    for (int i = 0; i < 1000; i++) {
        preco[i] = 500 + (i * 37) % 1000; // preços do cimento em centavos
    }
    int a = diferenca_pares(preco, 1000);
    int b = diferenca_uma(preco, 1000);
    printf("pares: diferença %d em %ld passos\n", a, passos_pares);
    printf("uma:   diferença %d em %ld passos\n", b, passos_uma);
    return 0;
}

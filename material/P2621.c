// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2621 · ★★★ · As fatias que deram zero
//
// Conserte o programa. Ele mede os passos da conferência de pares da fila
// do banco, f(n) = n(n+1)/2 + 3n, e procura as fatias do sanduíche do Θ(n²):
// c1 = menor e c2 = maior valor de passos / n² para n de 10 a 2000. Mas a
// saída sai assim:
//
//   Saída que aparece:
//   c1 = 0.0000, c2 = 0.0000
//
// Ache o erro na conta da razão (o laço e o contador estão certos):
//
//   Saída esperada:
//   c1 = 0.5018, c2 = 0.8500
//
// Dicas:
// 1. passos / (n * n) é divisão de inteiros, e a razão é sempre menor que 1:
//    dá 0 em toda a faixa.
// 2. Converta antes de dividir: (double)passos / ((double)n * n). Converter o
//    resultado já truncado não adianta.
// 3. Com n = 10, a razão é (55 + 30) / 100 = 0,85. Ela desce para 0,5 sem
//    chegar lá.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

long passos = 0;

void confere(int n) {
    for (int i = 0; i < n; i++) {
        passos += 3;                     // abre, confere e fecha a ficha
        for (int j = i; j < n; j++) {
            passos++;                    // o par (i, j)
        }
    }
}

int main(void) {
    double c1 = 1e9, c2 = 0;
    for (long n = 10; n <= 2000; n++) {
        passos = 0;
        confere((int)n);
        double r = (double)(passos / (n * n));
        if (r < c1) c1 = r;
        if (r > c2) c2 = r;
    }
    printf("c1 = %.4f, c2 = %.4f\n", c1, c2);
    return 0;
}

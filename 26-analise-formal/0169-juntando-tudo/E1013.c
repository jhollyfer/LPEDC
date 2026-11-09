// 0169 · Juntando tudo: passos e bytes conferidos
// Exercício E1013 · ★★★
//
// Conserte a instrumentação. O programa deveria conferir que o insertion
// sort faz n(n-1)/2 comparações no pior caso (vetor ao contrário), mas o
// contador está no lugar errado:
//
//   Saída que aparece:
//   n =  500:     499 comparações, n(n-1)/2 =  124750, confere: não
//   n = 1000:     999 comparações, n(n-1)/2 =  499500, confere: não
//   n = 2000:    1999 comparações, n(n-1)/2 = 1999000, confere: não
//
// Mova o contador para que ele conte cada comparação entre elementos
// (cada vez que v[j] é comparado com x). Sem mudar o algoritmo:
//
//   Saída esperada:
//   n =  500:  124750 comparações, n(n-1)/2 =  124750, confere: sim
//   n = 1000:  499500 comparações, n(n-1)/2 =  499500, confere: sim
//   n = 2000: 1999000 comparações, n(n-1)/2 = 1999000, confere: sim
//
// Dicas:
// 1. A comparação v[j] > x está na condição do while, junto com j >= 0.
//    Para contar só quando ela acontece, reescreva o while com o teste
//    j >= 0 na condição e o v[j] > x num if dentro, com break.
// 2. Conte antes do if, toda vez que for comparar.
// 3. No pior caso, o elemento i compara com todos os i anteriores:
//    1 + 2 + ... + (n-1) = n(n-1)/2 (assunto 0167).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

long comparacoes = 0;

void insercao(int v[], int n) {
    for (int i = 1; i < n; i++) {
        comparacoes++;
        int x = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > x) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

int main(void) {
    static int v[2000];
    for (int n = 500; n <= 2000; n *= 2) {
        for (int i = 0; i < n; i++) {
            v[i] = n - i;                // ao contrário: pior caso
        }
        comparacoes = 0;
        insercao(v, n);
        long formula = (long)n * (n - 1) / 2;
        printf("n = %4d: %7ld comparações, n(n-1)/2 = %7ld, confere: %s\n",
               n, comparacoes, formula, comparacoes == formula ? "sim" : "não");
    }
    return 0;
}

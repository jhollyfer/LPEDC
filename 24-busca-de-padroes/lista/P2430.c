// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2430 · ★★★ · A roda da fortuna
//
// No programa de auditório, as letras ficam numa roda: depois da última
// vem a primeira de novo. A roda tem "abracadabra". Escreva
// circular(t, p), um KMP que procura p no texto CIRCULAR sem montar t + t:
// percorra i de 0 até n + m - 2 lendo t[i % n]. Mostre o início de cada
// ocorrência (com um * quando ela dá a volta pelo fim) e o total.
//
//   Saída esperada:
//   abra: 0 7 (2)
//   raab: 9* (1)
//   aabr: 10* (1)
//   dabraabr: 6* (1)
//   aa: 10* (1)
//
// Dicas:
// 1. Uma ocorrência começa em (i - m + 1) % n; ela dá a volta quando
//    começo + m > n.
// 2. Parar em n + m - 2 garante que cada começo de 0 a n - 1 é testado uma
//    vez só (senão "abra" seria achado duas vezes na posição 0).
// 3. Resposta esperada: abra em 0 e 7; raab em 9*; aa em 10* (o último a
//    da roda com o primeiro).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

void calcula_pi(const char *p, int m, int pi[]) {
    pi[0] = 0;
    int k = 0;
    for (int j = 1; j < m; j++) {
        while (k > 0 && p[j] != p[k]) k = pi[k - 1];
        if (p[j] == p[k]) k++;
        pi[j] = k;
    }
}

int main(void) {
    const char *roda = "abracadabra";
    const char *busca[] = {"abra", "raab", "aabr", "dabraabr", "aa"};
    printf("%s: %s\n", roda, busca[0]);
    return 0;
}

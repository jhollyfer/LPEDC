// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2404 · ★☆☆ · Onde aparece o CEP
//
// A mensagem do cliente tem três CEPs. Complete
// int kmp_primeira(t, p, &comparacoes): o KMP que para na PRIMEIRA
// ocorrência e devolve a posição dela (ou -1), contando cada comparação
// t[i] com p[k], inclusive as que acontecem nos recuos. A calcula_pi já
// está pronta.
//
//   Saída esperada:
//   69060-001: posição 39, 49 comparações
//   69061-000: posição 52, 65 comparações
//   69000-000: posição -1, 67 comparações
//
// Dicas:
// 1. Escreva a comparação num laço só, para não contar duas vezes:
//    for (;;) { conta; se t[i] == p[k], k++ e sai; se k == 0, sai;
//    senão k = pi[k - 1]; }.
// 2. A ocorrência termina em i quando k chega a m: ela começa em i - m + 1.
// 3. Resposta esperada: 69060-001 na posição 39 (49 comparações); o
//    69000-000 não aparece, com 67 comparações num texto de 61 letras:
//    o KMP nunca passa de 2n.
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

int kmp_primeira(const char *t, const char *p, int *comparacoes) {
    (void)t; // apague estas linhas e escreva o KMP
    (void)p;
    *comparacoes = 0;
    return -1;
}

int main(void) {
    const char *msg = "entregar no CEP 69060-000; se fechado, 69060-001 ou 69061-000";
    const char *ceps[] = {"69060-001", "69061-000", "69000-000"};
    for (int c = 0; c < 3; c++) {
        int comp;
        int pos = kmp_primeira(msg, ceps[c], &comp);
        printf("%s: posição %d, %d comparações\n", ceps[c], pos, comp);
    }
    return 0;
}

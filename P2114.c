// Lista · Módulo 21 · Programação dinâmica
// Exercício P2114 · ★★☆ · Edição com troca mais cara
//
// No corretor do teclado do celular, trocar uma letra por outra é menos
// provável que esquecer ou repetir uma letra, então a empresa deu pesos:
// inserir custa 1, remover custa 1 e TROCAR custa 2 (o mesmo que remover e
// inserir). O programa abaixo é o Levenshtein comum, com troca custando 1.
// Estenda-o para receber os três custos como parâmetros e mostre, para
// cada par, a distância comum e a ponderada.
//
//   Saída esperada:
//   CASA -> COISA: comum 2, troca cara 3
//   GATO -> PATO: comum 1, troca cara 2
//   BOLA -> LOBA: comum 2, troca cara 4
//   FEIRA -> FERIADO: comum 4, troca cara 4
//
// Dicas:
// 1. Borda: d[i][0] = i · custo_remove e d[0][j] = j · custo_insere.
// 2. Letras iguais custam 0 na diagonal; diferentes, custo_troca.
// 3. Resposta esperada: com troca 2, a distância de edição é m + n - 2 ·
//    LCS. CASA para COISA vai de 2 para 3; veja os outros na saída.
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdio.h>
#include <string.h>

int min3(int x, int y, int z) {
    int m = x < y ? x : y;
    return m < z ? m : z;
}

int edicao(const char *a, const char *b) {
    int m = (int)strlen(a), n = (int)strlen(b);
    int d[16][16];
    for (int i = 0; i <= m; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        d[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int diag = d[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 0 : 1);
            d[i][j] = min3(d[i - 1][j] + 1, d[i][j - 1] + 1, diag);
        }
    }
    return d[m][n];
}

int main(void) {
    const char *pares[4][2] = {{"CASA", "COISA"}, {"GATO", "PATO"}, {"BOLA", "LOBA"}, {"FEIRA", "FERIADO"}};
    for (int k = 0; k < 4; k++) {
        printf("%s -> %s: comum %d\n", pares[k][0], pares[k][1], edicao(pares[k][0], pares[k][1]));
    }
    return 0;
}

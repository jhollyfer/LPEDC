// Lista · Módulo 21 · Programação dinâmica
// Exercício P2127 · ★★★ · A distância que erra por uma letra
//
// Este programa tem um erro de propósito. Ele calcula a distância de
// edição (Levenshtein: inserir, remover ou trocar, custo 1 cada) entre
// pares de palavras e compila sem aviso e roda limpo no sanitizer, mas os
// números estão errados: diz que CAVALO e CAVALO estão a distância 2,
// por exemplo. Ache e conserte o erro. A tabela, a borda e o mínimo dos
// três vizinhos estão certos.
//
//   Saída esperada:
//   CAVALO -> CAVALO: 0
//   CAVALO -> CABELO: 2
//   MANAUS -> MANAUARA: 3
//   TUCANO -> TUCUMA: 3
//
// Dicas:
// 1. Instrumente: mostre a tabela de CAVALO com CAVALO. A diagonal devia
//    ficar toda com 0.
// 2. A casa d[i][j] fala dos prefixos a[0..i - 1] e b[0..j - 1]. Quais são
//    as últimas letras desses prefixos? Compare com o que o programa olha.
// 3. Resposta esperada: compare a[i - 1] com b[j - 1]. A tabela tem uma
//    linha e uma coluna a mais que as strings (a da palavra vazia), por
//    isso os índices andam deslocados de um.
//
// Escreva sua resposta abaixo (conserte o código):

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
            int troca = a[i - 1] == b[j] ? 0 : 1;
            d[i][j] = min3(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + troca);
        }
    }
    return d[m][n];
}

int main(void) {
    const char *pares[4][2] = {{"CAVALO", "CAVALO"}, {"CAVALO", "CABELO"}, {"MANAUS", "MANAUARA"}, {"TUCANO", "TUCUMA"}};
    for (int k = 0; k < 4; k++) {
        printf("%s -> %s: %d\n", pares[k][0], pares[k][1], edicao(pares[k][0], pares[k][1]));
    }
    return 0;
}

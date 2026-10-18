// A314 · O pior caso: um código cheio de zeros

#include <stdio.h>
#include <string.h>

// força bruta que só conta: devolve as comparações de letra feitas
long comparacoes(const char *texto, const char *padrao, int *achados) {
    int n = (int) strlen(texto);
    int m = (int) strlen(padrao);
    long comp = 0;
    *achados = 0;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m) {
            comp++;
            if (texto[i + j] != padrao[j]) {
                break;
            }
            j++;
        }
        if (j == m) {
            (*achados)++;
        }
    }
    return comp;
}

int main(void) {
    // 20 dígitos: dezenove zeros e um 1 no fim (n = 20)
    const char *codigo = "00000000000000000001";
    const char *padroes[] = {"10000", "00001", "00000"};
    int achados;

    for (int k = 0; k < 3; k++) {
        long c = comparacoes(codigo, padroes[k], &achados);
        printf("%s: %d ocorrência(s), %3ld comparações\n", padroes[k], achados, c);
    }
    printf("teto (n - m + 1) * m = %d\n", (20 - 5 + 1) * 5);
    return 0;
}
// Saída:
// 10000: 0 ocorrência(s),  16 comparações
// 00001: 1 ocorrência(s),  80 comparações
// 00000: 15 ocorrência(s),  80 comparações
// teto (n - m + 1) * m = 80

// 0157 · Força bruta
// Exercício E939 · ★★☆

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// força bruta que ignora maiúsculas e minúsculas
int busca_sem_caixa(const char *texto, const char *padrao) {
    int n = (int) strlen(texto);
    int m = (int) strlen(padrao);
    int total = 0;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && tolower((unsigned char) texto[i + j]) ==
                            tolower((unsigned char) padrao[j])) {
            j++;
        }
        if (j == m) {
            printf("posição %2d: %.*s\n", i, m, texto + i);
            total++;
        }
    }
    return total;
}

int main(void) {
    const char *msg = "Recebi um PIX, mandei outro Pix e tem um pix agendado";
    int t = busca_sem_caixa(msg, "pix");
    printf("%d ocorrências\n", t);
    return 0;
}

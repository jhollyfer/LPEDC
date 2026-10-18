// 0157 · Força bruta
// Exercício E941 · ★★★

#include <stdio.h>
#include <string.h>

int conta(const char *texto, const char *padrao) {
    size_t n = strlen(texto);
    size_t m = strlen(padrao);
    int total = 0;
    if (m > n) {
        return 0;                 // padrão maior que o texto: nenhum alinhamento
    }
    for (size_t i = 0; i <= n - m; i++) {
        size_t j = 0;
        while (j < m && texto[i + j] == padrao[j]) {
            j++;
        }
        if (j == m) {
            total++;
        }
    }
    return total;
}

int main(void) {
    printf("%d\n", conta("pix pix", "pix"));
    printf("%d\n", conta("banana", "ana"));
    printf("%d\n", conta("pix", "pagamento"));
    return 0;
}

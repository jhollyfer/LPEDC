// 0160 · Rabin-Karp
// Exercício E955 · ★☆☆

#include <stdio.h>
#include <string.h>

// valor dos m dígitos de s, mod q, calculado pela regra de Horner
int hash_digitos(const char *s, int m, int q) {
    int h = 0;
    for (int j = 0; j < m; j++) {
        h = (h * 10 + (s[j] - '0')) % q;
    }
    return h;
}

int main(void) {
    const char *data = "18102026";
    int n = (int) strlen(data);
    int m = 4;

    for (int i = 0; i <= n - m; i++) {
        printf("%.*s -> %2d\n", m, data + i, hash_digitos(data + i, m, 97));
    }
    return 0;
}

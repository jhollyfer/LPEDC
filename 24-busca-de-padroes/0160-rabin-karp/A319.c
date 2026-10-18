// A319 · O tamanho do primo e os alarmes falsos

#include <stdio.h>
#include <string.h>

#define BASE 256  // cada byte é um "dígito" na base 256

int iguais(const char *t, const char *p, int m) {
    for (int j = 0; j < m; j++) {
        if (t[j] != p[j]) {
            return 0;
        }
    }
    return 1;
}

// Rabin-Karp com módulo q; conta ocorrências e falsos positivos
void rabin_karp(const char *t, const char *p, long long q) {
    int n = (int) strlen(t);
    int m = (int) strlen(p);
    long long pot = 1, hp = 0, ht = 0;
    for (int j = 0; j < m - 1; j++) {
        pot = pot * BASE % q;
    }
    for (int j = 0; j < m; j++) {
        hp = (hp * BASE + (unsigned char) p[j]) % q;
        ht = (ht * BASE + (unsigned char) t[j]) % q;
    }
    int achados = 0, falsos = 0;
    for (int i = 0; i <= n - m; i++) {
        if (ht == hp) {
            if (iguais(t + i, p, m)) {
                achados++;
            } else {
                falsos++;            // hash igual, letras diferentes
            }
        }
        if (i < n - m) {
            ht = (ht - (unsigned char) t[i] * pot % q + q) % q;
            ht = (ht * BASE + (unsigned char) t[i + m]) % q;
        }
    }
    printf("q = %7lld: %d ocorrências, %2d falsos positivos\n", q, achados, falsos);
}

int main(void) {
    const char *cronica =
        "na feira de domingo a barraca do seu jorge vende pastel de queijo e caldo de cana, "
        "a dona rita grita o preco da banana e do abacaxi, o menino do pastel corre com a bandeja, "
        "o fiscal confere a balanca, a fila do caldo de cana dobra a esquina e o sol de meio dia "
        "derrete o gelo do isopor enquanto o radio toca um samba antigo perto da banca de peixe";

    printf("%zu letras\n", strlen(cronica));
    long long primos[] = {7, 11, 101, 1009, 1000003};
    for (int k = 0; k < 5; k++) {
        rabin_karp(cronica, "caldo de cana", primos[k]);
    }
    return 0;
}
// Saída:
// 347 letras
// q =       7: 2 ocorrências, 48 falsos positivos
// q =      11: 2 ocorrências, 28 falsos positivos
// q =     101: 2 ocorrências,  4 falsos positivos
// q =    1009: 2 ocorrências,  0 falsos positivos
// q = 1000003: 2 ocorrências,  0 falsos positivos
